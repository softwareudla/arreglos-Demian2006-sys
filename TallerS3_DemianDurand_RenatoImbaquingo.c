#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
    char estudiantes[5][50];
    char asignaturas[3][50];
    float promedioa1[5], promedioa2[5], promedioa3[5];
    float nota1[5][3],mayor, menor,cantidad[5][3];
    int eaprobados;
    int opc1, cont = 0, result, len, valid = 0, cont2 = 0, valid2 = 0,len2;
    do
    {
        do
        {
            printf("_Menu de opciones_\n");
            printf("=========================\n");
            printf("1. Ingresar estudiante\n");
            printf("2. Ingresar materias\n");
            printf("3. Ingresar calificaciones de estudiante por materia\n");
            printf("4. Verificar promedio por asignatura\n");
            printf ("5. Verificar promedio por estudiante\n");
            printf ("6. Estudiantes aprobados y reprobados\n");
            printf("7. Salir\n");
            printf("=========================\n");
            printf(">>");
            result = scanf("%d", &opc1);
            if (result != 1)
            {
                printf("Opcion invalida, ingrese el numero entero\n");
                while (getchar() != '\n');
                opc1 = -1;
            }

        } while (result != 1);
        if (opc1 >= 3 && opc1 <= 6 && valid == 0 && valid2 == 0)
        {
            printf("No se ha registrado ningun estudiante. Ingrese primero los estudiantes y las materias.\n");
            continue;
        }
        switch (opc1)
        {
        case 1:
            if (cont < 5)
            {
                printf("Ingrese el nombre del estudiante %d: ", cont);
                fflush(stdin);
                fgets(estudiantes[cont], 50, stdin);
                len = strlen(estudiantes[cont])-1;
                estudiantes[cont][len] = '\0';
                cont++;
                valid++;
            }else{
                printf ("Numero maximo de estudiantes alcanzado (5)\n");
            }
            break;
        case 2:
        if (cont2<3){
            printf("Ingresar materia %d: ", cont2);
            fflush(stdin);
            fgets(asignaturas[cont2], 50, stdin);
            len2 = strlen(asignaturas[cont2])-1;
            asignaturas[cont2][len2] = '\0';
            cont2++;
            valid2++;
        }else{
            printf ("Numero maximo de materias alcanzado (3)\n");
        }
            break;
        case 3:
        char naux[50];
        printf ("Ingrese la asignatura a la que desea acceder (nombre):\n");
        for (int i = 0; i < cont2; i++)
        {
            printf ("-%s \n",asignaturas[i]);
        }
        scanf("%s",&naux);
        for (int i = 0; i < cont2; i++)
        {
            if (strcmp(asignaturas[i],naux)==0){
            char naux2[50];
            printf ("Ingrese el estudiante a calificar(el nombre): \n");
            for (int k = 0; k < cont; k++)
            {
                printf ("-%s \n",estudiantes[k]);
            }
            scanf("%s",&naux2);
            for (int j = 0; j < cont; j++)
            {
                if (strcmp(estudiantes[j],naux2)==0){
                    do{
                    if (nota1[j][i]<0 || nota1[j][i]>10){
                        printf ("Opcion invalida, vuelva a ingresar");
                    }else{
                    printf ("Ingrese la nota\n");
                    scanf ("%f",&nota1[j][i]);
                    nota1[j][i]+=nota1[j][i];
                    cantidad[j][i]++;
                    }
                    }while (nota1[j][i]<0 || nota1[j][i]>10);
                }
            }
        }else{
            printf ("Asignatura no encontrada");
        }
        }

        break;
        case 4:
        printf ("hi");
        
        case 7:
            printf("Saliendo del programa...");
        default:
            printf("Opcion no valida, ingrese una opcion valida\n");
            break;
        }
    } while (opc1 != 7);
    return 0;
}
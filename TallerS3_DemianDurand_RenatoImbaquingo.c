#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char estudiantes[5][50];
    char asignaturas[3][50];
    float promedioa1[5], promedioa2[5], promedioa3[5];
    float nota1[5][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}}, mayor, menor, cantidad[5][3];
    int eaprobados;
    int opc1, cont = 0, result, len, valid = 0, cont2 = 0, valid2 = 0, len2;
    do
    {
        do
        {
            printf("Menu de opciones\n");
            printf("=========================\n");
            printf("1. Ingresar estudiante\n");
            printf("2. Ingresar materias\n");
            printf("3. Ingresar calificaciones de estudiante por materia\n");
            printf("4. Verificar promedio por asignatura\n");
            printf("5. Verificar promedio por estudiante\n");
            printf("6. Estudiantes aprobados y reprobados\n");
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
        if (opc1 >= 3 && opc1 <= 6 && (valid == 0 || valid2 == 0))
        {
            printf("Ingrese primero los estudiantes y las materias.\n");
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
                len = strlen(estudiantes[cont]) - 1;
                estudiantes[cont][len] = '\0';
                cont++;
                valid++;
            }
            else
            {
                printf("Numero maximo de estudiantes alcanzado (5)\n");
            }
            break;

        case 2:
            if (cont2 < 3)
            {
                printf("Ingresar materia %d: ", cont2);
                fflush(stdin);
                fgets(asignaturas[cont2], 50, stdin);
                len2 = strlen(asignaturas[cont2]) - 1;
                asignaturas[cont2][len2] = '\0';
                cont2++;
                valid2++;
            }
            else
            {
                printf("Numero maximo de materias alcanzado (3)\n");
            }
            break;

        
        case 3:
            {
                char naux2[50];
                int estudianteEncontrado = 0;
            
                printf("Ingrese el nombre del estudiante para registrar sus calificaciones:\n");
                for (int i = 0; i < cont; i++) {
                    printf("- %s\n", estudiantes[i]);
                }
                fflush (stdin);
                fgets(naux2, 50, stdin);
                naux2[strcspn(naux2, "\n")] = '\0';
                for (int j = 0; j < cont; j++) {
                    if (strcmp(estudiantes[j], naux2) == 0) {
                        estudianteEncontrado = 1;
            
                        for (int i = 0; i < cont2; i++) {
                            float notaTemp;
                            int result;
            
                            do {
                                printf("Ingrese la nota de %s en %s: ", estudiantes[j], asignaturas[i]);
                                result = scanf("%f", &notaTemp);
                                if (result != 1) {
                                    printf("Entrada inválida. Ingrese un número válido.\n");
                                    while (getchar() != '\n');
                                    notaTemp = -1;
                                    continue;
                                } else if (notaTemp < 0 || notaTemp > 10) {
                                    printf("Nota fuera de rango (0-10). Intente nuevamente.\n");
                                }
                            } while (notaTemp < 0 || notaTemp > 10);
                            nota1[j][i] += notaTemp;
                            cantidad[j][i]++;
                        }
                        break;
                    }
                }
            
                if (!estudianteEncontrado) {
                    printf("Estudiante no encontrado.\n");
                }
            }
            break;
            

        case 4:
            printf("\n--- Promedio por asignatura ---\n");
            for (int i = 0; i < cont2; i++) {
                float suma = 0;
                int cuenta = 0;
                for (int j = 0; j < cont; j++) {
                    if (cantidad[j][i] > 0) {
                        suma += nota1[j][i];
                        cuenta += cantidad[j][i];
                    }
                }
                if (cuenta > 0) {
                    float promedio = suma / cuenta;
                    printf("Promedio de %s: %.2f / 10\n", asignaturas[i], promedio);
                } else {
                    printf("No hay calificaciones registradas para %s.\n", asignaturas[i]);
                }
            }
            break;

        case 5:
            printf("\n--- Promedio por estudiante ---\n");
            for (int i = 0; i < cont; i++) {
                float suma = 0;
                int cuenta = 0;
                for (int j = 0; j < cont2; j++) {
                    if (cantidad[i][j] > 0) {
                        suma += nota1[i][j];
                        cuenta += cantidad[i][j];
                    }
                }
                if (cuenta > 0) {
                    float promedio = suma / cuenta;
                    printf("Promedio de %s: %.2f / 10\n", estudiantes[i], promedio);
                } else {
                    printf("No hay calificaciones registradas para %s.\n", estudiantes[i]);
                }
            }
            break;

        case 6:
            printf("\n--- Estudiantes aprobados y reprobados (nota mínima: 6/10) ---\n");
            for (int i = 0; i < cont; i++) {
                float suma = 0;
                int cuenta = 0;
                for (int j = 0; j < cont2; j++) {
                    if (cantidad[i][j] > 0) {
                        suma += nota1[i][j];
                        cuenta += cantidad[i][j];
                    }
                }
                if (cuenta > 0) {
                    float promedio = suma / cuenta;
                    if (promedio >= 6.0) {
                        printf("%s - Promedio: %.2f - APROBADO\n", estudiantes[i], promedio);
                    } else {
                        printf("%s - Promedio: %.2f - REPROBADO\n", estudiantes[i], promedio);
                    }
                } else {
                    printf("%s no tiene notas registradas.\n", estudiantes[i]);
                }
            }

            printf("\n--- Aprobados y reprobados por asignatura ---\n");
            for (int i = 0; i < cont2; i++) {
                int aprobados = 0, reprobados = 0;

                for (int j = 0; j < cont; j++) {
                    if (cantidad[j][i] > 0) {
                        float notaFinal = nota1[j][i] / cantidad[j][i];
                        if (notaFinal >= 6.0) {
                            aprobados++;
                        } else {
                            reprobados++;
                        }
                    }
                }

                printf("Asignatura: %s\n", asignaturas[i]);
                printf("  Aprobados: %d\n", aprobados);
                printf("  Reprobados: %d\n", reprobados);
            }
            break;

        case 7:
            printf("Saliendo del programa...");
            break;

        default:
            printf("Opcion no valida, ingrese una opcion valida\n");
            break;
        }
    } while (opc1 != 7);

    return 0;
}
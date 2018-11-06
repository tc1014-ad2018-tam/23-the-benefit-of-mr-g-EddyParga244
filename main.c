/*
 * Alumno: Eduardo Parga Vela
 * Matricula: A01411896
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

int metodoPago=0;
struct dato {
    int asiento;
    char nombre[40];
    int zona;
}cliente;

struct dato alaIzquierda [20000];
struct dato alaDerecha [20000];
struct dato colCentral [40000];

//Definición de variables para cantidad de ventas:

 int cantVendida = 0;
 int zonaVIP = 0;
 int zonaPlatinum = 0;
 int zonaGold = 0;
 int zonaSilver = 0;
 int zonaGreen = 0;
 int zonaYellow = 0;
 int zonaRed = 0;
 int zonaSkyBlue = 0;
 int zonaNavyBlue = 0;
 int zonaDeepBlue = 0;

//Definición de variables para ingresos por ventas:

 double ingresosTotal = 0;
 double ingresosVIP = 0;
 double ingresosPlatinum = 0;
 double ingresosGold = 0;
 double ingresosSilver = 0;
 double ingresosGreen = 0;
 double ingresosYellow = 0;
 double ingresosRed = 0;
 double ingresosSkyBlue = 0;
 double ingresosNavyBlue = 0;
 double ingresosDeepBlue = 0;

//Definición de variables para tasa de ocupación:

 double tasaOcupacionLocal = 0;
 double tasaOcupacionVIP = 0;
 double tasaOcupacionPlatinum = 0;
 double tasaOcupacionGold = 0;
 double tasaOcupacionSilver = 0;
 double tasaOcupacionGreen = 0;
 double tasaOcupacionYellow = 0;
 double tasaOcupacionRed = 0;
 double tasaOcupacionSkyBlue = 0;
 double tasaOcupacionNavyBlue = 0;
 double tasaOcupacionDeepBlue = 0;

int menuPrincipal(){
    int opcion=0;
    do{
        printf("Seleccione una operacion\n");
        printf("1. Vender boleto\n");
        printf("2. Guardar datos de venta\n");
        printf("3. Reporte\n");
        printf("4. Salir\n");
        scanf("%d", &opcion); getc(stdin);
    } while (isdigit(opcion)&&opcion>=1&&opcion<=4);
    return opcion;
}

int capturaZona(){
    do {
        printf("Seleccione la zona que desee.\n");
        printf("1. VIP ($100 USD)\n");
        printf("2. Platinum ($85 USD\n");
        printf("3. Gold ($70 USD)\n");
        printf("4. Silver ($55 USD)\n");
        printf("5. Green ($45 USD)\n");
        printf("6. Yellow ($40 USD)\n");
        printf("7. Red ($30 USD)\n");
        printf("8. Sky Blue ($50 USD)\n");
        printf("9. Navy Blue ($35 USD)\n");
        printf("10. Deep Blue ($20 USD)\n");
        scanf("%d", &cliente.zona); getc(stdin);
    } while (isdigit(cliente.zona)&&cliente.zona>=1&&cliente.zona<=10);

    return cliente.zona;
}

char capturaNombre(){
    printf("Introdusca su nombre.\n");
    fgets(cliente.nombre, (char)strlen(cliente.nombre), stdin); getc(stdin);
    return *cliente.nombre;
}

int capturaMetodo(){

    getc(stdin);
    do {
        printf("Seleccione el metodo de pago que desee.\n");
        printf("1. Visa\n");
        printf("2. MasterCard\n");
        printf("3. American Express\n");
        scanf("%d", &metodoPago); getc(stdin);
    } while (isdigit(metodoPago)&&metodoPago>=1&&metodoPago<=3);

    return metodoPago;
}

void guardarDatoEnArreglo(){

    int opcion;
    capturaNombre();
    fflush(stdin);
    printf("¿Desea continuar con la compra? [1(si)] / [0(no)]\n");
    scanf("%d", &opcion); //getc(stdin);
    if (opcion==1){
        metodoPago = capturaMetodo();
        colCentral[cliente.asiento-1] = cliente;
    }
}

void guardarDatoEnArreglo2(){

    int opcion;
    capturaNombre();
    fflush(stdin);
    printf("¿Desea continuar con la compra? [1(si)] / [0(no)]\n");
    scanf("%d", &opcion); //getc(stdin);
    if (opcion==1){
        metodoPago = capturaMetodo();
        alaIzquierda[cliente.asiento-1] = cliente;
    }
}

void guardarDatoEnArreglo3(){

    int opcion;
    capturaNombre();
    fflush(stdin);
    printf("¿Desea continuar con la compra? [1(si)] / [0(no)]\n");
    scanf("%d", &opcion); //getc(stdin);
    if (opcion==1){
        metodoPago=capturaMetodo();
        alaDerecha[cliente.asiento-1] = cliente;
    }
}

bool disponibilidad (int zona, int asiento, int ala) {

    bool disp = true;

    switch (zona) {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
            if (colCentral[asiento - 1].asiento == 0) {
                disp = true;
            } else {
                printf("El asiento no esta disponible, por favor seleccione otro.");
                disp = false;
            }
            break;
        case 8:
        case 9:
        case 10:
            if (ala == 1) {
                if (alaIzquierda[asiento - 1].asiento == 0) {
                    disp = true;
                } else {
                    printf("El asiento no esta disponible, por favor seleccione otro.");
                    disp = false;
                }
            } else {
                if (alaDerecha[asiento - 1].asiento == 0) {
                    disp = true;
                } else {
                    printf("El asiento no esta disponible, por favor seleccione otro.");
                    disp = false;
                }
            }
            break;
        default:
            break;
    }
    return disp;
}

void capturaAsiento() {

    int opcion = 0;
    bool disp;
    switch (cliente.zona) {
        case 1:
            printf("Seleccione su asiento (1-500).\n");
            scanf("%d", &cliente.asiento); getc(stdin);
            disp = disponibilidad(cliente.zona, cliente.asiento, 0);
            if (disp) {
                guardarDatoEnArreglo();
                ++cantVendida;
                ++zonaVIP;
                ingresosTotal += 100;
                ingresosVIP += 100;
            }
            break;
        case 2:
            printf("Seleccione su asiento (501-1000).\n");
            scanf("%d", &cliente.asiento); getc(stdin);
            disp = disponibilidad(cliente.zona, cliente.asiento, 0);
            if (disp) {
                guardarDatoEnArreglo();
                ++cantVendida;
                ++zonaPlatinum;
                ingresosTotal += 85;
                ingresosPlatinum += 85;
            }
            break;
        case 3:
            printf("Seleccione su asiento (1001-5000).\n");
            scanf("%d", &cliente.asiento); getc(stdin);
            disp = disponibilidad(cliente.zona, cliente.asiento, 0);
            if (disp) {
                guardarDatoEnArreglo();
                ++cantVendida;
                ++zonaGold;
                ingresosTotal += 70;
                ingresosGold += 70;
            }
            break;
        case 4:
            printf("Seleccione su asiento (5001-10000).\n");
            scanf("%d", &cliente.asiento); getc(stdin);
            disp = disponibilidad(cliente.zona, cliente.asiento, 0);
            if (disp) {
                guardarDatoEnArreglo();
                ++cantVendida;
                ++zonaSilver;
                ingresosTotal += 55;
                ingresosSilver += 55;
            }
            break;
        case 5:
            printf("Seleccione su asiento (100001-25000).\n");
            scanf("%d", &cliente.asiento); getc(stdin);
            disp = disponibilidad(cliente.zona, cliente.asiento, 0);
            if (disp) {
                guardarDatoEnArreglo();
                ++cantVendida;
                ++zonaGreen;
                ingresosTotal += 45;
                ingresosGreen += 45;
            }
            break;
        case 6:
            printf("Seleccione su asiento (25001-35000).\n");
            scanf("%d", &cliente.asiento); getc(stdin);
            disp = disponibilidad(cliente.zona, cliente.asiento, 0);
            if (disp) {
                guardarDatoEnArreglo();
                ++cantVendida;
                ++zonaYellow;
                ingresosTotal += 40;
                ingresosYellow += 40;
            }
            break;
        case 7:
            printf("Seleccione su asiento (35001-40000).\n");
            scanf("%d", &cliente.asiento); getc(stdin);
            disp = disponibilidad(cliente.zona, cliente.asiento, 0);
            if (disp) {
                guardarDatoEnArreglo();
                ++cantVendida;
                ++zonaRed;
                ingresosTotal += 30;
                ingresosRed += 30;
            }
            break;
        case 8:
            do {
                printf("Seleccione el ala.");
                printf("1. Izquierda");
                printf("2. Derecha");
                scanf("%d", &opcion); getc(stdin);
            } while (isdigit(opcion) && opcion >= 1 && opcion <= 2);
            printf("Seleccione su asiento (1-5000).\n");
            scanf("%d", &cliente.asiento); getc(stdin);
            disp = disponibilidad(cliente.zona, cliente.asiento, opcion);
            if (disp && opcion == 1) {
                guardarDatoEnArreglo2();
                ++cantVendida;
                ++zonaSkyBlue;
                ingresosTotal += 50;
                ingresosSkyBlue += 50;
            } else {
                guardarDatoEnArreglo3();
                ++cantVendida;
                ++zonaSkyBlue;
                ingresosTotal += 50;
                ingresosSkyBlue += 50;
            }
            break;
        case 9:
            do {
                printf("Seleccione el ala.");
                printf("1. Izquierda");
                printf("2. Derecha");
                scanf("%d", &opcion); getc(stdin);
            } while (isdigit(opcion) && opcion >= 1 && opcion <= 2);
            printf("Seleccione su asiento (5001-15000).\n");
            scanf("%d", &cliente.asiento); getc(stdin);
            disp = disponibilidad(cliente.zona, cliente.asiento, opcion);
            if (disp && opcion == 1) {
                guardarDatoEnArreglo2();
                ++cantVendida;
                ++zonaNavyBlue;
                ingresosTotal += 35;
                ingresosNavyBlue += 35;
            }
            else {
                guardarDatoEnArreglo3();
                ++cantVendida;
                ++zonaNavyBlue;
                ingresosTotal += 35;
                ingresosNavyBlue += 35;
            }
            break;
        case 10:
            do {
                printf("Seleccione el ala.");
                printf("1. Izquierda");
                printf("2. Derecha");
                scanf("%d", &opcion); getc(stdin);
            } while (isdigit(opcion) && opcion >= 1 && opcion <= 2);
            printf("Seleccione su asiento (15001-20000).\n");
            scanf("%d", &cliente.asiento); getc(stdin);
            disp = disponibilidad(cliente.zona, cliente.asiento, opcion);
            if (disp && opcion == 1) {
                guardarDatoEnArreglo2();
                ++cantVendida;
                ++zonaDeepBlue;
                ingresosTotal += 20;
                ingresosNavyBlue += 20;
            } else {
                guardarDatoEnArreglo3();
                ++cantVendida;
                ++zonaDeepBlue;
                ingresosTotal += 20;
                ingresosDeepBlue += 20;
                }
        default: break;
       }
    }

    double calcularOcupacionTotal() {
        for (int i = 0; i < 20000; ++i) {
            if (alaIzquierda[i].asiento != 0) ++tasaOcupacionLocal;
            if (alaDerecha[i].asiento != 0) ++tasaOcupacionLocal;
        }
        for (int i = 0; i < 40000; ++i) {
            if (colCentral[i].asiento != 0) ++tasaOcupacionLocal;
        }
        return tasaOcupacionLocal * 100 / 80000;
    }

    double calcularOcupacionVIP() {
        for (int i = 0; i < 500; ++i) {
            if (colCentral[i].asiento != 0) ++tasaOcupacionVIP;
        }
        return tasaOcupacionVIP * 100 / 500;
    }

    double calcularOcupacionPlatinum() {
        for (int i = 500; i < 1000; ++i) {
            if (colCentral[i].asiento != 0) ++tasaOcupacionPlatinum;
        }
        return tasaOcupacionPlatinum * 100 / 500;
    }

    double calcularOcupacionGold() {
        for (int i = 1000; i < 5000; ++i) {
            if (colCentral[i].asiento != 0) ++tasaOcupacionGold;
        }
        return tasaOcupacionGold * 100 / 4000;
    }

    double calcularOcupacionSilver() {
        for (int i = 5000; i < 10000; ++i) {
            if (colCentral[i].asiento != 0) ++tasaOcupacionSilver;
        }
        return tasaOcupacionSilver * 100 / 5000;
    }

    double calcularOcupacionGreen() {
        for (int i = 10000; i < 25000; ++i) {
            if (colCentral[i].asiento != 0) ++tasaOcupacionGreen;
        }
        return tasaOcupacionGreen * 100 / 15000;
    }

    double calcularOcupacionYellow() {
        for (int i = 25000; i < 35000; ++i) {
            if (colCentral[i].asiento != 0) ++tasaOcupacionYellow;
        }
        return tasaOcupacionYellow * 100 / 10000;
    }

    double calcularOcupacionRed() {
        for (int i = 35000; i < 40000; ++i) {
            if (colCentral[i].asiento != 0) ++tasaOcupacionRed;
        }
        return tasaOcupacionRed * 100 / 5000;
    }

    double calcularOcupacionSkyBlue() {
        for (int i = 0; i < 5000; ++i) {
            if (alaIzquierda[i].asiento != 0) ++tasaOcupacionSkyBlue;
            if (alaDerecha[i].asiento != 0) ++tasaOcupacionSkyBlue;
        }
        return tasaOcupacionSkyBlue * 100 / 10000;
    }

    double calcularOcupacionNavyBlue() {
        for (int i = 5000; i < 15000; ++i) {
            if (alaIzquierda[i].asiento != 0) ++tasaOcupacionNavyBlue;
            if (alaDerecha[i].asiento != 0) ++tasaOcupacionNavyBlue;
        }
        return tasaOcupacionNavyBlue * 100 / 20000;
    }

    double calcularOcupacionDeepBlue() {
        for (int i = 15000; i < 20000; ++i) {
            if (alaIzquierda[i].asiento != 0) ++tasaOcupacionDeepBlue;
            if (alaDerecha[i].asiento != 0) ++tasaOcupacionDeepBlue;
        }
        return tasaOcupacionDeepBlue * 100 / 10000;
    }

/*void limpiarArreglos() {

    for (int i = 0; i < 20000; ++i) {
        alaIzquierda[i].asiento = 0;
        alaDerecha[i].asiento = 0;
    }
    for (int i = 0; i < 400000; ++i) {
        colCentral[i].asiento = 0;
    }
}
*/

    int main() {

        printf("---Bienvenido al concierto de cumpleaños del Sr. G!---\n");

        int opcion;
        int op;
        char resp = 's';
        FILE *fp;

        while (resp == 's'){
            opcion = menuPrincipal();
              switch (opcion) {
                case 1:
                    cliente.zona = capturaZona();
                    capturaAsiento(cliente.zona);
                    break;
                case 2:
                    fp=fopen("alaIzquierda.txt", "wb");
                    fwrite(alaIzquierda, sizeof(cliente),1,fp);
                    fclose(fp);
                    fp=fopen("alaIzquierda.txt", "rb");
                    fread(alaIzquierda, sizeof(cliente),1,fp);
                    fclose(fp);

                      fp=fopen("alaDerecha.txt", "wb");
                      fwrite(alaDerecha, sizeof(cliente),1,fp);
                      fclose(fp);
                      fp=fopen("alaDerecha.txt", "rb");
                      fread(alaDerecha, sizeof(cliente),1,fp);
                      fclose(fp);

                      fp=fopen("colCentral.txt", "wb");
                      fwrite(colCentral, sizeof(cliente),1,fp);
                      fclose(fp);
                      fp=fopen("colCentral.txt", "rb");
                      fread(colCentral, sizeof(cliente),1,fp);
                      fclose(fp);

                      printf("Archivos guardados con exito\n");
                    break;
                case 3:
                    do {
                        printf("Seleccione el tipo de reporte que desee consultar.\n");
                        printf("1. Total de tickets vendidos\n");
                        printf("2. Total de tickets por zona\n");
                        printf("3. Total de ingresos\n");
                        printf("4. Total de ingresos por zona\n");
                        printf("5. Tasa de ocupación del local\n");
                        printf("6. Tasa de ocupación por zona\n");
                        scanf("%d", &op); getc (stdin);
                    } while (!isdigit(op) && (op < 1 || op > 6));
                    switch (op) {
                        case 1:
                            printf("El total de tickets vendidos fue de %d\n", cantVendida);
                            break;
                        case 2:
                            printf("Reporte de ventas por zona que desea consultar\n");
                            do {
                                printf("1. VIP\n");
                                printf("2. Platinum\n");
                                printf("3. Gold\n");
                                printf("4. Silver\n");
                                printf("5. Green\n");
                                printf("6. Yellow\n");
                                printf("7. Red\n");
                                printf("8. Sky Blue\n");
                                printf("9. Navy Blue\n");
                                printf("10. Deep Blue\n");
                                scanf("%d", &cliente.zona); getc (stdin);
                            } while (!isdigit(cliente.zona) && (cliente.zona < 1 || cliente.zona > 10));
                            switch (cliente.zona) {
                                case 1:
                                    printf("Reporte de ventas de la zona VIP es de %d", zonaVIP);
                                    break;
                                case 2:
                                    printf("Reporte de ventas de la zona Platinum es de %d", zonaPlatinum);
                                    break;
                                case 3:
                                    printf("Reporte de ventas de la zona Gold es de %d", zonaGold);
                                    break;
                                case 4:
                                    printf("Reporte de ventas de la zona Silver es de %d", zonaSilver);
                                    break;
                                case 5:
                                    printf("Reporte de ventas de la zona Green es de %d", zonaGreen);
                                    break;
                                case 6:
                                    printf("Reporte de ventas de la zona Yellow es de %d", zonaYellow);
                                    break;
                                case 7:
                                    printf("Reporte de ventas de la zona Red es de %d", zonaRed);
                                    break;
                                case 8:
                                    printf("Reporte de ventas de la zona Sky Blue es de %d", zonaSkyBlue);
                                    break;
                                case 9:
                                    printf("Reporte de ventas de la zona Navy Blue es de %d", zonaNavyBlue);
                                    break;
                                case 10:
                                    printf("Reporte de ventas de la zona Deep Blue es de %d", zonaDeepBlue);
                                    break;
                                default:
                                    break;
                            }
                            break;
                        case 3:
                            printf("Reporte del total de ingresos es de $%lf USD", ingresosTotal);
                            break;
                        case 4:
                            printf("Reporte de ingresos por zona que desea consultar\n");
                            do {
                                printf("1. VIP\n");
                                printf("2. Platinum\n");
                                printf("3. Gold\n");
                                printf("4. Silver\n");
                                printf("5. Green\n");
                                printf("6. Yellow\n");
                                printf("7. Red\n");
                                printf("8. Sky Blue\n");
                                printf("9. Navy Blue\n");
                                printf("10. Deep Blue\n");
                                scanf("%d", &cliente.zona); getc (stdin);
                            } while (!isdigit(cliente.zona) && (cliente.zona < 1 || cliente.zona > 10));
                            switch (cliente.zona) {
                                case 1:
                                    printf("Reporte de ingresos de la zona VIP es de $%lf USD\n", ingresosVIP);
                                    break;
                                case 2:
                                    printf("Reporte de ingresos de la zona Platinum es de $%lf USD\n", ingresosPlatinum);
                                    break;
                                case 3:
                                    printf("Reporte de ingresos de la zona Gold es de $%lf USD\n", ingresosGold);
                                    break;
                                case 4:
                                    printf("Reporte de ingresos de la zona Silver es de $%lf USD\n", ingresosSilver);
                                    break;
                                case 5:
                                    printf("Reporte de ingresos de la zona Green es de $%lf USD\n", ingresosGreen);
                                    break;
                                case 6:
                                    printf("Reporte de ingresos de la zona Yellow es de $%lf USD\n", ingresosYellow);
                                    break;
                                case 7:
                                    printf("Reporte de ingresos de la zona Red es de $%lf USD\n", ingresosRed);
                                    break;
                                case 8:
                                    printf("Reporte de ingresos de la zona Sky Blue es de $%lf USD\n", ingresosSkyBlue);
                                    break;
                                case 9:
                                    printf("Reporte de ingresos de la zona Navy Blue es de $%lf USD\n", ingresosNavyBlue);
                                    break;
                                case 10:
                                    printf("Reporte de ingresos de la zona Deep Blue es de $%lf USD\n", ingresosDeepBlue);
                                    break;
                                default:
                                    break;
                            }
                            break;
                        case 5:
                        //    calcularOcupacionTotal();
                            printf("La tasa de ocupacion en total es de %lf por ciento\n", calcularOcupacionTotal());
                            break;
                        case 6:
                            printf("Reporte de tasa de ocupacion por zona que desea consultar\n");
                            do {
                                printf("1. VIP\n");
                                printf("2. Platinum\n");
                                printf("3. Gold\n");
                                printf("4. Silver\n");
                                printf("5. Green\n");
                                printf("6. Yellow\n");
                                printf("7. Red\n");
                                printf("8. Sky Blue\n");
                                printf("9. Navy Blue\n");
                                printf("10. Deep Blue\n");
                                scanf("%d", &cliente.zona); getc (stdin);
                            } while (!isdigit(cliente.zona) && (cliente.zona < 1 || cliente.zona > 10));
                            switch (cliente.zona) {
                                case 1:
                                    printf("Reporte de tasa de ocupacion de la zona VIP es de %lf por ciento\n", calcularOcupacionVIP());
                                    break;
                                case 2:
                                    printf("Reporte de tasa de ocupacion de la zona Platinum es de %lf por ciento\n", calcularOcupacionPlatinum());
                                    break;
                                case 3:
                                    printf("Reporte de tasa de ocupacion de la zona Gold es de %lf por ciento\n", calcularOcupacionGold());
                                    break;
                                case 4:
                                    printf("Reporte de tasa de ocupacion de la zona Silver es de %lf por ciento\n", calcularOcupacionSilver());
                                    break;
                                case 5:
                                    printf("Reporte de tasa de ocupacion de la zona Green es de %lf por ciento\n", calcularOcupacionGreen());
                                    break;
                                case 6:
                                    printf("Reporte de tasa de ocupacion de la zona Yellow es de %lf por ciento\n", calcularOcupacionYellow());
                                    break;
                                case 7:
                                    printf("Reporte de tasa de ocupacion de la zona Red es de %lf por ciento\n", calcularOcupacionRed());
                                    break;
                                case 8:
                                    printf("Reporte de tasa de ocupacion de la zona Sky Blue es de %lf por ciento\n", calcularOcupacionSkyBlue());
                                    break;
                                case 9:
                                    printf("Reporte de tasa de ocupacion de la zona Navy Blue es de %lf por ciento\n", calcularOcupacionNavyBlue());
                                    break;
                                case 10:
                                    printf("Reporte de tasa de ocupacion de la zona Deep Blue es de %lf por ciento\n", calcularOcupacionDeepBlue());
                                    break;
                                default:
                                    break;
                            }
                            break;
                        default:
                            break;
                    }
                    break;
                  case 4:
                      fp=fopen("alaIzquierda.txt", "wb");
                      fwrite(alaIzquierda, sizeof(cliente),1,fp);
                      fclose(fp);
                      fp=fopen("alaIzquierda.txt", "rb");
                      fread(alaIzquierda, sizeof(cliente),1,fp);
                      fclose(fp);

                      fp=fopen("alaDerecha.txt", "wb");
                      fwrite(alaDerecha, sizeof(cliente),1,fp);
                      fclose(fp);
                      fp=fopen("alaDerecha.txt", "rb");
                      fread(alaDerecha, sizeof(cliente),1,fp);
                      fclose(fp);

                      fp=fopen("colCentral.txt", "wb");
                      fwrite(colCentral, sizeof(cliente),1,fp);
                      fclose(fp);
                      fp=fopen("colCentral.txt", "rb");
                      fread(colCentral, sizeof(cliente),1,fp);
                      fclose(fp);

                      printf("Adios, que tenga un buen dia.");
                      resp='n';
                      break;
                  default:
                      break;
            }
        }
        return 0;
    }



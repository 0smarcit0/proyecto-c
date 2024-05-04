/*V 30982189 Useche Cordero Tomas Antonio
V 31509694 Porras Chacón Osmar Leonardo 10
V 29507510 Chacón Moncada Luis Nabid-
Equipo 10 Computacion 1 2024-1*/


//Proyecto 20 puntos Parcial II Lenguaje C Seccion 11

#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#define n 1000


int main(){
    setlocale(LC_ALL,"spanish");
    int respuestaDia, respuestaMenu, comparadorCedulaCliente, respuestaProductoCarrito, respuestaCicloProveedor,respuestaMostrarCarrito;
    char nombreCliente[30],apellidoCliente[30], direccionCliente[30];
    int cedulaCliente, cantVisitasMercado=1, checker, idClienteRegistrado,checkerProveedor,checkValidezIndiceProducto=0,checkerValidezCantProducto=0;
    float descMarcaAsociada =0;
    int seleccionProducto=0, seleccionCantProduct,seleccionProveedor;
    float totalCompra, totalParcial;
    int carritoCompra[50],cantProductosIngresados=0, cantProductosSeleccionados[50];
    time_t tiempoahora;
    time(&tiempoahora);
    

    char infoClientesNombre[n][30], infoClientesApellido[n][30],infoClientesDireccion[n][30];
    int visitasMercado[n][2]; 
    //manejamos en una columna la cedula y en la otra la cantidad de veces que esa cedula (el cliente) ha ingresado a comprar algo en el mercado

    char nombreProducto[12][30] = {{"arroz"},{"harina"},{"mantequilla"},{"mayonesa"}
                                   ,{"leche entera"},{"leche condensada"},{"queso amarillo"},{"leche en polvo"}
                                   ,{"tomate"},{"cebolla"},{"pimenton"},{"ajo"}};
    
    char proveedores[3][50]={{"Empresas Polar"},{"Paisa"}, {"Frutas y Verduras Pepito Perez"}};
    int idProveedores[3]={0,1,2};

    

    int productos[n][4]= {{10,10,0,0},
                         {11,10,0,1},
                         {15,10,0,2},
                         {14,10,0,3},
                         {9,10,1,4},
                         {15,10,1,5},
                         {12,10,1,6},
                         {16,10,1,7},
                         {8,10,2,8},
                         {7,10,2,9},
                         {6,10,2,10},
                         {5,10,2,11}};

    
    do{
        printf("\t ======================== \n");
        printf("\t BIENVENIDO AL SUPERMERCADO!\n");
        printf("\t ======================== \n");
        do
        {
            printf("OPCIONES.\n");
            printf("1) Abrir el carrito. \n");
            printf("2) Consultar productos por nombre.\n");
            printf("3) Salir de la jornada. \n");
            scanf("%d", &respuestaMenu);
            switch (respuestaMenu)
            {
            case 1:
                cantProductosIngresados=0;
                checker =0;
                totalCompra= 0;
                totalParcial= 0;
                descMarcaAsociada=0;
                printf("\tBienvenido al carrito, primeramente ingrese los datos del cliente.\n");
                printf("Cedula de identidad del cliente: ");
                scanf("%d",&comparadorCedulaCliente);

                for(int i =0; i<cantVisitasMercado;i++){
                    if(comparadorCedulaCliente == visitasMercado[i][0]){
                        checker = 1;
                        idClienteRegistrado =i;
                    }
                }

                if(checker ==1){
                    printf("El cliente ya se encuentra en nuestra base de datos'\n");
                    printf("Nombre: %s", infoClientesNombre[idClienteRegistrado]);
                    printf("\napellido: %s", infoClientesApellido[idClienteRegistrado]);
                    printf("\nCedula: %d", visitasMercado[idClienteRegistrado][0]);
                    printf("\nDireccion: %s", infoClientesNombre[idClienteRegistrado]);
                    system("pause");
                }else{
                    visitasMercado[cantVisitasMercado][0]= comparadorCedulaCliente;
                    printf("\nIngrese el nombre del cliente: ");
                    scanf("%s",&infoClientesNombre[cantVisitasMercado]);
                    printf("\ningrese el apellido del cliente: ");
                    scanf("%s",&infoClientesApellido[cantVisitasMercado]);
                    printf("\nIngrese la direccion (corta), del cliente: ");
                    scanf("%s",&infoClientesDireccion[cantVisitasMercado]);
                    fflush(stdin);

                    cantVisitasMercado++;
                    checker =0;
                }
                do{
                    do
                    {
                        checkerProveedor=0;
                        system("cls");
                        printf("Desea ver el carrito actual? \n 1)si\n 2)no\n ");
                        scanf("%d",&respuestaMostrarCarrito);
                        if(respuestaMostrarCarrito==1){
                            if(cantProductosIngresados ==0){
                                printf("El carrito esta vacio. \n");
                            }else{
                                for(int i=0;i<cantProductosIngresados;i++){
                                    printf("%s, Cantidad: %d \n",nombreProducto[carritoCompra[i]],cantProductosSeleccionados[i]);
                                }
                                printf("%f \n",totalParcial);
                            }

                        }
                        printf("Selecione uno de nuestros proveedores para ver los productos de esa marca: \n");
                        for(int i= 0;i<3;i++){
                            printf("%d) %s \n",i,proveedores[i]);
                        }

                        printf(" ");
                        scanf("%d",&seleccionProveedor);

                        for(int i=0; i<3;i++){
                            if(seleccionProveedor==idProveedores[i]){
                                checkerProveedor = 1;
                            }
                        }
                        if(seleccionProveedor>=0 && seleccionProveedor<=2){
                            descMarcaAsociada = 0.1;
                        }
                        
                    } while (checkerProveedor==0);
                    
                    
                    do{
                        fflush(stdin);
                        for (int i = 0; i < 12; i++){
                            if(seleccionProveedor==productos[i][2]){
                                printf("%d) %s. \n\tPrecio:%d. \n \t Cantidad en stock: %d\n", i, nombreProducto[i],productos[i][0],productos[i][1]);
                            }
                        }
                        do{
                            checkValidezIndiceProducto=0;
                            printf("Ingrese el Id del productro que desea llevar: ");
                            scanf("%d",&seleccionProducto);
    
                            for(int i=0;i<12;i++){
                            if(seleccionProveedor==productos[i][2]){
                                if(productos[i][3]==seleccionProducto){
                                    if(productos[i][1]<=0){
                                        printf("\n Ya no queda stock de este producto.\n");
                                    }else{
                                       checkValidezIndiceProducto=1;
                                       carritoCompra[cantProductosIngresados] =seleccionProducto;
                                    }
                                    
                                    
                                }
                            }        
                         }

                        } while (checkValidezIndiceProducto==0);
                    
                        do{
                            checkerValidezCantProducto=0;
                            printf("Ingrese que cantidad desea llevar: ");
                            scanf("%d",&seleccionCantProduct);
                            for(int i=0;i<12;i++){
                            if(seleccionProducto==productos[i][3]){
                               if(productos[seleccionProducto][1]<seleccionCantProduct){
                                  break;
                                }else{
                                    productos[seleccionProducto][1]-=seleccionCantProduct;
                                    checkerValidezCantProducto =1;
                                    cantProductosSeleccionados[cantProductosIngresados]=seleccionCantProduct;
                                    cantProductosIngresados++;

                                }
                              }        
                            }
                            totalParcial+=(productos[seleccionProducto][0]*seleccionCantProduct);
                        } while (checkerValidezCantProducto==0);
                        

                        printf("desea ingresar otro producto de este proveedor? \n 1)si \n 2)no \n");
                        scanf("%d",&respuestaCicloProveedor);
                    } while (respuestaCicloProveedor==1);
                
                    printf("quiere agregar otro producto? ");
                    scanf("%d",&respuestaProductoCarrito);
                } while(respuestaProductoCarrito==1);
                
                system("cls");
                fflush(stdin);
                totalCompra= totalParcial-(totalParcial*descMarcaAsociada);
                printf("FACTURA \nDATOS DE LA FACTURA:\n");
                  
                struct tm *mitiempo =localtime(&tiempoahora);
                printf("Fecha y hora de la compra: %d/%d/%d %d:%d:%d \n", mitiempo->tm_mday, mitiempo->tm_mon+1, mitiempo->tm_year+1900,mitiempo->tm_hour,mitiempo->tm_min,mitiempo->tm_sec);
                for(int i =0;i<cantVisitasMercado;i++){
                    if(comparadorCedulaCliente == visitasMercado[i][0]){
                        printf("Nombre: %s \n Apellido: %s\n Cedula: %d \n Direccion: %s\n",infoClientesNombre[i],infoClientesApellido[i],comparadorCedulaCliente,infoClientesDireccion[i]);
                    }
                }
                fflush(stdin);
                for(int i=0;i<cantProductosIngresados;i++){
                    printf("%s, Cantidad: %d\n",nombreProducto[carritoCompra[i]],cantProductosSeleccionados[i]);
                }
                printf("Total a pagar: %0.2f \n",totalCompra);
                break;

            default:
                break;
            }
            printf("salir o continuar?");
            scanf("%d", &respuestaMenu);

        } while (respuestaMenu==1);
        

        printf("Comenzar otro dia?:  ");
        scanf("%d",&respuestaDia);
    }while(respuestaDia==1);
    
    getche();
    return 0;
}





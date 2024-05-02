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
    int respuestaDia, respuestaMenu, comparadorCedulaCliente, respuestaProductoCarrito;
    char nombreCliente[30],apellidoCliente[30], direccionCliente[30];
    int cedulaCliente, cantVisitasMercado=1, checker, idClienteRegistrado;
    int j=0,k=0;
    int seleccionProducto, seleccionCantProduct;

    char infoClientesNombre[n][30], infoClientesApellido[n][30],infoClientesDireccion[n][30];
    int visitasMercado[n][2]; 
    //manejamos en una columna la cedula y en la otra la cantidad de veces que esa cedula (el cliente) ha ingresado a comprar algo en el mercado

    char nombreProducto[12][30] = {{"arroz"},{"harina"},{"mantequilla"},{"mayonesa"}
                                   ,{"leche entera"},{"leche condensada"},{"queso amarillo"},{"leche en polvo"}
                                   ,{"tomate"},{"cebolla"},{"pimenton"},{"ajo"}};
    int cantProducto[3][4] = {{10,10,10,10},
                               {10,10,10,10},
                               {10,10,10,10}};

    int precioProducto[3][4]= {{10,11,15,14},
                               {9,15,12,16},
                               {8,7,6,5}};

    
    do{
        printf("\t\t ======================== \n");
        printf("\t BIENVENIDO AL SUPERMERCADO!\n");
        printf("\t\t ======================== \n");
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
                	k=0;
                    system("cls");
                    printf("Productos disponibles en nuestro inventario:\n");
                    for(int i =0;i<3;i++){
                    	for(j=0;j<4;j++){
                    		printf("%d) %s. Precio unitario: %d\n",k,nombreProducto[k],precioProducto[i][j]);
                    		k++;
						}
                    }
                    printf("ingrese la id del producto que quiere llevar: ");
                    scanf("%d", &seleccionProducto);
                    printf("\nIngrese la cantidad que desea llevar: ");
                    scanf("%d", &seleccionCantProduct);


                    

                    printf("quiere agregar otro producto? ");
                    scanf("%d",&respuestaProductoCarrito);
                } while(respuestaProductoCarrito==1);
                




                break;
            default:
                break;
            }
            printf("salir o continuar?");
            scanf("%d", &respuestaMenu);
        } while (respuestaMenu==1);
        

        printf("salir? ");
        scanf("%d",&respuestaDia);
    }while(respuestaDia==1);
    
    getche();
    return 0;
}
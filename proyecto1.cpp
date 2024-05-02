/*V 30982189 Useche Cordero Tomas Antonio
V 31509694 Porras Chac�n Osmar Leonardo 10
V 29507510 Chac�n Moncada Luis Nabid-
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

    char infoClientesNombre[n][30], infoClientesApellido[n][30],infoClientesDireccion[n][30], restarInventario[n][30];
    int visitasMercado[n][2]; 
    //manejamos en una columna la cedula y en la otra la cantidad de veces que esa cedula (el cliente) ha ingresado a comprar algo en el mercado

    char nombreProducto[12][30] = {{"Arroz"},{"Harina"},{"Mantequilla"},{"Mayonesa"}
                                   ,{"Leche entera"},{"Leche condensada"},{"Queso amarillo"},{"Leche en polvo"}
                                   ,{"Tomate"},{"Cebolla"},{"Pimenton"},{"Ajo"}};
    int cantProducto[3][4] = {{10,10,10,10},
                               {10,10,10,10},
                               {10,10,10,10}};

    int precioProducto[3][4]= {{10,11,15,14},
                               {9,15,12,16},
                               {8,7,6,5}};

    
    do{
        printf("\t\t =============================== \n");
        printf("\t\t * BIENVENIDO AL SUPERMERCADO! * \n");
        printf("\t\t =============================== \n");
        do
        {
            if(respuestaMenu==1){system("cls");} //para limpiar todo si el cliente desea retornar al men� principal.
			printf("\n\t OPCIONES.\n\n");
            printf("1) Abrir el carrito. \n");
            printf("2) Consultar productos por nombre.\n");
            printf("3) Salir de la jornada. \n\n");
            scanf("%d", &respuestaMenu);
            switch (respuestaMenu)
            {
            case 1:
                system("cls");
				printf("\t\n Bienvenido al carrito, primeramente ingrese los datos del cliente. \n");
                printf("\n C�dula de identidad del cliente: ");
                scanf("%d",&comparadorCedulaCliente);

                for(int i =0; i<cantVisitasMercado;i++){
                    if(comparadorCedulaCliente == visitasMercado[i][0]){
                        checker = 1;
                        idClienteRegistrado =i;
                    }
                }

                if(checker ==1){
                    printf("\n\n El cliente ya se encuentra en nuestra base de datos'\n");
                    printf("\n Nombre: %s \n", infoClientesNombre[idClienteRegistrado]);
                    printf("\n Apellido: %s \n", infoClientesApellido[idClienteRegistrado]);
                    printf("\n C�dula: %d \n", visitasMercado[idClienteRegistrado][0]);
                    printf("\n Direcci�n: %s \n\n", infoClientesDireccion[idClienteRegistrado]);
                    system("pause");
                }else{
                    visitasMercado[cantVisitasMercado][0]= comparadorCedulaCliente;
                    printf("\n Ingrese el nombre del cliente: ");
                    fflush(stdin);
					gets(infoClientesNombre[cantVisitasMercado]);
                    printf("\n Ingrese el apellido del cliente: ");
                    fflush(stdin);
					gets(infoClientesApellido[cantVisitasMercado]);
                    printf("\n Ingrese la direccion (corta) del cliente: ");
                    fflush(stdin);
					gets(infoClientesDireccion[cantVisitasMercado]);

                    cantVisitasMercado++;
                    checker =0;
                }
                do{
                	k=0;
                    system("cls");
                    printf("Productos disponibles en nuestro inventario: \n");
                    for(int i =0;i<3;i++){
                    	for(j=0;j<4;j++){
                    		printf("%d) %s. Precio unitario: %d. Cantidad en stock: %d \n",k,nombreProducto[k],precioProducto[i][j],cantProducto[i][j]);
                    		k++;
						}
                    }
                    printf("\n Ingrese el ID y la cantidad del producto que quiere ingresar al carro: ");
                    scanf("%d %d", &seleccionProducto,&seleccionCantProduct);
					
					// DIOSM�O HICE TODAS LAS COMBINACIONES POSIBLES Y NO ENCUENTRO COMO RESTAR EL STOCK XD
					// le pregunt� a una IA pero no entiendo su c�digo y lo que intent� de eso tampoco funcion�
                    // s�lo cambi� cosas est�ticas, hice varios ensayos y encontr� algunos errores que correg� ya
                    // pero hasta q no podamos actualizar el stock no podemos seguir con el inventario 
                    // y despu�s de eso podemos preocuparnos por hacer los acumuladores de las facturas de cada cliente, del d�a y de la semana. 

                    printf("\n\n �Quiere agregar otro producto? \n\n 1. Si \n 2. No \n\n");
                    scanf("%d",&respuestaProductoCarrito);
                } while(respuestaProductoCarrito==1);
                




                break;
            case 2:
					k=0;
                    system("cls");
                    printf("Productos disponibles en nuestro inventario: \n");
                    for(int i =0;i<3;i++){
                    	for(j=0;j<4;j++){
                    		printf("%d) %s. Precio unitario: %d. Cantidad en stock: %d \n",k,nombreProducto[k],precioProducto[i][j],cantProducto[i][j]);
                    		k++;
						}
					}
					system("pause");
				break;
			default:
                break;
            }
            system("cls");
            printf("\n\n �Qu� desea hacer? \n\n 1. Regresar al men� principal \n 2. Salir. \n"); //esta opci�n est� para comprobar que la c�dula aparece registrada si se usa de nuevo
            scanf("%d", &respuestaMenu); //OJO cuando regresas as� coloques otra c�dula te dice que est�s registrado y toma al primer usuario que colocaste
        } while (respuestaMenu==1);
        

        printf("salir? ");
        scanf("%d",&respuestaDia);
    }while(respuestaDia==1);
    
    getche();
    return 0;
}

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
#include <ctype.h>
#define n 1000
#define filas 3

int main(){
    setlocale(LC_ALL,"spanish");
    int respuestaDia, respuestaMenu, comparadorCedulaCliente, respuestaProductoCarrito, respuestaCicloProveedor,respuestaMostrarCarrito;
    char nombreCliente[30],apellidoCliente[30], direccionCliente[30];
    int cedulaCliente, cantVisitasMercado=1, checker, idClienteRegistrado,checkerProveedor,checkValidezIndiceProducto=0,checkerValidezCantProducto=0;
    float descMarcaAsociada =0;
    int seleccionProducto=0, seleccionCantProduct,seleccionProveedor;
    float totalCompra, totalParcial;
    int carritoCompra[50],cantProductosIngresados=0, cantProductosSeleccionados[50];
    int secuenciaSimulacionDias=0, controlDias=0,idCompra=0,idCantIdProductos=0,cantMaximaProductos=0, respuestaBuscador=0, opcionBuscador=0;
    
    char infoClientesNombre[n][30], infoClientesApellido[n][30],infoClientesDireccion[n][30];
    int visitasMercado[n][2]; 
    //manejamos en una columna la cedula y en la otra la cantidad de veces que esa cedula (el cliente) ha ingresado a comprar algo en el mercado

    char nombreProducto[12][30] = {{"arroz"},{"harina"},{"mantequilla"},{"mayonesa"}
                                   ,{"leche entera"},{"leche condensada"},{"queso amarillo"},{"leche en polvo"}
                                   ,{"tomate"},{"cebolla"},{"pimenton"},{"ajo"}};
    
    char proveedores[3][50]={{"Empresas Polar"},{"Paisa"}, {"Frutas y Verduras Pepito Perez"}};
    int idProveedores[3]={0,1,2};

	// MATRIZ PARA EL FUNCIONAMIENTO DE BUSCAR PRODUCTOS
	// SOLO SE USA EN LA OPCION 2, NO TOCA NADA DEL CARRITO
	char productosBuscador[3][5][50] = {{"empresas polar", "harina pan", "harina juana", "malta", "cerveza"},
										{"paisa", "leche entera", "leche condensada", "queso amarillo", "leche en polvo"},
										{"frutas y verduras pepito perez", "tomate", "cebolla", "pimenton", "ajo"}};
	int preciosBuscador[3][5] = {{0, 15, 12, 8, 5},
								{0, 10, 18, 20, 25},
								{0, 6, 4, 7, 3}};
	
	
	int fechas_HorasCompras[n][5];
    int idProductosComprados[n][100];
    int cantProductosComprados[n][100];
    float totalIngresosCompras[n];
    int axuliarControlDia=0;
	
	char buscarEmpresa[50], buscarProducto[50];
	
    fflush(stdin);

    

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
        fflush(stdin);
        
        system("cls");
		printf("\t ======================== \n");
        printf("\t BIENVENIDO AL SUPERMERCADO!\n");
        printf("\t ======================== \n");
        do
        {
            time_t tiempoahora;
            time(&tiempoahora);
            struct tm *mitiempo =localtime(&tiempoahora);
            if(respuestaMenu==1){
            	system("cls");
			}
			printf("OPCIONES.\n");
            printf("1) Abrir el carrito. \n");
            printf("2) Consultar inventario del SuperMarket.\n");
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
                        visitasMercado[i][1]+=1;
                    }
                }

                if(checker ==1){
                    printf("El cliente ya se encuentra en nuestra base de datos'\n");
                    printf("Nombre: %s", infoClientesNombre[idClienteRegistrado]);
                    printf("\nApellido: %s", infoClientesApellido[idClienteRegistrado]);
                    printf("\nCedula: %d", visitasMercado[idClienteRegistrado][0]);
                    printf("\nDireccion: \n%s", infoClientesDireccion[idClienteRegistrado]);
                    system("pause");
                }else{
                    visitasMercado[cantVisitasMercado][0]= comparadorCedulaCliente;
                    printf("\nIngrese el nombre del cliente: ");
                    fflush(stdin);
					gets(infoClientesNombre[cantVisitasMercado]);
                    printf("\ningrese el apellido del cliente: ");
                    fflush(stdin);
					gets(infoClientesApellido[cantVisitasMercado]);
                    printf("\nIngrese la direccion (corta), del cliente: ");
                    fflush(stdin);
					gets(infoClientesDireccion[cantVisitasMercado]);
                    visitasMercado[cantVisitasMercado][1]+=1;
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
                                       for(int i =-1; i<idCantIdProductos;i++){
                                            if(seleccionProducto==idProductosComprados[idCompra][idCantIdProductos]){
                                                break;
                                            }else{
                                                idProductosComprados[idCompra][idCantIdProductos] =seleccionProducto;
                                            }
                                       }
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
                                    totalParcial+=(productos[seleccionProducto][0]*seleccionCantProduct);
                                }
                              }

                            }
                            cantProductosComprados[idCompra][idCantIdProductos]=seleccionCantProduct;
                            idCantIdProductos++;
                            //printf("%d\n",idCantIdProductos);

                            
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
                totalIngresosCompras[idCompra] =totalCompra;
                printf("FACTURA \nDATOS DE LA FACTURA:\n");
                  
                
                printf("Fecha y hora de la compra: %d/%d/%d %d:%d:%d \n", mitiempo->tm_mday+secuenciaSimulacionDias, mitiempo->tm_mon+1, mitiempo->tm_year+1900,mitiempo->tm_hour,mitiempo->tm_min,mitiempo->tm_sec);
                fechas_HorasCompras[idCompra][0]=mitiempo->tm_mday+secuenciaSimulacionDias;
                fechas_HorasCompras[idCompra][1]=mitiempo->tm_mon+1;
                fechas_HorasCompras[idCompra][2]=mitiempo->tm_year+1900;
                fechas_HorasCompras[idCompra][3]=mitiempo->tm_hour;
                fechas_HorasCompras[idCompra][4]=mitiempo->tm_min;
                fechas_HorasCompras[idCompra][5]=mitiempo->tm_sec;

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

                if(idCantIdProductos>cantMaximaProductos){
                    cantMaximaProductos=idCantIdProductos;

                }
                
                idCantIdProductos=0;
                idCompra++;
                break;
            
            case 2:
            	do{
					system("cls");
					printf("\n\n\tIngrese por favor de qué manera desea buscar.\n\n1. Por nombre de la empresa.\n2. Por nombre del producto.\n");
					scanf("%d", &opcionBuscador);
					if(opcionBuscador==1){
						system("cls");
						printf("\n\n\tIngrese el nombre de la empresa a buscar.\n\n "); 
          				fflush(stdin); 
           				gets(buscarEmpresa); 
           				for (int i = 0; buscarEmpresa[i] != 0; i++){
        					buscarEmpresa[i] = tolower(buscarEmpresa[i]);
    					}
						for(int i=0; i<filas; i++){
        					if(strcmp(productosBuscador[i][0],buscarEmpresa)==0){
         						printf("\n%s tiene los siguientes productos:\n\n",buscarEmpresa);
								for(int j=1; j<5 ; j++){ 
									printf("%s, con un costo de: %d Bs.\n\n", productosBuscador[i][j],preciosBuscador[i][j]); 
									
    							}
    						}
						}
						system("pause");
					}
					if(opcionBuscador==2) {
						system("cls");
						printf("\n\n\tIngrese el nombre del producto que desea buscar.\n\n");
						fflush(stdin);
						gets(buscarProducto);
						for (int i = 0; buscarProducto[i] != 0; i++){
        					buscarProducto[i] = tolower(buscarProducto[i]);
    					}
						for (int i=0; i<filas;i++){
							for (int j=0; j<5;j++){
								if(strcmp(productosBuscador[i][j], buscarProducto)==0){
									printf("\n\nEl producto: %s, tiene un costo de: %d Bs\n\n", buscarProducto, preciosBuscador[i][j]);
								}
							}
						}
					system("pause");
					}
					printf("\n\n\t¿Desea consultar nuevamente?\n\n1. Si.\n2. No.\n\n");
					scanf("%d", &respuestaBuscador);
				} while(respuestaBuscador==1);
			
			break; 
			
			default:
                break;
            }
            system("cls");
			printf("\n\n¿Desea regresar al menú principal?\n\n1. Si.\n2. Finalizar día.\n\n");
            scanf("%d", &respuestaMenu);

        } while (respuestaMenu==1);
        fflush(stdin);

        printf("\n FACTURACION DEL DIA.\n");
        for(int i=axuliarControlDia;i<idCompra;i++){
            printf("\n Factura %d\n",i+1);
            printf("Productos: \n");
            for(int j=0;j<cantMaximaProductos;j++){
                //if(idProductosComprados[i][j]){
                    printf("%s, cantidad: %d \n",nombreProducto[idProductosComprados[i][j]],cantProductosComprados[i][j]);
                //}
            }
            printf("total compra: %f\n",totalIngresosCompras[i]);
            printf("fecha y hora de la compra: %d/%d/%d %d:%d:%d\n",fechas_HorasCompras[i][0],fechas_HorasCompras[i][1],fechas_HorasCompras[i][2],fechas_HorasCompras[i][3],fechas_HorasCompras[i][4],fechas_HorasCompras[i][5]);

        }
        axuliarControlDia=idCompra;
        controlDias++;
        printf("Comenzar otro dia?:  ");
        scanf("%d",&respuestaDia);
        secuenciaSimulacionDias++;
    }while(respuestaDia==1 && controlDias<5);

    printf("\nFacturacion de la semana.\n");
    for(int i=0;i<idCompra;i++){
            printf("\n Factura %d\n",i+1);
            printf("Productos: \n");
            for(int j=0;j<cantMaximaProductos;j++){
                fflush(stdin);
                if(idProductosComprados[i][j]){
                    printf("%s, cantidad: %d \n",nombreProducto[idProductosComprados[i][j]],cantProductosComprados[i][j]);
                }
            }
            printf("total compra: %f\n",totalIngresosCompras[i]);
            printf("fecha y hora de la compra: %d/%d/%d %d:%d:%d\n",fechas_HorasCompras[i][0],fechas_HorasCompras[i][1],fechas_HorasCompras[i][2],fechas_HorasCompras[i][3],fechas_HorasCompras[i][4],fechas_HorasCompras[i][5]);
    }
    
    getche();
    return 0;
}

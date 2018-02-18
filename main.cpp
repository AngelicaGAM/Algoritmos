
#include <stdio.h>
#include <string.h>
//Se crea la estructura que usaremos para las listas
typedef struct barco {
    char puerto1[50];//Origen
    char puerto2[50];//Destino
    int ID;
    float almacenamiento;
    int tripulantes;
    barco *sig;
    barco *ant;
}barco;

void Pantallabarcos ( int x , int y);
void  Menuinteractivo (int *OPCION);
void Capturainfo ( barco *b1);
void Imprimeinfo ( barco b1);
int Insert(barco P1, barco **H, barco **T);
int DespacharPAD( barco **H, barco **T);// Despachar por adelante
int DespacharPAT(barco **H, barco **T); //Despachar por atrás
int ListarBarcos  (barco **H, barco **T);

int main() {
    int OPCION;
    barco *HC= NULL , *TC=NULL;// Head y Tail para lista del canal
    barco *HR= NULL, *TR=NULL;// Head y Tail para lista de retenidos
    int ExisteC=0 , ExisteR=0 , STATUS; // Se declara el contador para saber cuantas embarcaciones existen
    barco b1;// Se declara la estructura barco b1 con el cual se insertaran o se despacharan 
    
    Pantallabarcos( ExisteC, ExisteR);
    Menuinteractivo (&OPCION);   
    
    while (OPCION != 8){
    switch (OPCION) {
        case 1 ://Insertamos embarcación al canal 
            Capturainfo(&b1);
            
            if (Insert(b1, &HC , &TC) < 0){ 
            printf ("¡Error no hay memoria!");
            }
            else{
            ExisteC= ExisteC +1;
            printf ("\nLa embarcación se ha añadido al CANAL");
            }
            Pantallabarcos( ExisteC, ExisteR);
            Menuinteractivo (&OPCION);
            break;
        case 2 : //Despachamos embarcación por adelante y preguntamos si se va a zona de retención
            if (HC != NULL){
                b1=*HC;
            }
            if(DespacharPAD( &HC, &TC) < 0){
                printf ("\n ¡ERROR Lista Canal Vacía!");
            }
            else{
                ExisteC= ExisteC-1;
                printf ("\n¿Se enviará a zona de retención? 1= SI  0= NO :  ");
                scanf ("%d", &STATUS);
                if (STATUS == 1){
                    if (Insert(b1, &HR , &TR) < 0){ 
                        printf ("¡Error no hay memoria!");
                    }
                    else{
                        ExisteR= ExisteR +1;
                        printf ("\nLa embarcación se ha añadido a zona de RETENCIÓN");
                    }
                }
                else{
                     printf ("\nLa embarcación de adelante se ha despachado");
                }
            }
            Pantallabarcos( ExisteC, ExisteR);
            Menuinteractivo (&OPCION);
            break;
        case 3 : //Despachamos embarcación por atrás y preguntamos si se va a zona de retención
             if (TC != NULL){
                b1=*TC;
            }
            if(DespacharPAT( &HC, &TC) < 0){
                printf ("\n ¡ERROR Lista Canal Vacia!");
            }
            else{
                ExisteC= ExisteC-1;
                printf ("\n¿Se enviara a zona de retención? 1= SI  0= NO :  ");
                scanf ("%d", &STATUS);
                if (STATUS == 1){
                    if (Insert(b1, &HR , &TR) < 0){ 
                        printf ("¡Error no hay memoria!");
                    }
                    else{
                        ExisteR= ExisteR +1;
                        printf ("\nLa embarcación se ha añadido a zona de RETENCIÓN");
                    }
                }
                else {
                    printf ("\nLa embarcación de atras se ha despachado");
                }
            }
            Pantallabarcos( ExisteC, ExisteR);
            Menuinteractivo (&OPCION);
            break;
                
        case 4 : //Despacharemos embarcación en zona de retención
            if(DespacharPAD( &HR, &TR) < 0){
                printf ("\n ¡ERROR Lista Retenidos Vacia!");
            }
            else{
                ExisteR= ExisteR-1;
                printf ("\nLa embarcación retenida se ha despachado: ");
            }
            Pantallabarcos( ExisteC, ExisteR);
            Menuinteractivo (&OPCION);
            break; 
        case 5 : //Lista todos los barcos del canal
            printf("\nLista de embarcaciones en el canal: \n");
            if (ListarBarcos( &HC , &TC) < 0){
                printf ("\n¡ERROR No hay embarcaciones para listar en el canal!");
            }
            Pantallabarcos( ExisteC, ExisteR);
            Menuinteractivo (&OPCION);
            break;   
        case 6 : //Lista todos los barcos de la zona de retención
            printf("\nLista de embarcaciones en retención: \n");
            if (ListarBarcos( &HR , &TR) < 0){
                printf ("\n¡ERROR No hay embarcaciones para listar en retención!");
            }
            Pantallabarcos( ExisteC, ExisteR);
            Menuinteractivo (&OPCION);
            break;   
        case 7 : //
            Pantallabarcos( ExisteC, ExisteR);
            Menuinteractivo (&OPCION);
            break;   
        default :
            printf ("\n ¡Error, No Existe Esa Opción!\n");
            Menuinteractivo (&OPCION);
    }
    }

    return 0;   
}
    
    
// Esta función mostrará en pantalla cuantos barcos hay con una representación en caracteres 
void Pantallabarcos ( int x , int y){
    
    printf ("\n\n=========== M A P A ===========\n");
    if ( x > 0){
        printf ("___________>>Canal<<___________ \n");
        for ( int i=1; i<=x ; i++){
            printf ("  </*/>  ");
        }
        printf ("\n");
    }
    else {       
        printf ("___________>>Canal<<___________ \n");
        printf ("               \n");
    }
     if ( y > 0){
        printf ("_________>>Retenidos<<_________ \n");
        for ( int i=1; i<=y ; i++){
            printf ("  </*/>  ");
        }
        printf ("\n");
    }
     else {      
        printf ("_________>>Retenidos<<_________ \n");
        printf ("               \n");
    }

    

    return ;
}

//Esta función imprime el menú y escanea la opcion 
void  Menuinteractivo (int *OPCION){
   printf ("=============================================================== M E N U ================================================================\n>>1) Ingresar una barcación al canal<<     >>2) Despachar una embarcación por delante<<      >>3) Despachar una embarcación por atrás<<      \n>>4)Despachar una embarcación retenida<<    >>5)Listar embarcaciones del canal<<<      >>6)Listar embarcaciones retenida<<      \n>>7)Consultar embarcación por ID<<      >>8)Salir<< \nDa una opción : ");
   scanf ("%d", &*OPCION);
   return ;
}
//Esta función captura la información de la estructura barco b1
void Capturainfo ( barco *b1){
    getchar();
   printf ("Da Puerto de Origen: ");
 
   gets(b1->puerto1);
   printf ("Da Puerto de Destino: ");
   gets  (b1->puerto2);
   printf ("Da ID : ");
   scanf ("%d", &b1->ID);
   printf ("Da tamaño de almacenamiento: ");
   scanf ("%f", &b1->almacenamiento);
   printf ("Da Número de tripulantes: ");
   scanf ("%d", &b1->tripulantes); 
   return;
}
// Imprime la información de la embarcación
void Imprimeinfo ( barco b1){
    printf ("\n Puerto Origen: %s", b1.puerto1);
    printf ("\n Puerto Destino: %s", b1.puerto2);
    printf ("\n Número ID: %d", b1.ID);
    printf ("\n Tamaño de almacenamiento : %f metros cubicos", b1.almacenamiento);
    printf ( "\n Número de tripulantes: %d", b1.tripulantes);
    return;
}


//Inserta elementos a una lista por adelante
int Insert(barco P1, barco **H, barco **T){
	
        barco *ap1=*H;
	barco *newCuadro;
	newCuadro = new barco;
	*newCuadro = P1;

	if ((*H == NULL) && (*T == NULL)) {
		newCuadro->sig = NULL;
		newCuadro->ant = NULL;
		*H = newCuadro;
		*T = newCuadro;
		return 1;
	}

	while (ap1->sig != NULL) {
		ap1 = ap1->sig;
	}
		
	newCuadro->sig = NULL;
	ap1->sig = newCuadro;
	newCuadro->ant = ap1;
	*T = newCuadro;

	return 1; 
}


//Esta función elimina elementos de la lista por atras
int DespacharPAT (barco **H , barco **T){
    barco *ab1, *ant;
    ab1= *H;
    ant= *H;
    if (*H==NULL && *T==NULL){
        return -1;
    }
    if ( *H == *T){
        *H=NULL;
        *T=NULL;
        delete ab1;
        return 1;
    }
    while (ab1->sig != NULL){
        ant = ab1;
        ab1= ab1->sig;
    }
    ant->sig=NULL;
    *T=ant;
    delete ab1;
    return 1;
}

//Esta función elimina elementos de la lista por delante
int DespacharPAD (barco **H , barco **T){
    barco *ab1 , *siguiente;
    ab1= *H;
    if (*H==NULL && *T==NULL){
        return -1;
    }
    
    if( *H == *T){
        *H=NULL;
        *T=NULL;
        delete ab1;
        return 1;
    }
    siguiente=ab1->sig;
    siguiente->ant=NULL;
    *H=siguiente;
    delete ab1;
    return 1;
}
//Lista todos los elementos de de derecha a izquierda y los enumera
int ListarBarcos  (barco **H, barco **T){
    barco *app;
    app= *H;
    int cont=1;
    if (*H==NULL && *T==NULL){
        return -1;
    }
    if (*H == *T){
        printf ("\n%d.-\n", cont);
       Imprimeinfo(*app);
       return 1;
    }
    
    while (app->sig != NULL){
       printf ("\n%d.-\n", cont);
       Imprimeinfo(*app);
       app=app->sig;
       cont= cont +1;
    }
    printf ("\n%d.-\n", cont);
    Imprimeinfo(*app);
    return 1;

}
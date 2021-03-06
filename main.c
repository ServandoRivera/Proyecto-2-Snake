# Proyecto-2-Snake
/*
 * File:   programa.c
 * Author: Rigoberto Flores
 *
 * Created on 7 de septiembre de 2018, 09:11 PM
 */

#include <xc.h>
#define _XTAL_FREQ 32000000
#include "config.h"

int x=1,y=255,x2=1,vel=60;            // barrido  cuantas veces se correra el ciclo for
int xp,yp;                             // coordenadas de la manzana
int dir=2,num,cont;                    // dir= direccion, num cantidad de manzanas comidas, cont= cunta las beces que se ha echo el barrido
int matriz[9][9],matbol[9][9];        // matriz 9*9 ( cero ignorado)
int ux=5,ux1=0,ux2=0,ux3=0,ux4=0,ux5=0,ux6=0,ux7=0,ux8=0,ux9=0,ux10=0; // 
int uy=4,uy1=0,uy2=0,uy3=0,uy4=0,uy5=0,uy6=0,uy7=0,uy8=0,uy9=0,uy10=0; // posiciones de cada vez come una manzana

 
void main(void) {
        // Configuracion del oscilador a 32Mhz OSC=HFINT DIV 1:1
        OSCFRQbits.HFFRQ = 0b110;// //HFINT a 32MHz
        
        //Configuracion de puertos
        PORTA=0; //Limpia puerto A
        PORTB=0; //Limpia puerto B
        PORTD=0; //Limpia puerto D
        ANSELA=0; //Puerto A como digital
        ANSELB=0; // Puerto B como digital
        ANSELD=0; // Puerto D como digital
        TRISA=0b00000000; // Todo puerto A como salida
        TRISB=0b00000000; // Todo puerto B como salida
        TRISD=0b11110000; // RDO-3 salidas
        WPUA=1; // Resistencia Pull Up todo puerto A
        WPUB=1; // Resistencia Pull Up todo puerto B
      
                    xp=3+(rand()%8);     // genera en una pocison  aleatorio en x de 1 a 8
                    yp=3+(rand()%8);     // genera en una pocison  aleatorio en y 
                    while (7==xp){       // mientras pocision xp sea igual a la pocision de la cabeza
                    xp=2+(rand()%8);     // buelve hacer otra posicion aleatoria x
                    }
                    while (1==yp){       // mientras pocision xp sea igual a la pocision de la cabeza
                    yp=2+(rand()%8);  // buelve hacer otra posicion aleatoria y
                    }
                    //__delay_ms(30)
        matbol[xp][yp]=1;               // matriz de pocision de la manzana
    while(1){
        ////////////////////////////
        for (int f=1;f<9;f++){  //   for para  cambio de filas  
            y=255-x2;             // genera el barrido en filas 
           if(y<=126){           // valor minimo en las filas 
               y=254;      // lo regresa a el volor inicial
           } 
            for(int c=1;c<9;c++){        // for para cambio de columnas  
                if (matriz[f][c]==1){      // cuando f y c sea=1 prenla las cordenadas y x
                    LATA=y;                 //uno en y
                     LATB=x;               // uno en x
                     __delay_ms(3);        
                }
                if (matbol[f][c]==1){     // enciende la posicion de la manzana  
                    LATA=y;               // cordenad en y
                     LATB=x;              // cordenad en x 
                     __delay_ms(3);
                }
                if ((matriz[f][c]==1)&&(matbol[f][c]==1)){      // cuando las coordenadas de la manzana y la cabeza coiciden = ya se la comio
                    matbol[f][c]=0;                             // apaga la pocicion actual de la manzana
                    xp=1+(rand()%8);                               // vuelve a generar la manzana en x y
                    yp=1+(rand()%8);
                    while (f==xp){                                // si la pocicion de la manzanaes igual a la vibora x
                    xp=1+(rand()%8);                                // genera otra  manzana aleatoria x
                    }
                    while (c==yp){                                   // si la pocicion de manzana es igual a la vibora y
                    yp=1+(rand()%8);                               // genera otra  manzana aleatoria y
                    }
                    matbol[xp][yp]=1;                          // activa la nueva posicion de la manzana
                    num=num+1;                                // cuanta cuantas manzanas se a comido
                    vel=vel-9;                                // mantiene la velocidad constante devido al incremento en delays o por comer manzanas
                }
                 x=x*2;                                           // cambio de columna
                if (x>=256){                                        // si las col llegan una columna despuies de la ultima
                    x=1;                                        // columna regresa al inicio
                }
            }
            x2=x2*2;                                            //x2 auxuliar para recorrer a las filas
            if (x2>=256){                                       // si la variable aux llega a su valor max 
              x2=1;                                             // x aux regresa a su valor inicial
            }
        }
                                                     //       termina el for 
                                                     //      actualizacion de posicion de la vibora 
        cont=cont+1;                                 // incremeto hasta que el for lo haga 50 veces    
        if (cont==vel){                              // si el cont = a vel 
            matriz[ux][uy]=0;                        // apagas todas las posiciones anteriores
            matriz[ux1][uy1]=0;
            matriz[ux2][uy2]=0;
            matriz[ux3][uy3]=0;
            matriz[ux4][uy4]=0;
            matriz[ux5][uy5]=0;
            matriz[ux6][uy6]=0;
            matriz[ux7][uy7]=0;
            matriz[ux8][uy8]=0;                         // de la vibora
            matriz[ux9][uy9]=0;
            matriz[ux10][uy10]=0;
            
            if (num==1){                             // si 
                ux1=ux;
                uy1=uy;
            }
            else if (num==2){
                ux2=ux1;
                uy2=uy1;
                ux1=ux;
                uy1=uy;
            }
            else if (num==3){
                ux3=ux2;
                uy3=uy2;
                ux2=ux1;
                uy2=uy1;
                ux1=ux;
                uy1=uy;
            }
            else if (num==4){
                ux4=ux3;
                uy4=uy3;
                ux3=ux2;
                uy3=uy2;
                ux2=ux1;
                uy2=uy1;
                ux1=ux;
                uy1=uy;
            }
           

            else if (num==5){           // si come mas de 5 manzanas se reinicia el juego
                matriz[ux][uy]=0;
            matriz[ux1][uy1]=0;
            matriz[ux2][uy2]=0;
            matriz[ux3][uy3]=0;
            matriz[ux4][uy4]=0;
           
                ux4=0;
                ux3=0;
                ux2=0;
                ux1=0;
                num=0;
            vel=60;                 // regresa a vel a si valor inicial
            }
            if (dir==1){   // direccion de x decresca
                if (ux<8){
                ux=ux+1;                    
                }
                else{               // aparesca del otro lado, para no perder en las paredes
                    ux=1;
                }
            }
            if (dir==2){       // direccion en x creciendo
                if (ux>1){
                ux=ux-1;
                }
                else{ // aparesca del otro lado, para no perder en las paredes
                    ux=8;            
                }
            }
            if (dir==3){         // direccion en y decresiendo
                if (uy<8){
                uy=uy+1;
                }
                else{
                    uy=1;         // aparesca del otro lado, para no perder en las paredes
                }
            }
            if (dir==4){       // direccion en y creciendo
                if (uy>1){
                uy=uy-1;
                }
                else{           // aparesca del otro lado, para no perder en las paredes
                    uy=8;
                }
            }
            // si la cabeza se come con la anterior se reinicia.
            //condiciones que se cumplan y las manda a cero.
           
            matriz[ux][uy]=1;
            matriz[ux1][uy1]=1;
            matriz[ux2][uy2]=1;
            matriz[ux3][uy3]=1;
            matriz[ux4][uy4]=1;
            matriz[ux5][uy5]=1;
            
            cont=0;
        }


        //  BOTONES 
        
        
                    if ((PORTDbits.RD0==1)&&(dir>2)){   //movimiento izquierda                     
                        dir=1;
                    }
                    if ((PORTDbits.RD1==1)&&(dir>2)){    //movimiento derecha                    
                        dir=2;
                    }
                    if ((PORTDbits.RD2==1)&&(dir<3)){    //movimiento arriiba                   
                        dir=3;
                    }
                    if ((PORTDbits.RD3==1)&&(dir<3)){   //movimiento abajo                     
                        dir=4;
                    }
    }

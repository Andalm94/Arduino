/*
Se trata de un dimmer digital. 
El botón Superior aumenta el nivel de brillo en pasos del 5% cada uno.
El botón inferior baja el nivel de brillo también en pasos de 5% cada uno. 
El display debe indicar la leyenda Brillo: seguida del porcentaje de brillo 
encendido en la línea superior y en la línea inferior la última tecla presionada (SUBIR – BAJAR)
El nivel de brillo seleccionado, debe verse en el led conectado a la salida PWM
*/
#include<LiquidCrystal.h>
LiquidCrystal lcd(2,3,4,5,6,7);

#define pinLed 11
char brillo[16];
char ultimaTecla[16];
int aux;
int porcentaje = 0;
int intensidadLed = 0;
int pulsadorAumenta;
int pulsadorReduce;
char ultimaTeclaPresionada[16];


void setup()
{
  Serial.begin(9600);
  lcd.begin(16,2);
}


void loop()
{
    sprintf(brillo,"Brillo: %d  ", porcentaje);
	sprintf(ultimaTecla,"%s", ultimaTeclaPresionada);
	
	//==============MANEJO DE PULSADORES=========================
    aux = analogRead(A0);
	if(aux >= 0 && aux <= 100){
		pulsadorAumenta = 0;
	}
	if(aux >= 500 && aux <= 600){
		pulsadorReduce = 0;
	}
	
	if(!(aux >= 0 && aux <= 100) && pulsadorAumenta == 0 && porcentaje < 99){
		porcentaje = porcentaje + 5;
		pulsadorAumenta = 1;
      	strcpy(ultimaTeclaPresionada, "SUBIR");
	}
	if(!(aux >= 500 && aux <= 600) && pulsadorReduce == 0 && porcentaje > 0){
		porcentaje = porcentaje - 5;
		pulsadorReduce = 1;
        strcpy(ultimaTeclaPresionada, "BAJAR");
	}
    //===========================================================
	
    //Serial.println(porcentaje);
	
  
    //======================== PRINT EN LCD =======================
  	//-------PORCENTAJE------
	lcd.setCursor(0,0);
    lcd.print(brillo);
	if(porcentaje < 100){
    	lcd.setCursor(10,0);  
   		lcd.print("  ");
    } 
   if(porcentaje < 10){
   		lcd.setCursor(9,0);
    	lcd.print("   ");
    }
    //-------ULTIMA TECLA------
	lcd.setCursor(0,1);
	lcd.print(ultimaTecla);
	//===========================================================
	
  
  	//------MAPEO Y ENCENDIDO LED
    intensidadLed = map(porcentaje, 0, 100, 0, 1023);
	analogWrite(pinLed, intensidadLed);
  

  	
   
}
/*
Se trata de un contador de 0 a 100. Al llegar a Cero, pasa a 100, al llegar a 100, vuelve a 0.
la tecla superior sube de a una unidad
la seguda tecla baja de a una unidad
la tercera tecla sube de a dos unidades
la cuarta tecla, baja de a dos unidades
la quinta tecla, borra el estado de la cuenta, poniéndola en cero
en la 1º línea debe mostrarse el valor del contador,
en la segunda línea
debe aparecer la ultima tecla presionada (+1; -1;+2;-2;Borrar)
En el Monitor en serie debe escribirse el valor del contador, y la ultima tecla presionada, cada vez que cambia.
*/
#include<LiquidCrystal.h>
LiquidCrystal lcd(8,9,4,5,6,7);

int aux;

int teclaUno;
int teclaDos;
int teclaTres;
int teclaCuatro;
int teclaCinco;
char ultimaTeclaPresionada[16];
int contador = 0;

char conteo[16];
char ultimaTecla[16];


void setup()
{
  Serial.begin(9600);
  lcd.begin(16,2);
}

//teclaSuperior: 0
//segundaTecla: 145
//TercerTela: 329
//CuartaTecla: 352
//QuintaTecla: 701


void loop() {
	aux = analogRead(A1);
	sprintf(conteo,"%d", contador);
	sprintf(ultimaTecla,"%s", ultimaTeclaPresionada);
	Serial.println(teclaUno);
	
	//==============MANEJO DE PULSADORES=========================
 
	if(aux >= 0 && aux <= 20){
		teclaUno = 0;
	}
	if(aux >= 130 && aux <= 160){
		teclaDos = 0;
	}
	if(aux >= 320 && aux <= 340){
		teclaTres = 0;
	}
	if(aux >= 345 && aux <= 365){
		teclaCuatro = 0;
	}
	if(aux >= 600 && aux <= 800){
		teclaCinco = 0;
	}
	//===========================================================
	
	
	//==============MANEJO DE PULSADORES=========================
	if(!(aux >= 0 && aux <= 50) && teclaUno == 0){
		teclaUno = 1;
		contador = contador + 1;
      	strcpy(ultimaTeclaPresionada, "+1         ");
	}
	if(!(aux >= 100 && aux <= 200) && teclaDos == 0){
		teclaDos = 1;
		contador = contador - 1;
      	strcpy(ultimaTeclaPresionada, "-1         ");
	}
	if(!(aux >= 300 && aux <= 340) && teclaTres == 0){
		teclaTres = 1;
		contador = contador + 2;
      	strcpy(ultimaTeclaPresionada, "+2          ");
	}
	if(!(aux >= 340 && aux <= 400) && teclaCuatro == 0){
		teclaCuatro = 1;
		contador = contador - 2;
      	strcpy(ultimaTeclaPresionada, "-2          ");
	}
	if(!(aux >= 600 && aux <= 800) && teclaCinco == 0){
		teclaCinco = 1;
		contador = 0;
      	strcpy(ultimaTeclaPresionada, "Borrar       ");
	}
	
	
	if(contador > 100){
      	contador = 0;
	}
	if(contador < 0){
		contador = 100;
	}
    
	//======================== PRINT EN LCD =======================
  	//-------PORCENTAJE------
	lcd.setCursor(0,0);
    lcd.print(conteo);
	
	if(contador < 100){
    	lcd.setCursor(2,0);  
   		lcd.print("  ");
    } 
   if(contador < 10){
   		lcd.setCursor(1,0);
    	lcd.print("   ");
    }
	
    //-------ULTIMA TECLA------
	lcd.setCursor(0,1);
	lcd.print(ultimaTecla);
	//===========================================================

}
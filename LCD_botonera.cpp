/* Se trata de un sistema que indica con qué porcentaje se encenderá 
// una lámpara. 
// al presionar la tecla "C" se permitirá el acceso a la programación 
// Se debe ingresar en el teclado un valor entre 0 y 100 que indique 
// el porcentaje de iluminacion con que se encenderá la lámpara. 
// el valor se mostrará en el display, que se grabará al presionar "A" 
// y se encenderá la lámpara con ese porcentaje. 
// Al presionar la tecla "B", se apaga la lámpara 
// Para cambiar el porcentaje, se presiona la tecla "C" y eso permite 
// volver a escribir un valor de porcentaje de encendido. 
// En resumen.  
// --> "C" Permite cambiar el porcentaje de encendido 
// --> "A" Graba el nuevo porcentaje y enciende la lámpara 
// --> "B" Apaga la lámpara.  
// El resto de las teclas no cumplen una función. 
// Cada vez que se graba un nuevo brillo, se debe enviar por el monitor en serie
// la keyenda "Nuevo Brillo" y el porcentaje de brillo grabado.*/

#include <Keypad.h>
#include <LiquidCrystal.h>
#include <stdio.h>
#include <stdlib.h>

#define pinBombilla 11


//------------Configuracion del LCD------------------------
LiquidCrystal lcd(A0,2,A2,A3,A4,A5);

const byte rows = 4;
const byte cols = 4;

char keys[rows][cols] = {
	{'1', '2', '3', 'A'},
	{'4', '5', '6', 'B'},
	{'7', '8', '9', 'C'},
	{'*', '0', '#', 'D'},
};
byte rowPins[rows] = {10,9,8,7}; //pines conectados de filas
byte colPins[cols] = {6,5,4,3}; //pines conectados de filas
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, rows, cols);
//------------------------------------------------------------



//---------Prototipos de funciones--------------- 
void leerNumero(int *numeroIngresado, char key);
int establecerBrillo(int numeroIngresado);
void borrarEspacios(int intensidadBrillo);
//----------------------------------------------
 
 
 
//--------------Variables------------------------
 char key; //input del usuario
 int numeroIngresado; //Numero que ingresa el usuario
 int flagAccesoProgramacion = 0; //Habilitada la carga de numeros (no:1 // si:1)
 int flagTeclaPresionada; //La utilizamos para permitir que se ingrese un solo numero por tecla presionada
 int intensidadBrillo = 0; //Rango entre 0 y 100 que enciende la bombilla al presionar A
 int intensidadBrilloAux = 0; //Variable donde se almacena el porcentaje ingresado por el usuario
 char lcdLine[16]; //Lo que muestra el LCD en la pantalla
//-------------------------------------------------
 
 
 
void setup() {
   Serial.begin(9600);
   lcd.begin(16,2);
}
 
void loop() {
	key = keypad.getKey();
	sprintf(lcdLine, "Brillo: %% %d", intensidadBrillo);
	
	
	//-------flagTeclaPresionada-----------
	//Permitimos que el usuario cargue solo un digito
	//por cada vez que se presiona la tecla.
	flagTeclaPresionada = 0;
	if(key != NO_KEY){
		flagTeclaPresionada = 1;
	}
	//-------------------------------------
	
	
	//-----------Key == C-------------------
	//Se activa flagAccesoProgramacion
	//Se permite al usuario ingresar digitos
	if (key != NO_KEY && key == 'C') {
 		flagAccesoProgramacion = 1;
    }
	//--------------------------------------
	
	
	//-----------Key == A-------------------
	//Se graba el porcentaje ingresado por el usuario
	//Se enciende la bombilla dependiendo de la intensidad indicada
	if (key != NO_KEY && key == 'A') {
 		intensidadBrillo = intensidadBrilloAux;
		intensidadBrilloAux = 0;
		numeroIngresado = 0;
		flagAccesoProgramacion = 0;
    }
	//--------------------------------------
	
	
	//-----------Key == B-------------------
	//Resetea el porcentaje ingresado por el usuario
	if (key != NO_KEY && key == 'B') {
 		numeroIngresado = 0;
		intensidadBrilloAux = 0;
		intensidadBrillo = 0;
    }
	//--------------------------------------
	
	//Almaceno el numero ingresado por el usuario en la variable numeroIngresado
	//Valido que permanezca en un rango entre 0 y 100 y almaceno su valor en intensidadBrilloAux
	if(flagAccesoProgramacion == 1 && key != NO_KEY){
		leerNumero(&numeroIngresado, key);
	}
	intensidadBrilloAux = establecerBrillo(numeroIngresado);
	
	
	
	lcd.setCursor(0,0);
	lcd.print(lcdLine);
	borrarEspacios(intensidadBrillo);
	
	analogWrite(pinBombilla, map(intensidadBrillo, 0,100, 0,255));

}


void leerNumero(int *numeroIngresado, char key){
	
	*numeroIngresado = (*numeroIngresado) * 10;
	switch(key){
		case '1':
			*numeroIngresado = *numeroIngresado + 1;
			break;
		case '2':
			*numeroIngresado = *numeroIngresado + 2;
			break;
		case '3':
			*numeroIngresado = *numeroIngresado + 3;
			break;
		case '4':
			*numeroIngresado = *numeroIngresado + 4;
			break;
		case '5':
			*numeroIngresado = *numeroIngresado + 5;
			break;
		case '6':
			*numeroIngresado = *numeroIngresado + 6;
			break;
		case '7':
			*numeroIngresado = *numeroIngresado + 7;
			break;
		case '8':
			*numeroIngresado = *numeroIngresado + 8;
			break;
		case '9':
			*numeroIngresado = *numeroIngresado + 9;
			break;
		case '0':
			*numeroIngresado = *numeroIngresado + 0;
			break;
		
	}

}

int establecerBrillo(int numeroIngresado){
	
	int brillo;
	
	if(numeroIngresado > 100){
		numeroIngresado = 100;
	}
	if(numeroIngresado < 0){
		numeroIngresado = 0;
	}
	
	brillo = numeroIngresado;
	
	return brillo;
}

void borrarEspacios(int intensidadBrillo){
	if(intensidadBrillo < 100){
		lcd.setCursor(13,0);
		lcd.print("  ");
	}
	if(intensidadBrillo < 10){
		lcd.setCursor(12,0);
		lcd.print("  ");
	}
}
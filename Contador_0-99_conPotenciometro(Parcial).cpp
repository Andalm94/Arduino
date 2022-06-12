/*
Se trata de un circuito que controla el brillo del Led
Con el cursor del potenciómetro a izquierda, el display debe mostrar 
000 e ir aumentando a medida que se gira, hast allegar a 100 en el caso del máximo
Al mismo tiempo, el led debe variar el brillo desde el 0% al 100%
*/
#define B 13
#define A 12
#define F 11
#define G 10
#define E 9
#define D 8
#define C 7

#define CENTENAS A5
#define DECENAS A4
#define UNIDADES A3

#define LED 3

int potenciometro;
int conversionPotenciometroLed;
int conversionPotenciometroNumero;

void setup()
{
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(CENTENAS, OUTPUT);
  pinMode(DECENAS, OUTPUT);
  pinMode(UNIDADES, OUTPUT);
  Serial.begin(9600);
  
}

void loop()
{	
    digitalWrite(A, LOW);
    digitalWrite(B, LOW);
    digitalWrite(C, LOW);
    digitalWrite(D, LOW);
    digitalWrite(E, LOW);
    digitalWrite(F, LOW);
    digitalWrite(G, LOW);
	
	potenciometro = analogRead(A0);
	
	conversionPotenciometroLed = map(potenciometro, 0, 1023, 255, 0);
	conversionPotenciometroNumero = map(potenciometro, 0, 1023, 100, 0);
	
	
	
	analogWrite(LED,conversionPotenciometroLed);
	mostrarNumeroEnDisplay(conversionPotenciometroNumero);

}


void mostrarNumeroEnDisplay(int numero){
	int decenas;
  	int unidades;
    int centenas;
	
	//tomo el valor del contador y calculo las unidades y las decenas
  	centenas = numero/100;
  	decenas = numero/10;
  	unidades = numero - ((numero/10) * 10);
  
    if(decenas == 10){
      decenas = 0;
    }
  
    //Enciendo el digito de las unidades
	digitalWrite(CENTENAS,HIGH);
  	digitalWrite(DECENAS,HIGH);
	digitalWrite(UNIDADES,HIGH);
    encenderNumero(unidades);
	digitalWrite(UNIDADES, LOW);
	digitalWrite(DECENAS, HIGH);
    digitalWrite(CENTENAS,HIGH);
	delay(5);
	
	//Enciendo el digito de las decenas
    digitalWrite(CENTENAS,HIGH);
	digitalWrite(UNIDADES, HIGH);
    digitalWrite(DECENAS, HIGH);
  	encenderNumero(decenas);
  	digitalWrite(DECENAS,LOW);
  	digitalWrite(UNIDADES,HIGH);
    digitalWrite(CENTENAS,HIGH);
  	delay(5);
  
  	//Enciendo el digito de las centenas
    digitalWrite(CENTENAS,HIGH);
	digitalWrite(UNIDADES, HIGH);
    digitalWrite(DECENAS, HIGH);
  	encenderNumero(centenas);
  	digitalWrite(DECENAS,HIGH);
  	digitalWrite(UNIDADES,HIGH);
    digitalWrite(CENTENAS,LOW);
  	delay(5);
    
}



void encenderNumero(int numero){
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  
  switch(numero){
  	case 0:
        digitalWrite(A, HIGH);
        digitalWrite(B, HIGH);
        digitalWrite(C, HIGH);
        digitalWrite(D, HIGH);
        digitalWrite(E, HIGH);
        digitalWrite(F, HIGH);
		digitalWrite(G, LOW);
    	break;
    case 1:
	    digitalWrite(A, LOW);
		digitalWrite(D, LOW);
		digitalWrite(E, LOW);
		digitalWrite(F, LOW);
		digitalWrite(G, LOW);
    	digitalWrite(B, HIGH);
  		digitalWrite(C, HIGH);
    	break;
    case 2:
	    digitalWrite(C, LOW);
	    digitalWrite(F, LOW);
        digitalWrite(A, HIGH);
        digitalWrite(B, HIGH);
        digitalWrite(G, HIGH);
        digitalWrite(E, HIGH);
        digitalWrite(D, HIGH);
    	break;
    case 3:
	    digitalWrite(E, LOW);
	    digitalWrite(F, LOW);
        digitalWrite(A, HIGH);
        digitalWrite(B, HIGH);
        digitalWrite(G, HIGH);
        digitalWrite(C, HIGH);
        digitalWrite(D, HIGH);
    	break;
    case 4:
	    digitalWrite(A, LOW);
	    digitalWrite(D, LOW);
	    digitalWrite(E, LOW);
        digitalWrite(F, HIGH);
        digitalWrite(G, HIGH);
        digitalWrite(B, HIGH);
        digitalWrite(C, HIGH);
    	break;
    case 5:
	    digitalWrite(B, LOW);
	    digitalWrite(E, LOW);
        digitalWrite(A, HIGH);
        digitalWrite(F, HIGH);
        digitalWrite(G, HIGH);
        digitalWrite(C, HIGH);
        digitalWrite(D, HIGH);
    	break;
    case 6:
	    digitalWrite(B, LOW);
        digitalWrite(A, HIGH);
        digitalWrite(C, HIGH);
        digitalWrite(D, HIGH);
        digitalWrite(E, HIGH);
        digitalWrite(F, HIGH);
    	digitalWrite(F, HIGH);
      	digitalWrite(G, HIGH);
    	break;
    case 7:
	    digitalWrite(D, LOW);
	    digitalWrite(E, LOW);
	    digitalWrite(F, LOW);
	    digitalWrite(G, LOW);
        digitalWrite(A, HIGH);
        digitalWrite(B, HIGH);
        digitalWrite(C, HIGH);
    	break;
    case 8:
        digitalWrite(A, HIGH);
        digitalWrite(B, HIGH);
        digitalWrite(C, HIGH);
        digitalWrite(D, HIGH);
        digitalWrite(E, HIGH);
        digitalWrite(F, HIGH);
    	digitalWrite(G, HIGH);
    	break;
    case 9:
	    digitalWrite(D, LOW);
	    digitalWrite(E, LOW);
        digitalWrite(A, HIGH);
        digitalWrite(B, HIGH);
        digitalWrite(C, HIGH);
        digitalWrite(F, HIGH);
        digitalWrite(G, HIGH);
    	break;
  }
}
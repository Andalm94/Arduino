// C++ code
//
#define SUMAR 2
#define RESTAR 3
#define RESET 4

#define LED1 A2
#define LED2 A3
#define LED3 A4
#define LED4 A5

int contadorDecimal = 0;
int pulsadorSumar;
int pulsadorRestar;
int pulsadorReset;

void encenderEnBinario(int decimal);



void setup()
{
  pinMode(SUMAR, INPUT_PULLUP);
  pinMode(RESTAR, INPUT_PULLUP);
  pinMode(RESET, INPUT_PULLUP);
  
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);

  Serial.begin(9600);
}

void loop()
{
	
  	if(digitalRead(SUMAR) == 1){
		pulsadorSumar = 0;
	}
	if(digitalRead(RESTAR) == 1){
		pulsadorRestar = 0;
	}
	if(digitalRead(RESET) == 1){
		pulsadorReset = 0;
	}
	
	if(digitalRead(SUMAR) == 0 && pulsadorSumar == 0 && contadorDecimal < 15){
		contadorDecimal = contadorDecimal + 1;
		pulsadorSumar = 1;
	}
	if(digitalRead(RESTAR) == 0 && pulsadorRestar == 0 && contadorDecimal > 0){
		contadorDecimal = contadorDecimal - 1;
		pulsadorRestar = 1;
	}
	if(digitalRead(RESET) == 0 && pulsadorReset == 0){
		contadorDecimal = 0;
		pulsadorReset = 1;
	}
  
  if(contadorDecimal > 15){
  	contadorDecimal = 15;
  }
  if(contadorDecimal < 0){
  	contadorDecimal = 0;
  }
  
  encenderEnBinario(contadorDecimal);

  
  Serial.println(contadorDecimal);
  
}

void encenderEnBinario(int decimal){
   digitalWrite(LED1, LOW);
   digitalWrite(LED2, LOW);
   digitalWrite(LED3, LOW);
   digitalWrite(LED4, LOW);
  
  
  switch(decimal){
  case 1:
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
  	break;
   case 2:
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
  	break;
   case 3:
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
  	break;  
   case 4:
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, LOW);
  	break;
   case 5:
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, LOW);
  	break; 
   case 6:
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, LOW);
  	break;
   case 7:
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, LOW);
  	break;
   case 8:
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, HIGH);
  	break;  
   case 9:
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, HIGH);
  	break;
   case 10:
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, LOW);
  	break;
   case 11:
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, HIGH);
  	break; 
   case 12:
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
  	break;
   case 13:
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, HIGH);
  	break;
   case 14:
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, LOW);
  	break;  
   case 15:
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, HIGH);
  	break; 
  }
}
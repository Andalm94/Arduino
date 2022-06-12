//Define PINES:
#define A 13
#define B 12
#define C 11
#define D 10
#define E 9
#define F 8
#define G 7
#define PINSUMAR1 5
#define PINRESTAR1 3
#define PINRESET 4
#define UNIDAD A5
#define DECENA A4
//-------------------

void encenderNumero(int numero);
int contador = 0;
int pulsadorAumentaUno;
int pulsadorReduceUno;

void setup()
{
  pinMode(PINSUMAR1,INPUT_PULLUP);
  pinMode(PINRESTAR1,INPUT_PULLUP);
  pinMode(PINRESET,INPUT_PULLUP);
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);
  Serial.begin(9600);

}

void loop()
{
    Serial.println(digitalRead(PINSUMAR1));
  
  	if(digitalRead(PINSUMAR1) == 1){
		pulsadorAumentaUno = 0;
	}
	if(digitalRead(PINRESTAR1) == 1){
		pulsadorReduceUno = 0;
	}
	
	if(digitalRead(PINSUMAR1) == 0 && pulsadorAumentaUno == 0 && contador < 99){
		contador = contador + 1;
		pulsadorAumentaUno = 1;
	}
	if(digitalRead(PINRESTAR1) == 0 && pulsadorReduceUno == 0 && contador > 0){
		contador = contador - 1;
		pulsadorReduceUno = 1;
	}
	
  
  mostrarNumeroEnDisplay(contador);

  
}


//DESARROLLO DE FUNCIONES:
void mostrarNumeroEnDisplay(int contador){
	int decenas;
  	int unidades;
	
	//tomo el valor del contador y calculo las unidades y las decenas
  	decenas = contador/10;
  	unidades = contador - ((contador/10) * 10);
  
    //Enciendo el digito de las unidades
	digitalWrite(DECENA,HIGH);
	digitalWrite(UNIDAD,HIGH);
    encenderNumero(unidades);
	digitalWrite(UNIDAD, LOW);
	digitalWrite(DECENA, HIGH);
	delay(5);
	
	//Enciendo el digito de las decenas
	digitalWrite(UNIDAD, HIGH);
    digitalWrite(DECENA, HIGH);
  	encenderNumero(decenas);
  	digitalWrite(DECENA,LOW);
  	digitalWrite(UNIDAD,HIGH);
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
    	break;
    case 1:
    	digitalWrite(B, HIGH);
  		digitalWrite(C, HIGH);
    	break;
    case 2:
        digitalWrite(A, HIGH);
        digitalWrite(B, HIGH);
        digitalWrite(G, HIGH);
        digitalWrite(E, HIGH);
        digitalWrite(D, HIGH);
    	break;
    case 3:
        digitalWrite(A, HIGH);
        digitalWrite(B, HIGH);
        digitalWrite(G, HIGH);
        digitalWrite(C, HIGH);
        digitalWrite(D, HIGH);
    	break;
    case 4:
        digitalWrite(F, HIGH);
        digitalWrite(G, HIGH);
        digitalWrite(B, HIGH);
        digitalWrite(C, HIGH);
    	break;
    case 5:
        digitalWrite(A, HIGH);
        digitalWrite(F, HIGH);
        digitalWrite(G, HIGH);
        digitalWrite(C, HIGH);
        digitalWrite(D, HIGH);
    	break;
    case 6:
        digitalWrite(A, HIGH);
        digitalWrite(C, HIGH);
        digitalWrite(D, HIGH);
        digitalWrite(E, HIGH);
        digitalWrite(F, HIGH);
    	digitalWrite(F, HIGH);
      	digitalWrite(G, HIGH);
    	break;
    case 7:
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
        digitalWrite(A, HIGH);
        digitalWrite(B, HIGH);
        digitalWrite(C, HIGH);
        digitalWrite(F, HIGH);
        digitalWrite(G, HIGH);
    	break;
  }
}
//------------------------------------

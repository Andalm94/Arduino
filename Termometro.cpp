//Define PINES:
#define A 12
#define B 11
#define C 10
#define D 9
#define E 8
#define F 7
#define G 6


#define UNIDAD A5
#define DECENA A4
#define SIGNO A3

#define TERMOMETRO A0


int medicionTermometro;
int temperatura;
int temp;
void mostrarTemperaturaEnDisplay(int contador);

void setup(){
  pinMode(TERMOMETRO, INPUT_PULLUP);
  
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  
  pinMode(UNIDAD, OUTPUT);
  pinMode(DECENA, OUTPUT);
  pinMode(SIGNO, OUTPUT);
  
  Serial.begin(9600);
  
}




void loop(){
  
  medicionTermometro = analogRead(TERMOMETRO);
  temperatura = map(medicionTermometro, 689, 801, -40, 125);
  mostrarTemperaturaEnDisplay(temperatura);

  
  Serial.println(temperatura);

 
}

void mostrarTemperaturaEnDisplay(int temperatura){
	int decenas;
  	int unidades;
	int centenas;
	
	//Limita la variable temperatura a 99
	if(temperatura>99){
		temperatura=99;
	}
  
  	//Si la temperatura es negativa, la convertimos a positiva
    //para poder mostrarla en el display.
    if(temperatura <0){
      temperatura = temperatura * (-1);
        digitalWrite(DECENA,HIGH);
	    digitalWrite(UNIDAD,HIGH);
        digitalWrite(SIGNO,HIGH);
	    encenderSignoNegativo();
        digitalWrite(DECENA,HIGH);
  	    digitalWrite(UNIDAD,HIGH);
        digitalWrite(SIGNO,LOW);
      delay(5);
    }
	
	//Descomponemos la variable temperatura en unidades y decenas
  	centenas = temperatura / 100;
	decenas = temperatura/10;
  	unidades = temperatura - ((temperatura/10) * 10);
    
	
  
    //Enciendo el digito de las unidades
	digitalWrite(SIGNO,HIGH);
    digitalWrite(DECENA,HIGH);
	digitalWrite(UNIDAD,HIGH);
    encenderNumero(unidades);
	digitalWrite(UNIDAD, LOW);
	digitalWrite(DECENA, HIGH);
    digitalWrite(SIGNO,HIGH);
	delay(5);
	
	//Enciendo el digito de las decenas
	digitalWrite(SIGNO,HIGH);
    digitalWrite(UNIDAD, HIGH);
    digitalWrite(DECENA, HIGH);
  	encenderNumero(decenas);
  	digitalWrite(DECENA,LOW);
  	digitalWrite(UNIDAD,HIGH);
    digitalWrite(SIGNO,HIGH);	
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

void encenderSignoNegativo(){
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  
  digitalWrite(G, HIGH);
}
void encenderSignoPositivo(){
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  
  digitalWrite(G, HIGH);
}
// Una vez terminado el código Pegalo en el documento del examen
//
// Objetivos:
//Se trata de un contador de 00 a 99
// El pulsador conectado al cable NARANJA aumenta la cuenta en 2 unidades.
// El pulsador conectado al cable AMARILLO aumenta la cuenta en 1 unidad.
// El pulsador conectado al cable VERDE disminuye la cuenta en 1 unidad.
// El pulsador conectado al cable AZUL disminuye la cuenta en 2 unidades.
// si la cuenta excede de 99, no debe aumentar mas (solo se puede disminuir)
// si la cuenta está en 00, solo se puede aumentar
// El led Naranja debe encender con brillo variable en función del valor de la cuenta del contador 
// (desde apagado para 00 hasta máximo brillo para 99), pasando por los brillos intermedios en los estados intermedios de la cuenta

//---Define PINES------
#define A 11
#define B 12
#define C A1
#define D A2
#define E A3
#define F 10
#define G 9
#define PINSUMAR2 2
#define PINSUMAR1 3
#define PINRESTAR1 4
#define PINRESTAR2 5
#define UNIDAD A4
#define DECENA A5
#define LED 6

//---------------------

void mostrarNumeroEnDisplay(int * contador);
void encenderNumero(int numero);
int contador = 0;

int pulsadorAumentaUno = 0;
int pulsadorAumentaDos = 0;
int pulsadorReduceUno = 0;
int pulsadorReduceDos = 0;

void setup()
{
  pinMode(PINSUMAR1,INPUT_PULLUP);
  pinMode(PINSUMAR2,INPUT_PULLUP);
  pinMode(PINRESTAR1,INPUT_PULLUP);
  pinMode(PINRESTAR2,INPUT_PULLUP);
  
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(UNIDAD, OUTPUT);
  pinMode(DECENA, OUTPUT);
  pinMode(LED, OUTPUT);

  Serial.begin(9600);

}



void loop()
{
  
  //-----------------------------------------------------------
  //Lee la tecla pulsada por el usuario y modifica el contador.
  //-----------------------------------------------------------
	if(digitalRead(PINSUMAR1) == 1){
		pulsadorAumentaUno = 0;
	}
	if(digitalRead(PINSUMAR2) == 1){
		pulsadorAumentaDos = 0;
	}
	if(digitalRead(PINRESTAR1) == 1){
		pulsadorReduceUno = 0;
	}
	if(digitalRead(PINRESTAR2) == 1){
		pulsadorReduceDos = 0;
	}
	
	
	//Lee las condiciones para modificar el contador;
	if(digitalRead(PINSUMAR1) == 0 && pulsadorAumentaUno == 0 && contador < 99){
		contador = contador + 1;
		pulsadorAumentaUno = 1;
	}
	if(digitalRead(PINSUMAR2) == 0 && pulsadorAumentaDos == 0 && contador < 99){
		contador = contador + 2;
		pulsadorAumentaDos = 1;
	}
	if(digitalRead(PINRESTAR1) == 0 && pulsadorReduceUno == 0 && contador > 0){
		contador = contador - 1;
		pulsadorReduceUno = 1;
	}
	if(digitalRead(PINRESTAR2) == 0 && pulsadorReduceDos == 0 && contador > 0){
		contador = contador - 2;
		pulsadorReduceDos = 1;
	}
	
	
	//Se asegura que el contador nunca pueda exceder el rango
	if(contador > 99){
		contador = 99;
	}
	if(contador < 0){
		contador = 0;
	}
  
  
  
  
  //-----------------------------------------------------------
  //Recibe el numero del contador y lo muestra
  //-----------------------------------------------------------
  mostrarNumeroEnDisplay(contador);
  
  
  //-----------------------------------------------------------
  //Enciende el LED segun el valor del contador
  //-----------------------------------------------------------
  analogWrite(LED, map(contador, 0, 99, 0, 255));
  
  Serial.println(contador);
  
}





//—---DESARROLLO DE FUNCIONES:

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


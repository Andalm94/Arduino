int medicionRED;
int medicionGREEN;
int medicionBLUE;

int conversionRED;
int conversionGREEN;
int conversionBLUE;


void setup()
{
  pinMode(A6, OUTPUT);
  pinMode(A6, OUTPUT);
  pinMode(A3, OUTPUT);
  //Serial.begin(9600);  
}

void loop()
{
  //Leo la tension proveniente de los pines conectados a los tensiometros
  medicionRED = analogRead(A0);
  medicionGREEN = analogRead(A1);
  medicionBLUE = analogRead(A2);
  
  //Mapeo dicha tension en valores que lea la salida analogica
  conversionRED = map(medicionRED, 0, 1023, 0, 255);
  conversionGREEN = map(medicionGREEN, 0, 1023, 0, 255);
  conversionBLUE = map(medicionBLUE, 0, 1023, 0, 255);

  //Envio al LED-RGB la tension convertida
  analogWrite(6,conversionRED);
  analogWrite(5,conversionBLUE);
  analogWrite(3,conversionGREEN);
 
}
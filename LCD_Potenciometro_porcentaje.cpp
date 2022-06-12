#include<LiquidCrystal.h>
LiquidCrystal lcd(4,5,6,7,8,9);
char lcdLine[16];//16 + el '\0'
int variable=0;
int aux;
int porcentaje;

void setup()
{
  Serial.begin(9600);
  lcd.begin(16,2);
}


void loop()
{
    porcentaje = map(aux, 0, 1023, 0, 100);
	sprintf(lcdLine,"porcentaje: %d", porcentaje);
	aux=analogRead(A0);
  
    lcd.setCursor(0,0);
    lcd.print(lcdLine);
  	
  
  
    if(porcentaje < 100){
    	lcd.setCursor(14,0);  
   		lcd.print(" ");
    } 
   if(porcentaje < 10){
   		lcd.setCursor(13,0);
    	lcd.print("  ");
    }
  
  
  if(porcentaje < 10){
  	lcd.setCursor(0,1);  
  	lcd.print("/               ");
  }
  else if(porcentaje < 20){
  	lcd.setCursor(0,1);  
  	lcd.print("//             ");
  }
  else if(porcentaje < 30){
  	lcd.setCursor(0,1);  
  	lcd.print("///            ");
  }
  else if(porcentaje < 40){
  	lcd.setCursor(0,1);  
  	lcd.print("////           ");
  }
  else if(porcentaje < 50){
  	lcd.setCursor(0,1);  
  	lcd.print("/////          ");
  }
  else if(porcentaje < 60){
  	lcd.setCursor(0,1);  
  	lcd.print("//////         ");
  }
  else if(porcentaje < 70){
  	lcd.setCursor(0,1);  
  	lcd.print("///////        ");
  }
  else if(porcentaje < 80){
  	lcd.setCursor(0,1);  
  	lcd.print("////////       ");
  }
  else if(porcentaje < 90){
  	lcd.setCursor(0,1);  
  	lcd.print("/////////      ");
  }
  else if(porcentaje <= 100){
  	lcd.setCursor(0,1);  
  	lcd.print("//////////     ");
  }

 
    
  
  Serial.println(porcentaje);
    

  	
   
}
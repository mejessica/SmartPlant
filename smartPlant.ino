#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);
int sensor = A1;
int LED = 8;
int nivel_umidade;
int motor = 6;

  
void setup()
{
  Serial.begin(9600);
  lcd.begin(16,2);
  pinMode(sensor, INPUT);
  pinMode(LED, OUTPUT);
  pinMode (motor, OUTPUT);
  
}

void seco(){
    digitalWrite(LED, HIGH);
    lcd.clear();
    lcd.print("\numidade: ");
    lcd.print("ESTOU COM SEDE");    
}

void umido(){
    digitalWrite(LED, LOW);
    lcd.clear();
    lcd.print("\numidade: ");
    lcd.print("HIDRATADA");
}

void loop()
{
  nivel_umidade = analogRead(sensor);
  lcd.clear();
  lcd.print("\numidade: " + nivel_umidade);
  
  
  if(nivel_umidade < 500){
    lcd.display();
    seco();
    
     digitalWrite(motor, HIGH);//rele, valvula, soneloide, bomba
     delay(500);
     digitalWrite(motor, LOW); 
     delay(10000); 
  } 
  else {
    umido();
  }
  
   if(nivel_umidade > 800){
  	lcd.noDisplay();
  }
  
   delay(1000);
}

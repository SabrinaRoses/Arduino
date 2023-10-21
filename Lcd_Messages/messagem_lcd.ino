
#include <LiquidCrystal.h> //Inclui a biblioteca do LCD

int seconds = 0; //zerando meu contador
float horas = 0;


LiquidCrystal lcd_1(12, 11, 5, 4, 3, 2); //Portas do arduino que estamos usando

void setup()
{
  lcd_1.begin(16, 2); //Informando o modelo do LCD usado
  
  lcd_1.setCursor(0,0); //Onde aparecerá o printf
  
  lcd_1.print(horas);
  lcd_1.setCursor(4,3);
  
  lcd_1.print("RM95045");
}

void loop()
{
  lcd_1.setCursor(0, 1);
  //print O número em segundos desde do reset:
  lcd_1.print(seconds);
  delay(1000); //Espere por 1000 milliseconds
  seconds += 1;
  horas = (seconds/3600);

}

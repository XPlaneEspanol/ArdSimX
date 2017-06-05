/*
X-Plane Español - ArdSimX
v1.0

Conexion de Arduino por: USB

www.youtube.com/c/XplaneEspañol
www.patreon.com/XPlaneEspanol

Descargar librería ARDsimX: http://svglobe.com/ardsimx/
 */
 
#include <ArdCom.h>
#include <ArdSimIn.h>
#include <ArdSimX_Interface.h>

//Inicializacion LCD
#include <LCD.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

float Com1 = 0;
float Com1stb = 0;


float Nav1 = 0;
float Nav1stb = 0;

int Xpdr = 0;
int mode_xpd = 0;

int Adf = 0;
int Adfstb = 0;

void setup()  {

  BoardNumber 1; // -- Numero de Placa  (0...9)

//Inicializacion LCD
  lcd.begin(20,4);
  lcd.clear();
  lcd.backlight();
  
}

void loop()   {

  ArdSimScan; // main loop  - escanea y lee los datos

  lcd.setCursor(3,0);
  lcd.print("COM    NAV   XPDR");
  /*
  lcd.setCursor(0,1);
  lcd.print("1 123.45 123.45 7000");
  lcd.setCursor(0,2);
  lcd.print("2 123.45 123.45 MODE");
  lcd.setCursor(0,3);
  lcd.print(" ADF 1234  1234  ALT");  
  delay(2000);
  */
   
   lcd.setCursor(0,1);
   lcd.print("A "); lcd.print(Com1);
   
   lcd.setCursor(0,2);
   lcd.print("S "); lcd.print(Com1stb);

   lcd.setCursor(9,1);
   lcd.print(Nav1);
   
   lcd.setCursor(9,2);
   lcd.print(Nav1stb);

   lcd.setCursor(16,1);
   lcd.print(Xpdr);

   lcd.setCursor(16,2);
   lcd.print("MODE");
   lcd.setCursor(16,3);
   switch (mode_xpd) {
    case 0: lcd.print(" OFF");break; 
    case 1: lcd.print("STBY");break; 
    case 2: lcd.print(" ON ");break; 
    case 3: lcd.print("TEST");break; 
   }

   lcd.setCursor(0,3);
   lcd.print(" ADF ");lcd.print(Adf);
   
   lcd.setCursor(12,3);
   lcd.print(Adfstb);   

   
}
void ProgOut(byte id, float val) {
  
  switch (id) {
    case 1: Com1 = val/1000; break; 
    case 2: Com1stb = val/1000; break; 
    case 3: Nav1 = val/100; break; 
    case 4: Nav1stb = val/100; break;     
    case 5: Xpdr = val; break;    
    case 6: mode_xpd = val; break;
    case 7: Adf = val; break; 
    case 8: Adfstb = val; break;     
  }   
}
/* data.cfg
@ ================= INFO =================

Board #1 - Arduino (USB) -------------------------------------------------------

---- Digital pins: ----


---- Analog pins: ----


---- Programmable inputs: ----


---- Programmable outputs: ----

1 - Com 1 active – 6 digits
2 - Com 1 standby – 6 digits
3 - Nav 1 frequency
4 - Nav 1 standby frequency
5 - Current Transponder code (0000-7777)
6 - Transponder mode
7 - ADF 1 Active frequency, hz
8 - ADF 1 Standby frequency, hz



@ ================= CONFIG =================

*1-1U
[A]
[O]
3D 0 sim/cockpit2/radios/actuators/nav1_frequency_hz 1
4D 0 sim/cockpit2/radios/actuators/nav1_standby_frequency_hz 1
5D 0 sim/cockpit2/radios/actuators/transponder_code 1
6D 0 sim/cockpit2/radios/actuators/transponder_mode 1
7D 0 sim/cockpit2/radios/actuators/adf1_frequency_hz 1
8D 0 sim/cockpit2/radios/actuators/adf1_standby_frequency_hz 1
1D 0 sim/cockpit2/radios/actuators/com1_frequency_hz_833 1
2D 0 sim/cockpit2/radios/actuators/com1_standby_frequency_hz_833 1
*/

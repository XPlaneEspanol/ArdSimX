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

void setup()  {

  BoardNumber 1; // -- Numero de Placa  (0...9)

//Inicializacion LCD
  lcd.begin(16,2);
  lcd.backlight(); 
}

void loop()   {

  ArdSimScan; // main loop  - escanea y lee los datos

}

void ProgOut(byte id, float val) {
  
  switch (id) {
    case 1: lcd.setCursor(0,0); lcd.print(val/100); break;
    case 2: lcd.setCursor(10,0); lcd.print(val/100); break;
  }
    //ESCRIBE EN LCD - linea 2
    lcd.setCursor(2,1);
    lcd.print("USE");  
    lcd.setCursor(11,1);
    lcd.print("STBY");
    
}

/* data.cfg
@ ================= INFO =================

Board #1 - Arduino (USB) -------------------------------------------------------

---- Digital pins: ----


---- Analog pins: ----


---- Programmable outputs: ----

1 - Com radio 1 frequency, 10 hz
2 - Com radio 2 standby frequency, 10 hz



@ ================= CONFIG =================

*1-1U
[A]
[O]
1D 0 sim/cockpit2/radios/actuators/com1_frequency_hz 1
2D 0 sim/cockpit2/radios/actuators/com1_standby_frequency_hz 2
 */



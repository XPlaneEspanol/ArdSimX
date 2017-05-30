/*
X-Plane Español - ArdSimX
v1.0

Conexion de Arduino por: USB

www.youtube.com/c/XplaneEspañol
www.patreon.com/XPlaneEspanol

Descargar librería ARDsimX: http://svglobe.com

 */
 
#include <ArdCom.h>
#include <ArdSimIn.h>
#include <ArdSimX_Interface.h>

void setup()  {

  BoardNumber 1;            // -- Numero de Placa  (0...9)

}

void loop()   {

  ArdSimScan;               // main loop  - escanea y lee los datos

}

void ProgOut(byte id, float val) {

  if (id == 1) {
  //codigo
  }
  else if (id == 2 && val > 0) {
    //codigo
  }
  
}

/* data.cfg
@ ================= INFO =================

Board #1 - Arduino (USB) -------------------------------------------------------

---- Digital pins: ----

7 - Autopilot Airspeed Encoder.

---- Analog pins: ----




@ ================= CONFIG =================

*1-1U
[A]
[I]
E7- sim/autopilot/airspeed_down
E7+ sim/autopilot/airspeed_up
*/



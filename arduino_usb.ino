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


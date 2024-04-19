
//VARIABLES
const byte ledPin[] = {2,3,4,5};
int ledPinLength = sizeof(ledPin) / sizeof(ledPin[0]);

//PREPARAR SALIDA
void setup()
{
  	for (int i=0; i<ledPinLength; i++) {
   		pinMode(ledPin[i], OUTPUT);  //los preparamos para salida
 	}
}

//LOOP PRINCIPAL
void loop() {
  //Ascendente
  for (int num = 0; num < Exponente(ledPinLength); num++) { // Cuenta de 0 a 15
    for (int i = 0; i < ledPinLength; i++) {
      if (num & (1 << i)) { // Comprueba si el bit en la posición i está encendido
        digitalWrite(ledPin[i], HIGH); // Enciende el LED si el bit está encendido
      } else {
        digitalWrite(ledPin[i], LOW); // Apaga el LED si el bit está apagado
      }
    }
    delay(1000); // Espera un segundo antes de mostrar el siguiente número
  }
  
  //Espera un poco antes de conteo descendente
  delay(2000);
  
  //Descendente
  for (int num = Exponente(ledPinLength) - 1; num >= 0; num--) {
    for (int i = 0; i < ledPinLength; i++) {
      if (num & (1 << i)) {
        digitalWrite(ledPin[i], HIGH);
      } else {
        digitalWrite(ledPin[i], LOW);
      }
    }
    delay(1000); // Espera un segundo
  }
}

int Exponente(int num){
  int resultado = 1;
  for(int i = 0 ; i<num ; i++){
    resultado = resultado * 2;
  }
  return resultado;
}

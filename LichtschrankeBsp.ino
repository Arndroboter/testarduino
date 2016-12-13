/*
Edits zum test
  AnalogReadSerial abgewandelt
  Für die Steuerung einer Lichtschranke mit FT:
  - mit weiss an +5V
  - mit rot an 1. Analog in: A0 und 2. über Potenzometer oder Widerstand an _|_ GND zum Entladen des Anschlusses

  Gibt aus: 1 und 0

  verändern von: Delay (wird konstanter
*/

void setup() {
  Serial.begin(9600);
  //Bitte aendern: - wait (normal 3) macht das Signal stabiler
  //               - switching (normal 40) schwellwert zum Schalten von 0 auf 1

}

void loop() {
  int wait = 5;
  int switching = 40;
  int sensorValue = analogRead(A0);
  delay(wait);
  sensorValue = sensorValue + analogRead(A0);
  delay(wait);
  sensorValue = sensorValue + analogRead(A0);
  delay(wait);
  sensorValue = sensorValue + analogRead(A0);
  int printer = sensorValue;
 if(printer > switching){
    printer = 1;
  }
  else{
    printer = 0;
  }
  Serial.println(printer);
}

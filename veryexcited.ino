/*
 * veryexcited!
 */
 
int ledPin = 13;                // choose the pin for the LED
int inputPin = 1;               // choose the input pin (for PIR sensor)
int inputPin1 = 0;
int pirState = LOW;             // we start, assuming no motion detected
int pirState1 = LOW; 
int val = 0;                    // variable for reading the pin status
int sensorValue = 0;  // variable to store the value coming from the sensor
int sensorValue1, sensorValue2, sensorValue3, sensorValue4;
int sensorValue10, sensorValue20, sensorValue30, sensorValue40;
bool sv1s, sv2s, sv3s, sv4s;
int touchRead_pin = A5;
int touchRead_pin1 = A8;
int touchRead_pin2 = 3;
int touchRead_pinValue = 0;
int touchRead_pinValue1 = 0;
int touchRead_pinValue2 = 0;
bool tr;
bool tr1;
bool tr2;
int data;
 
void setup() {
  pinMode(ledPin, OUTPUT);      // declare LED as output
  pinMode(inputPin, INPUT);     // declare sensor as input
  pinMode(inputPin1, INPUT);
  Serial.begin(115200);
}
 
void loop(){

  if (sensorValue1 != sensorValue10){
    if (sensorValue1 > 150){
      if (sv1s == true){
        usbMIDI.sendNoteOn(60, 127, 4);
        sv1s = false;
      }
    }
  } 
  else { 
    if (sv1s == false) {
      usbMIDI.sendNoteOff(60, 0, 4);
      sv1s = true;
    }
  }
  if (sensorValue2 != sensorValue20){
    if (sensorValue2 > 150){
      if (sv2s == true){
        usbMIDI.sendNoteOn(60, 127, 5);
        sv2s = false;
     }
    }
  }
  else { 
    if (sv2s == false){
      usbMIDI.sendNoteOff(60, 0, 5);
      sv2s = true;
    }
  }
  if (sensorValue3 != sensorValue30){
    if (sensorValue3 > 150){
      if (sv3s == true){
        usbMIDI.sendNoteOn(60, 127, 6);
        sv3s = false;
      }
    }
  } 
  else { 
    if (sv3s == false){
      usbMIDI.sendNoteOff(60, 0, 6);
      sv3s = true;
    }
  }
  if (sensorValue4 != sensorValue40){
    if (sensorValue4 > 150){
      if (sv4s == true){
        usbMIDI.sendNoteOn(60, 127, 7);
        sv4s = false;
      }
    }
  } 
  else { 
    if (sv4s == false){
      usbMIDI.sendNoteOff(60, 0, 7);
      sv4s = true;
    }
  }
  data = touchRead(touchRead_pin);
  Serial.println(data);
  if (data >4000) {
    if (tr == true) {
      usbMIDI.sendNoteOn(60, 127, 1);
      tr = false;
    }
  } 
  else { 
    if (tr == false){
      usbMIDI.sendNoteOff(60, 0, 1); 
      tr = true;
    }
  }  
  data = touchRead(touchRead_pin1);
  Serial.println(data);
  if (data > 4000) {
    if (tr1 == true) {
      usbMIDI.sendNoteOn(60, 127, 8);
      tr1 = false;
    }
  } 
  else { 
    if (tr1 == false){
      usbMIDI.sendNoteOff(60, 0, 8); 
      tr1 = true;
    }
  }  
   data = touchRead(touchRead_pin2);
  Serial.println(data);
  if (data > 4000) {
    if (tr2 == true) {
      usbMIDI.sendNoteOn(60, 127, 10);
      tr2 = false;
    }
  } 
  else { 
    if (tr2 == false){
      usbMIDI.sendNoteOff(60, 0, 10); 
      tr2 = true;
    }
  }  
  
  //delay(100);
  
  val = digitalRead(inputPin);  // read input value - for PIR sensor
  if (val == HIGH) {            // check if the input is HIGH
    digitalWrite(ledPin, HIGH);  // turn LED ON
    if (pirState == LOW) {
      // we have just turned on
      Serial.println("Motion detected!");
      usbMIDI.sendControlChange(15, 127, 11);
      // We only want to print on the output change, not state
      pirState = HIGH;
    }
  } 
  else {
    digitalWrite(ledPin, LOW); // turn LED OFF
    if (pirState == HIGH){
      // we have just turned of
      Serial.println("Motion ended!");
      usbMIDI.sendControlChange(15, 0, 11);
      // We only want to print on the output change, not state
      pirState = LOW;
    }
  }
  
  val = digitalRead(inputPin1);  // read input value
  if (val == HIGH) {            // check if the input is HIGH
    digitalWrite(ledPin, HIGH);  // turn LED ON
    if (pirState1 == LOW) {
      // we have just turned on
      Serial.println("_Motion detected!");
      usbMIDI.sendControlChange(14, 127, 8);
      // We only want to print on the output change, not state
      pirState1 = HIGH;
    }
  } 
  else {
    digitalWrite(ledPin, LOW); // turn LED OFF
    if (pirState1 == HIGH){
      // we have just turned of
      Serial.println("_Motion ended!");
      usbMIDI.sendControlChange(14, 0, 8);
      // We only want to print on the output change, not state
      pirState1 = LOW;
    }
  }
  
   // touchRead_pinValue = touchRead(A5);
  //Serial.print(touchRead_pinValue);
  sensorValue10 = sensorValue1;
  sensorValue1 = analogRead(A0);
  Serial.print (" _ "); 
  sensorValue20 = sensorValue2;
  Serial.print(sensorValue1);   
  sensorValue2 = analogRead(A1); 
  Serial.print(" _ ");
  sensorValue3 = sensorValue30;
  Serial.print(sensorValue2); 
  sensorValue3 = analogRead(A2); 
  Serial.print(" _ ");
  sensorValue4 = sensorValue40;
  Serial.print(sensorValue3); 
  sensorValue4 = analogRead(A3); 
  Serial.print(" _ ");
  Serial.println(sensorValue4);
  delay(100);   
  while (usbMIDI.read()); {
  }
  usbMIDI.send_now();{
  }
  }


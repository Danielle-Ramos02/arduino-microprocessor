int pinLed = 10;

int pinSwitch = 2;
 
boolean oldSwitchState = LOW;

boolean newSwitchState = LOW;

boolean LEDstatus = LOW;
 
void setup() {

pinMode(pinLed, OUTPUT);

digitalWrite(pinLed, LOW);

pinMode(pinSwitch, INPUT); 

}
 
void loop() {

newSwitchState = digitalRead(pinSwitch);

if (newSwitchState != oldSwitchState)

{

   if (newSwitchState == HIGH)

{

     if (LEDstatus == LOW) {

       digitalWrite(pinLed, HIGH);

       LEDstatus = HIGH;

     }

     else

       digitalWrite(pinLed, LOW);

       LEDstatus = LOW;

   }

}

  oldSwitchState = newSwitchState;

}

int led = 0;
int led_r = 5;
int led_g = 1;
int led_b = 2;
int sw = 3;
int vol = A2;

int ledRState = 0;
int ledGState = 0;
int ledBState = 0; 

// the setup routine runs once when you press reset:
void setup() {               
  // initialize the digital pin as an output.  
  pinMode(led, OUTPUT);  
  pinMode(led_r, OUTPUT);  
  pinMode(led_g, OUTPUT);  
  pinMode(led_b, OUTPUT);   
  pinMode(sw, INPUT);   
}

void loop() {  
  static unsigned long time_1 = millis();
  static const unsigned long INTERVAL_MESSAGE1 = 1000;
  
  // read the state of the switch into a local variable
  int buttonState = digitalRead(sw);
  // read the input on analog pin 0:
  int sensorValue = analogRead(vol);
  int output = map(sensorValue, 0, 1023, 0, 255);
  analogWrite(led,output);
  if(buttonState == 0) {
    if(millis() - time_1 > INTERVAL_MESSAGE1){
      if (ledRState == 0 && ledGState == 0 && ledBState == 0) {
        ledRState = 1;
        ledGState = 0;
        ledBState = 0;
      } else if (ledRState == 1) {      
        ledRState = 0;
        ledGState = 1;
        ledBState = 0;
      } else if (ledGState == 1) {      
        ledRState = 0;
        ledGState = 0;
        ledBState = 1;
      } else if (ledBState == 1) {      
        ledRState = 0;
        ledGState = 0;
        ledBState = 0;
      }
      controlLED(ledRState, ledGState, ledBState);        
      time_1 = millis();
    }  
  }
}

void controlLED(int LED1, int LED2, int LED3) {
  digitalWrite(led_r, LED1);
  digitalWrite(led_g, LED2);
  digitalWrite(led_b, LED3);
}

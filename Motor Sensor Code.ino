String voltagesign(float motor){
    String sign;   
  
   if (motor==0){
       sign="Negative";
       return sign;
   }
    
    if (motor>=0){
       sign="Posititve";
       return sign;
   }
}


//declare global variables:
String last_sign;
int timer;
float t0;


void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}


// the loop routine runs over and over again forever:
void loop() {
  // Convert the A0 analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float motor = analogRead(A0); // * (5.0 / 1023.0);
  // print out the value you read:
  //Serial.println(Potvoltage);
  
  String sign=voltagesign(motor);
  //Serial.println("Pin 0:" );
  Serial.println(motor);
  //Serial.println("Pin 1:" );
  //Serial.println(analogRead(A1));
  Serial.println(sign);
  last_sign=sign;
  if (last_sign!=sign){
    float millis; 
    float t1;
    t1=millis;
    Serial.println("It changed direction!");
    Serial.print("The period was:")
    Serial.println(t1-t0);
    t0=t1;
  }
  //Serial.println(timer);
  delay(50);
}

String voltagesign(float motor){
    String sign;   
    
    if (motor>=9){
       sign="Gate happened";
       return sign;
   }
}


//declare global variables:
int sensorPin = A0;    // select the input pin for the potentiometer
int sensorValue = 0;  // variable to store the value coming from the sensor
float lasttime;

//setup loop:
void setup() {
  pinMode(sensorPin, INPUT);
  Serial.begin(9600);
}


void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  //Serial.println(sensorValue);
  String gate=voltagesign(sensorValue);
  //Serial.println(gate);
  if (gate=="Gate happened"){
    Serial.print("The time of this period event was:");
    lasttime=millis();
    Serial.println(millis());
  }
}

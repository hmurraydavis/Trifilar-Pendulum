String lookatderiv(float last, float current){
    String deriv;   
  
    if (last-current>=.01){
       deriv="decreasing";
       return deriv;
   }
   
   if (current-last>=.01){
       deriv="increasing";
       return deriv;
   }
   
   if (current-last<.02){
       deriv="constant not turning";
       return deriv;
   } 
}


//declare global variables:
float last_pot;
float potpot;
String lastderiv;
int counter=0;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  last_pot=1;//analogRead(A0)*(5.0 / 1023.0);   
}


// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int Pot = analogRead(A0);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float Potvoltage = Pot * (5.0 / 1023.0);
  // print out the value you read:
  //Serial.println(Potvoltage);
  
  String derv=lookatderiv(last_pot,Potvoltage);
  Serial.println(derv);
  last_pot=Potvoltage;
  counter++;
  Serial.println(counter);
  if (deriv != lastderiv){
    counter=0;
  }
  delay(10);
}


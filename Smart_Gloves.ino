   // Pin connected to voltage divider output
const int flexPin = A0;
const int flexPin1 = A1;

//for flex 2.8
// Change these constants according to your project's design
const float VCC = 5;      // voltage at Ardunio 5V line
const float R_DIV = 10000.0;  // resistor used to create a voltage divider
const float flatResistance = 10000.0; // resistance when flat
const float bendResistance = 30000.0; // resistance at 90 deg


// for flex 2.2
const float VCC1 = 5;      // voltage at Ardunio 5V line
const float R_DIV1 = 47000.0;  // resistor used to create a voltage divider
const float flatResistance1 = 25000.0; // resistance when flat
const float bendResistance1 = 100000.0; // resistance at 90 deg

void setup() {
  // put your setup code here, to run once:
  pinMode(flexPin, INPUT);
  pinMode(flexPin1, INPUT);
  Serial.begin(9600);
  
}

void loop() {
  
  //flex sensor 2.8
  // Read the ADC, and calculate voltage and resistance from it
  int ADCflex = analogRead(flexPin);
  float Vflex = ADCflex * VCC / 1023.0;
  float Rflex = R_DIV * (VCC / Vflex - 1.0);

    
    Serial.println("R: " + String(Rflex) + " ohms");
     //Use the calculated resistance to estimate the sensor's bend angle:
    float angle = map(Rflex, flatResistance, bendResistance, 0, 90.0);
    Serial.println("Bend: " + String(angle) + " degrees");
    Serial.println();
    


    
    //flex sensor 2.2
    int ADCflex1 = analogRead(flexPin1);
    float Vflex1 = ADCflex1 * VCC1 / 1023.0;
    float Rflex1 = R_DIV1 * (VCC1 / Vflex1 - 1.0);


    Serial.println("R1: " + String(Rflex1) + " ohms");
    // Use the calculated resistance to estimate the sensor's bend angle:
    float angle1 = map(Rflex1, flatResistance1, bendResistance1, 0, 90.0);
    Serial.println("Bend1: " + String(angle1) + " degrees");
    Serial.println();
    delay(2000);

        
  
   if(angle>20 && angle1>20){
  Serial.println("good morning");
  delay(1000);
  }
  
  else if((angle>=20 && angle<=49) && angle1<20){
  Serial.println("i want to eat please");
  delay(1000);
  }

  else if(angle>=50 && angle1<20){
  Serial.println("i want some water please");
  delay(1000);
  }
   else if(angle<20 && (angle1>=20 && angle1<=49)){
  Serial.println("How are you");
  delay(1000);
  }
    else if(angle<20 && angle1>=50){
  Serial.println("Could you help me");
  delay(1000);
  }
  
}

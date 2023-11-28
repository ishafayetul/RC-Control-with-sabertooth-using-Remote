// C++ code
//
//Declare here Sabertooth and Realy Pins
#define sabertooth_S1 7
#define sabertooth_S2 8
#define relay_1 9
#define relay_2 10

//Motor 1
int m1_forward_low=1,m1_forward_high=63;
int m1_reverse_low=65,m1_reverse_high=127;

//Motor 2
int m2_forward_low=128,m1_forward_high=191;
int m2_reverse_low=193,m1_reverse_high=255;

/*Declare here remote pins
Example:
#define pwm1 PIN_NUMBER
*/
#define pwm1 
#define pwm2
#define pwm3
#define pwm4
#define pwm5

int pwm1_min=1050,pwm1_max=1950,pwm1_mid=1500;
int pwm2_min=1050,pwm2_max=1950,pwm2_mid=1500;
int pwm3_min=1050,pwm3_max=1950,pwm3_mid=1500;
int pwm4_min=1050,pwm4_max=1950,pwm4_mid=1500;
int pwm5_min=1050,pwm5_max=1950,pwm5_mid=1500;

int pwm1_reading,pwm2_reading,pwm3_reading,pwm4_reading,pwm5_reading;

void setup()
{
  pinMode(pwm1,INPUT);pinMode(pwm2,INPUT);pinMode(pwm3,INPUT);pinMode(pwm4,INPUT);pinMode(pwm5,INPUT);
  pinMode(relay_1,OUTPUT);pinMode(relay_2,OUTPUT);
}

void loop()
{
  pwm1_reading=pulseIn(pwm1,HIGH);
  pwm2_reading=pulseIn(pwm2,HIGH);
  pwm3_reading=pulseIn(pwm3,HIGH);
  pwm4_reading=pulseIn(pwm4,HIGH);
  pwm5_reading=pulseIn(pwm5,HIGH);
  
  //FORWARD Condition
  if(pwm1_reading>pwm1_min && pwm1_reading<(pwm1_mid-100)){
    Serial.write(map(constrain(pwm1_reading,pwm1_min,pwm1_mid)),pwm1_min,pwm1_mid,m1_forward_low,m1_forward_high);
    Serial.write(map(constrain(pwm1_reading,pwm1_min,pwm1_mid)),pwm1_min,pwm1_mid,m2_forward_low,m2_forward_high);
  }
  
  //BACKWARD Condition
  if(pwm1_reading>(pwm1_mid+100) && pwm1_reading<pwm1_max){
    Serial.write(map(constrain(pwm1_reading,pwm1_mid,pwm1_max)),pwm1_mid,pwm1_max,m1_reverse_low,m1_reverse_high);
    Serial.write(map(constrain(pwm1_reading,pwm1_mid,pwm1_max)),pwm1_mid,pwm1_max,m2_reverse_low,m2_reverse_high);
  }
  
   //RIGHT Condition
  if(pwm2_reading>pwm2_min && pwm2_reading<(pwm2_mid-100)){
    Serial.write(map(constrain(pwm2_reading,pwm2_min,pwm2_mid)),pwm2_min,pwm2_mid,m1_reverse_low,m1_reverse_high);
    Serial.write(map(constrain(pwm2_reading,pwm2_min,pwm2_mid)),pwm2_min,pwm2_mid,m2_forward_low,m2_forward_high);
  }
  
  //LEFT Condition
  if(pwm2_reading>(pwm2_mid+100) && pwm2_reading<pwm2_max){
    Serial.write(map(constrain(pwm2_reading,pwm2_mid,pwm2_max)),pwm2_mid,pwm2_max,m1_forward_low,m1_forward_high);
    Serial.write(map(constrain(pwm2_reading,pwm2_mid,pwm2_max)),pwm2_mid,pwm2_max,m2_reverse_low,m2_reverse_high);
  }
  
  //STOP Condition
  if(pwm1_reading<pwm1_mid+100 && pwm1_reading>pwm1_mid-100 && pwm2_reading<pwm2_mid+100 && pwm2_reading>pwm2_mid-100 ){
  Serial.write(0);
  }
  
  //RELAY 1
  if(pwm4_reading>pwm4_mid){
  digitalWrite(relay_1,HIGH);
  }else { digitalWrite(relay_1,LOW); }
  
  //RELAY 2
  if(pwm5_reading>pwm5_mid){
  digitalWrite(relay_2,HIGH);
  }else { digitalWrite(relay_2,LOW); }
}
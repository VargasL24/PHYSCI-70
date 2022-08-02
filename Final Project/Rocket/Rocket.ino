#include <MPU6050_tockn.h>
#include <ESP32Servo.h>


int servopin1 = 13;  // Servo pin
int servopin2 = 14;
int servopin3 = 4 ;
int servopin4 = 16;

Servo servo1;   // Servo object
Servo servo2;
Servo servo3;
Servo servo4;

int pos = 0; //position

MPU6050 mpu6050(Wire);

long timer = 0;

void setup()
{
  Serial.begin(9600);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);

  servo1.attach(servopin1);   //attach object to pin
  servo2.attach(servopin2);
  servo3.attach(servopin3);
  servo4.attach(servopin4);

  if( mpu6050.getAngleX() == -1<0< 1){                  
      servo2.write(90);    //set to 90 degrees
    }
    
  if( mpu6050.getAngleX() == 0){
      servo1.write(90); //set to 90 degrees
    }
  if(mpu6050.getAngleY() == 0){        
    servo3.write(90);//set to 90 degrees
    }
    
  if(mpu6050.getAngleY() == 0){
    servo4.write(90); //set to 90 degrees2
}

void loop()
{

  mpu6050.update();

  if (millis() - timer > 10000) {


    Serial.print("angleX : ");            // print
    Serial.print(mpu6050.getAngleX());
    Serial.print("  angleY : ");
    Serial.println(mpu6050.getAngleY());

    timer = millis();

  }

  //x-axis / roll

 
   servo2.write(90 -mpu6050.getAngleY()); //unstable angle


   
   servo1.write(90 + mpu6050.getAngleY()); //unstable angle
//y-axis / pitch 
       
  
   servo3.write(90 - mpu6050.getAngleX()); //unstable angle
    
 
   servo4.write(90 + mpu6050.getAngleX());//unstable angle
  
  }

#include <ArduinoHardware.h>
#include <ros.h>
#include <geometry_msgs/Twist.h>

#define D1 3
#define D2 4
#define D3 5
#define T1 6
#define T2 7
#define T3 8

ros::NodeHandle nh;
geometry_msgs::Twist msg;


  // this is for steering
  /*
  
  */


void roverCallBack(const geometry_msgs::Twist& cmd_vel)
{
  //move1 = cmd_vel.linear.x * 127 ;
  //if(cmd_vel.linear.x> cmd_vel.linear.z){
  //  digitalWrite(13, HIGH);
  //} else {
  //  digitalWrite(13, LOW);
  //}
   // this is for dirving
  if (cmd_vel.linear.x > 0){
    digitalWrite(D3,HIGH);
    digitalWrite(D2,LOW);
    digitalWrite(D1,HIGH);
  } else if (cmd_vel.linear.x < 0) {
    digitalWrite(D3,HIGH);
    digitalWrite(D2,HIGH);
    digitalWrite(D1,LOW);
  } else {
    digitalWrite(D3,LOW);
    digitalWrite(D2,LOW);
    digitalWrite(D1,LOW);
  }
  if (cmd_vel.linear.z+
  > 0){
    digitalWrite(T1,HIGH);
    digitalWrite(T2,LOW);
    digitalWrite(T3,HIGH); 
  } else if (cmd_vel.linear.z < 0){
    digitalWrite(T1,HIGH);
    digitalWrite(T2,HIGH);
    digitalWrite(T3,LOW);
  } else {
    digitalWrite(T1,LOW);
    digitalWrite(T2,LOW);
    digitalWrite(T3,LOW);
  }
}

ros::Subscriber <geometry_msgs::Twist> sub("/cmd_vel", roverCallBack);

void setup()
{
  for(int i=0; i<12; i++){
    pinMode(i, OUTPUT);
  }
  pinMode(13, OUTPUT);
  nh.initNode();
  nh.subscribe(sub);
} 

void loop()
{
  nh.spinOnce();
  delay(1);
}

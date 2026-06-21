#include <Servo.h>

Servo myservo;  
const int trigPin = 9;
const int echoPin = 10;

long duration;
int distance;

void setup() {
  myservo.attach(7);  // Servo pin 7 par connect hai
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);  
  
  myservo.write(0); // Shuruat me dustbin ka dhakkan band rahega
}

void loop() {
  // Ultrasonic sensor se distance measure karna
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2; // Distance cm me convert kiya

  // Agar haath 20 cm ke andar aata hai
  if (distance < 20 && distance > 0) {
    myservo.write(90);  // Dhakkan kholne ke liye servo ko 90 degree rotate karo
    delay(3000);        // 3 seconds tak dhakkan khula rahega
  } 
  else {
    myservo.write(0);   // Wapas dhakkan band kar do
  }
  delay(100);
}

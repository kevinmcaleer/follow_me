/*
 * Follow me code
 * Kevin McAleer 23 September 2020
 */
// set Motor A to Arduino Pins
int motor_A = 12; // official Arduino Motor Shield uses D12
int motor_B = 13; // official Arduino Motor Shield uses D13
int buzzer = 4;

// set the Motor Speed using the Arduino Pins
int motor_A_speed = 10; // official Arduino Motor Shield uses D3
int motor_B_speed = 11; // official Arduino Motor Shield uses D11

// defines pins numbers
const int trigPin = 7;
const int echoPin = 8;
// defines variables
long duration;
int distance;

// set the time between motor on and motor off
int wait_in_milliseconds = 50;

int ping() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance= duration*0.034/2;
  // Prints the distance on the Serial Monitor
//  Serial.print("Distance: ");
//  Serial.println(distance);
  return distance;
}

// move forward
void forward() {

  // set the direction to forward
  digitalWrite(motor_A, HIGH);
  digitalWrite(motor_B, LOW);

  // set to full speed
  analogWrite(motor_A_speed, 255);
  analogWrite(motor_B_speed, 255);

  // wait
  delay(wait_in_milliseconds);

  // stop
  analogWrite(motor_A_speed, 0);
  analogWrite(motor_B_speed, 0);
}

// move backward
void backward() {

  // set the direction to backward
  digitalWrite(motor_A, LOW);
  digitalWrite(motor_B, HIGH);

  // set to full speed
  analogWrite(motor_A_speed, 255);
  analogWrite(motor_B_speed, 255);

  // wait
  delay(wait_in_milliseconds);

  // stop
  analogWrite(motor_A_speed, 0);
  analogWrite(motor_B_speed, 0);
}

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input

    // set the Arduino pin to OUTPUT mode
  pinMode(motor_A, OUTPUT);
  pinMode(motor_B, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  // check distance
  distance = ping();
  Serial.print("Distance ");
  Serial.println(distance);
  if (distance < 5) {
    Serial.println("backwards");
    backward();
  }
  if (distance > 10) {
    Serial.println("forwards");
    forward();
  }
  if (distance == 5) {
    Serial.print("stay still");
  }
  
  // if less than 5cm then move backward
  // if greater than 5 cm then move forward
}
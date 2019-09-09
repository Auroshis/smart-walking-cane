const int trigPinfront = 9;
const int echoPinfront = 10;
const int buzzerPinfront = 11;
const int trigPindown = 5;
const int echoPindown = 6;
const int buzzerPindown = 3;

// defines variables
long durationfront;
int distancefront;
int Distancefront;
long durationdown;
int distancedown;
int Distancedown;


void setup() {
pinMode(trigPinfront, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPinfront, INPUT); // Sets the echoPin as an Input
pinMode(buzzerPinfront, OUTPUT);

pinMode(trigPindown, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPindown, INPUT); // Sets the echoPin as an Input
pinMode(buzzerPindown, OUTPUT);
Serial.begin(9600); // Starts the serial communication
}

void loop() {
Distancefront = front();
Distancedown = down();
if (Distancefront <= 85.0){//
  //digitalWrite(buzzer, HIGH);
  digitalWrite(buzzerPinfront,HIGH);
}
else{
 digitalWrite(buzzerPinfront,LOW);
}

if (Distancedown <= 60){//
  digitalWrite(buzzerPindown,HIGH);
}
else{
 digitalWrite(buzzerPindown,LOW);
}
}

float front()
{
  // Clears the trigPin
digitalWrite(trigPinfront, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPinfront, HIGH);
delayMicroseconds(10);
digitalWrite(trigPinfront, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
durationfront = pulseIn(echoPinfront, HIGH);

// Calculating the distance
distancefront = durationfront*0.034/2;//main formula basically,distance = (time*speed)/2
// Prints the distance on the Serial Monitor
Serial.print("Front: ");
Serial.println(distancefront);
return distancefront;//delay(100000);
}
 
float down()
{
   // Clears the trigPin
digitalWrite(trigPindown, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPindown, HIGH);
delayMicroseconds(10);
digitalWrite(trigPindown, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
durationdown = pulseIn(echoPindown, HIGH);

// Calculating the distance
distancedown = durationdown*0.034/2;//main formula basically,distance = (time*speed)/2

// Prints the distance on the Serial Monitor
Serial.print("Down: ");
Serial.println(distancedown);
return distancedown;//delay(100000); 
}


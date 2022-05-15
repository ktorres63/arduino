const int TriggerPin=8;
const int EchoPin =9;

long Duration =0;

void setup() {
  pinMode (TriggerPin,OUTPUT);
  pinMode(EchoPin,INPUT );
  Serial.begin(9600);
  
}

void loop() {
  digitalWrite(TriggerPin,LOW);
  delayMicroseconds(2);
  digitalWrite(TriggerPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(TriggerPin,LOW);

  Duration = pulseIn(EchoPin,HIGH);

  long Distance_cm = Distance(Duration);

  Serial.println(Distance_cm);
  delay(1000);
}

long Distance(long time){
  long DistanceCalc;
  DistanceCalc = ((time * 0.034)/2);
  return DistanceCalc;
}

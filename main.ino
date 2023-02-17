#define MQ3 A0
#define Buzzer 12
#define LED_1 11
#define LED_2 10
#define LED_3 9
#define Threshold_value 1022
int value;
void setup()
{
  Serial.begin(9600);
  pinMode(MQ3, INPUT);
  pinMode(Buzzer, OUTPUT);
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  Serial.println("CLEARDATA");
  Serial.println("LABEL, Time, Started Time, Date, Analog Value");
  Serial.println("RESETTIMER");
}
void loop()
{
  value = analogRead(MQ3);
  Serial.print("DATA, TIME, TIMER, DATE,");
  Serial.println(value);
  if (value > Threshold_value)
  {
    digitalWrite(LED_1, HIGH);
    digitalWrite(LED_2, HIGH);
    digitalWrite(LED_3, HIGH);
    digitalWrite(Buzzer, HIGH);
  }
  else
  {
    digitalWrite(LED_1, LOW);
    digitalWrite(LED_2, LOW);
    digitalWrite(LED_3, LOW);
    digitalWrite(Buzzer, LOW);
  }
  delay(500);
}

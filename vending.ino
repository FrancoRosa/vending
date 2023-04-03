#define led 13
#define valve 11
#define coin_sensor 10
#define water_sensor 9
#define vol_per_pulse 45;

int coin_count = 0;
int water_count = 0;
int debt = 0;

void coins() {
  coin_count++;
  debt += vol_per_pulse;
  digitalWrite(valve, HIGH);
}

void water() {
  water_count++;
  if (debt > 0)
    debt--;
  else
    digitalWrite(valve, LOW);
}

void setup() {
  pinMode(led, OUTPUT);
  pinMode(coin_sensor, INPUT_PULLUP);
  pinMode(water_sensor, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(coin_sensor), coins, FALLING);
  attachInterrupt(digitalPinToInterrupt(water_sensor), water, FALLING);
  Serial.begin(9600);
}

void loop() {
  Serial.print("water: ");
  Serial.print(water_count);
  Serial.print(", coin: ");
  Serial.print(coin_count);
  Serial.print(", debt: ");
  Serial.println(debt);
  digitalWrite(led, !digitalRead(led));
  delay(500);
}

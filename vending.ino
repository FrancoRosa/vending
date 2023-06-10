#define led 13
#define valve 2
#define coin_sensor 10
#define water_sensor 9
#define vol_per_pulse 45;


long signed coin_count = 0;
long signed water_count = 0;
long signed debt = 0;

void valve_on() {
  digitalWrite(valve, LOW);
}

void valve_off() {
  digitalWrite(valve, HIGH);
}

void coins() {
  coin_count++;
  debt += vol_per_pulse;
  valve_on();
}

void water() {
  water_count++;
  if (debt > 0)
    debt--;
  else
    valve_off();
}

void setup() {
  pinMode(led, OUTPUT);
  pinMode(valve, OUTPUT);
  pinMode(coin_sensor, INPUT_PULLUP);
  pinMode(water_sensor, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(coin_sensor), coins, FALLING);
  attachInterrupt(digitalPinToInterrupt(water_sensor), water, FALLING);
  valve_off();
  Serial.begin(9600);
  Serial.println("...start");
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

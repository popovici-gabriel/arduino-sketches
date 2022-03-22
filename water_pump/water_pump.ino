// Setup
#define WATER_PUMP_1 3
#define WATER_PUMP_2 5
#define DELAY_MS 3000
int analogPin0 = A0; 
int analogPin1 = A1; 

void setup() {
  Serial.begin(9600);  
  pinMode(WATER_PUMP_1,OUTPUT);
  pinMode(WATER_PUMP_2,OUTPUT);
}

// Actual code
void loop() {  
  readAndTrigger(A0,WATER_PUMP_1,DELAY_MS,"HUMIDITY SENSOR PIN:A0");
  readAndTrigger(A1,WATER_PUMP_2,DELAY_MS,"HUMIDITY SENSOR PIN:A1");
}

void readAndTrigger(int analogPin, int waterPumpPin, int delayMs, const char *message) {
  int humidityRaw = analogRead(analogPin);  // 1023 to 0 ===> o to 100%
  int humidityReal = map(humidityRaw, 1023, 0, 0, 100);  
  Serial.print(message);  
  Serial.print(" VALUE:");
  Serial.println(humidityReal);  
  trigger(humidityReal,waterPumpPin);
  delay(delayMs);
}


void trigger(int humidityReal, int pinPump) {
  if (humidityReal > 30) {
    Serial.print("WATER PUMP PIN:");
    Serial.print(pinPump);
    Serial.println(" HIGH");
    digitalWrite(pinPump, HIGH);
  } else {
    Serial.print("WATER PUMP PIN:");
    Serial.print(pinPump);
    Serial.println(" LOW");
    digitalWrite(pinPump, LOW);
  }
}


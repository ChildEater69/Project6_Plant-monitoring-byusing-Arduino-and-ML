// Pin connections
const int moisturePin = A0;      // Analog input pin for moisture sensor
const int lightPin = A1;         // Analog input pin for light sensor

void setup() {
  Serial.begin(9600);             // Initialize serial communication
  pinMode(moisturePin, INPUT);    // Set moisture pin as input
  pinMode(lightPin, INPUT);       // Set light pin as input
}

void loop() {
  // Read sensor values
  int moistureValue = analogRead(moisturePin);
  int lightValue = analogRead(lightPin);

  // Print sensor readings
  Serial.print("Moisture: ");
  Serial.print(moistureValue);
  Serial.print("\tLight: ");
  Serial.println(lightValue);

  delay(1000);  // Delay between readings (adjust as needed)
}

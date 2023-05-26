const int moisturePin = A0;      // Analog input pin for moisture sensor
const int lightPin = A1;         // Analog input pin for light sensor

// Constants
const int moistureThreshold = 100;  // Threshold value for moisture level
const int yRange = 100;            // Desired y-axis range

unsigned long previousTime = 0;    // Variable to store the previous time

void setup() {
  Serial.begin(9600);             // Initialize serial communication
  pinMode(moisturePin, INPUT);    // Set moisture pin as input
  pinMode(lightPin, INPUT);       // Set light pin as input
}

void loop() {
  // Read sensor values
  int moistureValue = analogRead(moisturePin);
  int lightValue = analogRead(lightPin);

  // Convert sensor values to actual measurements
  float moisturePercentage = map(moistureValue, 0, 1023, 0, yRange);
  float scaledLightValue = map(lightValue, 0, 1023, 0, yRange);

  // Get current time
  unsigned long currentTime = millis();

  // Check if it's time to send the data
  if (currentTime - previousTime >= 1000) {  // Send data every 1 second (adjust as needed)
    // Print color, timestamp, and sensor readings
    Serial.print("#FF0000");   // Red color for moisture graph
    Serial.print(currentTime);
    Serial.print(",");
    Serial.print(moisturePercentage);
    Serial.println();

    Serial.print("#00FF00");   // Green color for light graph
    Serial.print(currentTime);
    Serial.print(",");
    Serial.print(scaledLightValue);
    Serial.println();

    // Update previous time
    previousTime = currentTime;
  }

  // Check moisture level
  if (moistureValue < moistureThreshold) {
    Serial.println("WARNING\tLow moisture level!");
    // Add your desired action here, such as activating a water pump
  }
}

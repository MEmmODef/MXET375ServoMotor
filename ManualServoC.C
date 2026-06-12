#include <Servo.h> // Include the Servo library

Servo servo; // Create a Servo object

int servoPin = 9; // Servo signal pin connected to D9
int controlValue = 0; // Current control value (0 for stop, 1 for right, 2 for left)

void setup() {
  servo.attach(servoPin); // Attach the servo to the specified pin
  servo.write(90);        // Set the servo to neutral (stop)
  Serial.begin(9600);     // Start Serial communication

  // Print initial message
  Serial.println("Servo Control Options:");
  Serial.println("Enter '0' to stop the servo.");
  Serial.println("Enter '1' to turn right.");
  Serial.println("Enter '2' to turn left.");
}

void loop() {
  // Check if input is available from the Serial Monitor
  if (Serial.available() > 0) {
    controlValue = Serial.parseInt(); // Read the user input as an integer

    // Handle the user input
    if (controlValue == 0) {
      Serial.println("Stopping the servo.");
      servo.write(90); // Stop the servo (neutral position)
    } else if (controlValue == 1) {
      Serial.println("Turning right.");
      servo.write(180); // Turn right
    } else if (controlValue == 2) {
      Serial.println("Turning left.");
      servo.write(0); // Turn left
    } else {
      Serial.println("Invalid input. Enter 0, 1, or 2.");
    }

    // Clear the Serial buffer
    while (Serial.available() > 0) {
      Serial.read();
    }
  }

  delay(100); // Small delay to avoid overloading the loop
}


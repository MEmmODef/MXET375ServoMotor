#include <Servo.h> // Include the Servo library


Servo servo; // Create a Servo object


int servoPin = 9;       // Servo signal pin connected to D9
int rotationRightDuration = 2600; // Time in milliseconds for one full 360° rotation
int rotationLeftDuration = 1960;
int pauseDuration = 1500;    // Pause duration in milliseconds between rotations
bool isRunning = false;      // Flag to check if the sequence should run


void setup() {
  servo.attach(servoPin); // Attach the servo to the specified pin
  servo.write(90);        // Neutral (stopped) position
  Serial.begin(9600);     // Start Serial communication


  // Print instructions
  Serial.println("Press '1' to start the servo sequence (right → pause → left).");
  Serial.println("Sequence will run once and stop.");
}


void loop() {
  // Check if input is available
  if (Serial.available() > 0) {
    int command = Serial.parseInt(); // Read the input as an integer


    // Handle valid commands
    if (command == 1) {
      isRunning = true; // Set the flag to start the sequence
      Serial.println("Starting the servo sequence...");
      runSequence(); // Run the sequence immediately
      isRunning = false; // Reset the flag after the sequence finishes
    } else {
      Serial.println("Invalid command. Press '1' to start.");
    }


    // Clear the Serial buffer
    while (Serial.available() > 0) {
      Serial.read();
    }
  }
}


void runSequence() {
  // Turn right for 4 seconds
  Serial.println("Turning right...");
  servo.write(180); // Full speed to the right
  delay(rotationRightDuration); // Run the servo for the specified time
  stopServo();


  // Pause for 1 second
  Serial.println("Pausing...");
  delay(pauseDuration);


  // Turn left for 4 seconds
  Serial.println("Turning left...");
  servo.write(0); // Full speed to the left
  delay(rotationLeftDuration); // Run the servo for the specified time
  stopServo();


  // Pause for 1 second
  Serial.println("Pausing...");
  delay(pauseDuration);


  // Sequence complete
  Serial.println("Sequence complete. Waiting for a new command.");
}


void stopServo() {
  Serial.println("Stopping the servo.");
  servo.write(90); // Neutral position stops the continuous rotation servo
}


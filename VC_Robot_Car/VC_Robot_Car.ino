#include <SoftwareSerial.h>

/*=========================================================
        Voice Controlled Robot Car with Chatbot
        Fixed & Optimized Version
        Commands:
            F = Forward
            B = Backward
            L = Left
            R = Right
            S = Stop
=========================================================*/

// ---------------- Motor Driver Pins ----------------
const byte motor1Pin1 = 2;
const byte motor1Pin2 = 3;
const byte motor2Pin1 = 4;
const byte motor2Pin2 = 5;

// ---------------- Bluetooth Pins ----------------
// HC-05 TXD -> Arduino Pin 10
// HC-05 RXD -> Arduino Pin 11
const byte bluetoothRX = 10;
const byte bluetoothTX = 11;

SoftwareSerial bluetooth(bluetoothRX, bluetoothTX);

// =====================================================

void setup()
{
    // Motor Pins
    pinMode(motor1Pin1, OUTPUT);
    pinMode(motor1Pin2, OUTPUT);
    pinMode(motor2Pin1, OUTPUT);
    pinMode(motor2Pin2, OUTPUT);

    // Safety
    stopMotors();

    // Serial Monitor
    Serial.begin(9600);

    // Bluetooth
    bluetooth.begin(9600);

    Serial.println("====================================");
    Serial.println(" Voice Controlled Robot Car Ready ");
    Serial.println(" Waiting for Bluetooth Commands...");
    Serial.println("====================================");
}

// =====================================================

void loop()
{
    if (bluetooth.available())
    {
        char command = toupper(bluetooth.read());

        Serial.print("Received Command : ");
        Serial.println(command);

        switch (command)
        {
            case 'F':
                moveForward();
                break;

            case 'B':
                moveBackward();
                break;

            case 'L':
                turnLeft();
                break;

            case 'R':
                turnRight();
                break;

            case 'S':
                stopMotors();
                break;

            default:
                Serial.println("Unknown Command!");
                stopMotors();
                break;
        }
    }
}

// =====================================================
// Movement Functions
// =====================================================

void moveForward()
{
    digitalWrite(motor1Pin1, HIGH);
    digitalWrite(motor1Pin2, LOW);

    digitalWrite(motor2Pin1, HIGH);
    digitalWrite(motor2Pin2, LOW);

    Serial.println("Moving Forward");
}

void moveBackward()
{
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, HIGH);

    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, HIGH);

    Serial.println("Moving Backward");
}

void turnLeft()
{
    // Left Motor Stop
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, LOW);

    // Right Motor Forward
    digitalWrite(motor2Pin1, HIGH);
    digitalWrite(motor2Pin2, LOW);

    Serial.println("Turning Left");
}

void turnRight()
{
    // Left Motor Forward
    digitalWrite(motor1Pin1, HIGH);
    digitalWrite(motor1Pin2, LOW);

    // Right Motor Stop
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, LOW);

    Serial.println("Turning Right");
}

void stopMotors()
{
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, LOW);

    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, LOW);

    Serial.println("Robot Stopped");
}
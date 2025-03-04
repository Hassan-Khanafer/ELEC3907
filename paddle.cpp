#ifndef PADDLE_H
#define PADDLE_H

#include "Player.h"  // Assuming Paddle inherits from Player
#include <Arduino.h> // For analogRead

class Paddle : public Player {
private:
    int potentiometerPin;  // Analog pin for potentiometer
    int position;          // Current position of the paddle

public:
    // Constructor to initialize the paddle
    Paddle(int potPin) : potentiometerPin(potPin), position(0) {}

    // Function to update paddle position based on potentiometer input
    void UpdatePosition() {
        position = analogRead(potentiometerPin); // Read potentiometer value
        position = map(position, 0, 1023, 0, 255); // Scale value to game range

        // Send position to game logic (to be used in game mechanics)
        Serial.print("Paddle Position: ");
        Serial.println(position);
    }

    // Getter function for position
    int getPosition() const {
        return position;
    }
};

#endif // PADDLE_H

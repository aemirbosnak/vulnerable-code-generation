//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the main smart home functions
void turnOnLights(char *room) {
    printf("Turning on lights in %s.\n", room);
}

void turnOffLights(char *room) {
    printf("Turning off lights in %s.\n", room);
}

void setTemperature(float temp) {
    printf("Setting temperature to %.1f degrees Celsius.\n", temp);
}

void playMusic(char *song) {
    printf("Playing %s.\n", song);
}

void stopMusic() {
    printf("Stopping music.\n");
}

void lockDoors() {
    printf("Locking all doors.\n");
}

void unlockDoors() {
    printf("Unlocking all doors.\n");
}

// The main function that handles user input
int main() {
    char input[100];

    while (1) {
        printf("What would you like me to do? ");
        fgets(input, 100, stdin);

        // Parse the user input
        char *command = strtok(input, " ");
        char *args = strtok(NULL, "\n");

        // Execute the appropriate command
        if (strcmp(command, "turn on lights") == 0) {
            turnOnLights(args);
        } else if (strcmp(command, "turn off lights") == 0) {
            turnOffLights(args);
        } else if (strcmp(command, "set temperature") == 0) {
            setTemperature(atof(args));
        } else if (strcmp(command, "play music") == 0) {
            playMusic(args);
        } else if (strcmp(command, "stop music") == 0) {
            stopMusic();
        } else if (strcmp(command, "lock doors") == 0) {
            lockDoors();
        } else if (strcmp(command, "unlock doors") == 0) {
            unlockDoors();
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Sorry, I don't understand that command. Please try again.\n");
        }
    }

    return 0;
}
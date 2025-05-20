//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Define light modes
#define LIGHT_BRIGHT 100
#define LIGHT_DIM 50
#define LIGHT_OFF 0

// A structure to represent a smart bulb
typedef struct {
    char name[50];
    int brightness;
    int power; // 1 for ON, 0 for OFF
} SmartBulb;

// Function to display the current state of the bulb
void displayBulbState(SmartBulb bulb) {
    printf("Bulb: %s\n", bulb.name);
    printf("Status: %s\n", bulb.power ? "ON" : "OFF");
    printf("Brightness: %d%%\n\n", bulb.brightness);
}

// Function to switch the bulb on
void switchOn(SmartBulb *bulb) {
    bulb->power = 1;
    bulb->brightness = LIGHT_BRIGHT;
}

// Function to switch the bulb off
void switchOff(SmartBulb *bulb) {
    bulb->power = 0;
    bulb->brightness = LIGHT_OFF;
}

// Function to dim the bulb
void dimBulb(SmartBulb *bulb, int dimValue) {
    if (bulb->power) {
        bulb->brightness = dimValue;
    }
}

// Function to automate lighting based on time of day
void automateLighting(SmartBulb *bulb) {
    time_t now;
    struct tm *tm_info;

    time(&now);
    tm_info = localtime(&now);

    if (tm_info->tm_hour >= 18 || tm_info->tm_hour < 6) {
        switchOn(bulb);
        dimBulb(bulb, LIGHT_DIM);
    } else {
        switchOff(bulb);
    }
}

// Function to simulate a user command
void userCommand(SmartBulb *bulb, const char *command) {
    if (strcmp(command, "on") == 0) {
        switchOn(bulb);
    } else if (strcmp(command, "off") == 0) {
        switchOff(bulb);
    } else if (strcmp(command, "bright") == 0) {
        dimBulb(bulb, LIGHT_BRIGHT);
    } else if (strcmp(command, "dim") == 0) {
        dimBulb(bulb, LIGHT_DIM);
    } else {
        printf("Unknown command: %s\n", command);
    }
}

int main() {
    SmartBulb livingRoomLight;
    strcpy(livingRoomLight.name, "Living Room Light");
    livingRoomLight.power = 0;
    livingRoomLight.brightness = LIGHT_OFF;

    // Display initial state
    printf("Initial state of the smart home...\n");
    displayBulbState(livingRoomLight);

    // Automate lighting
    printf("Automating lighting...\n");
    automateLighting(&livingRoomLight);
    displayBulbState(livingRoomLight);

    // Simulate user commands
    printf("User commands:\n");
    userCommand(&livingRoomLight, "dim");
    displayBulbState(livingRoomLight);
    
    userCommand(&livingRoomLight, "bright");
    displayBulbState(livingRoomLight);

    userCommand(&livingRoomLight, "off");
    displayBulbState(livingRoomLight);

    userCommand(&livingRoomLight, "on");
    displayBulbState(livingRoomLight);

    // Final state
    printf("Final state of the smart home...\n");
    displayBulbState(livingRoomLight);

    return 0;
}
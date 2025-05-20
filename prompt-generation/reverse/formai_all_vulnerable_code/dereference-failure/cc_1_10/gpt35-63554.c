//FormAI DATASET v1.0 Category: Smart home automation ; Style: interoperable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define the structure for the smart home automation
typedef struct {
    int lights;
    int temperature;
    int security;
} SmartHome;

// Define functions to control the smart home automation
void turnOnLights(SmartHome *home) {
    home->lights = 1;
    printf("The lights are now on.\n");
}

void turnOffLights(SmartHome *home) {
    home->lights = 0;
    printf("The lights are now off.\n");
}

void adjustTemperature(SmartHome *home, int temperature) {
    home->temperature = temperature;
    printf("The temperature has been set to %d.\n", temperature);
}

void armSecurity(SmartHome *home) {
    home->security = 1;
    printf("The security system is now armed.\n");
}

void disarmSecurity(SmartHome *home) {
    home->security = 0;
    printf("The security system is now disarmed.\n");
}

// Define a function to print the current state of the smart home automation
void printState(SmartHome *home) {
    printf("Current State:\n");
    printf("Lights: %s\n", home->lights ? "On" : "Off");
    printf("Temperature: %d\n", home->temperature);
    printf("Security: %s\n", home->security ? "Armed" : "Disarmed");
}

int main() {
    char command[50];
    SmartHome *home = (SmartHome*) malloc(sizeof(SmartHome));
    home->lights = 0;
    home->temperature = 70;
    home->security = 0;

    printf("Welcome to the Smart Home Automation system.\n");
    printf("Type 'help' for a list of available commands.\n");

    while (1) {
        printf("> ");
        fgets(command, 50, stdin);
        command[strlen(command) - 1] = '\0';

        if (strcmp(command, "help") == 0) {
            printf("Available Commands:\n");
            printf("help - Show this list of commands\n");
            printf("lights on - Turn on the lights\n");
            printf("lights off - Turn off the lights\n");
            printf("temperature [value] - Set the temperature to [value]\n");
            printf("security arm - Arm the security system\n");
            printf("security disarm - Disarm the security system\n");
            printf("state - Print the current state of the system\n");
            printf("exit - Exit the program\n");
        } else if (strcmp(command, "lights on") == 0) {
            turnOnLights(home);
        } else if (strcmp(command, "lights off") == 0) {
            turnOffLights(home);
        } else if (strstr(command, "temperature") != NULL) {
            int temperature = atoi(strchr(command, ' ') + 1);
            adjustTemperature(home, temperature);
        } else if (strcmp(command, "security arm") == 0) {
            armSecurity(home);
        } else if (strcmp(command, "security disarm") == 0) {
            disarmSecurity(home);
        } else if (strcmp(command, "state") == 0) {
            printState(home);
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command. Type 'help' for a list of available commands.\n");
        }
    }

    free(home);
    printf("Goodbye!\n");

    return 0;
}
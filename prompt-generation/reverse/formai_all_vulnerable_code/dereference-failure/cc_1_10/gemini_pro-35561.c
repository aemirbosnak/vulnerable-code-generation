//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Simulated hardware
typedef struct {
    int state; // 0 = off, 1 = on
    int brightness; // 0-100
} Light;

// Simulated user input
typedef struct {
    char *command;
    char *argument;
} Command;

// Simulated network connection
typedef struct {
    int connected;
    int error;
} Network;

// Initialize simulated hardware
Light light = {0, 0};

// Initialize simulated user input
Command command = {NULL, NULL};

// Initialize simulated network connection
Network network = {0, 0};

// Parse user input
void parse_command(char *input) {
    char *ptr = strtok(input, " ");
    command.command = ptr;
    command.argument = strtok(NULL, " ");
}

// Execute user command
void execute_command() {
    if (strcmp(command.command, "on") == 0) {
        light.state = 1;
        printf("Light turned on\n");
    } else if (strcmp(command.command, "off") == 0) {
        light.state = 0;
        printf("Light turned off\n");
    } else if (strcmp(command.command, "brightness") == 0) {
        light.brightness = atoi(command.argument);
        printf("Light brightness set to %d\n", light.brightness);
    } else {
        printf("Invalid command\n");
    }
}

// Check network connection
int check_network() {
    if (!network.connected) {
        printf("Network not connected\n");
        return -1;
    }
    if (network.error) {
        printf("Network error\n");
        return -1;
    }
    return 0;
}

// Send data over network
int send_data(char *data) {
    if (check_network() < 0) {
        return -1;
    }
    printf("Sending data: %s\n", data);
    return 0;
}

// Main loop
int main() {
    char input[100];
    while (1) {
        printf("> ");
        fgets(input, sizeof(input), stdin);
        parse_command(input);
        execute_command();
        if (strcmp(command.command, "exit") == 0) {
            break;
        }
    }
    return 0;
}
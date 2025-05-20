//GPT-4o-mini DATASET v1.0 Category: Drone Remote Control ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_LOG_LENGTH 256

// Enum to manage drone states
typedef enum {
    READY,
    FLYING,
    LANDING,
    EMERGENCY
} DroneState;

// Function declarations
void show_menu();
void execute_command(char* command, DroneState* state);
void take_off();
void land();
void log_event(const char* event);
void emergency_landing();

// Global variable for logging
FILE *log_file;

// Main function
int main() {
    char command[MAX_COMMAND_LENGTH];
    DroneState state = READY;

    // Open log file
    log_file = fopen("drone_log.txt", "a");
    if (!log_file) {
        perror("Error opening log file");
        return EXIT_FAILURE;
    }

    // Process user commands
    while (true) {
        show_menu();
        printf("Enter command: ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0; // Remove newline character

        // Execute command
        execute_command(command, &state);
    }

    fclose(log_file);
    return EXIT_SUCCESS;
}

// Show the command menu
void show_menu() {
    printf("\n--- Drone Control Menu ---\n");
    printf("1. Take Off\n");
    printf("2. Land\n");
    printf("3. Emergency Landing\n");
    printf("4. Status\n");
    printf("5. Exit\n");
}

// Execute the command based on user input
void execute_command(char* command, DroneState* state) {
    if (strcmp(command, "1") == 0) {
        take_off();
        *state = FLYING;
        log_event("Drone taking off.");
    } else if (strcmp(command, "2") == 0) {
        if (*state == FLYING) {
            land();
            *state = READY;
            log_event("Drone landing.");
        } else {
            printf("Drone is not flying.\n");
        }
    } else if (strcmp(command, "3") == 0) {
        emergency_landing();
        *state = READY;
        log_event("Emergency landing initiated.");
    } else if (strcmp(command, "4") == 0) {
        printf("Drone status: %s\n", *state == FLYING ? "Flying" : "Ready");
    } else if (strcmp(command, "5") == 0) {
        log_event("Exiting control program.");
        fclose(log_file);
        exit(EXIT_SUCCESS);
    } else {
        printf("Invalid command. Please try again.\n");
    }
}

// Simulate takeoff
void take_off() {
    printf("Drone is taking off...\n");
    sleep(2);
    printf("Drone has taken off successfully!\n");
}

// Simulate landing
void land() {
    printf("Drone is landing...\n");
    sleep(2);
    printf("Drone has landed successfully!\n");
}

// Log an event to the log file with timestamp
void log_event(const char* event) {
    time_t now = time(NULL);
    char* time_str = ctime(&now);
    time_str[strcspn(time_str, "\n")] = 0; // Remove newline

    fprintf(log_file, "[%s] %s\n", time_str, event);
}

// Simulate emergency landing
void emergency_landing() {
    printf("Emergency landing initiated! Drone is landing immediately...\n");
    sleep(2);
    printf("Drone has landed urgently!\n");
}
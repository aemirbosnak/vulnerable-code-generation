//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Seed random number generator
    int speed = 0;
    int direction = 0;
    char response[100] = "";
    
    printf("Welcome to the Remote Control Vehicle Simulation\n");
    printf("Use commands like 'speed 5' or 'turn left' to control your vehicle.\n");
    
    while (1) { // Loop forever
        // Get user input and split into command and argument
        printf("> ");
        fgets(response, sizeof(response), stdin);
        char *command = strtok(response, " \n");
        char *arg = strtok(NULL, " \n");
        
        if (strcmp(command, "speed") == 0) { // Adjust speed
            if (arg != NULL) {
                speed = atoi(arg);
                printf("Vehicle is now moving at %d mph\n", speed);
            }
            else {
                printf("Error: please provide a speed value\n");
            }
        }
        else if (strcmp(command, "turn") == 0) { // Change direction
            if (arg != NULL) {
                if (strcmp(arg, "left") == 0) {
                    direction -= rand() % 45;
                    printf("Vehicle turned left and is now facing %d degrees\n", direction);
                }
                else if (strcmp(arg, "right") == 0) {
                    direction += rand() % 45;
                    printf("Vehicle turned right and is now facing %d degrees\n", direction);
                }
                else {
                    printf("Error: invalid turn direction\n");
                }
            }
            else {
                printf("Error: please provide a turn direction\n");
            }
        }
        else if (strcmp(command, "status") == 0) { // Print status
            printf("Vehicle is currently moving at %d mph and facing %d degrees\n", speed, direction);
        }
        else if (strcmp(command, "exit") == 0) { // Exit program
            printf("Goodbye!\n");
            break;
        }
        else { // Unknown command
            printf("Error: unknown command\n");
        }
    }
    
    return 0;
}
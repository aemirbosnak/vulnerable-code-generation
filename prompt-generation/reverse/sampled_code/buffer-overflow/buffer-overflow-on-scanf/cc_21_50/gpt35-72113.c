//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 20

int main() {
    char command[MAX_COMMAND_LENGTH];
    int altitude = 0;
    int speed = 0;
    int heading = 0;
    int battery_life = 100;
    int is_connected = 1;
    int is_armed = 0;
    int is_flying = 0;

    while(is_connected) {
        printf("Enter command: ");
        scanf("%s", command);

        if(strcmp(command, "arm") == 0) {
            is_armed = 1;
            printf("Drone is armed and ready to fly.\n");
        }
        else if(strcmp(command, "disarm") == 0) {
            is_armed = 0;
            printf("Drone is disarmed and cannot fly.\n");
        }
        else if(strcmp(command, "takeoff") == 0) {
            if(is_armed && !is_flying) {
                is_flying = 1;
                altitude = 10;
                printf("Drone has taken off.\n");
            }
            else if(!is_armed) {
                printf("Drone is not armed and cannot takeoff.\n");
            }
            else if(is_flying) {
                printf("Drone is already flying and cannot takeoff again.\n");
            }
        }
        else if(strcmp(command, "land") == 0) {
            if(is_armed && is_flying) {
                is_flying = 0;
                altitude = 0;
                printf("Drone has landed.\n");
            }
            else if(!is_armed) {
                printf("Drone is not armed and cannot land.\n");
            }
            else if(!is_flying) {
                printf("Drone is not flying and cannot land.\n");
            }
        }
        else if(strcmp(command, "up") == 0) {
            if(is_armed && is_flying) {
                altitude += 10;
                printf("Drone has gone up to altitude %d meters.\n", altitude);
            }
            else if(!is_armed) {
                printf("Drone is not armed and cannot go up.\n");
            }
            else if(!is_flying) {
                printf("Drone is not flying and cannot go up.\n");
            }
        }
        else if(strcmp(command, "down") == 0) {
            if(is_armed && is_flying && altitude > 0) {
                altitude -= 10;
                printf("Drone has gone down to altitude %d meters.\n", altitude);
            }
            else if(!is_armed) {
                printf("Drone is not armed and cannot go down.\n");
            }
            else if(!is_flying) {
                printf("Drone is not flying and cannot go down.\n");
            }
            else {
                printf("Drone is already at minimum altitude.\n");
            }
        }
        else if(strcmp(command, "left") == 0) {
            if(is_armed && is_flying) {
                heading -= 10;
                printf("Drone has turned left to heading %d degrees.\n", heading);
            }
            else if(!is_armed) {
                printf("Drone is not armed and cannot turn left.\n");
            }
            else if(!is_flying) {
                printf("Drone is not flying and cannot turn left.\n");
            }
        }
        else if(strcmp(command, "right") == 0) {
            if(is_armed && is_flying) {
                heading += 10;
                printf("Drone has turned right to heading %d degrees.\n", heading);
            }
            else if(!is_armed) {
                printf("Drone is not armed and cannot turn right.\n");
            }
            else if(!is_flying) {
                printf("Drone is not flying and cannot turn right.\n");
            }
        }
        else if(strcmp(command, "forward") == 0) {
            if(is_armed && is_flying) {
                speed += 10;
                printf("Drone has gone forward at speed %d km/h.\n", speed);
            }
            else if(!is_armed) {
                printf("Drone is not armed and cannot go forward.\n");
            }
            else if(!is_flying) {
                printf("Drone is not flying and cannot go forward.\n");
            }
        }
        else if(strcmp(command, "back") == 0) {
            if(is_armed && is_flying && speed > 0) {
                speed -= 10;
                printf("Drone has gone back at speed %d km/h.\n", speed);
            }
            else if(!is_armed) {
                printf("Drone is not armed and cannot go back.\n");
            }
            else if(!is_flying) {
                printf("Drone is not flying and cannot go back.\n");
            }
            else {
                printf("Drone is already at minimum speed.\n");
            }
        }
        else if(strcmp(command, "battery") == 0) {
            printf("Battery life remaining: %d\n", battery_life);
        }
        else if(strcmp(command, "exit") == 0) {
            break;
        }
        else {
            printf("Invalid command.\n");
        }

        if(is_flying) {
            battery_life -= 5;
        }

        if(battery_life <= 0) {
            printf("Drone is out of battery and is landing.\n");
            is_flying = 0;
            altitude = 0;
        }
    }

    printf("Connection to drone lost.\n");

    return 0;
}
//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_DRONES 4

typedef struct {
    int x;
    int y;
    int z;
} coordinates;

typedef struct {
    coordinates location;
    int battery_level;
    int speed;
    char drone_name[20];
} drone;

int main() {
    drone fleet[NUM_DRONES];
    
    for (int i=0; i<NUM_DRONES; i++) {
        strcpy(fleet[i].drone_name, "Drone ");
        char num[1];
        sprintf(num, "%d", i+1);
        strcat(fleet[i].drone_name, num);
        fleet[i].location.x = rand() % 100;
        fleet[i].location.y = rand() % 100;
        fleet[i].location.z = rand() % 10;
        fleet[i].speed = rand() % 50;
        fleet[i].battery_level = rand() % 100;
    }
    
    int choice;
    printf("Welcome to drone control! Choose an option: \n");
    printf("1. View drone fleet\n");
    printf("2. Send command to drone\n");
    printf("3. Exit\n");
    scanf("%d", &choice);
    
    while (choice != 3) {
        switch (choice) {
            case 1:
                printf("Drone fleet:\n");
                for (int i=0; i<NUM_DRONES; i++) {
                    printf("%s at (%d, %d, %d) with speed %d and battery level %d%%\n", fleet[i].drone_name, fleet[i].location.x, fleet[i].location.y, fleet[i].location.z, fleet[i].speed, fleet[i].battery_level);
                }
                break;
            case 2:
                printf("Enter drone number to send command to (1-%d):\n", NUM_DRONES);
                int num;
                scanf("%d", &num);
                if (num < 1 || num > NUM_DRONES) {
                    printf("Invalid input\n");
                    break;
                }
                printf("Enter command (forward, backward, left, right, up, down):\n");
                char command[20];
                scanf("%s", command);
                printf("Sending command '%s' to %s\n", command, fleet[num-1].drone_name);
                break;
            default:
                printf("Invalid input\n");
        }
        printf("\nChoose an option: \n");
        printf("1. View drone fleet\n");
        printf("2. Send command to drone\n");
        printf("3. Exit\n");
        scanf("%d", &choice);
    }
    printf("Exiting program\n");
    return 0;
}
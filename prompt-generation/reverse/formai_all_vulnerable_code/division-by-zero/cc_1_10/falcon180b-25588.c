//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265358979323846

// Function prototypes
void move_forward(int speed, int time);
void turn_left(int speed, int time);
void turn_right(int speed, int time);
void stop_robot(void);

int main() {
    int choice;
    int speed = 0;
    int time = 0;

    do {
        printf("\nRobot Control\n");
        printf("1. Move forward\n");
        printf("2. Turn left\n");
        printf("3. Turn right\n");
        printf("4. Stop\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter speed (0-100): ");
                scanf("%d", &speed);
                printf("Enter time in seconds: ");
                scanf("%d", &time);
                move_forward(speed, time);
                break;
            case 2:
                printf("Enter speed (0-100): ");
                scanf("%d", &speed);
                printf("Enter time in seconds: ");
                scanf("%d", &time);
                turn_left(speed, time);
                break;
            case 3:
                printf("Enter speed (0-100): ");
                scanf("%d", &speed);
                printf("Enter time in seconds: ");
                scanf("%d", &time);
                turn_right(speed, time);
                break;
            case 4:
                stop_robot();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (1);

    return 0;
}

// Move the robot forward at a given speed for a given time
void move_forward(int speed, int time) {
    printf("Moving forward at %d%% speed for %d seconds\n", speed, time);
    for (int i = 0; i < time; i++) {
        printf(".");
        usleep(1000000 / (speed * 2)); // Sleep for 1/speed seconds
    }
    printf("\n");
}

// Turn the robot left at a given speed for a given time
void turn_left(int speed, int time) {
    printf("Turning left at %d%% speed for %d seconds\n", speed, time);
    for (int i = 0; i < time; i++) {
        printf(".");
        usleep(1000000 / (speed * 2)); // Sleep for 1/speed seconds
    }
    printf("\n");
}

// Turn the robot right at a given speed for a given time
void turn_right(int speed, int time) {
    printf("Turning right at %d%% speed for %d seconds\n", speed, time);
    for (int i = 0; i < time; i++) {
        printf(".");
        usleep(1000000 / (speed * 2)); // Sleep for 1/speed seconds
    }
    printf("\n");
}

// Stop the robot
void stop_robot() {
    printf("Stopping robot\n");
}
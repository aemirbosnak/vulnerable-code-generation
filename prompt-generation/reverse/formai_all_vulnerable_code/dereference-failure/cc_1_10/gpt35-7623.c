//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: mathematical
#include <stdio.h>

// Constants
#define MAX_HEIGHT 100 // Maximum height of the drone in meters
#define MAX_SPEED 10 // Maximum speed of the drone in meters per second

// Variables
int current_height = 0; // Current height of the drone in meters
int current_speed = 0; // Current speed of the drone in meters per second
int target_height = 0; // Target height of the drone in meters
int target_speed = 0; // Target speed of the drone in meters per second
int battery_level = 100; // Battery level of the remote control in percents
int distance_traveled = 0; // Distance traveled by the drone in meters

// Functions
void increase_height(int amount)
{
    target_height += amount;
    if (target_height > MAX_HEIGHT)
    {
        target_height = MAX_HEIGHT;
    }
}

void decrease_height(int amount)
{
    target_height -= amount;
    if (target_height < 0)
    {
        target_height = 0;
    }
}

void increase_speed(int amount)
{
    target_speed += amount;
    if (target_speed > MAX_SPEED)
    {
        target_speed = MAX_SPEED;
    }
}

void decrease_speed(int amount)
{
    target_speed -= amount;
    if (target_speed < 0)
    {
        target_speed = 0;
    }
}

void apply_changes()
{
    current_height = target_height;
    current_speed = target_speed;
}

void print_status()
{
    printf("Current height: %dm\n", current_height);
    printf("Current speed: %dm/s\n", current_speed);
    printf("Battery level: %d%%\n", battery_level);
    printf("Distance traveled: %dm\n", distance_traveled);
}

int main()
{
    printf("Welcome to the C Drone Remote Control Example Program\n");

    // Main loop
    while (1)
    {
        printf("\n");
        printf("Enter a command:\n");
        printf("1 - Increase height\n");
        printf("2 - Decrease height\n");
        printf("3 - Increase speed\n");
        printf("4 - Decrease speed\n");
        printf("5 - Print status\n");
        printf("6 - Exit\n");

        int command;
        scanf("%d", &command);

        switch (command)
        {
            case 1:
                printf("Enter amount to increase height (0-%d): ", MAX_HEIGHT - target_height);
                int amount;
                scanf("%d", &amount);
                increase_height(amount);
                apply_changes();
                distance_traveled += current_speed;
                break;

            case 2:
                printf("Enter amount to decrease height (0-%d): ", target_height);
                scanf("%d", &amount);
                decrease_height(amount);
                apply_changes();
                distance_traveled += current_speed;
                break;

            case 3:
                printf("Enter amount to increase speed (0-%d): ", MAX_SPEED - target_speed);
                scanf("%d", &amount);
                increase_speed(amount);
                apply_changes();
                distance_traveled += current_speed;
                break;

            case 4:
                printf("Enter amount to decrease speed (0-%d): ", target_speed);
                scanf("%d", &amount);
                decrease_speed(amount);
                apply_changes();
                distance_traveled += current_speed;
                break;

            case 5:
                print_status();
                break;

            case 6:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid command\n");
        }

        // Decrease battery level after each command
        battery_level--;
        if (battery_level == 0)
        {
            printf("Battery level is 0%%. Exiting...\n");
            return 0;
        }
    }
}
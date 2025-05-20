//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// struct to hold the information of the Remote control Vehicle
struct RCVehicle {
    int speed;
    int direction;
    int battery;
    char *name;
};

// function to create a new RCVehicle
struct RCVehicle *create_RCVehicle(char *name, int speed, int direction, int battery) {
    struct RCVehicle *vehicle = malloc(sizeof(struct RCVehicle));

    vehicle->name = strdup(name);
    vehicle->speed = speed;
    vehicle->direction = direction;
    vehicle->battery = battery;

    return vehicle;
}

// function to move the RCVehicle
void move_RCVehicle(struct RCVehicle *vehicle) {
    printf("%s is moving at %d km/hour in direction %d\n", vehicle->name, vehicle->speed, vehicle->direction);
}

// function to increase the speed of RCVehicle
void increase_speed(struct RCVehicle *vehicle, int increment) {
    vehicle->speed = vehicle->speed + increment;
    printf("Speed of %s increased to %d km/hour\n", vehicle->name, vehicle->speed);
}

// function to change the direction of RCVehicle
void change_direction(struct RCVehicle *vehicle, int new_direction) {
    vehicle->direction = new_direction;
    printf("%s is now moving in direction %d\n", vehicle->name, vehicle->direction);
}

// function to check battery level of RCVehicle
void check_battery(struct RCVehicle *vehicle) {
    printf("Battery level of %s is %d%%\n", vehicle->name, vehicle->battery);
}

// function to recharge the battery of RCVehicle
void recharge_battery(struct RCVehicle *vehicle) {
    vehicle->battery = 100;
    printf("%s's battery is fully charged\n", vehicle->name);
}

// main function
int main() {
    // creating a new RCVehicle
    struct RCVehicle *vehicle1 = create_RCVehicle("Car", 40, 0, 75);

    // moving the RCVehicle
    move_RCVehicle(vehicle1);

    // increasing the speed of the RCVehicle
    increase_speed(vehicle1, 20);

    // changing the direction of the RCVehicle
    change_direction(vehicle1, 90);

    // checking battery level of the RCVehicle
    check_battery(vehicle1);

    // recharging the battery of the RCVehicle
    recharge_battery(vehicle1);

    // freeing the memory allocated for the RCVehicle
    free(vehicle1->name);
    free(vehicle1);

    return 0;
}
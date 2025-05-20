//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Drone struct to hold its status.
typedef struct Drone {
    int battery_level;
    int altitude;
    int orientation;
    int speed;
    char* status;
    char* location;
} Drone;

// Define the Remote Control struct to manage the Drone.
typedef struct RemoteControl {
    Drone* drone;
    char* owner;
    char* model;
    float version;
} RemoteControl;

// Define functions to operate the Drone.
void takeoff(Drone* drone) {
    drone->altitude = 1;
    drone->status = "Flying";
    printf("Drone is now taking off.\n");
}

void land(Drone* drone) {
    drone->altitude = 0;
    drone->status = "Landed";
    printf("Drone is now landing.\n");
}

void move_forward(Drone* drone, int distance) {
    drone->location = "Moving forward";
    printf("Drone is now moving %d meters forward.\n", distance);
}

void move_backward(Drone* drone, int distance) {
    drone->location = "Moving backward";
    printf("Drone is now moving %d meters backward.\n", distance);
}

void move_left(Drone* drone, int distance) {
    drone->location = "Moving left";
    printf("Drone is now moving %d meters to the left.\n", distance);
}

void move_right(Drone* drone, int distance) {
    drone->location = "Moving right";
    printf("Drone is now moving %d meters to the right.\n", distance);
}

void rotate_left(Drone* drone, int degrees) {
    drone->orientation = (drone->orientation - degrees) % 360;
    printf("Drone is now rotating %d degrees to the left.\n", degrees);
}

void rotate_right(Drone* drone, int degrees) {
    drone->orientation = (drone->orientation + degrees) % 360;
    printf("Drone is now rotating %d degrees to the right.\n", degrees);
}

void set_speed(Drone* drone, int speed) {
    drone->speed = speed;
    printf("Drone is now set to fly at a speed of %d meters per second.\n", speed);
}

void set_battery_level(Drone* drone, int level) {
    drone->battery_level = level;
    printf("Drone battery level is now at %d percent.\n", level);
}

// Define functions to operate the Remote Control.
RemoteControl* init_remote_control(Drone* drone, char* owner, char* model, float version) {
    RemoteControl* rc = (RemoteControl*) malloc(sizeof(RemoteControl));
    rc->drone = drone;
    rc->owner = owner;
    rc->model = model;
    rc->version = version;
    printf("Remote control successfully initialized.\n");
    return rc;
}

void connect_to_drone(RemoteControl* rc) {
    printf("Remote control is now connected to the drone.\n");
}

void disconnect_from_drone(RemoteControl* rc) {
    printf("Remote control is now disconnected from the drone.\n");
}

void hover(Drone* drone) {
    drone->location = "Hovering";
    printf("Drone is now hovering.\n");
}

void low_battery_warning(Drone* drone) {
    if (drone->battery_level < 20) {
        printf("Warning: Drone battery level is low.\n");
    }
}

void out_of_range_warning(Drone* drone) {
    if (drone->altitude > 50) {
        printf("Warning: Drone is out of range.\n");
    }
}

// Define the main function.
int main() {

    // Initialize the Drone and set its initial status.
    Drone drone = {100, 0, 0, 0, "Landed", ""};

    // Initialize the Remote Control and connect it to the Drone.
    RemoteControl* rc = init_remote_control(&drone, "John", "X1", 1.2);
    connect_to_drone(rc);

    // Take off the Drone and set its speed and battery level.
    takeoff(&drone);
    set_speed(&drone, 10);
    set_battery_level(&drone, 80);

    // Move the Drone forward and rotate it to the left.
    move_forward(&drone, 50);
    rotate_left(&drone, 45);

    // Hover the Drone and check its battery level and range.
    hover(&drone);
    low_battery_warning(&drone);
    out_of_range_warning(&drone);

    // Move the Drone to the right and backward.
    move_right(&drone, 30);
    move_backward(&drone, 20);

    // Rotate the Drone to the right and land it.
    rotate_right(&drone, 90);
    land(&drone);

    // Disconnect the Remote Control from the Drone.
    disconnect_from_drone(rc);
    free(rc);

    return 0;
}
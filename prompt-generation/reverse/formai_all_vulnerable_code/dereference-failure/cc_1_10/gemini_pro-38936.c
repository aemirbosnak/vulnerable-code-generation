//GEMINI-pro DATASET v1.0 Category: Traffic Flow Simulation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to represent a vehicle
typedef struct vehicle {
    int id;             // Vehicle ID
    int type;           // Vehicle type (0 for car, 1 for truck)
    int speed;          // Vehicle speed
    int position;       // Vehicle position on the road
    struct vehicle *next; // Pointer to the next vehicle in the linked list
} vehicle;

// Structure to represent a road
typedef struct road {
    int length;         // Length of the road
    int num_lanes;      // Number of lanes on the road
    struct vehicle *head; // Pointer to the head of the linked list of vehicles on the road
} road;

// Function to create a new vehicle
vehicle *create_vehicle(int id, int type, int speed, int position) {
    vehicle *new_vehicle = (vehicle *)malloc(sizeof(vehicle));
    new_vehicle->id = id;
    new_vehicle->type = type;
    new_vehicle->speed = speed;
    new_vehicle->position = position;
    new_vehicle->next = NULL;

    return new_vehicle;
}

// Function to create a new road
road *create_road(int length, int num_lanes) {
    road *new_road = (road *)malloc(sizeof(road));
    new_road->length = length;
    new_road->num_lanes = num_lanes;
    new_road->head = NULL;

    return new_road;
}

// Function to add a vehicle to the road
void add_vehicle(road *road, vehicle *new_vehicle) {
    // If the road is empty, add the vehicle to the head of the linked list
    if (road->head == NULL) {
        road->head = new_vehicle;
        return;
    }

    // If the road is not empty, find the appropriate position to insert the vehicle
    vehicle *current_vehicle = road->head;
    while (current_vehicle->next != NULL && current_vehicle->next->position <= new_vehicle->position) {
        current_vehicle = current_vehicle->next;
    }

    // Insert the vehicle into the linked list
    new_vehicle->next = current_vehicle->next;
    current_vehicle->next = new_vehicle;
}

// Function to remove a vehicle from the road
void remove_vehicle(road *road, vehicle *vehicle_to_remove) {
    // If the vehicle to remove is the head of the linked list, update the head pointer
    if (road->head == vehicle_to_remove) {
        road->head = vehicle_to_remove->next;
        free(vehicle_to_remove);
        return;
    }

    // If the vehicle to remove is not the head of the linked list, find the previous vehicle
    vehicle *current_vehicle = road->head;
    while (current_vehicle->next != vehicle_to_remove) {
        current_vehicle = current_vehicle->next;
    }

    // Remove the vehicle from the linked list
    current_vehicle->next = vehicle_to_remove->next;
    free(vehicle_to_remove);
}

// Function to update the position of all vehicles on the road
void update_positions(road *road) {
    vehicle *current_vehicle = road->head;

    while (current_vehicle != NULL) {
        // Update the vehicle's position
        current_vehicle->position += current_vehicle->speed;

        // If the vehicle has reached the end of the road, remove it from the linked list
        if (current_vehicle->position >= road->length) {
            remove_vehicle(road, current_vehicle);
        }

        // Move to the next vehicle in the linked list
        current_vehicle = current_vehicle->next;
    }
}

// Function to print the state of the road
void print_road(road *road) {
    vehicle *current_vehicle = road->head;

    while (current_vehicle != NULL) {
        printf("Vehicle %d (type %d) at position %d\n", current_vehicle->id, current_vehicle->type, current_vehicle->position);
        current_vehicle = current_vehicle->next;
    }
}

// Main function
int main() {
    // Create a new road
    road *road = create_road(1000, 3);

    // Create a new vehicle
    vehicle *vehicle1 = create_vehicle(1, 0, 50, 0);

    // Add the vehicle to the road
    add_vehicle(road, vehicle1);

    // Print the state of the road
    print_road(road);

    // Update the position of the vehicle
    update_positions(road);

    // Print the state of the road
    print_road(road);

    return 0;
}
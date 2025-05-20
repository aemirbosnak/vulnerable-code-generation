//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Location {
    double lat;
    double lng;
};

struct Node {
    struct Location location;
    struct Node* next;
};

// Function to add a new location to the linked list
void add_location(struct Node** head, struct Location location) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->location = location;
    new_node->next = *head;
    *head = new_node;
}

// Function to print the linked list of locations
void print_locations(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("Location: (%f, %f)\n", current->location.lat, current->location.lng);
        current = current->next;
    }
}

int main() {
    // Initialize the start location and destination location
    struct Location start_location = {52.5200, 13.4050};
    struct Location destination_location = {48.8566, 2.3522};

    // Initialize the linked list of locations for the GPS navigation simulation
    struct Node* locations_head = NULL;
    add_location(&locations_head, start_location);

    // Simulate GPS navigation by randomly generating new locations near the destination
    bool reached_destination = false;
    while (!reached_destination) {
        struct Location current_location = locations_head->location;
        double lat_diff = destination_location.lat - current_location.lat;
        double lng_diff = destination_location.lng - current_location.lng;

        // Generate a new location near the destination by randomly adding or subtracting from the current location
        double new_lat, new_lng;
        if (lat_diff < 0) {
            new_lat = current_location.lat - (rand() % 10) / 100.0;
        } else {
            new_lat = current_location.lat + (rand() % 10) / 100.0;
        }
        if (lng_diff < 0) {
            new_lng = current_location.lng - (rand() % 10) / 100.0;
        } else {
            new_lng = current_location.lng + (rand() % 10) / 100.0;
        }
        struct Location new_location = {new_lat, new_lng};
        add_location(&locations_head, new_location);

        // Check if the new location is close enough to the destination
        if (abs(new_lat - destination_location.lat) < 0.005 && abs(new_lng - destination_location.lng) < 0.005) {
            reached_destination = true;
        }
    }

    // Print the linked list of locations for the GPS navigation simulation
    print_locations(locations_head);

    return 0;
}
//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Define device types
typedef enum { LIGHT, FAN, AC, DOOR } device_type;

// Define device states
typedef enum { ON, OFF } device_state;

// Define a device struct
typedef struct {
    device_type type;
    char *name;
    device_state state;
} device;

// Define a linked list node for storing devices
typedef struct node {
    device *device;
    struct node *next;
} node;

// Define a linked list for storing devices
typedef struct {
    node *head;
    node *tail;
} linked_list;

// Initialize a device
device *init_device(device_type type, char *name, device_state state) {
    device *new_device = (device *)malloc(sizeof(device));
    new_device->type = type;
    new_device->name = strdup(name);
    new_device->state = state;
    return new_device;
}

// Initialize a linked list
linked_list *init_linked_list() {
    linked_list *new_list = (linked_list *)malloc(sizeof(linked_list));
    new_list->head = NULL;
    new_list->tail = NULL;
    return new_list;
}

// Add a device to a linked list
void add_device(linked_list *list, device *device) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->device = device;
    new_node->next = NULL;
    if (list->head == NULL) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
    }
}

// Get a device by name from a linked list
device *get_device_by_name(linked_list *list, char *name) {
    node *current_node = list->head;
    while (current_node != NULL) {
        if (strcmp(current_node->device->name, name) == 0) {
            return current_node->device;
        }
        current_node = current_node->next;
    }
    return NULL;
}

// Turn on a device
void turn_on_device(device *device) {
    device->state = ON;
    printf("%s turned on\n", device->name);
}

// Turn off a device
void turn_off_device(device *device) {
    device->state = OFF;
    printf("%s turned off\n", device->name);
}

// Toggle a device
void toggle_device(device *device) {
    if (device->state == ON) {
        turn_off_device(device);
    } else {
        turn_on_device(device);
    }
}

// Print the current state of all devices
void print_device_states(linked_list *list) {
    node *current_node = list->head;
    while (current_node != NULL) {
        printf("%s is ", current_node->device->name);
        if (current_node->device->state == ON) {
            printf("on\n");
        } else {
            printf("off\n");
        }
        current_node = current_node->next;
    }
}

// Main function
int main() {
    // Initialize a linked list of devices
    linked_list *devices = init_linked_list();

    // Add some devices to the linked list
    add_device(devices, init_device(LIGHT, "Living Room Light", OFF));
    add_device(devices, init_device(FAN, "Bedroom Fan", OFF));
    add_device(devices, init_device(AC, "Master Bedroom AC", OFF));
    add_device(devices, init_device(DOOR, "Front Door", OFF));

    // Get a device by name
    device *living_room_light = get_device_by_name(devices, "Living Room Light");

    // Turn on the living room light
    turn_on_device(living_room_light);

    // Print the current state of all devices
    print_device_states(devices);

    return 0;
}
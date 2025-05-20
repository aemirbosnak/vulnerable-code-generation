//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define the types of devices
typedef enum {
    DEVICE_TYPE_LIGHT,
    DEVICE_TYPE_THERMOSTAT,
    DEVICE_TYPE_DOOR_LOCK
} device_type_t;

// Define the states of devices
typedef enum {
    DEVICE_STATE_ON,
    DEVICE_STATE_OFF
} device_state_t;

// Define the structure of a device
typedef struct {
    char *name;
    device_type_t type;
    device_state_t state;
    // Other members can be added here, such as current temperature or brightness
} device_t;

// Define a linked list of devices
typedef struct device_list {
    device_t *device;
    struct device_list *next;
} device_list_t;

// Create a new device
device_t *create_device(char *name, device_type_t type) {
    device_t *device = malloc(sizeof(device_t));
    if (device == NULL) {
        return NULL;
    }

    device->name = strdup(name);
    if (device->name == NULL) {
        free(device);
        return NULL;
    }

    device->type = type;
    device->state = DEVICE_STATE_OFF;

    return device;
}

// Add a device to the linked list
void add_device(device_list_t **head, device_t *device) {
    device_list_t *new_node = malloc(sizeof(device_list_t));
    if (new_node == NULL) {
        return;
    }

    new_node->device = device;
    new_node->next = *head;

    *head = new_node;
}

// Find a device by name
device_t *find_device(device_list_t *head, char *name) {
    while (head != NULL) {
        if (strcmp(head->device->name, name) == 0) {
            return head->device;
        }

        head = head->next;
    }

    return NULL;
}

// Turn a device on or off
void set_device_state(device_t *device, device_state_t state) {
    device->state = state;
}

// Print the state of all devices
void print_devices(device_list_t *head) {
    while (head != NULL) {
        printf("%s: ", head->device->name);
        switch (head->device->type) {
            case DEVICE_TYPE_LIGHT:
                printf("Light");
                break;
            case DEVICE_TYPE_THERMOSTAT:
                printf("Thermostat");
                break;
            case DEVICE_TYPE_DOOR_LOCK:
                printf("Door Lock");
                break;
            default:
                printf("Unknown");
        }
        printf(" is ");
        switch (head->device->state) {
            case DEVICE_STATE_ON:
                printf("on\n");
                break;
            case DEVICE_STATE_OFF:
                printf("off\n");
                break;
            default:
                printf("in an unknown state\n");
        }

        head = head->next;
    }
}

// Main function
int main() {
    // Create a linked list of devices
    device_list_t *head = NULL;

    // Add some devices to the linked list
    device_t *kitchen_light = create_device("Kitchen Light", DEVICE_TYPE_LIGHT);
    add_device(&head, kitchen_light);

    device_t *living_room_light = create_device("Living Room Light", DEVICE_TYPE_LIGHT);
    add_device(&head, living_room_light);

    device_t *thermostat = create_device("Thermostat", DEVICE_TYPE_THERMOSTAT);
    add_device(&head, thermostat);

    device_t *front_door_lock = create_device("Front Door Lock", DEVICE_TYPE_DOOR_LOCK);
    add_device(&head, front_door_lock);

    // Print the state of all devices
    print_devices(head);

    // Turn on the kitchen light
    set_device_state(kitchen_light, DEVICE_STATE_ON);

    // Set the thermostat to 72 degrees
    // (This would normally be done through a thermostat interface, but for simplicity we just set it directly here)
    thermostat->state = 72;

    // Print the state of all devices again
    print_devices(head);

    // Clean up
    while (head != NULL) {
        device_list_t *next = head->next;
        free(head->device->name);
        free(head->device);
        free(head);
        head = next;
    }

    return 0;
}
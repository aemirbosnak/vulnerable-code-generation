//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

// Struct for Baggage
typedef struct {
    int id; // Baggage ID
    int weight; // Baggage weight in kgs
} Baggage;

// Struct for Conveyor Belt
typedef struct {
    Baggage** baggage_list; // List of Baggage
    int length; // Conveyor Belt's length in meters
    int capacity; // Maximum number of Baggage that can be present on the conveyor belt at a time
    int count; // Number of Baggage currently on the conveyor belt
} ConveyorBelt;

// Struct for Destination
typedef struct {
    char* location; // Destination location
    int max_weight; // Maximum weight of Baggage allowed at the destination
} Destination;

// Function prototypes
void add_baggage(ConveyorBelt* cb, Baggage* bag);
void remove_baggage(ConveyorBelt* cb, Baggage* bag);
void transfer_baggage(ConveyorBelt* cb1, ConveyorBelt* cb2);
bool send_baggage(ConveyorBelt* cb, Destination* dest);
void print_baggage_list(ConveyorBelt* cb);
void print_destination_info(Destination* dest);

int main() {
    // Create a conveyor belt with length of 10 meters and max capacity of 5 baggage
    ConveyorBelt cb1 = {
        .baggage_list = malloc(5 * sizeof(Baggage)),
        .length = 10,
        .capacity = 5,
        .count = 0
    };
    assert(cb1.baggage_list);

    // Create another conveyor belt with length of 5 meters and max capacity of 3 baggage
    ConveyorBelt cb2 = {
        .baggage_list = malloc(3 * sizeof(Baggage)),
        .length = 5,
        .capacity = 3,
        .count = 0
    };
    assert(cb2.baggage_list);

    // Create a Destination
    Destination dest = {
        .location = "Paris",
        .max_weight = 50
    };

    // Add some baggage to the conveyor belt cb1
    Baggage bag1 = {
        .id = 1,
        .weight = 15
    };
    add_baggage(&cb1, &bag1);

    Baggage bag2 = {
        .id = 2,
        .weight = 20
    };
    add_baggage(&cb1, &bag2);

    Baggage bag3 = {
        .id = 3,
        .weight = 10
    };
    add_baggage(&cb1, &bag3);

    printf("Initial Conveyor Belt 1:\n");
    print_baggage_list(&cb1);

    printf("\n");

    // Transfer two baggage from cb1 to cb2
    transfer_baggage(&cb1, &cb2);

    printf("Conveyor Belt 1 after transfer:\n");
    print_baggage_list(&cb1);

    printf("\n");

    printf("Conveyor Belt 2 after transfer:\n");
    print_baggage_list(&cb2);

    printf("\n");

    // Send a baggage to the destination
    send_baggage(&cb1, &dest);

    printf("Conveyor Belt 1 after sending a baggage to Paris:\n");
    print_baggage_list(&cb1);

    printf("\n");

    // Print the Destination info
    print_destination_info(&dest);

    // Free the memory
    free(cb1.baggage_list);
    free(cb2.baggage_list);
    cb1.baggage_list = NULL;
    cb2.baggage_list = NULL;

    return 0;
}

// Function to add a baggage to the conveyor belt
void add_baggage(ConveyorBelt* cb, Baggage* bag) {
    assert(cb && bag);

    // Check if the conveyor belt is not already full
    if (cb->count < cb->capacity) {
        cb->baggage_list[cb->count++] = bag;
    }
}

// Function to remove a baggage from the conveyor belt
void remove_baggage(ConveyorBelt* cb, Baggage* bag) {
    assert(cb && bag);

    int i, j;

    // Find the baggage index in the baggage list
    for (i=0; i<cb->count; i++) {
        if (cb->baggage_list[i] == bag) {
            break;
        }
    }

    assert(i < cb->count);

    // Remove the baggage from the list
    for (j=i; j<cb->count-1; j++) {
        cb->baggage_list[j] = cb->baggage_list[j+1];
    }

    cb->count--;
}

// Function to transfer baggage from cb1 to cb2
void transfer_baggage(ConveyorBelt* cb1, ConveyorBelt* cb2) {
    assert(cb1 && cb2);

    int i, j=0;

    // Transfer the baggage from cb1 to cb2
    for (i=0; i<cb1->count; i++) {
        if (cb2->count < cb2->capacity) {
            cb2->baggage_list[cb2->count++] = cb1->baggage_list[i];
            j++;
        } else {
            break;
        }
    }

    // Remove the transferred baggage from cb1
    for (i=0; i<j; i++) {
        remove_baggage(cb1, cb2->baggage_list[cb2->count-i-1]);
    }
}

// Function to send a baggage to the destination
bool send_baggage(ConveyorBelt* cb, Destination* dest) {
    assert(cb && dest);

    int i;

    // Find a baggage that can be sent to the destination
    for (i=0; i<cb->count; i++) {
        if (cb->baggage_list[i]->weight <= dest->max_weight) {
            remove_baggage(cb, cb->baggage_list[i]);
            return true;
        }
    }

    return false;
}

// Function to print the list of baggage on a conveyor belt
void print_baggage_list(ConveyorBelt* cb) {
    assert(cb);

    printf("Conveyor Belt length: %d meters\n", cb->length);
    printf("Max capacity: %d baggage\n", cb->capacity);
    printf("Current count: %d baggage\n", cb->count);

    printf("\nBaggage List:\n");

    int i;
    for (i=0; i<cb->count; i++) {
        printf("Baggage ID: %d, Weight: %d kgs\n", cb->baggage_list[i]->id, cb->baggage_list[i]->weight);
    }
}

// Function to print the destination info
void print_destination_info(Destination* dest) {
    assert(dest);

    printf("Destination Info:\n");
    printf("Location: %s\n", dest->location);
    printf("Max Weight: %d kgs\n", dest->max_weight);
}
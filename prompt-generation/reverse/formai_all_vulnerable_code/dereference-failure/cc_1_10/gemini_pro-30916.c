//GEMINI-pro DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the baggage types
#define BAGGAGE_TYPE_SMALL 0
#define BAGGAGE_TYPE_MEDIUM 1
#define BAGGAGE_TYPE_LARGE 2

// Define the baggage status
#define BAGGAGE_STATUS_UNLOADED 0
#define BAGGAGE_STATUS_LOADED 1
#define BAGGAGE_STATUS_DELIVERED 2

// Define the baggage handling system
typedef struct {
    int type;
    int status;
    int weight;
} baggage_t;

typedef struct {
    int num_baggage;
    baggage_t *baggage;
} baggage_handler_t;

// Create a new baggage handling system
baggage_handler_t *baggage_handler_create() {
    baggage_handler_t *baggage_handler = malloc(sizeof(baggage_handler_t));
    baggage_handler->num_baggage = 0;
    baggage_handler->baggage = NULL;
    return baggage_handler;
}

// Destroy a baggage handling system
void baggage_handler_destroy(baggage_handler_t *baggage_handler) {
    free(baggage_handler->baggage);
    free(baggage_handler);
}

// Add a new baggage to the system
void baggage_handler_add_baggage(baggage_handler_t *baggage_handler, baggage_t baggage) {
    baggage_handler->num_baggage++;
    baggage_handler->baggage = realloc(baggage_handler->baggage, sizeof(baggage_t) * baggage_handler->num_baggage);
    baggage_handler->baggage[baggage_handler->num_baggage - 1] = baggage;
}

// Load baggage onto a cart
void baggage_handler_load_cart(baggage_handler_t *baggage_handler, int cart_id) {
    for (int i = 0; i < baggage_handler->num_baggage; i++) {
        if (baggage_handler->baggage[i].status == BAGGAGE_STATUS_UNLOADED) {
            baggage_handler->baggage[i].status = BAGGAGE_STATUS_LOADED;
            printf("Loaded baggage %d onto cart %d\n", baggage_handler->baggage[i].type, cart_id);
        }
    }
}

// Deliver baggage to a destination
void baggage_handler_deliver_baggage(baggage_handler_t *baggage_handler, int destination_id) {
    for (int i = 0; i < baggage_handler->num_baggage; i++) {
        if (baggage_handler->baggage[i].status == BAGGAGE_STATUS_LOADED) {
            baggage_handler->baggage[i].status = BAGGAGE_STATUS_DELIVERED;
            printf("Delivered baggage %d to destination %d\n", baggage_handler->baggage[i].type, destination_id);
        }
    }
}

// Main function
int main() {
    // Create a new baggage handling system
    baggage_handler_t *baggage_handler = baggage_handler_create();

    // Add some baggage to the system
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        baggage_t baggage;
        baggage.type = rand() % 3;
        baggage.status = BAGGAGE_STATUS_UNLOADED;
        baggage.weight = rand() % 100;
        baggage_handler_add_baggage(baggage_handler, baggage);
    }

    // Load the baggage onto a cart
    baggage_handler_load_cart(baggage_handler, 1);

    // Deliver the baggage to a destination
    baggage_handler_deliver_baggage(baggage_handler, 2);

    // Destroy the baggage handling system
    baggage_handler_destroy(baggage_handler);

    return 0;
}
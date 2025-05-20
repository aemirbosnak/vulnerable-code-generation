//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of baggage pieces
#define MAX_BAGGAGE 1000

// Define the maximum weight of each baggage piece
#define MAX_WEIGHT 30

// Define the maximum time it takes to transfer baggage
#define MAX_TRANSFER_TIME 10

// Define the maximum time it takes to load the plane
#define MAX_LOAD_TIME 120

// Define the maximum number of baggage handlers
#define MAX_HANDLERS 10

// Define the capacity of each baggage cart
#define CART_CAPACITY 100

// Define the time it takes to transfer one piece of baggage
#define TRANSFER_TIME 2

// Define the time it takes to load one piece of baggage into the plane
#define LOAD_TIME 3

// Define the baggage struct
typedef struct {
    int weight;
} baggage;

// Define the cart struct
typedef struct {
    baggage **baggage_list;
    int num_baggage;
    int total_weight;
} cart;

// Define the handler struct
typedef struct {
    cart *current_cart;
    int current_time;
} handler;

// Define the function to add baggage to a cart
void add_baggage(cart *c, baggage *b) {
    if (c->num_baggage < CART_CAPACITY) {
        c->baggage_list[c->num_baggage++] = b;
        c->total_weight += b->weight;
    }
}

// Define the function to create a new baggage
baggage *new_baggage() {
    baggage *b = malloc(sizeof(baggage));
    b->weight = rand() % MAX_WEIGHT + 1;
    return b;
}

// Define the function to create a new cart
cart *new_cart() {
    cart *c = malloc(sizeof(cart));
    c->baggage_list = malloc(sizeof(baggage *) * CART_CAPACITY);
    c->num_baggage = 0;
    c->total_weight = 0;
    return c;
}

// Define the function to create a new handler
handler *new_handler() {
    handler *h = malloc(sizeof(handler));
    h->current_cart = NULL;
    h->current_time = 0;
    return h;
}

// Define the main function
int main() {
    srand(time(NULL));

    int num_baggage = rand() % MAX_BAGGAGE + 1;
    baggage **baggage_list = malloc(sizeof(baggage *) * num_baggage);

    int i;
    for (i = 0; i < num_baggage; i++) {
        baggage_list[i] = new_baggage();
    }

    cart **cart_list = malloc(sizeof(cart *) * (num_baggage / CART_CAPACITY + 1));
    int num_carts = 1;

    cart_list[0] = new_cart();

    for (i = 0; i < num_baggage; i++) {
        if (cart_list[num_carts - 1]->num_baggage == CART_CAPACITY) {
            cart_list[num_carts++] = new_cart();
        }
        add_baggage(cart_list[num_carts - 1], baggage_list[i]);
    }

    handler **handler_list = malloc(sizeof(handler *) * MAX_HANDLERS);
    int num_handlers = rand() % MAX_HANDLERS + 1;

    for (i = 0; i < num_handlers; i++) {
        handler_list[i] = new_handler();
    }

    int current_time = 0;

    while (1) {
        // Check if all baggage has been loaded on the plane
        int all_loaded = 1;
        for (i = 0; i < num_carts; i++) {
            if (cart_list[i]->num_baggage != 0) {
                all_loaded = 0;
                break;
            }
        }
        if (all_loaded) {
            printf("All baggage has been loaded onto the plane in %d minutes.\n", current_time);
            break;
        }

        // Check if there is a handler available to transfer baggage
        int handler_index = -1;
        for (i = 0; i < num_handlers; i++) {
            if (handler_list[i]->current_time <= current_time) {
                handler_index = i;
                break;
            }
        }

        if (handler_index != -1) {
            // If a handler is available, find a cart with baggage
            int cart_index = -1;
            for (i = 0; i < num_carts; i++) {
                if (cart_list[i]->num_baggage != 0) {
                    cart_index = i;
                    break;
                }
            }
            if (cart_index != -1) {
                // If a cart with baggage is found, transfer one piece of baggage
                baggage *b = cart_list[cart_index]->baggage_list[0];
                cart_list[cart_index]->num_baggage--;
                cart_list[cart_index]->total_weight -= b->weight;
                handler_list[handler_index]->current_cart = cart_list[cart_index];
                handler_list[handler_index]->current_time = current_time + TRANSFER_TIME;
            }
        }

        // Check if there is a handler available to load the plane
        handler_index = -1;
        for (i = 0; i < num_handlers; i++) {
            if (handler_list[i]->current_time <= current_time) {
                handler_index = i;
                break;
            }
        }

        if (handler_index != -1) {
            // If a handler is available, load one piece of baggage onto the plane
            for (i = 0; i < num_carts; i++) {
                if (cart_list[i]->num_baggage != 0) {
                    handler_list[handler_index]->current_cart = cart_list[i];
                    handler_list[handler_index]->current_time = current_time + LOAD_TIME;
                    cart_list[i]->num_baggage--;
                    cart_list[i]->total_weight -= cart_list[i]->baggage_list[0]->weight;
                    break;
                }
            }
        }

        current_time++;

        // Sleep for a short period of time to simulate real time
        int delay = rand() % MAX_TRANSFER_TIME + 1;
        usleep(delay * 1000);
    }

    // Free memory allocated for baggage, carts, and handlers
    for (i = 0; i < num_baggage; i++) {
        free(baggage_list[i]);
    }

    for (i = 0; i < num_carts; i++) {
        free(cart_list[i]->baggage_list);
        free(cart_list[i]);
    }

    for (i = 0; i < num_handlers; i++) {
        free(handler_list[i]);
    }

    free(baggage_list);
    free(cart_list);
    free(handler_list);

    return 0;
}
//LLAMA2-13B DATASET v1.0 Category: Networking ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define NETWORK_NODES 10
#define MAX_DATA_LEN 1024

typedef struct node_t {
    int id;
    char data[MAX_DATA_LEN];
    struct node_t* next;
} node_t;

node_t* create_network(void) {
    node_t* head = NULL;
    for (int i = 0; i < NETWORK_NODES; i++) {
        node_t* new_node = malloc(sizeof(node_t));
        new_node->id = i;
        new_node->data[0] = 'A' + (i % 2) * 2;
        new_node->next = head;
        head = new_node;
    }
    return head;
}

void transmit_data(node_t* source, node_t* destination, char* data) {
    node_t* current = source;
    while (current != destination) {
        if (current->next != NULL) {
            current = current->next;
        } else {
            current = destination;
        }
    }
    strcat(current->data, data);
}

int main(void) {
    srand(time(NULL));
    node_t* network = create_network();
    char data[] = "Hello, World!";

    // Transmit data through the network
    transmit_data(network, network, data);

    // Print the received data at each node
    node_t* current = network;
    while (current != NULL) {
        printf("%d: %s\n", current->id, current->data);
        current = current->next;
    }

    return 0;
}
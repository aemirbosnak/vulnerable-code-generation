//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: complex
// Complex C Circuit Simulator
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define complex number struct
struct complex {
    double real;
    double imag;
};

// Define complex addition
struct complex add(struct complex a, struct complex b) {
    struct complex result;
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
    return result;
}

// Define complex multiplication
struct complex multiply(struct complex a, struct complex b) {
    struct complex result;
    result.real = (a.real * b.real) - (a.imag * b.imag);
    result.imag = (a.real * b.imag) + (a.imag * b.real);
    return result;
}

// Define node struct
struct node {
    int id;
    struct complex voltage;
    struct complex current;
    struct node *next;
};

// Define circuit struct
struct circuit {
    int num_nodes;
    struct node *head;
};

int main() {
    // Create circuit with 3 nodes
    struct circuit my_circuit;
    my_circuit.num_nodes = 3;

    // Create individual nodes and connect them
    struct node *node1 = malloc(sizeof(struct node));
    struct node *node2 = malloc(sizeof(struct node));
    struct node *node3 = malloc(sizeof(struct node));
    node1->id = 1;
    node2->id = 2;
    node3->id = 3;
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;
    my_circuit.head = node1;

    // Set voltage values and run simulation for 1 second
    double time = 0;
    double time_step = 0.1;
    while (time < 1) {
        node1->voltage.real = 10 * sin(time);
        node1->voltage.imag = 5 * cos(time);
        node2->voltage.real = 5 * sin(time);
        node2->voltage.imag = 10 * cos(time);
        node3->voltage.real = 0;
        node3->voltage.imag = 0;
        struct node *curr_node = my_circuit.head;
        while (curr_node != NULL) {
            // Calculate total current flowing into node
            struct complex total_current;
            total_current.real = 0;
            total_current.imag = 0;
            struct node *curr_node2 = my_circuit.head;
            while (curr_node2 != NULL) {
                if (curr_node2->id != curr_node->id) {
                    struct complex voltage_diff = add(curr_node->voltage, multiply(curr_node2->voltage, (struct complex) { -1, 0 }));
                    double resistance = pow(curr_node->id + curr_node2->id, 2);
                    struct complex current = { voltage_diff.real / resistance, voltage_diff.imag / resistance };
                    total_current = add(total_current, current);
                }
                curr_node2 = curr_node2->next;
            }
            curr_node->current = total_current;
            curr_node = curr_node->next;
        }
        time += time_step;
    }

    // Print final node voltages and currents
    struct node *curr_node = my_circuit.head;
    while (curr_node != NULL) {
        printf("Node %d: Voltage (%f + %fi), Current (%f + %fi)\n", curr_node->id, curr_node->voltage.real, curr_node->voltage.imag, curr_node->current.real, curr_node->current.imag);
        curr_node = curr_node->next;
    }

    return 0;
}
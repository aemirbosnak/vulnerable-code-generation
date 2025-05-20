//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: genious
#include <stdio.h>
#include <stdlib.h>

// define maximum number of nodes
#define MAX_NODES 100

// node structure
struct node {
    int id;
    double voltage;
    double current;
};

// resistor structure
struct resistor {
    struct node *a;
    struct node *b;
    double resistance;
};

// main function
int main() {
    int num_nodes, num_resistors;
    printf("Enter the number of nodes: ");
    scanf("%d", &num_nodes);
    printf("Enter the number of resistors: ");
    scanf("%d", &num_resistors);

    // create an array of nodes
    struct node *nodes = malloc(num_nodes * sizeof(struct node));

    // initialize nodes
    for (int i = 0; i < num_nodes; i++) {
        nodes[i].id = i+1;
        nodes[i].voltage = 0.0;
        nodes[i].current = 0.0;
    }

    // create an array of resistors
    struct resistor *resistors = malloc(num_resistors * sizeof(struct resistor));

    // initialize resistors
    for (int i = 0; i < num_resistors; i++) {
        printf("Enter the two nodes that the resistor is connected to (separated by a space): ");
        int node_a, node_b;
        scanf("%d %d", &node_a, &node_b);
        resistors[i].a = &nodes[node_a-1];
        resistors[i].b = &nodes[node_b-1];
        printf("Enter the resistance of the resistor: ");
        scanf("%lf", &resistors[i].resistance);
    }

    // print initial voltages and currents
    printf("\nInitial node voltages:\n");
    for (int i = 0; i < num_nodes; i++) {
        printf("Node %d: %.2lfV\n", nodes[i].id, nodes[i].voltage);
    }
    printf("\nInitial resistor currents:\n");
    for (int i = 0; i < num_resistors; i++) {
        printf("Resistor %d: %.2lfA\n", i+1, (resistors[i].a->voltage - resistors[i].b->voltage) / resistors[i].resistance);
    }

    // simulation loop
    int num_iterations;
    printf("\nEnter the number of simulation iterations: ");
    scanf("%d", &num_iterations);
    printf("\n");
    for (int iter = 0; iter < num_iterations; iter++) {
        for (int i = 0; i < num_resistors; i++) {
            double current = (resistors[i].a->voltage - resistors[i].b->voltage) / resistors[i].resistance;
            resistors[i].a->current -= current;
            resistors[i].b->current += current;
        }
        for (int i = 0; i < num_nodes; i++) {
            nodes[i].voltage += nodes[i].current;
            nodes[i].current = 0.0;
        }
        // print node voltages and resistor currents
        printf("Iteration %d:\n", iter+1);
        printf("Node voltages:\n");
        for (int i = 0; i < num_nodes; i++) {
            printf("Node %d: %.2lfV\n", nodes[i].id, nodes[i].voltage);
        }
        printf("\nResistor currents:\n");
        for (int i = 0; i < num_resistors; i++) {
            printf("Resistor %d: %.2lfA\n", i+1, (resistors[i].a->voltage - resistors[i].b->voltage) / resistors[i].resistance);
        }
        printf("\n");
    }

    // free memory
    free(nodes);
    free(resistors);

    return 0;
}
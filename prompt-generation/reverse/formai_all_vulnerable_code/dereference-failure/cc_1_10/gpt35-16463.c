//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: creative
#include <stdio.h>

typedef struct Resistor {
    double resistance;
} Resistor;

typedef struct Node {
    int id;
    Resistor *resistors[12];
} Node;

typedef struct Circuit {
    Node nodes[30];
    int num_nodes;
} Circuit;

void add_resistor_to_node(Node *node, Resistor *resistor) {
    for(int i = 0; i < 12; i++) {
        if(!node->resistors[i]) {
            node->resistors[i] = resistor;
            break;
        }
    }
}

void add_node_to_circuit(Circuit *circuit, Node *node) {
    circuit->nodes[circuit->num_nodes] = *node;
    circuit->num_nodes++;
}

int main() {
    Resistor *resistor1 = (Resistor *) malloc(sizeof(Resistor));
    resistor1->resistance = 100;

    Resistor *resistor2 = (Resistor *) malloc(sizeof(Resistor));
    resistor2->resistance = 200;

    Node node1 = { .id = 1 };
    add_resistor_to_node(&node1, resistor1);
    add_resistor_to_node(&node1, resistor2);

    Resistor *resistor3 = (Resistor *) malloc(sizeof(Resistor));
    resistor3->resistance = 300;

    Resistor *resistor4 = (Resistor *) malloc(sizeof(Resistor));
    resistor4->resistance = 400;

    Node node2 = { .id = 2 };
    add_resistor_to_node(&node2, resistor3);
    add_resistor_to_node(&node2, resistor4);

    Circuit circuit = { .num_nodes = 0 };
    add_node_to_circuit(&circuit, &node1);
    add_node_to_circuit(&circuit, &node2);

    printf("Circuit with %d nodes\n", circuit.num_nodes);
    for (int i = 0; i < circuit.num_nodes; i++) {
        Node node = circuit.nodes[i];
        printf("Node %d has %d resistors\n", node.id, (int)(sizeof(node.resistors)/sizeof(node.resistors[0])));
        for (int j = 0; j < 12; j++) {
            if (node.resistors[j] != NULL) {
                printf("  Resistor %d has resistance %f\n", j, node.resistors[j]->resistance);
            }
        }
    }
    return 0;
}
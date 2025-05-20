//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: relaxed
// A Classical Circuit Simulator Example Program in C

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_NODES 1000
#define MAX_VAL 2147483647

typedef struct compParams compParams;
typedef struct Circuit_Node Circuit_Node;

// structure to store component parameters
struct compParams {
    double value;
    double phase;
};

// structure to store circuit node details
struct Circuit_Node {
    char name[20];
    double voltage, current;
    int visited;
    int num_elements;
    compParams elements[10];
};

int num_nodes = 0;
Circuit_Node* Node_Array[MAX_NODES];
double Epsilon = 0.000001;
double Time_Step = 0.00001;
double Stop_Time = 0.1;

// function to create a new circuit node
Circuit_Node* create_node(char* node_name) {
    Circuit_Node* node = (Circuit_Node*)malloc(sizeof(Circuit_Node));
    node->num_elements = 0;
    node->voltage = node->current = 0;
    node->visited = 0;
    strcpy(node->name, node_name);
    Node_Array[num_nodes++] = node;
    return node;
}

// function to add component to a node
void add_element(Circuit_Node* node, char element_type, double element_val) {
    compParams c = {};
    c.value = element_val;
    switch (element_type) {
        case 'R': c.phase = 0;
                  break;
        case 'C': c.phase = - M_PI_2;
                  break;
        case 'L': c.phase = M_PI_2;
                  break;
        default: fprintf(stderr, "Invalid Element Type!");
                 exit(1);
    }
    node->elements[node->num_elements++] = c;
}

// function to get node by name
Circuit_Node* get_node(char* node_name) {
    int i;
    for (i = 0; i < num_nodes; i++) {
        if (strcmp(Node_Array[i]->name, node_name) == 0) {
            return Node_Array[i];
        }
    }
    return NULL;
}

// function to simulate circuit for given time
void simulate(double time) {
    int i, j, k, n;
    double delta_t = Time_Step;
    int steps = time / delta_t;
    for (j = 0; j < steps; j++) {
        // reset node voltages and visited flags
        for (i = 0; i < num_nodes; i++) {
            Node_Array[i]->voltage = Node_Array[i]->current = 0;
            Node_Array[i]->visited = 0;
        }
        // calculate voltages for each node
        for (i = 0; i < num_nodes; i++) {
            Circuit_Node* node = Node_Array[i];
            double voltage = 0;
            for (k = 0; k < node->num_elements; k++) {
                compParams el = node->elements[k];
                voltage += el.value * sin(el.phase - node->current);
            }
            node->voltage = voltage;
        }
        // update currents for each node
        for (i = 0; i < num_nodes; i++) {
            Circuit_Node* node = Node_Array[i];
            double current = 0;
            for (n = 0; n < num_nodes; n++) {
                Circuit_Node* neighbor = Node_Array[n];
                if (neighbor == node) continue;
                double V = node->voltage - neighbor->voltage;
                for (k = 0; k < neighbor->num_elements; k++) {
                    compParams el = neighbor->elements[k];
                    current += el.value * sin(el.phase - V);
                }
            }
            current /= node->elements[0].value;
            node->current = current;
        }
        // print node voltages and currents
        printf("Time = %.6lf\n", (j + 1) * delta_t);
        for (i = 0; i < num_nodes; i++) {
            Circuit_Node* node = Node_Array[i];
            printf("%s: V = %.6lf, I = %.6lf\n", node->name, node->voltage, node->current);
        }
        printf("\n");
    }
}

int main() {
    // create circuit with 3 nodes and components
    Circuit_Node* node_A = create_node("A");
    add_element(node_A, 'R', 10.0);
    add_element(node_A, 'C', 0.000001);
    Circuit_Node* node_B = create_node("B");
    add_element(node_B, 'R', 5.0);
    Circuit_Node* node_C = create_node("C");
    add_element(node_C, 'L', 0.00001);
    add_element(node_C, 'R', 7.0);
    // simulate circuit for 0.1 seconds
    simulate(Stop_Time);
    return 0;
}
//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: portable
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX_NODES 100
#define MAX_ELEMENTS 1000
#define EPSILON 1e-6

struct node{
    int index;
    double voltage;
};

struct element{
    int node1;
    int node2;
    double resistance;
};

struct circuit{
    int num_nodes;
    int num_elements;
    struct node *nodes;
    struct element *elements;
};

void create_circuit(struct circuit *circuit){
    circuit->num_nodes = 0;
    circuit->num_elements = 0;
    circuit->nodes = (struct node*)malloc(MAX_NODES*sizeof(struct node));
    circuit->elements = (struct element*)malloc(MAX_ELEMENTS*sizeof(struct element));
}

void add_node(struct circuit *circuit, int index, double voltage){
    struct node *node = &circuit->nodes[circuit->num_nodes];
    node->index = index;
    node->voltage = voltage;
    circuit->num_nodes++;
}

void add_element(struct circuit *circuit, int node1, int node2, double resistance){
    struct element *element = &circuit->elements[circuit->num_elements];
    element->node1 = node1;
    element->node2 = node2;
    element->resistance = resistance;
    circuit->num_elements++;
}

void calculate_voltages(struct circuit *circuit){
    int i,j;
    for(i=0;i<circuit->num_nodes;i++){
        circuit->nodes[i].voltage = 0;
    }
    for(i=0;i<circuit->num_elements;i++){
        int node1 = circuit->elements[i].node1;
        int node2 = circuit->elements[i].node2;
        double resistance = circuit->elements[i].resistance;
        double current = (circuit->nodes[node2].voltage - circuit->nodes[node1].voltage)/resistance;
        circuit->nodes[node1].voltage -= current*resistance;
        circuit->nodes[node2].voltage += current*resistance;
    }
}

int main(){
    struct circuit circuit;
    create_circuit(&circuit);
    add_node(&circuit, 0, 5);
    add_node(&circuit, 1, 0);
    add_element(&circuit, 0, 1, 10);
    calculate_voltages(&circuit);
    printf("Node 0 voltage: %f\n", circuit.nodes[0].voltage);
    printf("Node 1 voltage: %f\n", circuit.nodes[1].voltage);
    return 0;
}
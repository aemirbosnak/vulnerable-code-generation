//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_COMPONENTS 100
#define MAX_NODES 1000
#define MAX_LINKS 1000
#define MAX_STEPS 1000

typedef struct {
    char name[20];
    double value;
    int type;
} Component;

typedef struct {
    int num;
    int type;
    int node1;
    int node2;
} Link;

typedef struct {
    int num;
    double value;
} Node;

int num_components = 0;
int num_nodes = 0;
int num_links = 0;
int num_steps = 0;

Component *components = NULL;
Node *nodes = NULL;
Link *links = NULL;

void add_component(char *name, double value, int type) {
    Component *c = (Component *) malloc(sizeof(Component));
    strcpy(c->name, name);
    c->value = value;
    c->type = type;
    components[num_components++] = *c;
}

void add_node(int num, double value) {
    Node *n = (Node *) malloc(sizeof(Node));
    n->num = num;
    n->value = value;
    nodes[num_nodes++] = *n;
}

void add_link(int num, int type, int node1, int node2) {
    Link *l = (Link *) malloc(sizeof(Link));
    l->num = num;
    l->type = type;
    l->node1 = node1;
    l->node2 = node2;
    links[num_links++] = *l;
}

void run_simulation(int steps) {
    for (int i = 0; i < steps; i++) {
        // Update node values based on component values and link types
        for (int j = 0; j < num_nodes; j++) {
            double sum = 0;
            for (int k = 0; k < num_links; k++) {
                if (links[k].node1 == j || links[k].node2 == j) {
                    sum += components[links[k].type - 1].value;
                }
            }
            nodes[j].value = sum;
        }
    }
}

int main() {
    add_component("Resistor", 1000, 1);
    add_component("Capacitor", 1, 2);
    add_component("Inductor", 1, 3);

    add_node(1, 5);
    add_node(2, 0);

    add_link(1, 1, 1, 2);

    num_steps = 10;
    run_simulation(num_steps);

    // Print results
    for (int i = 0; i < num_nodes; i++) {
        printf("%s: %.2f\n", nodes[i].num == 1? "V1" : "V2", nodes[i].value);
    }

    return 0;
}
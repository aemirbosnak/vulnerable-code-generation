//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

/* Define resistors and capacitors */
typedef struct component {
    char name[10];
    double value;
    char type[3];
} Component;

/* Define node structure */
typedef struct node {
    int name;
    double voltage;
    int visited;
    Component *component;
} Node;

/* Define edge structure */
typedef struct edge {
    Node *node1;
    Node *node2;
} Edge;

/* Define circuit structure */
typedef struct circuit {
    Node *nodes[100];
    Edge *edges[100];
    int num_nodes, num_edges;
} Circuit;

/* Initialize the circuit */
void init_circuit(Circuit *c) {
    c->num_nodes = 0;
    c->num_edges = 0;
}

/* Find node based on name */
Node *find_node(Circuit *c, int name) {
    for(int i = 0; i < c->num_nodes; i++) {
        if(c->nodes[i]->name == name) {
            return c->nodes[i];
        }
    }
    return NULL;
}

/* Add resistor */
void add_resistor(Circuit *c, char name[10], double value, int node1, int node2) {
    Component *r = (Component *) malloc(sizeof(Component));
    r->value = value;
    r->type[0] = 'R';
    r->type[1] = '\0';
    for(int i = 0; i < 10; i++) {
        r->name[i] = name[i];
    }
    Edge *e = (Edge *) malloc(sizeof(Edge));
    e->node1 = find_node(c, node1);
    e->node2 = find_node(c, node2);
    e->node1->component = r;
    e->node2->component = r;
    c->edges[c->num_edges] = e;
    c->num_edges++;
}

/* Add capacitor */
void add_capacitor(Circuit *c, char name[10], double value, int node1, int node2) {
    Component *cap = (Component *) malloc(sizeof(Component));
    cap->value = value;
    cap->type[0] = 'C';
    cap->type[1] = '\0';
    for(int i = 0; i < 10; i++) {
        cap->name[i] = name[i];
    }
    Edge *e = (Edge *) malloc(sizeof(Edge));
    e->node1 = find_node(c, node1);
    e->node2 = find_node(c, node2);
    e->node1->component = cap;
    e->node2->component = cap;
    c->edges[c->num_edges] = e;
    c->num_edges++;
}

/* Add node */
void add_node(Circuit *c, int name) {
    Node *n = (Node *) malloc(sizeof(Node));
    n->name = name;
    n->component = NULL;
    n->voltage = 0;
    n->visited = 0;
    c->nodes[c->num_nodes] = n;
    c->num_nodes++;
}

/* Simulate circuit */
void simulate(Circuit *c, double time, double step) {
    double t = 0;
    while(t <= time) {
        for(int i = 0; i < c->num_nodes; i++) {
            c->nodes[i]->visited = 0;
        }

        for(int i = 0; i < c->num_edges; i++) {
            Edge *e = c->edges[i];
            Node *n1 = e->node1;
            Node *n2 = e->node2;

            if(n1->visited == 0 && n2->visited == 0) {
                n1->voltage = 0;
                n2->voltage = 0;
            }

            if(n1->visited == 0) {
                n1->visited = 1;
                if(n1->component != NULL && n1->component->type[0] == 'R') {
                    n1->voltage += (n2->voltage - n1->voltage) * (n1->component->value / (n1->component->value + n2->component->value)) * (step / n1->component->value);
                }
                if(n1->component != NULL && n1->component->type[0] == 'C') {
                    n1->voltage += (n2->voltage - n1->voltage) * (n1->component->value / (n1->component->value + n2->component->value)) * (step / n1->component->value);
                }
            }

            if(n2->visited == 0) {
                n2->visited = 1;
                if(n2->component != NULL && n2->component->type[0] == 'R') {
                    n2->voltage += (n1->voltage - n2->voltage) * (n2->component->value / (n2->component->value + n1->component->value)) * (step / n2->component->value);
                }
                if(n2->component != NULL && n2->component->type[0] == 'C') {
                    n2->voltage += (n1->voltage - n2->voltage) * (n2->component->value / (n2->component->value + n1->component->value)) * (step / n2->component->value);
                }
            }
        }

        printf("Time: %lf\n", t);
        for(int i = 0; i < c->num_nodes; i++) {
            printf("Node %d: %lf\n", c->nodes[i]->name, c->nodes[i]->voltage);
        }
        printf("\n");

        t += step;
    }
}

/* Main function */
int main() {
    Circuit c;
    init_circuit(&c);

    /* Add nodes */
    add_node(&c, 1);
    add_node(&c, 2);

    /* Add resistors and capacitors */
    add_resistor(&c, "R1", 10, 1, 2);
    add_capacitor(&c, "C1", 0.001, 1, 2);

    /* Simulate the circuit */
    simulate(&c, 1, 0.1);

    return 0;
}
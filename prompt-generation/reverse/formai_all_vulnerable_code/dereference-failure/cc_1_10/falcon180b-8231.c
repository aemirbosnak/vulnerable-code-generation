//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

typedef struct {
    char *name;
    double value;
    struct node *next;
} node;

typedef struct {
    char *name;
    node *head;
} circuit;

void add_node(circuit *c, char *name, double value) {
    node *n = (node*)malloc(sizeof(node));
    n->name = strdup(name);
    n->value = value;
    n->next = NULL;
    if (c->head == NULL) {
        c->head = n;
    } else {
        node *curr = c->head;
        while (curr->next!= NULL) {
            curr = curr->next;
        }
        curr->next = n;
    }
}

void print_circuit(circuit *c) {
    node *curr = c->head;
    while (curr!= NULL) {
        printf("%s = %f\n", curr->name, curr->value);
        curr = curr->next;
    }
}

void evaluate_circuit(circuit *c) {
    node *curr = c->head;
    while (curr!= NULL) {
        char *name = curr->name;
        double value = curr->value;
        if (name[0] == 'V') {
            // voltage source
        } else if (name[0] == 'R') {
            // resistor
        } else if (name[0] == 'C') {
            // capacitor
        } else if (name[0] == 'L') {
            // inductor
        } else if (name[0] == 'D') {
            // diode
        } else if (name[0] == 'T') {
            // transistor
        }
        curr = curr->next;
    }
}

int main() {
    srand(time(NULL));
    circuit c;
    add_node(&c, "V1", rand() % 10 + 1);
    add_node(&c, "R1", rand() % 10 + 1);
    add_node(&c, "C1", rand() % 10 + 1);
    add_node(&c, "L1", rand() % 10 + 1);
    add_node(&c, "D1", rand() % 10 + 1);
    add_node(&c, "T1", rand() % 10 + 1);
    print_circuit(&c);
    evaluate_circuit(&c);
    return 0;
}
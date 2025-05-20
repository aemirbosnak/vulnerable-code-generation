//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define MAX_COMPONENTS 100

struct component {
    int type;
    double value;
    struct component *next;
};

struct circuit {
    struct component *head;
    struct component *tail;
};

void add_component(struct circuit *circuit, int type, double value) {
    struct component *new_component = (struct component *)malloc(sizeof(struct component));
    new_component->type = type;
    new_component->value = value;
    new_component->next = NULL;

    if (circuit->head == NULL) {
        circuit->head = new_component;
        circuit->tail = new_component;
    } else {
        circuit->tail->next = new_component;
        circuit->tail = new_component;
    }
}

void simulate_circuit(struct circuit *circuit) {
    struct component *current_component = circuit->head;
    while (current_component!= NULL) {
        switch (current_component->type) {
            case 1: // Resistor
                printf("Resistor with value %.2f\n", current_component->value);
                break;
            case 2: // Capacitor
                printf("Capacitor with value %.2f\n", current_component->value);
                break;
            case 3: // Inductor
                printf("Inductor with value %.2f\n", current_component->value);
                break;
            default:
                printf("Unknown component\n");
        }
        current_component = current_component->next;
    }
}

int main() {
    struct circuit circuit;
    circuit.head = NULL;
    circuit.tail = NULL;

    add_component(&circuit, 1, 100.0);
    add_component(&circuit, 2, 0.001);
    add_component(&circuit, 3, 0.01);

    simulate_circuit(&circuit);

    return 0;
}
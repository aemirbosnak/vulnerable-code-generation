//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    FALSE,
    TRUE
} boolean;

typedef struct {
    char *name;
    boolean value;
} wire;

typedef struct {
    char *name;
    wire *inputs[2];
    wire *output;
    boolean (*operation)(boolean, boolean);
} gate;

typedef struct {
    wire *wires[10];
    gate *gates[10];
} circuit;

boolean and_gate(boolean a, boolean b) {
    return a && b;
}

boolean or_gate(boolean a, boolean b) {
    return a || b;
}

boolean not_gate(boolean a) {
    return !a;
}

void initialize_circuit(circuit *c) {
    c->wires[0] = malloc(sizeof(wire));
    c->wires[0]->name = "a";
    c->wires[0]->value = FALSE;

    c->wires[1] = malloc(sizeof(wire));
    c->wires[1]->name = "b";
    c->wires[1]->value = FALSE;

    c->wires[2] = malloc(sizeof(wire));
    c->wires[2]->name = "c";
    c->wires[2]->value = FALSE;

    c->gates[0] = malloc(sizeof(gate));
    c->gates[0]->name = "and_gate1";
    c->gates[0]->inputs[0] = c->wires[0];
    c->gates[0]->inputs[1] = c->wires[1];
    c->gates[0]->output = c->wires[2];
    c->gates[0]->operation = and_gate;

    c->gates[1] = malloc(sizeof(gate));
    c->gates[1]->name = "not_gate1";
    c->gates[1]->inputs[0] = c->wires[2];
    c->gates[1]->output = c->wires[3];
    c->gates[1]->operation = not_gate;
}

void simulate_circuit(circuit *c) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            c->wires[0]->value = i;
            c->wires[1]->value = j;

            for (int k = 0; k < 2; k++) {
                c->gates[k]->operation(c->gates[k]->inputs[0]->value, c->gates[k]->inputs[1]->value);
            }

            printf("%s: %d, %s: %d, %s: %d\n", c->wires[0]->name, c->wires[0]->value, c->wires[1]->name, c->wires[1]->value, c->wires[2]->name, c->wires[2]->value);
        }
    }
}

int main() {
    circuit c;
    initialize_circuit(&c);
    simulate_circuit(&c);
    return 0;
}
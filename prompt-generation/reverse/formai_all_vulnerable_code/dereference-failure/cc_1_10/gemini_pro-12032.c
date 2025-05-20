//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: realistic
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    char *name;
    bool value;
    struct {
        char *name;
        bool value;
    } **inputs;
    size_t num_inputs;
} gate;
typedef struct {
    gate *gates;
    size_t num_gates;
} circuit;

circuit *create_circuit(size_t num_gates) {
    circuit *c = malloc(sizeof(circuit));
    c->gates = malloc(sizeof(gate) * num_gates);
    c->num_gates = num_gates;
    return c;
}

void add_gate(circuit *c, gate g) {
    c->gates[c->num_gates++] = g;
}

void add_input_to_gate(gate *g, char *name, bool value) {
    g->inputs = realloc(g->inputs, sizeof(gate *) * (g->num_inputs + 1));
    g->inputs[g->num_inputs++] = malloc(sizeof(gate));
    g->inputs[g->num_inputs - 1]->name = name;
    g->inputs[g->num_inputs - 1]->value = value;
}

void init_gate(gate *g, char *name, bool value) {
    g->name = name;
    g->value = value;
    g->inputs = NULL;
    g->num_inputs = 0;
}

void destroy_gate(gate *g) {
    free(g->name);
    for (size_t i = 0; i < g->num_inputs; i++) {
        free(g->inputs[i]);
    }
    free(g->inputs);
}

void destroy_circuit(circuit *c) {
    for (size_t i = 0; i < c->num_gates; i++) {
        destroy_gate(&c->gates[i]);
    }
    free(c->gates);
    free(c);
}

void print_gate(gate *g) {
    printf("%s = ", g->name);
    for (size_t i = 0; i < g->num_inputs; i++) {
        printf("%s = %d, ", g->inputs[i]->name, g->inputs[i]->value);
    }
    printf("%d\n", g->value);
}

void print_circuit(circuit *c) {
    for (size_t i = 0; i < c->num_gates; i++) {
        print_gate(&c->gates[i]);
    }
}

int main() {
    circuit *c = create_circuit(1);
    gate g1;
    init_gate(&g1, "g1", true);
    add_gate(c, g1);
    gate g2;
    init_gate(&g2, "g2", false);
    add_input_to_gate(&g2, "g1", true);
    add_gate(c, g2);
    print_circuit(c);
    destroy_circuit(c);
    return 0;
}
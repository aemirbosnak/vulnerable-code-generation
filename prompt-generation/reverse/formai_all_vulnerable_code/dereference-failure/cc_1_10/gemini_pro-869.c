//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *state;
    int size;
} circuit;

circuit *new_circuit(int size) {
    circuit *c = malloc(sizeof(circuit));
    c->state = malloc(sizeof(int) * size);
    c->size = size;
    return c;
}

void free_circuit(circuit *c) {
    free(c->state);
    free(c);
}

void set_state(circuit *c, int index, int value) {
    c->state[index] = value;
}

int get_state(circuit *c, int index) {
    return c->state[index];
}

void print_state(circuit *c) {
    for (int i = 0; i < c->size; i++) {
        printf("%d ", c->state[i]);
    }
    printf("\n");
}


int main() {
    circuit *c = new_circuit(10);

    set_state(c, 0, 1);
    set_state(c, 1, 0);
    set_state(c, 2, 1);
    set_state(c, 3, 0);
    set_state(c, 4, 1);
    set_state(c, 5, 0);
    set_state(c, 6, 1);
    set_state(c, 7, 0);
    set_state(c, 8, 1);
    set_state(c, 9, 0);

    print_state(c);

    free_circuit(c);

    return 0;
}
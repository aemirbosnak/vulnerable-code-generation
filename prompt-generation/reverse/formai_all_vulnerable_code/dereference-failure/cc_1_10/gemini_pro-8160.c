//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int *values;
    int size;
} Circuit;

Circuit *circuit_create(int size) {
    Circuit *circuit = malloc(sizeof(Circuit));
    circuit->values = malloc(sizeof(int) * size);
    circuit->size = size;
    return circuit;
}

void circuit_destroy(Circuit *circuit) {
    free(circuit->values);
    free(circuit);
}

int circuit_get(Circuit *circuit, int index) {
    if (index < 0 || index >= circuit->size) {
        return -1;
    }
    return circuit->values[index];
}

void circuit_set(Circuit *circuit, int index, int value) {
    if (index < 0 || index >= circuit->size) {
        return;
    }
    circuit->values[index] = value;
}

int circuit_evaluate(Circuit *circuit) {
    int result = 0;
    for (int i = 0; i < circuit->size; i++) {
        result += circuit->values[i];
    }
    return result;
}

int main() {
    srand(time(NULL));
    int size = rand() % 100 + 1;
    Circuit *circuit = circuit_create(size);

    for (int i = 0; i < size; i++) {
        circuit->values[i] = rand() % 2;
    }

    int result = circuit_evaluate(circuit);

    printf("Circuit size: %d\n", size);
    printf("Circuit values: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", circuit->values[i]);
    }
    printf("\n");
    printf("Circuit result: %d\n", result);

    circuit_destroy(circuit);

    return 0;
}
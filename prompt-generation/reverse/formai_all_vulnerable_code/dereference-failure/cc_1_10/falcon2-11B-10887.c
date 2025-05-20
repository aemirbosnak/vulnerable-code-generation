//Falcon2-11B DATASET v1.0 Category: Classical Circuit Simulator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 5

typedef struct {
    double v;
    double *wires;
} Circuit;

void solve(Circuit *c) {
    double total_resistance = 0;
    for (int i = 0; i < N; i++) {
        total_resistance += c->wires[i];
    }

    if (total_resistance!= 0) {
        for (int i = 0; i < N; i++) {
            c->v -= c->wires[i] / (1 / total_resistance - 1);
        }

        for (int i = 0; i < N; i++) {
            c->v -= c->wires[i] * c->wires[i] / (1 / total_resistance - 1);
        }

        for (int i = 0; i < N; i++) {
            c->v -= c->wires[i] * c->wires[i] * c->wires[i] / (1 / total_resistance - 1);
        }
    }

    for (int i = 0; i < N; i++) {
        printf("Wire %d: %lf V\n", i, c->v);
    }

    printf("Program has ended.\n");
}

int main() {
    Circuit circuit;
    double resistances[N] = {1.0, 2.0, 3.0, 4.0, 5.0};

    circuit.wires = (double *)malloc(N * sizeof(double));
    for (int i = 0; i < N; i++) {
        circuit.wires[i] = resistances[i];
    }

    circuit.v = 5.0;
    solve(&circuit);

    return 0;
}
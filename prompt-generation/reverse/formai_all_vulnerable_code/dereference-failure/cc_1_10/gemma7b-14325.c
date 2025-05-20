//Gemma-7B DATASET v1.0 Category: Classical Circuit Simulator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265359

typedef struct Circuit {
    double r;
    double l;
    double c;
    double v;
    double i;
    struct Circuit *next;
} Circuit;

Circuit *circuit_create(double r, double l, double c) {
    Circuit *circuit = malloc(sizeof(Circuit));
    circuit->r = r;
    circuit->l = l;
    circuit->c = c;
    circuit->v = 0;
    circuit->i = 0;
    circuit->next = NULL;
    return circuit;
}

void circuit_simulate(Circuit *circuit) {
    double time = 0;
    double dt = 0.01;
    double v_source = 10;
    double i_source = 2;

    while (time < 1) {
        double voltage = v_source * sin(2 * PI * 500 * time);
        circuit->v = voltage;

        double current = i_source / circuit->r;
        circuit->i = current;

        time += dt;
    }
}

int main() {
    Circuit *circuit = circuit_create(2, 1, 0.1);
    circuit_simulate(circuit);

    free(circuit);
    return 0;
}
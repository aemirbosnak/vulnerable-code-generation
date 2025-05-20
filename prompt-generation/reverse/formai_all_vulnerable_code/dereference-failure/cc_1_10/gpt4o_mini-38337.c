//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    double resistance; // ohms
} Resistor;

typedef struct {
    char name[20];
    double capacitance; // farads
} Capacitor;

typedef struct {
    char name[20];
    double inductance; // henries
} Inductor;

typedef struct {
    char type; // 'R', 'C', 'L'
    union {
        Resistor res;
        Capacitor cap;
        Inductor ind;
    } component;
} CircuitElement;

typedef struct {
    CircuitElement *elements;
    size_t size;
    size_t capacity;
} Circuit;

Circuit *createCircuit(size_t capacity) {
    Circuit *circuit = (Circuit *) malloc(sizeof(Circuit));
    circuit->elements = (CircuitElement *) malloc(capacity * sizeof(CircuitElement));
    circuit->size = 0;
    circuit->capacity = capacity;
    return circuit;
}

void addResistor(Circuit *circuit, const char *name, double resistance) {
    if (circuit->size >= circuit->capacity) {
        circuit->capacity *= 2;
        circuit->elements = (CircuitElement *) realloc(circuit->elements, circuit->capacity * sizeof(CircuitElement));
    }
    CircuitElement elem;
    elem.type = 'R';
    strcpy(elem.component.res.name, name);
    elem.component.res.resistance = resistance;
    circuit->elements[circuit->size++] = elem;
}

void addCapacitor(Circuit *circuit, const char *name, double capacitance) {
    if (circuit->size >= circuit->capacity) {
        circuit->capacity *= 2;
        circuit->elements = (CircuitElement *) realloc(circuit->elements, circuit->capacity * sizeof(CircuitElement));
    }
    CircuitElement elem;
    elem.type = 'C';
    strcpy(elem.component.cap.name, name);
    elem.component.cap.capacitance = capacitance;
    circuit->elements[circuit->size++] = elem;
}

void addInductor(Circuit *circuit, const char *name, double inductance) {
    if (circuit->size >= circuit->capacity) {
        circuit->capacity *= 2;
        circuit->elements = (CircuitElement *) realloc(circuit->elements, circuit->capacity * sizeof(CircuitElement));
    }
    CircuitElement elem;
    elem.type = 'L';
    strcpy(elem.component.ind.name, name);
    elem.component.ind.inductance = inductance;
    circuit->elements[circuit->size++] = elem;
}

void printCircuit(const Circuit *circuit) {
    printf("Circuit Elements:\n");
    for (size_t i = 0; i < circuit->size; i++) {
        CircuitElement elem = circuit->elements[i];
        if (elem.type == 'R') {
            printf("Resistor: %s, Resistance: %.2f Ohms\n", elem.component.res.name, elem.component.res.resistance);
        } else if (elem.type == 'C') {
            printf("Capacitor: %s, Capacitance: %.2f Farads\n", elem.component.cap.name, elem.component.cap.capacitance);
        } else if (elem.type == 'L') {
            printf("Inductor: %s, Inductance: %.2f Henrys\n", elem.component.ind.name, elem.component.ind.inductance);
        }
    }
}

void freeCircuit(Circuit *circuit) {
    free(circuit->elements);
    free(circuit);
}

int main() {
    Circuit *circuit = createCircuit(2);

    addResistor(circuit, "R1", 100);
    addCapacitor(circuit, "C1", 0.000001);
    addInductor(circuit, "L1", 0.01);
    addResistor(circuit, "R2", 220);
    addCapacitor(circuit, "C2", 0.000002);
    addInductor(circuit, "L2", 0.05);

    printCircuit(circuit);
    freeCircuit(circuit);

    return 0;
}
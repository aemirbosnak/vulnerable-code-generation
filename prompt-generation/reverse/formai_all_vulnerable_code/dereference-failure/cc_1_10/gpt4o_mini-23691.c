//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    char name[20];
    double value; // Value of the resistor in Ohms
} Resistor;

typedef struct {
    char name[20];
    double voltage; // Voltage across the capacitor in Volts
    double capacitance; // Capacitance in Farads
} Capacitor;

typedef struct {
    char name[20];
    double voltage; // Voltage across the inductor in Volts
    double inductance; // Inductance in Henry
} Inductor;

typedef struct {
    Resistor *resistors;
    Capacitor *capacitors;
    Inductor *inductors;
    int numResistors;
    int numCapacitors;
    int numInductors;
} Circuit;

Circuit createCircuit(int numResistors, int numCapacitors, int numInductors) {
    Circuit circuit;
    circuit.numResistors = numResistors;
    circuit.numCapacitors = numCapacitors;
    circuit.numInductors = numInductors;

    circuit.resistors = (Resistor *)malloc(numResistors * sizeof(Resistor));
    circuit.capacitors = (Capacitor *)malloc(numCapacitors * sizeof(Capacitor));
    circuit.inductors = (Inductor *)malloc(numInductors * sizeof(Inductor));

    return circuit;
}

void freeCircuit(Circuit *circuit) {
    free(circuit->resistors);
    free(circuit->capacitors);
    free(circuit->inductors);
}

void addResistor(Circuit *circuit, int index, const char *name, double value) {
    strncpy(circuit->resistors[index].name, name, sizeof(circuit->resistors[index].name) - 1);
    circuit->resistors[index].value = value;
}

void addCapacitor(Circuit *circuit, int index, const char *name, double voltage, double capacitance) {
    strncpy(circuit->capacitors[index].name, name, sizeof(circuit->capacitors[index].name) - 1);
    circuit->capacitors[index].voltage = voltage;
    circuit->capacitors[index].capacitance = capacitance;
}

void addInductor(Circuit *circuit, int index, const char *name, double voltage, double inductance) {
    strncpy(circuit->inductors[index].name, name, sizeof(circuit->inductors[index].name) - 1);
    circuit->inductors[index].voltage = voltage;
    circuit->inductors[index].inductance = inductance;
}

double totalResistance(Circuit *circuit) {
    double total = 0.0;
    for (int i = 0; i < circuit->numResistors; i++) {
        total += circuit->resistors[i].value;
    }
    return total;
}

double totalCapacitance(Circuit *circuit) {
    double total = 0.0;
    for (int i = 0; i < circuit->numCapacitors; i++) {
        total += circuit->capacitors[i].capacitance;
    }
    return total;
}

double totalInductance(Circuit *circuit) {
    double total = 0.0;
    for (int i = 0; i < circuit->numInductors; i++) {
        total += circuit->inductors[i].inductance;
    }
    return total;
}

void printCircuitDetails(Circuit *circuit) {
    printf("Circuit Details:\n");
    printf("----------------\n");
    printf("Resistors:\n");
    for (int i = 0; i < circuit->numResistors; i++) {
        printf("Name: %s, Value: %.2f Ohms\n", circuit->resistors[i].name, circuit->resistors[i].value);
    }
    printf("Total Resistance: %.2f Ohms\n\n", totalResistance(circuit));

    printf("Capacitors:\n");
    for (int i = 0; i < circuit->numCapacitors; i++) {
        printf("Name: %s, Voltage: %.2f V, Capacitance: %.2f F\n",
               circuit->capacitors[i].name, circuit->capacitors[i].voltage, circuit->capacitors[i].capacitance);
    }
    printf("Total Capacitance: %.2f F\n\n", totalCapacitance(circuit));
    
    printf("Inductors:\n");
    for (int i = 0; i < circuit->numInductors; i++) {
        printf("Name: %s, Voltage: %.2f V, Inductance: %.2f H\n",
               circuit->inductors[i].name, circuit->inductors[i].voltage, circuit->inductors[i].inductance);
    }
    printf("Total Inductance: %.2f H\n\n", totalInductance(circuit));
}

int main() {
    int numResistors = 3;
    int numCapacitors = 2;
    int numInductors = 2;

    Circuit circuit = createCircuit(numResistors, numCapacitors, numInductors);

    addResistor(&circuit, 0, "R1", 100);
    addResistor(&circuit, 1, "R2", 150);
    addResistor(&circuit, 2, "R3", 220);

    addCapacitor(&circuit, 0, "C1", 5.0, 0.000001);
    addCapacitor(&circuit, 1, "C2", 5.0, 0.000002);

    addInductor(&circuit, 0, "L1", 12.0, 0.1);
    addInductor(&circuit, 1, "L2", 12.0, 0.2);

    printCircuitDetails(&circuit);

    freeCircuit(&circuit);

    return 0;
}
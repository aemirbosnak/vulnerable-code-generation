//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct {
    char name[20];
    double resistance;
} Resistor;

typedef struct {
    char name[20];
    double capacitance;
} Capacitor;

typedef struct {
    char name[20];
    double inductance;
} Inductor;

typedef struct {
    Resistor *resistors;
    int r_count;
    Capacitor *capacitors;
    int c_count;
    Inductor *inductors;
    int i_count;
} Circuit;

void initCircuit(Circuit *circuit) {
    circuit->resistors = NULL;
    circuit->r_count = 0;
    circuit->capacitors = NULL;
    circuit->c_count = 0;
    circuit->inductors = NULL;
    circuit->i_count = 0;
}

void addResistor(Circuit *circuit, const char *name, double resistance) {
    circuit->resistors = realloc(circuit->resistors, 
                          sizeof(Resistor) * (circuit->r_count + 1));
    strcpy(circuit->resistors[circuit->r_count].name, name);
    circuit->resistors[circuit->r_count].resistance = resistance;
    circuit->r_count++;
}

void addCapacitor(Circuit *circuit, const char *name, double capacitance) {
    circuit->capacitors = realloc(circuit->capacitors, 
                             sizeof(Capacitor) * (circuit->c_count + 1));
    strcpy(circuit->capacitors[circuit->c_count].name, name);
    circuit->capacitors[circuit->c_count].capacitance = capacitance;
    circuit->c_count++;
}

void addInductor(Circuit *circuit, const char *name, double inductance) {
    circuit->inductors = realloc(circuit->inductors, 
                            sizeof(Inductor) * (circuit->i_count + 1));
    strcpy(circuit->inductors[circuit->i_count].name, name);
    circuit->inductors[circuit->i_count].inductance = inductance;
    circuit->i_count++;
}

double calculateTotalResistance(Circuit *circuit) {
    double totalResistance = 0;
    for (int i = 0; i < circuit->r_count; i++) {
        totalResistance += circuit->resistors[i].resistance;  // Series Connection
    }
    return totalResistance;
}

void simulateCapacitors(Circuit *circuit, double voltage, double time) {
    printf("Capacitor Simulation:\n");
    for (int i = 0; i < circuit->c_count; i++) {
        double charge = voltage * circuit->capacitors[i].capacitance; 
        printf("Capacitor %s: Charge = %.2f C at %.2f s\n", 
            circuit->capacitors[i].name, charge, time);
    }
}

void simulateInductors(Circuit *circuit, double current, double time) {
    printf("Inductor Simulation:\n");
    for (int i = 0; i < circuit->i_count; i++) {
        double energy = 0.5 * circuit->inductors[i].inductance * current * current;
        printf("Inductor %s: Energy = %.2f J at %.2f s\n", 
            circuit->inductors[i].name, energy, time);
    }
}

void freeCircuit(Circuit *circuit) {
    free(circuit->resistors);
    free(circuit->capacitors);
    free(circuit->inductors);
}

int main() {
    Circuit circuit;
    initCircuit(&circuit);

    addResistor(&circuit, "R1", 100.0);
    addResistor(&circuit, "R2", 200.0);
    addResistor(&circuit, "R3", 50.0);
    
    addCapacitor(&circuit, "C1", 0.000001);
    addCapacitor(&circuit, "C2", 0.000002);
    
    addInductor(&circuit, "L1", 0.01);
    
    double totalResistance = calculateTotalResistance(&circuit);
    printf("Total Resistance in circuit: %.2f Ohms\n", totalResistance);
    
    simulateCapacitors(&circuit, 5.0, 10.0);
    simulateInductors(&circuit, 2.0, 10.0);
    
    freeCircuit(&circuit);
    return 0;
}
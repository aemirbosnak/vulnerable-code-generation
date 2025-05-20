//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct {
    char name[20];
    double resistance; // Ohms
} Resistor;

typedef struct {
    char name[20];
    double voltage; // Volts
} VoltageSource;

typedef struct {
    Resistor *r1;
    Resistor *r2;
    VoltageSource *vs;
} RomanticCircuit;

// Function prototypes
void initializeCircuit(RomanticCircuit *circuit, const char *name1, double r1_value, const char *name2, double r2_value, const char *vs_name, double v_value);
double calculateTotalResistance(RomanticCircuit *circuit);
double calculateCurrent(RomanticCircuit *circuit);
void simulateLove(RomanticCircuit *circuit);

int main() {
    RomanticCircuit myLoveCircuit;
    initializeCircuit(&myLoveCircuit, "Heart R1", 100.0, "Heart R2", 200.0, "Love Voltage", 10.0);

    printf("In the realm of love, our electrical impulses awaken...\n");
    simulateLove(&myLoveCircuit);
    
    // Free memory
    free(myLoveCircuit.r1);
    free(myLoveCircuit.r2);
    free(myLoveCircuit.vs);

    return 0;
}

void initializeCircuit(RomanticCircuit *circuit, const char *name1, double r1_value, const char *name2, double r2_value, const char *vs_name, double v_value) {
    circuit->r1 = (Resistor *) malloc(sizeof(Resistor));
    circuit->r2 = (Resistor *) malloc(sizeof(Resistor));
    circuit->vs = (VoltageSource *) malloc(sizeof(VoltageSource));

    strcpy(circuit->r1->name, name1);
    circuit->r1->resistance = r1_value;

    strcpy(circuit->r2->name, name2);
    circuit->r2->resistance = r2_value;

    strcpy(circuit->vs->name, vs_name);
    circuit->vs->voltage = v_value;
}

double calculateTotalResistance(RomanticCircuit *circuit) {
    // Series connection of resistors for a romantic bond
    return circuit->r1->resistance + circuit->r2->resistance;
}

double calculateCurrent(RomanticCircuit *circuit) {
    double totalResistance = calculateTotalResistance(circuit);
    // Ohm's Law: V = IR => I = V/R
    return circuit->vs->voltage / totalResistance;
}

void simulateLove(RomanticCircuit *circuit) {
    double current = calculateCurrent(circuit);
    printf("In the embrace of voltage and resistance, our love flows with a current of %.2f A.\n", current);
    printf("The total resistance of our heartfelt connection is %.2f Ohms.\n", calculateTotalResistance(circuit));
    printf("May our love dance through circuits, ignited by passion and powered by a shared dream.\n");
}
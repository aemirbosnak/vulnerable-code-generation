//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Define resistor structure
typedef struct {
    char name[10];
    double resistance;
} Resistor;

// Define capacitor structure
typedef struct {
    char name[10];
    double capacitance;
} Capacitor;

// Define voltage source structure
typedef struct {
    char name[10];
    double voltage;
} VoltageSource;

// Circuit structure to hold components
typedef struct {
    Resistor *resistors;
    Capacitor *capacitors;
    VoltageSource *voltageSources;
    int rCount;
    int cCount;
    int vCount;
} Circuit;

// Function prototypes
Circuit* createCircuit();
void addResistor(Circuit *circuit, const char *name, double resistance);
void addCapacitor(Circuit *circuit, const char *name, double capacitance);
void addVoltageSource(Circuit *circuit, const char *name, double voltage);
void displayCircuit(const Circuit *circuit);
void freeCircuit(Circuit *circuit);

int main() {
    Circuit *circuit = createCircuit();
    
    addResistor(circuit, "R1", 1000);
    addResistor(circuit, "R2", 2000);
    addCapacitor(circuit, "C1", 0.001);
    addVoltageSource(circuit, "V1", 5.0);
    
    displayCircuit(circuit);
    
    freeCircuit(circuit);
    return 0;
}

Circuit* createCircuit() {
    Circuit *circuit = (Circuit*)malloc(sizeof(Circuit));
    if (circuit == NULL) {
        fprintf(stderr, "Failed to allocate memory for circuit.\n");
        exit(EXIT_FAILURE);
    }
    circuit->rCount = 0;
    circuit->cCount = 0;
    circuit->vCount = 0;
    circuit->resistors = NULL;
    circuit->capacitors = NULL;
    circuit->voltageSources = NULL;
    return circuit;
}

void addResistor(Circuit *circuit, const char *name, double resistance) {
    circuit->resistors = realloc(circuit->resistors, sizeof(Resistor) * (circuit->rCount + 1));
    if (circuit->resistors == NULL) {
        fprintf(stderr, "Failed to allocate memory for resistors.\n");
        exit(EXIT_FAILURE);
    }
    strncpy(circuit->resistors[circuit->rCount].name, name, sizeof(circuit->resistors[circuit->rCount].name));
    circuit->resistors[circuit->rCount].resistance = resistance;
    circuit->rCount++;
}

void addCapacitor(Circuit *circuit, const char *name, double capacitance) {
    circuit->capacitors = realloc(circuit->capacitors, sizeof(Capacitor) * (circuit->cCount + 1));
    if (circuit->capacitors == NULL) {
        fprintf(stderr, "Failed to allocate memory for capacitors.\n");
        exit(EXIT_FAILURE);
    }
    strncpy(circuit->capacitors[circuit->cCount].name, name, sizeof(circuit->capacitors[circuit->cCount].name));
    circuit->capacitors[circuit->cCount].capacitance = capacitance;
    circuit->cCount++;
}

void addVoltageSource(Circuit *circuit, const char *name, double voltage) {
    circuit->voltageSources = realloc(circuit->voltageSources, sizeof(VoltageSource) * (circuit->vCount + 1));
    if (circuit->voltageSources == NULL) {
        fprintf(stderr, "Failed to allocate memory for voltage sources.\n");
        exit(EXIT_FAILURE);
    }
    strncpy(circuit->voltageSources[circuit->vCount].name, name, sizeof(circuit->voltageSources[circuit->vCount].name));
    circuit->voltageSources[circuit->vCount].voltage = voltage;
    circuit->vCount++;
}

void displayCircuit(const Circuit *circuit) {
    printf("Circuit Components:\n");
    
    printf("Resistors:\n");
    for (int i = 0; i < circuit->rCount; i++) {
        printf("%s: %.2f ohm\n", circuit->resistors[i].name, circuit->resistors[i].resistance);
    }

    printf("Capacitors:\n");
    for (int i = 0; i < circuit->cCount; i++) {
        printf("%s: %.4f F\n", circuit->capacitors[i].name, circuit->capacitors[i].capacitance);
    }

    printf("Voltage Sources:\n");
    for (int i = 0; i < circuit->vCount; i++) {
        printf("%s: %.2f V\n", circuit->voltageSources[i].name, circuit->voltageSources[i].voltage);
    }
}

void freeCircuit(Circuit *circuit) {
    free(circuit->resistors);
    free(circuit->capacitors);
    free(circuit->voltageSources);
    free(circuit);
}
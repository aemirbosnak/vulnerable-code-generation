//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

typedef struct Resistor {
    float resistance;  // Resistance in Ohms
} Resistor;

typedef struct Circuit {
    Resistor *resistors;
    int count;
} Circuit;

// Function declarations
Circuit* createCircuit(int count);
void addResistor(Circuit *circuit, float resistance, int index);
float calculateTotalResistance(Circuit *circuit, int isParallel);
void freeCircuit(Circuit *circuit);
void displayCircuit(Circuit *circuit);

int main() {
    int numResistors, option;
    printf("Welcome to the Classic Circuit Simulator!\n");
    printf("Enter the number of resistors in the circuit: ");
    scanf("%d", &numResistors);

    Circuit *circuit = createCircuit(numResistors);

    for (int i = 0; i < numResistors; i++) {
        float resistance;
        printf("Enter resistance of resistor %d (in Ohms): ", i + 1);
        scanf("%f", &resistance);
        addResistor(circuit, resistance, i);
    }

    printf("Choose the configuration you want to simulate:\n");
    printf("1. Series\n");
    printf("2. Parallel\n");
    printf("Your choice: ");
    scanf("%d", &option);

    float totalResistance = (option == 1) ? calculateTotalResistance(circuit, 0) : calculateTotalResistance(circuit, 1);
    
    printf("Total Resistance: %.2f Ohms\n", totalResistance);
    displayCircuit(circuit);
    freeCircuit(circuit);
    
    return 0;
}

Circuit* createCircuit(int count) {
    Circuit *circuit = (Circuit*)malloc(sizeof(Circuit));
    circuit->count = count;
    circuit->resistors = (Resistor*)malloc(count * sizeof(Resistor));
    return circuit;
}

void addResistor(Circuit *circuit, float resistance, int index) {
    if (index >= 0 && index < circuit->count) {
        circuit->resistors[index].resistance = resistance;
    }
}

float calculateTotalResistance(Circuit *circuit, int isParallel) {
    float total = 0.0f;

    if (isParallel) {
        for (int i = 0; i < circuit->count; i++) {
            total += 1.0f / circuit->resistors[i].resistance;
        }
        return (total != 0) ? 1.0f / total : 0;  // Handle division by zero
    } else {
        for (int i = 0; i < circuit->count; i++) {
            total += circuit->resistors[i].resistance;
        }
        return total;
    }
}

void freeCircuit(Circuit *circuit) {
    free(circuit->resistors);
    free(circuit);
}

void displayCircuit(Circuit *circuit) {
    printf("Resistor Values:\n");
    for (int i = 0; i < circuit->count; i++) {
        printf("Resistor %d: %.2f Ohms\n", i + 1, circuit->resistors[i].resistance);
    }
}
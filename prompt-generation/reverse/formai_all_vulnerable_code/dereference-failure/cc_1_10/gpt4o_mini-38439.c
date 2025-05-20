//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: protected
#include <stdio.h>
#include <stdlib.h>

// Define the types of resistors
typedef enum { SERIES, PARALLEL } ConnectionType;

typedef struct {
    float resistance;     // Resistance in ohms
    ConnectionType type;  // Connection type: series or parallel
} Resistor;

// Function to calculate total resistance for series connection
float totalResistanceSeries(Resistor* resistors, int count) {
    float total = 0.0;
    for (int i = 0; i < count; i++) {
        total += resistors[i].resistance;
    }
    return total;
}

// Function to calculate total resistance for parallel connection
float totalResistanceParallel(Resistor* resistors, int count) {
    float total = 0.0;
    for (int i = 0; i < count; i++) {
        total += 1.0 / resistors[i].resistance;
    }
    return 1.0 / total;
}

// Function to display the total resistance
void displayResistance(float totalResistance) {
    printf("Total Resistance: %.2f Ohms\n", totalResistance);
}

// Function to calculate current using Ohm's Law
float calculateCurrent(float voltage, float resistance) {
    if (resistance == 0) {
        printf("Error: Resistance cannot be zero.\n");
        return 0;
    }
    return voltage / resistance;
}

// Function to perform circuit simulation
void simulateCircuit() {
    int numResistors, connectionType;

    printf("Enter the number of resistors: ");
    scanf("%d", &numResistors);

    Resistor* resistors = (Resistor*)malloc(numResistors * sizeof(Resistor));
    
    for (int i = 0; i < numResistors; i++) {
        printf("Enter resistance of Resistor %d (in Ohms): ", i + 1);
        scanf("%f", &resistors[i].resistance);
        
        printf("Enter Connection Type for Resistor %d (0 for SERIES, 1 for PARALLEL): ", i + 1);
        scanf("%d", &connectionType);
        resistors[i].type = (ConnectionType)connectionType;
    }

    float totalResistance;
    
    printf("Calculating total resistance...\n");
    totalResistance = totalResistanceSeries(resistors, numResistors); // Default to series
    for (int i = 1; i < numResistors; i++) {
        if (resistors[i].type == PARALLEL) {
            printf("Calculator change to PARALLEL connection...\n");
            totalResistance = totalResistanceParallel(resistors, numResistors);
            break;
        }
    }

    displayResistance(totalResistance);

    float voltage;
    printf("Enter the voltage supplied by the source (in Volts): ");
    scanf("%f", &voltage);

    float current = calculateCurrent(voltage, totalResistance);
    printf("Total Current flowing through the circuit: %.2f Amperes\n", current);

    free(resistors);
}

int main() {
    printf("Welcome to the Circuit Simulator!\n");
    simulateCircuit();
    return 0;
}
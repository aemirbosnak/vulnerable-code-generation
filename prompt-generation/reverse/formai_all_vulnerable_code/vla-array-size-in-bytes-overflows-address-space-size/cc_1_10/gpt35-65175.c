//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: grateful
#include <stdio.h>

/* Grateful Classical Circuit Simulator */
/* Created by: [Your Name Here] */

int main()
{
    printf("Welcome to the Grateful Classical Circuit Simulator!\n");
    
    // Input variables
    int numNodes;
    printf("Enter the number of circuit nodes: ");
    scanf("%d", &numNodes);
    
    int numResistors;
    printf("Enter the number of resistors: ");
    scanf("%d", &numResistors);
    
    int numSources;
    printf("Enter the number of sources: ");
    scanf("%d", &numSources);
    
    // Arrays to store resistor and source values
    double resistances[numResistors];
    double voltageSources[numSources];
    double currentSources[numSources];
    
    // Get resistor values and calculate total resistance
    double totalResistance = 0;
    for (int i = 0; i < numResistors; i++) {
        printf("Enter the resistance value for resistor %d: ", i+1);
        scanf("%lf", &resistances[i]);
        totalResistance += resistances[i];
    }
    
    // Get voltage source values
    for (int i = 0; i < numSources; i++) {
        printf("Enter the voltage value for source %d: ", i+1);
        scanf("%lf", &voltageSources[i]);
    }
    
    // Get current source values
    for (int i = 0; i < numSources; i++) {
        printf("Enter the current value for source %d: ", i+1);
        scanf("%lf", &currentSources[i]);
    }
    
    // Calculate total voltage and current
    double totalVoltage = 0;
    double totalCurrent = 0;
    for (int i = 0; i < numSources; i++) {
        totalVoltage += voltageSources[i];
        totalCurrent += currentSources[i];
    }
    
    // Calculate total circuit resistance and power
    double totalCircuitResistance = totalResistance;
    double circuitPower = totalVoltage * totalCurrent;
    
    // Output circuit information
    printf("\n");
    printf("=== CIRCUIT INFORMATION ===\n");
    printf("Number of nodes: %d\n", numNodes);
    printf("Number of resistors: %d\n", numResistors);
    printf("Number of voltage sources: %d\n", numSources);
    printf("Number of current sources: %d\n", numSources);
    printf("Total circuit resistance: %lf\n", totalCircuitResistance);
    printf("Total circuit power: %lf\n", circuitPower);
    
    return 0;
}
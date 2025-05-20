//Falcon2-11B DATASET v1.0 Category: Classical Circuit Simulator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679821480865132823066470938446095505822317253594081284811174502841027019385211055596446229489549303819644288109756659334461284752143909245975294592655917978533944660794516437917513146289461583004495022341543373835823904540618244621079433579491004506166279877665238242563556342957496951552904080552020943104070125879402323588676529482503984890127778078358103121

// Function to simulate a circuit
void simulateCircuit(int numResistors, int numVoltageSources, int numCurrentSources) {
    int I[numResistors];
    int V[numVoltageSources];
    int R[numResistors];
    int current[numCurrentSources];
    int voltage[numVoltageSources];

    for (int i = 0; i < numResistors; i++) {
        R[i] = rand() % 1000;
        printf("Resistor %d: %d ohms\n", i+1, R[i]);
    }

    for (int i = 0; i < numVoltageSources; i++) {
        V[i] = rand() % 1000;
        printf("Voltage source %d: %d volts\n", i+1, V[i]);
    }

    for (int i = 0; i < numCurrentSources; i++) {
        current[i] = rand() % 1000;
        printf("Current source %d: %d amps\n", i+1, current[i]);
    }

    // Simulate the circuit
    for (int step = 0; step < 1000; step++) {
        for (int i = 0; i < numResistors; i++) {
            I[i] = (V[i] - voltage[i]) / R[i];
            printf("Resistor %d: %d mA\n", i+1, I[i]);
            voltage[i] += I[i];
        }

        for (int i = 0; i < numVoltageSources; i++) {
            voltage[i] += current[i] * R[i];
        }

        for (int i = 0; i < numCurrentSources; i++) {
            current[i] += (voltage[i] - V[i]) / R[i];
        }
    }
}

int main() {
    int numResistors, numVoltageSources, numCurrentSources;
    printf("Enter number of resistors: ");
    scanf("%d", &numResistors);
    printf("Enter number of voltage sources: ");
    scanf("%d", &numVoltageSources);
    printf("Enter number of current sources: ");
    scanf("%d", &numCurrentSources);

    simulateCircuit(numResistors, numVoltageSources, numCurrentSources);

    return 0;
}
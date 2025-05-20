//Falcon2-11B DATASET v1.0 Category: Classical Circuit Simulator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to simulate a circuit
void simulateCircuit(int numOfCells) {
    srand(time(NULL)); // Initialize random number generator

    int cellArray[numOfCells]; // Array to store cell states

    // Initialize all cells to 0
    for (int i = 0; i < numOfCells; i++) {
        cellArray[i] = 0;
    }

    // Simulate the circuit for N steps
    for (int i = 0; i < numOfCells; i++) {
        int numOfOnNeighbors = 0;

        // Count the number of on neighbors
        for (int j = 0; j < numOfCells; j++) {
            if (i!= j && cellArray[j] == 1) {
                numOfOnNeighbors++;
            }
        }

        // Update the cell state based on its neighbors
        if (numOfOnNeighbors == 2 || numOfOnNeighbors == 3) {
            cellArray[i] = 1;
        } else {
            cellArray[i] = 0;
        }
    }

    // Print the final state of the circuit
    printf("Final state of the circuit:\n");
    for (int i = 0; i < numOfCells; i++) {
        printf("%d ", cellArray[i]);
    }
    printf("\n");
}

int main() {
    int numOfCells;

    printf("Enter the number of cells: ");
    scanf("%d", &numOfCells);

    simulateCircuit(numOfCells);

    return 0;
}
//Gemma-7B DATASET v1.0 Category: Classical Circuit Simulator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void circuit_simulator(int **circuit, int num_components)
{
    for (int i = 0; i < num_components; i++)
    {
        switch (circuit[i][0])
        {
            case 'R':
                printf("Resistance: %.2f ohms\n", circuit[i][1]);
                break;
            case 'C':
                printf("Capacitance: %.2f farads\n", circuit[i][1]);
                break;
            case 'L':
                printf("Inductance: %.2f henrys\n", circuit[i][1]);
                break;
            default:
                printf("Error: Invalid component type\n");
                break;
        }
    }
}

int main()
{
    int num_components = 5;
    int **circuit = (int **)malloc(num_components * MAX);

    circuit[0] = malloc(MAX);
    circuit[0][0] = 'R';
    circuit[0][1] = 10;

    circuit[1] = malloc(MAX);
    circuit[1][0] = 'C';
    circuit[1][1] = 2.2;

    circuit[2] = malloc(MAX);
    circuit[2][0] = 'L';
    circuit[2][1] = 0.5;

    circuit[3] = malloc(MAX);
    circuit[3][0] = 'R';
    circuit[3][1] = 5;

    circuit[4] = malloc(MAX);
    circuit[4][0] = 'C';
    circuit[4][1] = 1.5;

    circuit_simulator(circuit, num_components);

    free(circuit);

    return 0;
}
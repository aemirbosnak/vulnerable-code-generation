//Gemma-7B DATASET v1.0 Category: Classical Circuit Simulator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

void simulate_circuit(int **circuit, int num_components)
{
    for (int i = 0; i < num_components; i++)
    {
        switch (circuit[i][0])
        {
            case 'R':
                circuit[i][1] = (circuit[i][2] * circuit[i][3]) / circuit[i][1];
                break;
            case 'C':
                circuit[i][1] = circuit[i][2] * circuit[i][3] * M_PI;
                break;
            case 'L':
                circuit[i][1] = circuit[i][2] * circuit[i][3] * M_PI;
                break;
            case 'V':
                circuit[i][1] = circuit[i][2];
                break;
            default:
                printf("Error: Invalid circuit component type.\n");
                exit(1);
        }
    }
}

int main()
{
    int num_components;
    scanf("Number of circuit components: ", &num_components);

    int **circuit = (int **)malloc(num_components * sizeof(int *));
    for (int i = 0; i < num_components; i++)
    {
        circuit[i] = (int *)malloc(4 * sizeof(int));
    }

    for (int i = 0; i < num_components; i++)
    {
        printf("Enter component type, resistance, capacitance, and inductance: ");
        scanf("%c %d %d %d", circuit[i], &circuit[i][1], &circuit[i][2], &circuit[i][3]);
    }

    simulate_circuit(circuit, num_components);

    for (int i = 0; i < num_components; i++)
    {
        printf("Component %d: Voltage = %.2f\n", i + 1, circuit[i][1]);
    }

    free(circuit);

    return 0;
}
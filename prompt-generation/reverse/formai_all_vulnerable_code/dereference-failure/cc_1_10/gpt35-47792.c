//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: invasive
#include<stdio.h>
#include<stdlib.h>

#define MAX_NODES 15

int numOfNodes = 0; // number of nodes in circuit
double edgeList[MAX_NODES][MAX_NODES] = {0}; // matrix that stores the values of all the edges

// function to display the circuit matrix
void displayMatrix()
{
    printf("\nCircuit Matrix: \n");
    printf("    ");
    for(int i=1;i<=numOfNodes;i++)
        printf("V%d   ", i);
    printf("\n");
    for(int i=1;i<=numOfNodes;i++)
    {
        printf("V%d  ", i);
        for(int j=1;j<=numOfNodes;j++)
            printf("%0.1lf   ", edgeList[i][j]);
        printf("\n");
    }
    printf("\n");
}

// recursive function to calculate the voltage for each node in the circuit
void calculateVoltage(double *voltageList, int nodeAt)
{
    double sum = 0;
    for(int i=1;i<=numOfNodes;i++)
    {
        if(edgeList[nodeAt][i] != 0)
        {
            if(voltageList[i-1] == -1)
                calculateVoltage(voltageList, i-1);
            sum += edgeList[nodeAt][i] * voltageList[i-1];
        }
    }
    voltageList[nodeAt] = sum;
}

// function to solve the circuit
void solve()
{
    double *voltageList = (double*) malloc(numOfNodes * sizeof(double));
    for(int i=0;i<numOfNodes;i++)
        voltageList[i] = -1;

    calculateVoltage(voltageList, 0);

    printf("Solution:\n");
    for(int i=0;i<numOfNodes;i++)
        printf("V%d = %0.2lf\n", i+1, voltageList[i]);

    free(voltageList);
}

int main(int argc, char *argv[])
{
    printf("Enter the number of nodes in the circuit (max=15): ");
    scanf("%d", &numOfNodes);

    // enter values for the edges
    printf("\nEnter the values of the edges (enter 0 if no edge):\n");
    for(int i=1;i<=numOfNodes;i++)
    {
        for(int j=1;j<=numOfNodes;j++)
        {
            if(i == j)
                edgeList[i][j] = -1;
            else if(edgeList[i][j] == 0)
            {
                printf("V%d -> V%d : ", i, j);
                scanf("%lf", &edgeList[i][j]);
            }
            else
                edgeList[j][i] = edgeList[i][j];
        }
    }

    displayMatrix();
    solve();

    return 0;
}
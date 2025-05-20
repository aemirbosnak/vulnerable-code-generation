//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: optimized
#include<stdio.h>
#include<stdlib.h>

struct circuitElement //Structure for circuit elements 
{
    char elementName[10];
    int nodeA, nodeB;
    double value, conductance, voltage;
};

int main() 
{
    int numElements, numNodes, i, j, t;
    double timeStep, stopTime;

    printf("\nEnter the number of elements in the circuit: ");
    scanf("%d",&numElements);

    struct circuitElement nodeList[numElements]; //Array of circuit elements

    printf("\nEnter the number of nodes in the circuit: ");
    scanf("%d",&numNodes);

    double conductanceMatrix[numNodes][numNodes], voltageMatrix[numNodes][1]; //Matrices for conductance and voltage

    for(i=0;i<numNodes;i++) //Initialize matrix values to 0
    {
        for(j=0;j<numNodes;j++)
        {
            conductanceMatrix[i][j] = 0;
        }
        voltageMatrix[i][0] = 0;
    }

    for(i=0;i<numElements;i++) //Input all circuit element details
    {
        printf("\nEnter element %d name (R/L/C): ",i+1);
        scanf("%s",&nodeList[i].elementName);

        printf("\nEnter the nodes for element %d: ",i+1);
        scanf("%d %d",&nodeList[i].nodeA,&nodeList[i].nodeB);

        printf("\nEnter the value of element %d (in Farads, Henrys or Ohms): ",i+1);
        scanf("%lf",&nodeList[i].value);
    }

    printf("\nEnter the time-step for simulation (in seconds): ");
    scanf("%lf",&timeStep);

    printf("\nEnter the stop time for simulation (in seconds): ");
    scanf("%lf",&stopTime);

    t=0;
    while(t<=stopTime/timeStep) //Simulation loop
    {
        for(i=0;i<numNodes;i++) //Initialize voltage values to 0
        {
            voltageMatrix[i][0] = 0;
        }

        for(i=0;i<numElements;i++) //Update conductance and voltage matrices
        {
            if(nodeList[i].elementName[0] == 'R') //Resistor element
            {
                nodeList[i].conductance = 1/nodeList[i].value;
                conductanceMatrix[nodeList[i].nodeA-1][nodeList[i].nodeA-1] += nodeList[i].conductance;
                conductanceMatrix[nodeList[i].nodeB-1][nodeList[i].nodeB-1] += nodeList[i].conductance;
                conductanceMatrix[nodeList[i].nodeA-1][nodeList[i].nodeB-1] -= nodeList[i].conductance;
                conductanceMatrix[nodeList[i].nodeB-1][nodeList[i].nodeA-1] -= nodeList[i].conductance;
            }

            else if(nodeList[i].elementName[0] == 'L') //Inductor element
            {
                nodeList[i].conductance = 0; //Set conductance to 0 for inductors
                conductanceMatrix[nodeList[i].nodeA-1][nodeList[i].nodeA-1] += 1;
                conductanceMatrix[nodeList[i].nodeB-1][nodeList[i].nodeB-1] += 1;
                conductanceMatrix[nodeList[i].nodeA-1][nodeList[i].nodeB-1] -= 1;
                conductanceMatrix[nodeList[i].nodeB-1][nodeList[i].nodeA-1] -= 1;

                nodeList[i].voltage = nodeList[i].value*nodeList[i].conductance*(voltageMatrix[nodeList[i].nodeA-1][0]-voltageMatrix[nodeList[i].nodeB-1][0]); //Update voltage across inductor
                voltageMatrix[nodeList[i].nodeA-1][0] -= nodeList[i].voltage;
                voltageMatrix[nodeList[i].nodeB-1][0] += nodeList[i].voltage;
            }

            else if(nodeList[i].elementName[0] == 'C') //Capacitor element
            {
                nodeList[i].conductance = 0; //Set conductance to 0 for capacitors
                conductanceMatrix[nodeList[i].nodeA-1][nodeList[i].nodeA-1] += nodeList[i].value/timeStep;
                conductanceMatrix[nodeList[i].nodeB-1][nodeList[i].nodeB-1] += nodeList[i].value/timeStep;
                conductanceMatrix[nodeList[i].nodeA-1][nodeList[i].nodeB-1] -= nodeList[i].value/timeStep;
                conductanceMatrix[nodeList[i].nodeB-1][nodeList[i].nodeA-1] -= nodeList[i].value/timeStep;

                nodeList[i].voltage = nodeList[i].value*nodeList[i].conductance*(voltageMatrix[nodeList[i].nodeA-1][0]-voltageMatrix[nodeList[i].nodeB-1][0]); //Update voltage across capacitor
                voltageMatrix[nodeList[i].nodeA-1][0] -= nodeList[i].voltage;
                voltageMatrix[nodeList[i].nodeB-1][0] += nodeList[i].voltage;
            }
        }

        for(i=0;i<numNodes;i++) //Print node voltages
        {
            printf("\nNode %d voltage at time %lf: %lf",i+1,t*timeStep,voltageMatrix[i][0]);
        }

        t++;
    }

    return 0;
}
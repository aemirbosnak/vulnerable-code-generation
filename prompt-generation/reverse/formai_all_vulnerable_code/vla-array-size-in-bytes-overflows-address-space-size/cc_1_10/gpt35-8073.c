//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: thoughtful
#include <stdio.h>

/* Define maximum number of circuits and maximum circuit size */
#define MAX_CIRCUITS 10
#define MAX_SIZE 100

/* Define boolean variables */
#define TRUE 1
#define FALSE 0

/* Define a structure to define circuits */
typedef struct{
    int circuit[MAX_SIZE];  // Array to store circuit elements
    int size;               // Size of the circuit
} Circuit;

/* Define function to read circuits from input */
void readCircuits(Circuit circuits[], int numCircuits){
    int i, j;

    /* Loop through circuits */
    for(i=0; i<numCircuits; i++){
        /* Read size of circuit */
        scanf("%d", &circuits[i].size);

        /* Loop through elements of circuit */
        for(j=0; j<circuits[i].size; j++){
            scanf("%d", &circuits[i].circuit[j]);
        }
    }
}

/* Define function to simulate circuits */
void simulateCircuits(Circuit circuits[], int numCircuits, int input[]){
    int i, j, k, output;

    /* Loop through circuits */
    for(i=0; i<numCircuits; i++){
        output = input[0];

        /* Loop through elements of circuit */
        for(j=0; j<circuits[i].size; j++){
            /* Check if element is a gate */
            if(circuits[i].circuit[j] == 0){
                /* AND gate */
                if(circuits[i].circuit[j+1] == 1){
                    output = output && input[circuits[i].circuit[j+2]];
                    j += 2;
                }
                /* OR gate */
                else if(circuits[i].circuit[j+1] == 2){
                    output = output || input[circuits[i].circuit[j+2]];
                    j += 2;
                }
                /* NOT gate */
                else if(circuits[i].circuit[j+1] == 3){
                    output = !output;
                    j += 1;
                }
            }
            /* Check if element is an input */
            else{
                /* Loop through inputs and find matching input */
                for(k=0; k<input[0]+1; k++){
                    if(input[k] == circuits[i].circuit[j]){
                        output = input[k+1];
                        break;
                    }
                }
                j += 1;
            }
        }

        printf("%d\n", output);
    }
}

/* Define main function */
int main(){
    int i, numCircuits, numInputs;

    /* Read number of circuits */
    scanf("%d", &numCircuits);

    /* Define array of circuits */
    Circuit circuits[MAX_CIRCUITS];

    /* Read circuits from input */
    readCircuits(circuits, numCircuits);

    /* Read number of inputs */
    scanf("%d", &numInputs);

    /* Define array of inputs */
    int inputs[numInputs+1];

    /* Loop through inputs */
    for(i=0; i<numInputs+1; i++){
        scanf("%d", &inputs[i]);
    }

    /* Simulate circuits */
    simulateCircuits(circuits, numCircuits, inputs);

    return 0;
}
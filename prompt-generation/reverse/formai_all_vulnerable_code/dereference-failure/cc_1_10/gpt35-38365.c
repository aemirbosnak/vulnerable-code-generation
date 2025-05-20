//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: peaceful
/* 
 * Title: Classical Circuit Simulator
 * Author: Peaceful Programmer
 * Description: A program to simulate classical circuits that use logic gates.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUTS 10 // maximum number of inputs for the circuit
#define MAX_OUTPUTS 5 // maximum number of outputs for the circuit
#define MAX_GATES 100 // maximum number of gates for the circuit

// Represents a logic gate
typedef struct Gate
{
    int input1;
    int input2;
    int output;
    char type;
} Gate;

// Takes input from user for circuit inputs
void get_input(int *inputs, int num_inputs)
{
    printf("Enter the values for the %d circuit inputs (0 or 1):\n", num_inputs);
    for (int i = 0; i < num_inputs; i++)
    {
        printf("Input %d: ", i+1);
        scanf("%d", &inputs[i]);
    }
}

// Evaluates the provided logic gate and returns the output
int evaluate_gate(Gate gate, int *inputs, int num_inputs)
{
    int output;
    int in1 = inputs[gate.input1];
    int in2 = (gate.type == 'N' || gate.type == 'NOT') ? 0 : inputs[gate.input2]; // second input not needed for NOT and NAND gates

    if (gate.type == 'A' || gate.type == 'AND')
    {
        output = in1 && in2;
    }
    else if (gate.type == 'O' || gate.type == 'OR')
    {
        output = in1 || in2;
    }
    else if (gate.type == 'X' || gate.type == 'XOR')
    {
        output = in1 ^ in2;
    }
    else if (gate.type == 'N' || gate.type == 'NOT')
    {
        output = !in1;
    }
    else if (gate.type == 'D' || gate.type == 'NAND')
    {
        output = !(in1 && in2);
    }
    return output;
}

int main()
{
    int num_inputs, num_gates, num_outputs;

    printf("Welcome to the Classical Circuit Simulator!\n\n");

    // Take input for number of inputs, gates and outputs for the circuit
    printf("Please enter the number of circuit inputs (between 1 and %d): ", MAX_INPUTS);
    scanf("%d", &num_inputs);
    printf("Please enter the number of gates (between 1 and %d): ", MAX_GATES);
    scanf("%d", &num_gates);
    printf("Please enter the number of circuit outputs (between 1 and %d): ", MAX_OUTPUTS);
    scanf("%d", &num_outputs);

    // Declare arrays for inputs, gates and outputs
    int inputs[num_inputs];
    Gate gates[num_gates];
    int outputs[num_outputs];

    // Get input for circuit inputs
    get_input(inputs, num_inputs);

    // Take input for each gate in the circuit
    printf("\nEnter the details for each gate in the circuit:\n");
    for (int i = 0; i < num_gates; i++)
    {
        printf("Gate %d:\n", i+1);
        printf("Input 1: ");
        scanf("%d", &gates[i].input1);
        printf("Input 2: ");
        scanf("%d", &gates[i].input2);
        printf("Output: ");
        scanf("%d", &gates[i].output);
        printf("Gate type (A for AND, O for OR, X for XOR, N for NOT, D for NAND): ");
        scanf(" %c", &gates[i].type);
    }

    // Evaluate the output of each gate and store it in the outputs array
    printf("\n");
    for (int i = 0; i < num_outputs; i++)
    {
        int output_index;
        printf("Enter the index of the gate connected to output %d: ", i+1);
        scanf("%d", &output_index);
        outputs[i] = evaluate_gate(gates[output_index-1], inputs, num_inputs);
    }

    // Print the inputs, gates and outputs of the circuit
    printf("\nInputs:\n");
    for (int i = 0; i < num_inputs; i++)
    {
        printf("%d ", inputs[i]);
    }

    printf("\n\nGates:\n");
    for (int i = 0; i < num_gates; i++)
    {
        printf("%c %d %d %d\n", gates[i].type, gates[i].input1, gates[i].input2, gates[i].output);
    }

    printf("\nOutputs:\n");
    for (int i = 0; i < num_outputs; i++)
    {
        printf("%d ", outputs[i]);
    }

    printf("\n\nThank you for using the Classical Circuit Simulator!\n");

    return 0;
}
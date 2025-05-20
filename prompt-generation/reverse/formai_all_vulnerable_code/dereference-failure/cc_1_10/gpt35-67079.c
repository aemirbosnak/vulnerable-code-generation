//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: peaceful
/* This program simulates a basic digital logic circuit with four inputs and one output.
   The circuit implements the XOR function.
   
   Made with peace and kindness by a chatbot.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUM_INPUTS 4

typedef struct {
    bool state;
    bool prev_state;
} Input;

typedef struct {
    bool state;
    bool prev_state;
} Output;

typedef struct {
    Input *inputs[NUM_INPUTS];
    Output *output;
} Circuit;

Input *create_input() {
    Input *input = (Input *)malloc(sizeof(Input));
    input->state = false;
    input->prev_state = false;
    return input;
}

Output *create_output() {
    Output *output = (Output *)malloc(sizeof(Output));
    output->state = false;
    output->prev_state = false;
    return output;
}

Circuit *create_circuit() {
    Circuit *circuit = (Circuit *)malloc(sizeof(Circuit));
    int i;
    for (i = 0; i < NUM_INPUTS; i++) {
        circuit->inputs[i] = create_input();
    }
    circuit->output = create_output();
    return circuit;
}

void update_input(Input *input, bool state) {
    input->prev_state = input->state;
    input->state = state;
}

void update_output(Output *output, bool state) {
    output->prev_state = output->state;
    output->state = state;
}

bool xor(bool a, bool b) {
    return (a && !b) || (!a && b);
}

void update_circuit(Circuit *circuit) {
    bool input_states[NUM_INPUTS];
    int i;
    for (i = 0; i < NUM_INPUTS; i++) {
        input_states[i] = circuit->inputs[i]->state;
    }
    bool new_output_state = xor(xor(input_states[0], input_states[1]), xor(input_states[2], input_states[3]));
    update_output(circuit->output, new_output_state);
}

int main() {
    Circuit *circuit = create_circuit();
    
    printf("Initial state of inputs and output:\n");
    int i;
    for (i = 0; i < NUM_INPUTS; i++) {
        printf("Input %d: %d\n", i+1, circuit->inputs[i]->state);
    }
    printf("Output: %d\n", circuit->output->state);
    
    printf("\nEnter new input states:\n");
    bool new_input_states[NUM_INPUTS];
    for (i = 0; i < NUM_INPUTS; i++) {
        printf("Input %d: ", i+1);
        scanf("%d", &new_input_states[i]);
        update_input(circuit->inputs[i], new_input_states[i]);
    }
    
    update_circuit(circuit);
    printf("\nNew state of inputs and output:\n");
    for (i = 0; i < NUM_INPUTS; i++) {
        printf("Input %d: %d\n", i+1, circuit->inputs[i]->state);
    }
    printf("Output: %d\n", circuit->output->state);
    
    return 0;
}
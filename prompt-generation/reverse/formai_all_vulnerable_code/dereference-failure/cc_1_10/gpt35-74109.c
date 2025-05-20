//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100
#define MAX_GATE_COUNT 10
#define MAX_WIRE_COUNT 12

/* Define the available gates */
#define NOT 1
#define AND 2
#define OR 3
#define XOR 4

/* Define the gate struct */
typedef struct {
    int type;       /* The gate type */
    int input1;     /* The first input wire index */
    int input2;     /* The second input wire index */
    int output;     /* The output wire index */
} Gate;

/* Define the wire struct */
typedef struct {
    int value;      /* The current value of the wire (0 or 1) */
    int num_gates;  /* The number of gates using this wire */
    int gates[MAX_GATE_COUNT];  /* The indexes of the gates using this wire */
} Wire;

/* Declare the global variables */
int num_gates = 0;
Gate gates[MAX_GATE_COUNT];
int num_wires = 0;
Wire wires[MAX_WIRE_COUNT];

/* Declare the function prototypes */
void add_gate(int type, int input1, int input2, int output);
void connect_wires(int gate_index, int wire_index);
void disconnect_wires(int gate_index, int wire_index);
void update_wire(int wire_index, int value);
int get_wire_value(int wire_index);

int main() {
    char input[MAX_LINE_LENGTH];
    char *command, *arg1, *arg2, *arg3, *arg4;
    int gate_type, input1, input2, output, gate_index, wire_index, value;

    printf("Welcome to the Classical Circuit Simulator!\n");

    /* Read in the user commands */
    while (1) {
        printf("> ");
        fgets(input, MAX_LINE_LENGTH, stdin);
        command = strtok(input, " \n");
        arg1 = strtok(NULL, " \n");
        arg2 = strtok(NULL, " \n");
        arg3 = strtok(NULL, " \n");
        arg4 = strtok(NULL, " \n");

        if (strcmp(command, "exit") == 0) {
            /* Exit the program */
            printf("Goodbye!\n");
            break;
        } else if (strcmp(command, "gate") == 0) {
            /* Add a gate */
            if (arg1 == NULL || arg2 == NULL || arg3 == NULL) {
                printf("Error: invalid command.\n");
            } else {
                gate_type = atoi(arg1);
                input1 = atoi(arg2);
                input2 = atoi(arg3);
                output = atoi(arg4);
                add_gate(gate_type, input1, input2, output);
                printf("Added gate with type %d, input1 %d, input2 %d, output %d.\n", gate_type, input1, input2, output);
            }
        } else if (strcmp(command, "connect") == 0) {
            /* Connect a wire to a gate */
            if (arg1 == NULL || arg2 == NULL) {
                printf("Error: invalid command.\n");
            } else {
                gate_index = atoi(arg1);
                wire_index = atoi(arg2);
                connect_wires(gate_index, wire_index);
                printf("Connected wire %d to gate %d.\n", wire_index, gate_index);
            }
        } else if (strcmp(command, "disconnect") == 0) {
            /* Disconnect a wire from a gate */
            if (arg1 == NULL || arg2 == NULL) {
                printf("Error: invalid command.\n");
            } else {
                gate_index = atoi(arg1);
                wire_index = atoi(arg2);
                disconnect_wires(gate_index, wire_index);
                printf("Disconnected wire %d from gate %d.\n", wire_index, gate_index);
            }
        } else if (strcmp(command, "input") == 0) {
            /* Update an input wire */
            if (arg1 == NULL || arg2 == NULL) {
                printf("Error: invalid command.\n");
            } else {
                wire_index = atoi(arg1);
                value = atoi(arg2);
                update_wire(wire_index, value);
                printf("Updated wire %d to value %d.\n", wire_index, value);
            }
        } else if (strcmp(command, "output") == 0) {
            /* Output a wire value */
            if (arg1 == NULL) {
                printf("Error: invalid command.\n");
            } else {
                wire_index = atoi(arg1);
                value = get_wire_value(wire_index);
                printf("Wire %d has value %d.\n", wire_index, value);
            }
        } else {
            printf("Error: invalid command.\n");
        }
    }

    return 0;
}

/* Add a new gate */
void add_gate(int type, int input1, int input2, int output) {
    if (num_gates >= MAX_GATE_COUNT) {
        printf("Error: too many gates.\n");
        return;
    }

    /* Configure the new gate */
    gates[num_gates].type = type;
    gates[num_gates].input1 = input1;
    gates[num_gates].input2 = input2;
    gates[num_gates].output = output;

    /* Connect the input wires to the new gate */
    connect_wires(num_gates, input1);
    connect_wires(num_gates, input2);

    /* Connect the output wire to the new gate */
    connect_wires(num_gates, output);

    /* Increment the gate count */
    num_gates++;
}

/* Connect a wire to a gate */
void connect_wires(int gate_index, int wire_index) {
    /* Check that the wire and gate indexes are valid */
    if (wire_index >= MAX_WIRE_COUNT || gate_index >= MAX_GATE_COUNT) {
        printf("Error: invalid index.\n");
        return;
    }

    /* Check that the wire is not already connected to the gate */
    if (wires[wire_index].num_gates >= MAX_GATE_COUNT) {
        printf("Error: too many gates connected to wire.\n");
        return;
    }
    for (int i = 0; i < wires[wire_index].num_gates; i++) {
        if (wires[wire_index].gates[i] == gate_index) {
            printf("Error: wire already connected to gate.\n");
            return;
        }
    }

    /* Connect the wire to the gate */
    wires[wire_index].gates[wires[wire_index].num_gates] = gate_index;
    wires[wire_index].num_gates++;
}

/* Disconnect a wire from a gate */
void disconnect_wires(int gate_index, int wire_index) {
    /* Check that the wire and gate indexes are valid */
    if (wire_index >= MAX_WIRE_COUNT || gate_index >= MAX_GATE_COUNT) {
        printf("Error: invalid index.\n");
        return;
    }

    /* Check that the wire is connected to the gate */
    int found = 0;
    for (int i = 0; i < wires[wire_index].num_gates; i++) {
        if (wires[wire_index].gates[i] == gate_index) {
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Error: wire not connected to gate.\n");
        return;
    }

    /* Disconnect the wire from the gate */
    for (int i = 0; i < wires[wire_index].num_gates; i++) {
        if (wires[wire_index].gates[i] == gate_index) {
            wires[wire_index].gates[i] = wires[wire_index].gates[wires[wire_index].num_gates - 1];
            wires[wire_index].num_gates--;
            break;
        }
    }
}

/* Update the value of an input wire */
void update_wire(int wire_index, int value) {
    /* Check that the wire index is valid */
    if (wire_index >= MAX_WIRE_COUNT) {
        printf("Error: invalid index.\n");
        return;
    }

    /* Update the wire's value */
    wires[wire_index].value = value;

    /* Update the values of the gates connected to the wire */
    for (int i = 0; i < wires[wire_index].num_gates; i++) {
        int gate_index = wires[wire_index].gates[i];
        int input1 = gates[gate_index].input1;
        int input2 = gates[gate_index].input2;
        int output = gates[gate_index].output;
        int input_value1 = wires[input1].value;
        int input_value2 = wires[input2].value;
        int output_value;
        switch (gates[gate_index].type) {
            case NOT:
                output_value = !input_value1;
                break;
            case AND:
                output_value = input_value1 && input_value2;
                break;
            case OR:
                output_value = input_value1 || input_value2;
                break;
            case XOR:
                output_value = (input_value1 && !input_value2) || (!input_value1 && input_value2);
                break;
            default:
                printf("Error: invalid gate type.\n");
                return;
        }
        update_wire(output, output_value);
    }
}

/* Get the current value of a wire */
int get_wire_value(int wire_index) {
    /* Check that the wire index is valid */
    if (wire_index >= MAX_WIRE_COUNT) {
        printf("Error: invalid index.\n");
        return -1;
    }

    /* Return the wire's current value */
    return wires[wire_index].value;
}
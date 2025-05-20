//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int num_inputs;
    int num_outputs;
    int **truth_table;
} Gate;

Gate *create_gate(char *name, int num_inputs, int num_outputs) {
    Gate *gate = malloc(sizeof(Gate));
    gate->name = strdup(name);
    gate->num_inputs = num_inputs;
    gate->num_outputs = num_outputs;
    gate->truth_table = malloc(sizeof(int *) * (1 << num_inputs));
    for (int i = 0; i < (1 << num_inputs); i++) {
        gate->truth_table[i] = malloc(sizeof(int) * num_outputs);
    }
    return gate;
}

void destroy_gate(Gate *gate) {
    for (int i = 0; i < (1 << gate->num_inputs); i++) {
        free(gate->truth_table[i]);
    }
    free(gate->truth_table);
    free(gate->name);
    free(gate);
}

int main() {
    Gate *and_gate = create_gate("AND", 2, 1);
    and_gate->truth_table[0][0] = 0;
    and_gate->truth_table[0][1] = 0;
    and_gate->truth_table[1][0] = 0;
    and_gate->truth_table[1][1] = 1;

    Gate *or_gate = create_gate("OR", 2, 1);
    or_gate->truth_table[0][0] = 0;
    or_gate->truth_table[0][1] = 1;
    or_gate->truth_table[1][0] = 1;
    or_gate->truth_table[1][1] = 1;

    Gate *not_gate = create_gate("NOT", 1, 1);
    not_gate->truth_table[0][0] = 1;
    not_gate->truth_table[1][0] = 0;

    Gate *nand_gate = create_gate("NAND", 2, 1);
    for (int i = 0; i < (1 << 2); i++) {
        nand_gate->truth_table[i][0] = !(and_gate->truth_table[i][0]);
    }

    Gate *nor_gate = create_gate("NOR", 2, 1);
    for (int i = 0; i < (1 << 2); i++) {
        nor_gate->truth_table[i][0] = !(or_gate->truth_table[i][0]);
    }

    Gate *xor_gate = create_gate("XOR", 2, 1);
    for (int i = 0; i < (1 << 2); i++) {
        xor_gate->truth_table[i][0] = and_gate->truth_table[i][0] ^ or_gate->truth_table[i][0];
    }

    Gate *xnor_gate = create_gate("XNOR", 2, 1);
    for (int i = 0; i < (1 << 2); i++) {
        xnor_gate->truth_table[i][0] = !(and_gate->truth_table[i][0] ^ or_gate->truth_table[i][0]);
    }

    printf("Truth table for AND gate:\n");
    for (int i = 0; i < (1 << 2); i++) {
        printf("%d %d %d\n", (i >> 1) & 1, i & 1, and_gate->truth_table[i][0]);
    }

    printf("Truth table for OR gate:\n");
    for (int i = 0; i < (1 << 2); i++) {
        printf("%d %d %d\n", (i >> 1) & 1, i & 1, or_gate->truth_table[i][0]);
    }

    printf("Truth table for NOT gate:\n");
    for (int i = 0; i < (1 << 1); i++) {
        printf("%d %d\n", i, not_gate->truth_table[i][0]);
    }

    printf("Truth table for NAND gate:\n");
    for (int i = 0; i < (1 << 2); i++) {
        printf("%d %d %d\n", (i >> 1) & 1, i & 1, nand_gate->truth_table[i][0]);
    }

    printf("Truth table for NOR gate:\n");
    for (int i = 0; i < (1 << 2); i++) {
        printf("%d %d %d\n", (i >> 1) & 1, i & 1, nor_gate->truth_table[i][0]);
    }

    printf("Truth table for XOR gate:\n");
    for (int i = 0; i < (1 << 2); i++) {
        printf("%d %d %d\n", (i >> 1) & 1, i & 1, xor_gate->truth_table[i][0]);
    }

    printf("Truth table for XNOR gate:\n");
    for (int i = 0; i < (1 << 2); i++) {
        printf("%d %d %d\n", (i >> 1) & 1, i & 1, xnor_gate->truth_table[i][0]);
    }

    destroy_gate(and_gate);
    destroy_gate(or_gate);
    destroy_gate(not_gate);
    destroy_gate(nand_gate);
    destroy_gate(nor_gate);
    destroy_gate(xor_gate);
    destroy_gate(xnor_gate);

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node {
    char *name;
    double value;
    struct node *next;
};

struct circuit {
    struct node *start;
    struct node *end;
};

struct node *create_node(char *name, double value) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->name = name;
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

struct circuit *create_circuit(struct node *start, struct node *end) {
    struct circuit *new_circuit = malloc(sizeof(struct circuit));
    new_circuit->start = start;
    new_circuit->end = end;
    return new_circuit;
}

void print_circuit(struct circuit *circuit) {
    struct node *current_node = circuit->start;
    printf("Circuit:\n");
    while (current_node!= NULL) {
        printf("%s = %f\n", current_node->name, current_node->value);
        current_node = current_node->next;
    }
}

double evaluate_circuit(struct circuit *circuit) {
    struct node *current_node = circuit->start;
    double result = 0.0;
    while (current_node!= NULL) {
        if (current_node->next == NULL) {
            result = current_node->value;
        } else {
            result = evaluate_circuit(current_node->next);
        }
        current_node = current_node->next;
    }
    return result;
}

void free_circuit(struct circuit *circuit) {
    struct node *current_node = circuit->start;
    while (current_node!= NULL) {
        current_node = current_node->next;
        free(current_node->name);
        free(current_node);
    }
    free(circuit);
}

int main() {
    struct node *resistor_node = create_node("R1", 1000.0);
    struct node *capacitor_node = create_node("C1", 1.0);
    struct node *voltage_source_node = create_node("V1", 5.0);
    struct node *ground_node = create_node("GND", 0.0);

    struct circuit *simple_circuit = create_circuit(voltage_source_node, ground_node);
    voltage_source_node->next = resistor_node;
    resistor_node->next = capacitor_node;
    capacitor_node->next = ground_node;

    print_circuit(simple_circuit);
    double output_voltage = evaluate_circuit(simple_circuit);
    printf("Output voltage: %f\n", output_voltage);

    free_circuit(simple_circuit);

    return 0;
}
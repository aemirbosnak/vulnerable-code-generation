//Falcon2-11B DATASET v1.0 Category: Classical Circuit Simulator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NUM_COMPONENTS 10
#define MAX_COMPONENT_NAME_LENGTH 10
#define MAX_COMPONENT_PARAM_LENGTH 20

struct component {
    char name[MAX_COMPONENT_NAME_LENGTH];
    char param[MAX_COMPONENT_PARAM_LENGTH];
    int id;
    struct component *next;
};

struct component *head = NULL;

void add_component(struct component *new_component) {
    new_component->next = head;
    head = new_component;
}

void delete_component(struct component *del_component) {
    if (del_component == head) {
        head = head->next;
        free(del_component);
    } else {
        struct component *current = head;
        while (current->next!= del_component) {
            current = current->next;
        }
        current->next = del_component->next;
        free(del_component);
    }
}

void print_components() {
    struct component *current = head;
    printf("Component List:\n");
    while (current!= NULL) {
        printf("%s (%d) - %s\n", current->name, current->id, current->param);
        current = current->next;
    }
}

void simulate() {
    struct component *current = head;
    while (current!= NULL) {
        printf("Simulating component %s (%d) - %s...\n", current->name, current->id, current->param);
        // Add your simulation code here
        // Example:
        float output = 0.0;
        float input = 0.0;
        switch (current->id) {
            case 1:
                input = current->param[0] + current->param[1] * sin(current->param[2]);
                output = exp(-input);
                break;
            case 2:
                input = current->param[0] * cos(current->param[1]);
                output = sin(input);
                break;
            case 3:
                input = current->param[0] - current->param[1] * cos(current->param[2]);
                output = log(input);
                break;
            default:
                printf("Unknown component ID: %d\n", current->id);
                break;
        }
        printf("Output: %f\n", output);
        current = current->next;
    }
}

int main() {
    printf("Circuit Simulator\n");

    add_component(malloc(sizeof(struct component)));
    strcpy(head->name, "Resistor");
    strcpy(head->param, "R");
    head->id = 1;
    head->next = NULL;

    add_component(malloc(sizeof(struct component)));
    strcpy(head->name, "Capacitor");
    strcpy(head->param, "C");
    head->id = 2;
    head->next = NULL;

    add_component(malloc(sizeof(struct component)));
    strcpy(head->name, "Voltmeter");
    strcpy(head->param, "V");
    head->id = 3;
    head->next = NULL;

    add_component(malloc(sizeof(struct component)));
    strcpy(head->name, "Amperemeter");
    strcpy(head->param, "I");
    head->id = 4;
    head->next = NULL;

    add_component(malloc(sizeof(struct component)));
    strcpy(head->name, "Variable Resistor");
    strcpy(head->param, "Rv");
    head->id = 5;
    head->next = NULL;

    add_component(malloc(sizeof(struct component)));
    strcpy(head->name, "Variable Capacitor");
    strcpy(head->param, "Cv");
    head->id = 6;
    head->next = NULL;

    add_component(malloc(sizeof(struct component)));
    strcpy(head->name, "Voltage Source");
    strcpy(head->param, "V");
    head->id = 7;
    head->next = NULL;

    add_component(malloc(sizeof(struct component)));
    strcpy(head->name, "Current Source");
    strcpy(head->param, "I");
    head->id = 8;
    head->next = NULL;

    add_component(malloc(sizeof(struct component)));
    strcpy(head->name, "Inductor");
    strcpy(head->param, "L");
    head->id = 9;
    head->next = NULL;

    add_component(malloc(sizeof(struct component)));
    strcpy(head->name, "Transistor");
    strcpy(head->param, "T");
    head->id = 10;
    head->next = NULL;

    simulate();

    printf("Simulation Complete\n");

    return 0;
}
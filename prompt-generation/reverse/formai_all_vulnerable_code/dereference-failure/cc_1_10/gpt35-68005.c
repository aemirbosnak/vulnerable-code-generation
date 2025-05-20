//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: lively
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_INPUT_LEN 100

typedef struct Node {
    char name[30];
    char voltage[10];
    struct Node *next;
} Node;

typedef struct {
    char name[30];
    double value;
} Resistor;

double voltage(char *value) {
    double n = atof(value);
    char suffix = value[strlen(value) - 1];

    if (suffix == 'V')
        return n;
    else if (suffix == 'm')
        return n / 1000.0;
    else if (suffix == 'k')
        return n * 1000.0;
    else if (suffix == 'M')
        return n * 1000000.0;
    else
        return -1;
}

int main() {
    char input[MAX_INPUT_LEN];
    char *tokens[10];
    int tokens_count, i;

    Node *head = NULL;
    Resistor resistors[10];
    int resistors_count = 0;

    while (1) {
        printf(">>> ");
        fgets(input, MAX_INPUT_LEN, stdin);
        tokens_count = 0;
        tokens[tokens_count++] = strtok(input, " \n");

        while ((tokens[tokens_count++] = strtok(NULL, " \n")) != NULL);

        if (tokens_count > 4) {
            printf("Invalid command!\n");
            continue;
        }

        if (strcmp(tokens[0], "add_node") == 0) {
            Node *new_node = (Node*) malloc(sizeof(Node));
            strcpy(new_node->name, tokens[1]);
            strcpy(new_node->voltage, tokens[2]);
            new_node->next = head;
            head = new_node;
        } else if (strcmp(tokens[0], "add_resistor") == 0) {
            Resistor new_resistor;
            strcpy(new_resistor.name, tokens[1]);
            new_resistor.value = atof(tokens[2]);
            resistors[resistors_count++] = new_resistor;
        } else if (strcmp(tokens[0], "simulate") == 0) {
            double total_resistance = 0;

            for (i = 0; i < resistors_count; ++i)
                total_resistance += resistors[i].value;

            Node *temp = head;
            double total_voltage = voltage(temp->voltage); 

            while (temp != NULL) {
                printf("%s: %f V\n", temp->name, total_voltage * resistors_count / (resistors_count + total_resistance));
                temp = temp->next;
            }
        } else if (strcmp(tokens[0], "exit") == 0)
            break;
        else
            printf("Invalid command!\n");
    }

    return 0;
}
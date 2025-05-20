//GEMINI-pro DATASET v1.0 Category: Periodic Table Quiz ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_TABLE_SIZE 118

typedef struct {
    char *symbol;
    char *name;
    int atomic_number;
    double atomic_mass;
} element;

element periodic_table[MAX_TABLE_SIZE];

void load_periodic_table() {
    FILE *fp = fopen("periodic_table.csv", "r");
    if (fp == NULL) {
        perror("Error opening periodic_table.csv");
        exit(EXIT_FAILURE);
    }

    char line[1024];
    int i = 0;
    while (fgets(line, sizeof(line), fp)) {
        char *symbol = strtok(line, ",");
        char *name = strtok(NULL, ",");
        int atomic_number = atoi(strtok(NULL, ","));
        double atomic_mass = atof(strtok(NULL, ","));

        periodic_table[i].symbol = strdup(symbol);
        periodic_table[i].name = strdup(name);
        periodic_table[i].atomic_number = atomic_number;
        periodic_table[i].atomic_mass = atomic_mass;

        i++;
    }

    fclose(fp);
}

void free_periodic_table() {
    for (int i = 0; i < MAX_TABLE_SIZE; i++) {
        free(periodic_table[i].symbol);
        free(periodic_table[i].name);
    }
}

int main() {
    load_periodic_table();

    char input[1024];
    int correct = 0;
    int incorrect = 0;

    printf("Welcome to the Periodic Table Quiz!\n");
    printf("Enter the symbol, name, or atomic number of an element to test your knowledge.\n");
    printf("Enter 'quit' to exit the quiz.\n");

    while (1) {
        printf("\n> ");
        fgets(input, sizeof(input), stdin);

        if (strcmp(input, "quit\n") == 0) {
            break;
        }

        int found = 0;
        for (int i = 0; i < MAX_TABLE_SIZE; i++) {
            if (strcmp(input, periodic_table[i].symbol) == 0) {
                printf("Correct! %s is the symbol for %s, which has an atomic number of %d and an atomic mass of %.2f.\n",
                    periodic_table[i].symbol, periodic_table[i].name, periodic_table[i].atomic_number, periodic_table[i].atomic_mass);
                correct++;
                found = 1;
                break;
            } else if (strcmp(input, periodic_table[i].name) == 0) {
                printf("Correct! %s is the name of %s, which has an atomic number of %d and an atomic mass of %.2f.\n",
                    periodic_table[i].name, periodic_table[i].symbol, periodic_table[i].atomic_number, periodic_table[i].atomic_mass);
                correct++;
                found = 1;
                break;
            } else if (atoi(input) == periodic_table[i].atomic_number) {
                printf("Correct! %d is the atomic number of %s, which has the symbol %s and an atomic mass of %.2f.\n",
                    periodic_table[i].atomic_number, periodic_table[i].name, periodic_table[i].symbol, periodic_table[i].atomic_mass);
                correct++;
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("Incorrect. Please try again.\n");
            incorrect++;
        }
    }

    printf("\nQuiz results:\n");
    printf("Correct answers: %d\n", correct);
    printf("Incorrect answers: %d\n", incorrect);

    free_periodic_table();
    return 0;
}
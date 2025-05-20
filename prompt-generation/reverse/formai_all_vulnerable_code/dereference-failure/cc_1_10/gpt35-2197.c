//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NUM_ELEMENTS 118
#define MAX_NAME_LENGTH 20
#define MAX_SYMBOL_LENGTH 3

struct element {
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_SYMBOL_LENGTH];
    int atomic_number;
    float atomic_weight;
};

void parse_file(struct element *elements, char *filename);
void print_element(struct element e);
void quiz(struct element *elements);

int main() {
    struct element elements[NUM_ELEMENTS];
    char *filename = "periodic_table.txt";

    parse_file(elements, filename);
    quiz(elements);

    return 0;
}

void parse_file(struct element *elements, char *filename) {
    FILE *file = fopen(filename, "r");
    char line[MAX_NAME_LENGTH + MAX_SYMBOL_LENGTH + 10];
    char *name, *symbol, *atomic_number, *atomic_weight;

    if (file == NULL) {
        fprintf(stderr, "Error: File '%s' not found.\n", filename);
        exit(1);
    }

    for (int i = 0; i < NUM_ELEMENTS; i++) {
        fgets(line, sizeof(line), file);
        line[strlen(line) - 1] = '\0';

        name = strtok(line, ",");
        symbol = strtok(NULL, ",");
        atomic_number = strtok(NULL, ",");
        atomic_weight = strtok(NULL, ",");

        strncpy(elements[i].name, name, sizeof(elements[i].name));
        strncpy(elements[i].symbol, symbol, sizeof(elements[i].symbol));
        elements[i].atomic_number = atoi(atomic_number);
        elements[i].atomic_weight = atof(atomic_weight);
    }

    fclose(file);
}

void print_element(struct element e) {
    printf("%s (%s)\n", e.name, e.symbol);
}

void quiz(struct element *elements) {
    int num_correct = 0;
    char guess[MAX_SYMBOL_LENGTH];
    int random_index;
    int done[NUM_ELEMENTS] = { 0 }; // Keeps track of which elements have been asked already

    printf("Welcome to the periodic table quiz!\n");
    printf("You will be asked to guess the symbol of a randomly selected element.\n");
    printf("Type 'quit' to exit the quiz.\n\n");

    while (1) {
        random_index = rand() % NUM_ELEMENTS;

        if (done[random_index] == 0) {
            printf("Guess the symbol of the element with atomic number %d: ", elements[random_index].atomic_number);
            scanf("%s", guess);

            if (strcmp(guess, "quit") == 0) {
                break;
            }

            // Convert guess to uppercase
            for (int i = 0; i < strlen(guess); i++) {
                guess[i] = toupper(guess[i]);
            }

            if (strcmp(guess, elements[random_index].symbol) == 0) {
                printf("Correct!\n\n");
                num_correct++;
            } else {
                printf("Incorrect. The correct symbol is '%s'.\n\n", elements[random_index].symbol);
            }

            done[random_index] = 1;
        }

        // Check if all elements have been asked already
        int all_done = 1;
        for (int i = 0; i < NUM_ELEMENTS; i++) {
            if (done[i] == 0) {
                all_done = 0;
            }
        }

        if (all_done) {
            break;
        }
    }

    printf("Quiz complete! You got %d out of %d correct.\n", num_correct, NUM_ELEMENTS);
}
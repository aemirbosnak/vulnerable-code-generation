//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_ELEMENTS 118

typedef struct element {
    char name[25];
    char symbol[3];
    int atomic_number;
    int atomic_weight;
} element;

int score = 0;

// Function to initialize elements array
void initialize_elements(element elements[]) {
    FILE *fp = fopen("periodic_table.txt", "r");
    if (fp == NULL) {
        printf("Error opening file!");
        exit(1);
    }

    char line[256];
    int i = 0;
    while (fgets(line, sizeof(line), fp)) {
        char *name = strtok(line, ",");
        char *symbol = strtok(NULL, ",");
        int atomic_number = atoi(strtok(NULL, ","));
        int atomic_weight = atoi(strtok(NULL, ","));

        strcpy(elements[i].name, name);
        strcpy(elements[i].symbol, symbol);
        elements[i].atomic_number = atomic_number;
        elements[i].atomic_weight = atomic_weight;
        i++;
    }

    fclose(fp);
}

// Function to shuffle elements array
void shuffle_elements(element elements[]) {
    srand(time(NULL));

    for (int i = NUM_ELEMENTS - 1; i > 0; i--) {
        int j = rand() % (i + 1);

        element temp = elements[i];
        elements[i] = elements[j];
        elements[j] = temp;
    }
}

// Function to get user input and check if correct
void get_input(element current_element) {
    char input[3];
    printf("What is the symbol for %s? ", current_element.name);
    scanf("%s", input);

    if (strcmp(input, current_element.symbol) == 0) {
        printf("Correct! +10 points\n");
        score += 10;
    } else {
        printf("Incorrect! The correct answer is %s.\n", current_element.symbol);
    }
}

// Function to play the game
void play_game(element elements[]) {
    int num_questions = 10;
    printf("Welcome to the Periodic Table Quiz! You will be asked %d questions.\n", num_questions);

    for (int i = 0; i < num_questions; i++) {
        printf("Question %d:\n", i + 1);
        element current_element = elements[i];
        get_input(current_element);
    }

    printf("Final score: %d out of %d\n", score, num_questions * 10);
}

int main() {
    element elements[NUM_ELEMENTS];
    initialize_elements(elements);
    shuffle_elements(elements);
    play_game(elements);

    return 0;
}
//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_QUESTIONS 10
#define ELEMENT_NAME_LENGTH 20
#define SYMBOL_LENGTH 5

typedef struct {
    char name[ELEMENT_NAME_LENGTH];
    char symbol[SYMBOL_LENGTH];
} Element;

Element periodicTable[] = {
    {"Hydrogen", "H"},
    {"Helium", "He"},
    {"Lithium", "Li"},
    {"Beryllium", "Be"},
    {"Boron", "B"},
    {"Carbon", "C"},
    {"Nitrogen", "N"},
    {"Oxygen", "O"},
    {"Fluorine", "F"},
    {"Neon", "Ne"},
    {"Sodium", "Na"},
    {"Magnesium", "Mg"},
    {"Aluminum", "Al"},
    {"Silicon", "Si"},
    {"Phosphorus", "P"},
    {"Sulfur", "S"},
    {"Chlorine", "Cl"},
    {"Argon", "Ar"},
    {"Potassium", "K"},
    {"Calcium", "Ca"},
    // Add more elements if necessary
};

int totalElements = sizeof(periodicTable) / sizeof(periodicTable[0]);

void shuffleElements() {
    srand(time(NULL));
    for (int i = totalElements - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Element temp = periodicTable[i];
        periodicTable[i] = periodicTable[j];
        periodicTable[j] = temp;
    }
}

void displayInstructions() {
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will be asked to match the name of an element to its symbol.\n");
    printf("Type the correct symbol for each element.\n");
    printf("You will have %d questions. Let's start!\n\n", MAX_QUESTIONS);
}

char* getAnswer(char *buffer) {
    printf("Your answer: ");
    fgets(buffer, SYMBOL_LENGTH, stdin);
    size_t len = strlen(buffer);
    if (buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0'; // Remove newline character
    }
    return buffer;
}

void startQuiz() {
    char answer[SYMBOL_LENGTH];
    int score = 0;

    for (int i = 0; i < MAX_QUESTIONS; i++) {
        printf("Question %d: What is the symbol for %s? ", i+1, periodicTable[i].name);
        
        getAnswer(answer);
        
        if (strcasecmp(answer, periodicTable[i].symbol) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect! The correct answer is %s.\n", periodicTable[i].symbol);
        }
    }

    printf("\nQuiz complete! Your score: %d/%d\n", score, MAX_QUESTIONS);
}

int main() {
    shuffleElements();
    displayInstructions();
    startQuiz();
    return 0;
}
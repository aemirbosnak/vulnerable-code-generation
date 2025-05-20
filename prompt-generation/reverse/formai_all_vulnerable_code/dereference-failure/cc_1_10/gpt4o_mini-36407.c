//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ELEMENTS 10
#define MAX_NAME_LENGTH 20
#define QUESTION_COUNT 5

typedef struct {
    char name[MAX_NAME_LENGTH];
    char symbol[3];
    int atomicNumber;
} Element;

Element periodicTable[MAX_ELEMENTS] = {
    {"Hydrogen", "H", 1},
    {"Helium", "He", 2},
    {"Lithium", "Li", 3},
    {"Beryllium", "Be", 4},
    {"Boron", "B", 5},
    {"Carbon", "C", 6},
    {"Nitrogen", "N", 7},
    {"Oxygen", "O", 8},
    {"Fluorine", "F", 9},
    {"Neon", "Ne", 10}
};

void displayIntro() {
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("Test your knowledge of the first 10 elements in the periodic table.\n");
    printf("Type the correct answer and press Enter.\n\n");
}

void askQuestion(int index) {
    printf("What is the symbol of %s? ", periodicTable[index].name);
}

int getUserInput(char *userInput) {
    fgets(userInput, MAX_NAME_LENGTH, stdin);
    userInput[strcspn(userInput, "\n")] = '\0'; // Strip newline character
    return strlen(userInput) > 0;
}

void quiz() {
    char userAnswer[3];
    int score = 0;
    int askedIndices[QUESTION_COUNT];
    srand(time(NULL));

    for (int i = 0; i < QUESTION_COUNT; i++) {
        int index;
        while (1) {
            index = rand() % MAX_ELEMENTS;
            // Check for duplicates
            int found = 0;
            for (int j = 0; j < i; j++) {
                if (askedIndices[j] == index) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                askedIndices[i] = index;
                break;
            }
        }

        askQuestion(index);
        if (getUserInput(userAnswer)) {
            if (strcasecmp(userAnswer, periodicTable[index].symbol) == 0) {
                printf("Correct!\n\n");
                score++;
            } else {
                printf("Incorrect! The correct answer is %s.\n\n", periodicTable[index].symbol);
            }
        }
    }

    printf("Your total score: %d out of %d\n", score, QUESTION_COUNT);
}

int main() {
    displayIntro();
    quiz();
    
    printf("Thank you for participating in the Periodic Table Quiz!\n");
    return 0;
}
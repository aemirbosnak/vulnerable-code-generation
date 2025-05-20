//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_ELEMENTS 118
#define MAX_NAME_LENGTH 20

typedef struct Element {
    int atomicNumber;
    char symbol[3];
    char name[MAX_NAME_LENGTH];
    float atomicMass;
    int groupNumber;
    int period;
} Element;

void printWelcomeMessage();
void initializeElements(Element *elements);
void printInstructions();
void runQuiz(Element *elements);

int main() {
    Element elements[NUM_ELEMENTS];
    initializeElements(elements);
    printWelcomeMessage();
    printInstructions();
    runQuiz(elements);
    return 0;
}

void initializeElements(Element *elements) {
    // Initialize elements using data from the periodic table
}

void printWelcomeMessage() {
    printf("Welcome to the C Periodic Table Quiz! Test your knowledge of the elements.\n\n");
}

void printInstructions() {
    printf("Instructions: Enter the atomic symbol of the element whose atomic number and group number are given.\n\n");
}

void runQuiz(Element *elements) {
    int score = 0;
    srand(time(NULL));
    int i;
    for (i = 0; i < 10; i++) {
        int index = rand() % NUM_ELEMENTS;
        Element *element = &elements[index];
        int atomicNumber = element->atomicNumber;
        int groupNumber = element->groupNumber;
        printf("Element %d is in group %d and has an atomic number of %d. What is the symbol of this element? ", i+1, groupNumber, atomicNumber);
        char answer[3];
        scanf("%2s", answer);
        if (strcmp(answer, element->symbol) == 0) {
            score++;
            printf("Correct!\n\n");
        } else {
            printf("Incorrect! The correct answer is %s.\n\n", element->symbol);
        }
    }
    printf("Quiz complete! You scored %d out of 10.\n", score);
}
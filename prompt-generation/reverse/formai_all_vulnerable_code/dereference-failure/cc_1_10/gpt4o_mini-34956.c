//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 118
#define MAX_NAME_LENGTH 20
#define NUM_QUESTIONS 5

typedef struct {
    int atomicNumber;
    char name[MAX_NAME_LENGTH];
    char symbol[3];
    float atomicWeight;
} Element;

Element periodicTable[MAX_ELEMENTS] = {
    {1, "Hydrogen", "H", 1.008},
    {2, "Helium", "He", 4.0026},
    {3, "Lithium", "Li", 6.94},
    {4, "Beryllium", "Be", 9.0122},
    {5, "Boron", "B", 10.81},
    {6, "Carbon", "C", 12.011},
    {7, "Nitrogen", "N", 14.007},
    {8, "Oxygen", "O", 15.999},
    {9, "Fluorine", "F", 18.998},
    {10, "Neon", "Ne", 20.180},
    // More elements would go here...
    {118, "Oganesson", "Og", 294},
};

void displayInstructions() {
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will be asked %d questions about elements.\n", NUM_QUESTIONS);
    printf("Answer with the correct element based on the atomic number, name, or symbol.\n");
    printf("Type 'exit' to end the quiz at any time.\n\n");
}

int getRandomQuestionIndex() {
    return rand() % MAX_ELEMENTS;
}

int checkAnswer(int atomicNumber, char *answer) {
    if (strcmp(answer, periodicTable[atomicNumber - 1].name) == 0 || 
        strcmp(answer, periodicTable[atomicNumber - 1].symbol) == 0) {
        return 1; // Correct
    }
    return 0; // Incorrect
}

void startQuiz() {
    char answer[MAX_NAME_LENGTH];
    int score = 0;

    for (int i = 0; i < NUM_QUESTIONS; i++) {
        int questionIndex = getRandomQuestionIndex();
        printf("Question %d: What is the element name or symbol for atomic number %d?\n", 
               i + 1, periodicTable[questionIndex].atomicNumber);
        
        printf("Your answer: ");
        fgets(answer, MAX_NAME_LENGTH, stdin);
        answer[strcspn(answer, "\n")] = 0; // Remove newline character
        
        if (strcmp(answer, "exit") == 0) {
            break;
        }

        if (checkAnswer(periodicTable[questionIndex].atomicNumber, answer)) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect! The correct answer is %s (%s).\n", 
                   periodicTable[questionIndex].name, periodicTable[questionIndex].symbol);
        }
        printf("\n");
    }

    printf("Quiz finished! Your score: %d/%d\n", score, NUM_QUESTIONS);
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    displayInstructions();
    startQuiz();
    return 0;
}
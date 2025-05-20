//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: portable
#include <stdio.h>
#include <string.h>

typedef struct element {
    char symbol[3];
    char name[30];
    int atomicNumber;
    float atomicMass;
    char electronConfig[30];
} Element;

int main() {

    // Initializing and populating array of elements
    Element elements[118];
    strcpy(elements[0].symbol, "H");
    strcpy(elements[0].name, "Hydrogen");
    elements[0].atomicNumber = 1;
    elements[0].atomicMass = 1.008;
    strcpy(elements[0].electronConfig, "1s1");

    strcpy(elements[1].symbol, "He");
    strcpy(elements[1].name, "Helium");
    elements[1].atomicNumber = 2;
    elements[1].atomicMass = 4.003;
    strcpy(elements[1].electronConfig, "1s2");

    // Populating the rest of the elements

    // Initializing variables for the quiz
    int numQuestions;
    int score = 0;

    printf("Welcome to the Periodic Table Quiz!\n");
    printf("How many questions would you like to answer? (Enter a number between 1 and 118)\n");
    scanf("%d", &numQuestions);

    // Generating random question numbers
    int questionNumbers[numQuestions];
    int possibleQuestions[118];
    for (int i = 0; i < 118; i++) {
        possibleQuestions[i] = i;
    }
    for (int i = 0; i < numQuestions; i++) {
        int randomIndex = rand() % (118 - i);
        questionNumbers[i] = possibleQuestions[randomIndex];
        possibleQuestions[randomIndex] = possibleQuestions[117 - i];
    }

    // Asking the questions
    for (int i = 0; i < numQuestions; i++) {
        int answerNumber;
        printf("Question %d\n", i+1);
        printf("What is the symbol for the element with atomic number %d?\n", elements[questionNumbers[i]].atomicNumber);
        for (int j = 0; j < numQuestions; j++) {
            printf("%d. %s\n", j+1, elements[questionNumbers[j]].symbol);
        }
        scanf("%d", &answerNumber);
        if (answerNumber == (questionNumbers[i] + 1)) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer was %s\n", elements[questionNumbers[i]].symbol);
        }
    }

    // Displaying final score
    printf("\nQuiz complete! You got %d out of %d questions correct.\n", score, numQuestions);

    return 0;
}
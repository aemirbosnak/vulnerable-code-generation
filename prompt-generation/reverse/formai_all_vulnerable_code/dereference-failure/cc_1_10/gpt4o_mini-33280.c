//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 118
#define MAX_NAME_LENGTH 20

typedef struct {
    int atomicNumber;
    char name[MAX_NAME_LENGTH];
    char symbol[3];
    float atomicWeight;
} Element;

void initializePeriodicTable(Element periodicTable[]);
void displayElement(const Element* element);
void quizUser(Element periodicTable[]);
int getRandomElementIndex(int maxIndex);
void clearInputBuffer();

int main() {
    Element periodicTable[MAX_ELEMENTS];
    initializePeriodicTable(periodicTable);
    quizUser(periodicTable);
    
    return 0;
}

void initializePeriodicTable(Element periodicTable[]) {
    // Sample initialization of a few elements
    periodicTable[0] = (Element){1, "Hydrogen", "H", 1.008};
    periodicTable[1] = (Element){2, "Helium", "He", 4.0026};
    periodicTable[2] = (Element){3, "Lithium", "Li", 6.94};
    periodicTable[3] = (Element){4, "Beryllium", "Be", 9.0122};
    // More elements can be added...

    // Assuming the remaining elements are initialized in a similar way...
    // Skipped initialization code for brevity
}

void displayElement(const Element* element) {
    printf("Element: %s\n", element->name);
    printf("Symbol: %s\n", element->symbol);
    printf("Atomic Number: %d\n", element->atomicNumber);
    printf("Atomic Weight: %.4f\n", element->atomicWeight);
}

void quizUser(Element periodicTable[]) {
    int score = 0;
    int totalQuestions = 5; // Total questions to ask
    srand(time(NULL)); // Seed random number generator

    for (int i = 0; i < totalQuestions; i++) {
        int randomIndex = getRandomElementIndex(MAX_ELEMENTS);
        
        // Asking user about element name
        printf("Question %d: What is the symbol of the element with atomic number %d?\n", i + 1, periodicTable[randomIndex].atomicNumber);
        char userAnswer[3];
        printf("Your answer: ");
        scanf("%2s", userAnswer);
        
        // Check answer
        if (strcmp(userAnswer, periodicTable[randomIndex].symbol) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Wrong! The correct answer is %s.\n", periodicTable[randomIndex].symbol);
        }
        clearInputBuffer(); // Clear newline from input buffer
    }

    printf("Quiz Over! Your score: %d out of %d\n", score, totalQuestions);
}

int getRandomElementIndex(int maxIndex) {
    return rand() % maxIndex; // Get a random index
}

void clearInputBuffer() {
    while (getchar() != '\n'); // Clear the input buffer
}
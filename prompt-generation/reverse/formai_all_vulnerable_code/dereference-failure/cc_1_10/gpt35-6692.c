//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_QUESTIONS 20
#define MAX_ANSWER_LENGTH 20

char* elements[118][3] = {
    {"1", "H", "Hydrogen"},
    {"2", "He", "Helium"},
    {"3", "Li", "Lithium"},
    // More elements are listed here...
    {"117", "Ts", "Tennessine"},
    {"118", "Og", "Oganesson"}
    };

char* questions[MAX_QUESTIONS][3] = {
    {"What is the symbol for Hydrogen?", "H"},
    {"What is the atomic number for Carbon?", "6"},
    {"What is the name of the element with the symbol Ag?", "Silver"},
    // More questions are listed here...
    {"What is the symbol for the element with atomic number 118?", "Og"}
    };

int main() {
    srand(time(NULL)); // Seed the random number generator
    
    int num_questions; // Number of questions for the quiz
    printf("How many questions would you like to answer? (maximum: %d)\n", MAX_QUESTIONS);
    scanf("%d", &num_questions);
    if (num_questions < 1 || num_questions > MAX_QUESTIONS) {
        printf("Invalid number of questions. Please choose a number between 1 and %d.\n", MAX_QUESTIONS);
        return 1;
    }
    
    int selected_questions[MAX_QUESTIONS]; // Array to keep track of which questions have been selected
    
    int i, j;
    for (i = 0; i < num_questions; i++) {
        int q = rand() % MAX_QUESTIONS; // Choose a random question
        while (selected_questions[q] == 1) { // Loop until an unused question is found
            q = rand() % MAX_QUESTIONS;
        }
        selected_questions[q] = 1; // Mark the question as selected
        
        printf("\nQuestion %d: %s\n", i+1, questions[q][0]);
        
        int valid_answer = 0;
        char answer[MAX_ANSWER_LENGTH];
        while (!valid_answer) { // Keep asking for an answer until a valid one is provided
            printf("Answer: ");
            scanf("%s", answer);
            
            if (strcmp(answer, questions[q][1]) == 0) {
                printf("Correct!\n");
                valid_answer = 1;
            } else {
                printf("Incorrect. Try again.\n");
            }
        }
    }
    
    printf("\nQuiz complete!\n\n");
    
    for (i = 0; i < 118; i++) {
        printf("%-3s ", elements[i][1]);
        if ((i+1) % 16 == 0) printf("\n"); // Print a newline every 16 elements
    }
    
    return 0;
}
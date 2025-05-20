//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMBER_OF_ELEMENTS 118  // Number of elements in the periodic table
#define NUMBER_OF_QUESTIONS 10  // Number of questions in the quiz
#define MAX_ANSWER_LENGTH 10    // Maximum length of a user's answer

// Structure representing an element in the periodic table
struct Element {
    int atomic_number;
    char symbol[3];
    char name[20];
};

// Initializes an array of elements with data from a file
void initialize_elements(struct Element* elements) {
    FILE *fp;
    char buffer[100];

    fp = fopen("elements.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return;
    }

    int i = 0;
    while (fgets(buffer, sizeof(buffer), fp)) {
        char *token;
        token = strtok(buffer, ",");
        elements[i].atomic_number = atoi(token);
        token = strtok(NULL, ",");
        strcpy(elements[i].symbol, token);
        token = strtok(NULL, ",");
        token[strcspn(token, "\r\n")] = 0;
        strcpy(elements[i].name, token);
        i++;
    }

    fclose(fp);
}

// Prints out all of the elements and their information
void print_elements(struct Element* elements) {
    printf("Atomic #      Symbol        Name\n");
    printf("------------------------------------\n");
    for (int i = 0; i < NUMBER_OF_ELEMENTS; i++) {
        printf("%-13d%-14s%s\n", elements[i].atomic_number, elements[i].symbol, elements[i].name);
    }
}

// Generates a random index for an element to use in a question
int generate_random_index() {
    return rand() % NUMBER_OF_ELEMENTS;
}

// Asks the user a question about a randomly selected element and returns 1 if their answer is correct 
int ask_question(struct Element* elements) {
    int index = generate_random_index();
    char answer[MAX_ANSWER_LENGTH];
    printf("What is the symbol for the element with atomic number %d? ", elements[index].atomic_number);
    scanf("%s", answer);
    if (strcasecmp(answer, elements[index].symbol) == 0) {
        printf("Correct!\n");
        return 1;
    } else {
        printf("Incorrect.\n");
        return 0;
    }
}

// Runs the periodic table quiz
void run_quiz(struct Element* elements) {
    int score = 0;
    for (int i = 0; i < NUMBER_OF_QUESTIONS; i++) {
        score += ask_question(elements);
    }
    printf("Quiz complete. You scored %d out of %d.\n", score, NUMBER_OF_QUESTIONS);
}

int main() {
    struct Element elements[NUMBER_OF_ELEMENTS];
    initialize_elements(elements);
    print_elements(elements);
    printf("\n\nReady to begin quiz.\n\n");
    run_quiz(elements);
    return 0;
}
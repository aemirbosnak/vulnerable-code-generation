//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ELEMENT_NAME_LENGTH 20
#define MAX_NUM_ELEMENTS 118

typedef struct {
    char name[MAX_ELEMENT_NAME_LENGTH];
    char symbol[3];
    int atomicNumber;
    float atomicWeight;
} Element;

void displayTable();
void displayMenu();
void playQuiz();

int main() {
    printf("Welcome to the Retro Periodic Table Quiz!\n\n");
    displayTable();
    displayMenu();
    return 0;
}

void displayTable() {
    Element elements[MAX_NUM_ELEMENTS];
    FILE* fptr;
    fptr = fopen("periodic_table.txt", "r");
    
    if (fptr == NULL) {
        printf("Error: Cannot open file.\n");
        exit(1);
    }
    
    int i = 0;
    char line[100];
    char* token;
    while (fgets(line, 100, fptr) != NULL) {
        token = strtok(line, ",");
        strcpy(elements[i].name, token);
        
        token = strtok(NULL, ",");
        strcpy(elements[i].symbol, token);
        
        token = strtok(NULL, ",");
        elements[i].atomicNumber = atoi(token);
        
        token = strtok(NULL, ",");
        elements[i].atomicWeight = atof(token);
        
        i++;
    }
    fclose(fptr);
    
    printf("\n");
    printf("     Retro Periodic Table Quiz\n");
    printf("------------------------------------\n\n");
    
    printf("  -----------------------------------------------------------------------------\n");
    for (i = 0; i < MAX_NUM_ELEMENTS; i++) {
        if (i == 0 || (elements[i-1].atomicNumber)/10 != (elements[i].atomicNumber)/10) {
            printf(" |");
        }
        printf(" %-2d %-20s ", elements[i].atomicNumber, elements[i].symbol);
        if (i == MAX_NUM_ELEMENTS-1 || (elements[i+1].atomicNumber)/10 != (elements[i].atomicNumber)/10) {
            printf("|\n");
            printf("  -----------------------------------------------------------------------------\n");
        }
    }
    printf("\n");
}

void displayMenu() {
    int choice;
    do {
        printf("Select an option:\n");
        printf("1. Play Quiz\n");
        printf("2. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        printf("\n");
        
        if (choice == 1) {
            playQuiz();
        }
        else if (choice != 2) {
            printf("Invalid choice. Please try again.\n\n");
        }
    } while (choice != 2);
}

void playQuiz() {
    Element elements[MAX_NUM_ELEMENTS];
    FILE* fptr;
    fptr = fopen("periodic_table.txt", "r");
    
    if (fptr == NULL) {
        printf("Error: Cannot open file.\n");
        exit(1);
    }
    
    int i = 0;
    char line[100];
    char* token;
    while (fgets(line, 100, fptr) != NULL) {
        token = strtok(line, ",");
        strcpy(elements[i].name, token);
        
        token = strtok(NULL, ",");
        strcpy(elements[i].symbol, token);
        
        token = strtok(NULL, ",");
        elements[i].atomicNumber = atoi(token);
        
        token = strtok(NULL, ",");
        elements[i].atomicWeight = atof(token);
        
        i++;
    }
    fclose(fptr);
    
    printf("\nWelcome to the Retro Periodic Table Quiz!\n\n");
    printf("Instructions:\n");
    printf("Guess the symbol of the element from its name or vice versa.\n");
    printf("Enter 'q' to quit the quiz.\n\n");
    
    int score = 0;
    char answer[MAX_ELEMENT_NAME_LENGTH];
    char guess[MAX_ELEMENT_NAME_LENGTH];
    srand(time(NULL));
    
    for (i = 0; i < 10; i++) {
        int index = rand() % MAX_NUM_ELEMENTS;
        printf("Question %d: ", i+1);
        if (rand() % 2) {
            printf("What is the symbol for %s?\n", elements[index].name);
            scanf("%s", guess);
            if (strcmp(guess, "q") == 0) {
                break;
            }
            for (int j = 0; guess[j]; j++) {
                guess[j] = toupper(guess[j]);
            }
            if (strcmp(guess, elements[index].symbol) == 0) {
                printf("Correct!\n");
                score++;
            }
            else {
                printf("Incorrect. The correct answer is %s.\n", elements[index].symbol);
            }
        }
        else {
            printf("What is the name of %s?\n", elements[index].symbol);
            scanf("%s", guess);
            if (strcmp(guess, "q") == 0) {
                break;
            }
            for (int j = 0; guess[j]; j++) {
                guess[j] = toupper(guess[j]);
            }
            if (strcmp(guess, elements[index].name) == 0) {
                printf("Correct!\n");
                score++;
            }
            else {
                printf("Incorrect. The correct answer is %s.\n", elements[index].name);
            }
        }
        printf("Current Score: %d\n\n", score);
    }
    printf("---------------\n");
    printf("Final Score: %d\n", score);
    printf("---------------\n\n");
}
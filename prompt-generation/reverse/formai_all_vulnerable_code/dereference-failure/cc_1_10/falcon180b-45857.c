//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ELEMENTS 118 // maximum number of elements in the periodic table
#define MAX_NAME_LENGTH 10 // maximum length of element name
#define MAX_SYMBOL_LENGTH 3 // maximum length of element symbol
#define MAX_ATOMIC_NUMBER_LENGTH 3 // maximum length of atomic number

typedef struct {
    char name[MAX_NAME_LENGTH]; // element name
    char symbol[MAX_SYMBOL_LENGTH]; // element symbol
    char atomicNumber[MAX_ATOMIC_NUMBER_LENGTH]; // atomic number
} Element;

Element elements[MAX_ELEMENTS]; // array of all elements in the periodic table
int numElements; // number of elements in the periodic table

void loadPeriodicTable() {
    // load periodic table data from file
    FILE *fp = fopen("periodic_table.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open periodic_table.txt\n");
        exit(1);
    }

    char line[100];
    int i = 0;
    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (i >= MAX_ELEMENTS) {
            printf("Error: periodic_table.txt contains too many elements\n");
            exit(1);
        }

        char *name = strtok(line, ",");
        char *symbol = strtok(NULL, ",");
        char *atomicNumber = strtok(NULL, ",");

        strncpy(elements[i].name, name, MAX_NAME_LENGTH);
        strncpy(elements[i].symbol, symbol, MAX_SYMBOL_LENGTH);
        strncpy(elements[i].atomicNumber, atomicNumber, MAX_ATOMIC_NUMBER_LENGTH);

        i++;
    }

    numElements = i;

    fclose(fp);
}

int main() {
    loadPeriodicTable();

    // quiz the user on the periodic table
    int score = 0;
    int numQuestions = 10;
    int correctAnswers = 0;

    for (int i = 0; i < numQuestions; i++) {
        int index = rand() % numElements;
        Element element = elements[index];

        printf("Question %d:\n", i+1);
        printf("What is the name of element %s?\n", element.symbol);

        char answer[MAX_NAME_LENGTH];
        scanf(" %s", answer);

        if (strcmp(answer, element.name) == 0) {
            correctAnswers++;
        }

        score += correctAnswers;
    }

    printf("You got %d out of %d correct.\n", correctAnswers, numQuestions);

    return 0;
}
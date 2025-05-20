//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Element {
    char symbol[3];
    int atomicNumber;
    char name[20];
} Element;

const int NUM_ELEMENTS = 118;
const int MAX_LENGTH = 20;
Element periodicTable[118];

void createPeriodicTable() {
    FILE* f = fopen("periodicTable.txt", "r"); // open file for reading
    if (f == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    char line[100]; 
    int index = 0;
    while (fgets(line, sizeof(line), f)) { // read each line of file
        char* token = strtok(line, "|"); // use pipe character to separate fields
        strcpy(periodicTable[index].symbol, token);
        token = strtok(NULL, "|");
        periodicTable[index].atomicNumber = atoi(token);
        token = strtok(NULL, "\n");
        strcpy(periodicTable[index].name, token);
        index++;
    }
    fclose(f); // close file
}

int getAtomicNumber(char symbol[3]) {
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        if (strcmp(symbol, periodicTable[i].symbol) == 0) {
            return periodicTable[i].atomicNumber;
        }
    }
    return -1; // symbol not found
}

int main() {
    createPeriodicTable();
    char symbol[3];
    int score = 0;
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("Enter the symbol of each element. Press 'q' to quit.\n");
    while (1) {
        printf("Element %d: ", score+1);
        scanf("%s", symbol);
        if (symbol[0] == 'q') {
            break;
        }
        int atomicNumber = getAtomicNumber(symbol);
        if (atomicNumber != -1) {
            printf("Correct! The atomic number of %s is %d.\n", symbol, atomicNumber);
            score++;
        } else {
            printf("Sorry, %s is not a valid symbol.\n", symbol);
        }
    }
    printf("Final score: %d\n", score);
    return 0;
}
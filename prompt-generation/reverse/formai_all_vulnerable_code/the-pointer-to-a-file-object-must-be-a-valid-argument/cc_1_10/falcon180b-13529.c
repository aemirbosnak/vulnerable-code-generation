//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ELEMENTS 118
#define MAX_NAME_LENGTH 10
#define MAX_SYMBOL_LENGTH 3
#define MAX_ATOMIC_NUMBER_LENGTH 3

typedef struct {
    char name[MAX_NAME_LENGTH + 1];
    char symbol[MAX_SYMBOL_LENGTH + 1];
    char atomic_number[MAX_ATOMIC_NUMBER_LENGTH + 1];
} Element;

Element elements[MAX_ELEMENTS];

void read_elements(void) {
    FILE *file = fopen("elements.txt", "r");
    char line[100];
    int count = 0;

    while (fgets(line, 100, file)!= NULL) {
        if (count >= MAX_ELEMENTS) {
            break;
        }
        char *name = strtok(line, ",");
        char *symbol = strtok(NULL, ",");
        char *atomic_number = strtok(NULL, ",");

        strncpy(elements[count].name, name, MAX_NAME_LENGTH);
        strncpy(elements[count].symbol, symbol, MAX_SYMBOL_LENGTH);
        strncpy(elements[count].atomic_number, atomic_number, MAX_ATOMIC_NUMBER_LENGTH);

        count++;
    }

    fclose(file);
}

void print_elements(void) {
    printf("Name\tSymbol\tAtomic Number\n");
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        if (elements[i].name[0]!= '\0') {
            printf("%-10s%-5s%-10s\n", elements[i].name, elements[i].symbol, elements[i].atomic_number);
        }
    }
}

int main(int argc, char *argv[]) {
    read_elements();
    print_elements();

    return 0;
}
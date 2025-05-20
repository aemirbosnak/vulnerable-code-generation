//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ELEMENTS 118
#define MAX_NAME_LENGTH 10
#define MAX_SYMBOL_LENGTH 3
#define MAX_ATOMIC_NUMBER_LENGTH 4
#define MAX_ELEMENT_NAME_LENGTH 20
#define MAX_ELEMENT_SYMBOL_LENGTH 3
#define MAX_ELEMENT_ATOMIC_NUMBER_LENGTH 4
#define MAX_ELEMENT_DESCRIPTION_LENGTH 40

typedef struct {
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_SYMBOL_LENGTH];
    int atomic_number;
    char description[MAX_ELEMENT_DESCRIPTION_LENGTH];
} Element;

Element elements[MAX_ELEMENTS];

void load_elements() {
    FILE *file = fopen("elements.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open elements file.\n");
        exit(1);
    }

    int count = 0;
    char line[MAX_ELEMENT_NAME_LENGTH];
    while (fgets(line, MAX_ELEMENT_NAME_LENGTH, file)!= NULL) {
        if (count >= MAX_ELEMENTS) {
            printf("Error: Too many elements in file.\n");
            exit(1);
        }

        char *name = strtok(line, " ");
        char *symbol = strtok(NULL, " ");
        int atomic_number = atoi(strtok(NULL, " "));
        char *description = strtok(NULL, "\n");

        strcpy(elements[count].name, name);
        strcpy(elements[count].symbol, symbol);
        elements[count].atomic_number = atomic_number;
        strcpy(elements[count].description, description);

        count++;
    }

    fclose(file);
}

void display_elements() {
    printf("Periodic Table:\n");
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        if (strlen(elements[i].name) > 0) {
            printf("%s (%s) - %d\n", elements[i].name, elements[i].symbol, elements[i].atomic_number);
        }
    }
}

int main() {
    load_elements();
    display_elements();

    return 0;
}
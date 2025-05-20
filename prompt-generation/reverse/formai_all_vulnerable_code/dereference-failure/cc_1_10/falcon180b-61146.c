//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ELEMENTS 118
#define MAX_SYMBOLS_PER_ELEMENT 4
#define MAX_NAME_LENGTH 80
#define MAX_ATOMIC_NUMBER_LENGTH 3

typedef struct {
    char symbol[MAX_SYMBOLS_PER_ELEMENT];
    char name[MAX_NAME_LENGTH];
    char atomic_number[MAX_ATOMIC_NUMBER_LENGTH];
} element_t;

element_t elements[MAX_ELEMENTS];

void load_elements() {
    FILE *fp;
    char line[256];
    int count = 0;

    fp = fopen("elements.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open elements.txt\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        int i = 0;
        char *token;
        element_t *element = &elements[count];

        token = strtok(line, ",");
        strcpy(element->symbol, token);

        token = strtok(NULL, ",");
        strcpy(element->name, token);

        token = strtok(NULL, ",");
        strcpy(element->atomic_number, token);

        count++;
    }

    fclose(fp);
}

void display_elements() {
    int i;

    for (i = 0; i < MAX_ELEMENTS; i++) {
        if (elements[i].name[0]!= '\0') {
            printf("%s (%s) - %s\n", elements[i].symbol, elements[i].atomic_number, elements[i].name);
        }
    }
}

int main() {
    load_elements();
    display_elements();

    return 0;
}
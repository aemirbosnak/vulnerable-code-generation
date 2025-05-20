//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX_ELEMENTS 118
#define MAX_SYMBOLS 3

struct Element {
    char symbol[MAX_SYMBOLS];
    char name;
    int atomic_number;
    double atomic_weight;
};

void read_elements(struct Element elements[]) {
    FILE *file = fopen("elements.txt", "r");
    char line[100];
    int count = 0;

    while (fgets(line, sizeof(line), file)!= NULL) {
        line[strcspn(line, "\n")] = '\0'; // remove newline character
        char *token = strtok(line, " ");

        strcpy(elements[count].symbol, token);
        elements[count].name = toupper(token[0]);
        elements[count].atomic_number = atoi(token);
        elements[count].atomic_weight = atof(strtok(NULL, " "));

        count++;
    }

    fclose(file);
}

void print_table(struct Element elements[]) {
    printf("+----+------------------+--------+--------------------+\n");
    printf("| #  | Element          | Symbol | Atomic Weight (u)  |\n");
    printf("+----+------------------+--------+--------------------+\n");

    for (int i = 0; i < MAX_ELEMENTS; i++) {
        if (elements[i].name == '\0') {
            break;
        }

        printf("| %2d | %-13s | %-3s | %9.2f |\n", i + 1, elements[i].name, elements[i].symbol, elements[i].atomic_weight);
    }

    printf("+----+------------------+--------+--------------------+\n");
}

int main() {
    struct Element elements[MAX_ELEMENTS];
    read_elements(elements);
    print_table(elements);

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ELEMENTS 118
#define MAX_NAME_LENGTH 10
#define MAX_SYMBOL_LENGTH 3

typedef struct {
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_SYMBOL_LENGTH];
    int atomic_number;
    int group;
    int period;
} Element;

Element elements[MAX_ELEMENTS];

void read_elements_data(FILE *fp) {
    int count = 0;
    char line[100];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (count >= MAX_ELEMENTS) {
            break;
        }
        char *name = strtok(line, " ");
        strcpy(elements[count].name, name);
        char *symbol = strtok(NULL, " ");
        strcpy(elements[count].symbol, symbol);
        elements[count].atomic_number = atoi(strtok(NULL, " "));
        elements[count].group = atoi(strtok(NULL, " "));
        elements[count].period = atoi(strtok(NULL, " "));
        count++;
    }
}

void print_elements() {
    printf("Element Name\tSymbol\tAtomic Number\tGroup\tPeriod\n");
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        if (elements[i].name[0]!= '\0') {
            printf("%-20s%-5s%-10d%-6d%-6d\n", elements[i].name, elements[i].symbol, elements[i].atomic_number, elements[i].group, elements[i].period);
        }
    }
}

int main() {
    FILE *fp;
    fp = fopen("elements.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    read_elements_data(fp);
    fclose(fp);
    print_elements();
    return 0;
}
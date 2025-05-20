//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1024

typedef struct {
    char name[MAXLINE];
    int age;
    char address[MAXLINE];
} Person;

int csv_reader(FILE *fp, Person **persons, int *size) {
    char line[MAXLINE];
    char *token;
    int count = 0;
    int i = 0;

    while (fgets(line, MAXLINE-1, fp) != NULL) {
        (*size)++;
        *persons = realloc(*persons, *size * sizeof(Person));
        token = strtok(line, ",");
        strcpy((*persons)[i].name, token);
        token = strtok(NULL, ",");
        (*persons)[i].age = atoi(token);
        token = strtok(NULL, ",");
        strcpy((*persons)[i].address, token);
        i++;
    }

    return *size;
}

void print_persons(Person *persons, int size) {
    for (int i = 0; i < size; i++) {
        printf("Name: %s\n", persons[i].name);
        printf("Age: %d\n", persons[i].age);
        printf("Address: %s\n\n", persons[i].address);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s filename.csv\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file '%s'.\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    Person *persons = NULL;
    int size = 0;

    csv_reader(fp, &persons, &size);

    fclose(fp);

    print_persons(persons, size);

    free(persons);

    return 0;
}
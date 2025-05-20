//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define DELIMITER ","

typedef struct {
    char *name;
    int age;
    float height;
} person_t;

int main() {
    FILE *file;
    char line[MAX_LINE_SIZE];
    char *token;
    person_t person;

    file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        token = strtok(line, DELIMITER);
        if (token == NULL) {
            printf("Invalid line format.\n");
            continue;
        }

        strcpy(person.name, token);
        token = strtok(NULL, DELIMITER);
        if (token == NULL) {
            printf("Invalid line format.\n");
            continue;
        }

        person.age = atoi(token);
        token = strtok(NULL, DELIMITER);
        if (token == NULL) {
            printf("Invalid line format.\n");
            continue;
        }

        person.height = atof(token);
        printf("Name: %s\nAge: %d\nHeight: %.2f\n", person.name, person.age, person.height);
    }

    fclose(file);
    return 0;
}
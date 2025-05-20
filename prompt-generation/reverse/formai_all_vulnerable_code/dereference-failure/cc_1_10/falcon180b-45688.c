//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 100
#define DELIMITER ","

typedef struct {
    char *name;
    int age;
    char *gender;
} Person;

int main() {
    FILE *inputFile = fopen("data.csv", "r");
    if (inputFile == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    char delimiter = DELIMITER[0];
    Person *people = malloc(MAX_FIELDS * sizeof(Person));
    int numPeople = 0;

    while (fgets(line, MAX_LINE_LENGTH, inputFile)!= NULL) {
        char *token = strtok(line, &delimiter);
        if (numPeople >= MAX_FIELDS) {
            printf("Error: Reached maximum number of people.\n");
            break;
        }

        Person *currentPerson = &people[numPeople];
        currentPerson->name = strdup(token);
        currentPerson->age = atoi(strtok(NULL, &delimiter));
        currentPerson->gender = strdup(strtok(NULL, &delimiter));

        numPeople++;
    }

    fclose(inputFile);

    printf("Number of people: %d\n", numPeople);
    for (int i = 0; i < numPeople; i++) {
        printf("Name: %s\nAge: %d\nGender: %s\n", people[i].name, people[i].age, people[i].gender);
    }

    free(people);
    return 0;
}
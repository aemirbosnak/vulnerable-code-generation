//Falcon-180B DATASET v1.0 Category: Error handling ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int age;
} Person;

int main() {
    Person *people = NULL;
    int count = 0;

    // Allocate memory for array of people
    people = (Person*)malloc(MAX_SIZE * sizeof(Person));
    if (people == NULL) {
        printf("Error: Could not allocate memory for people.\n");
        return 1;
    }

    // Read in data from file
    FILE *file = fopen("people.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file 'people.txt'.\n");
        return 1;
    }

    char line[MAX_SIZE];
    while (fgets(line, MAX_SIZE, file)!= NULL) {
        if (count >= MAX_SIZE) {
            printf("Error: Too many people in file.\n");
            return 1;
        }

        char *token = strtok(line, ",");
        if (token == NULL) {
            printf("Error: Invalid data in file.\n");
            return 1;
        }

        people[count].name = strdup(token);

        token = strtok(NULL, ",");
        if (token == NULL) {
            printf("Error: Invalid data in file.\n");
            return 1;
        }

        people[count].age = atoi(token);

        count++;
    }

    fclose(file);

    // Do something with the data
    for (int i = 0; i < count; i++) {
        printf("Name: %s, Age: %d\n", people[i].name, people[i].age);
    }

    // Free memory
    for (int i = 0; i < count; i++) {
        free(people[i].name);
    }
    free(people);

    return 0;
}
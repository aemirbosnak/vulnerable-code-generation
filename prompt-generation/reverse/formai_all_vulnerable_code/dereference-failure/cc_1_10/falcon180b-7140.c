//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int age;
} Person;

int main() {
    // Read in data from a file
    FILE *fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    Person *people = (Person*)malloc(MAX_SIZE * sizeof(Person));
    int num_people = 0;

    char line[100];
    while (fgets(line, 100, fp)!= NULL) {
        char *name = strtok(line, ",");
        int age = atoi(strtok(NULL, ","));

        Person person = {.name = name,.age = age};
        people[num_people++] = person;
    }

    fclose(fp);

    // Search for a person by name
    char search_name[100];
    printf("Enter name to search: ");
    scanf("%s", search_name);

    Person *result = NULL;
    for (int i = 0; i < num_people; i++) {
        if (strcmp(people[i].name, search_name) == 0) {
            result = &people[i];
            break;
        }
    }

    if (result!= NULL) {
        printf("Found person: %s, %d years old.\n", result->name, result->age);
    } else {
        printf("Person not found.\n");
    }

    // Free memory
    for (int i = 0; i < num_people; i++) {
        free(people[i].name);
    }
    free(people);

    return 0;
}
//MISTRAL-7B DATASET v1.0 Category: Building a CSV Reader ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FIELDS 100
#define MAX_LENGTH 255

typedef struct {
    char name[MAX_LENGTH];
    int age;
    char gender;
} Person;

void read_csv(FILE *file, Person *persons, size_t count) {
    size_t i;
    char line[MAX_LENGTH];
    char *token;

    for (i = 0; i < count; ++i) {
        if (fgets(line, MAX_LENGTH, file) == NULL) {
            break;
        }

        token = strtok(line, ",");
        strcpy(persons[i].name, token);

        token = strtok(NULL, ",");
        persons[i].age = atoi(token);

        token = strtok(NULL, ",");
        persons[i].gender = token[0];
    }
}

int main() {
    FILE *file;
    Person people[MAX_FIELDS];
    size_t count = 0;

    file = fopen("people.csv", "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    read_csv(file, people, MAX_FIELDS);
    fclose(file);

    size_t i;
    for (i = 0; i < count; ++i) {
        printf("Name: %s, Age: %d, Gender: %c\n", people[i].name, people[i].age, people[i].gender);
    }

    return EXIT_SUCCESS;
}
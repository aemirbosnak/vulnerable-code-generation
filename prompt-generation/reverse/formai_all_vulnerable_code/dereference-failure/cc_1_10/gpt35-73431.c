//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

typedef struct {
    char* name;
    int age;
    char* email;
} Person;

int main() {
    FILE* file;
    char line[MAX_LINE_SIZE];

    file = fopen("people.csv", "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    int num_people = 0;
    Person* people = NULL;

    while (fgets(line, MAX_LINE_SIZE, file)) {
        char* name = strtok(line, ",");
        int age = atoi(strtok(NULL, ","));
        char* email = strtok(NULL, ",");

        if (name == NULL || email == NULL) {
            printf("Invalid input.\n");
            continue;
        }

        Person* person = malloc(sizeof(Person));
        person->name = strdup(name);
        person->age = age;
        person->email = strdup(email);

        num_people++;
        people = realloc(people, num_people * sizeof(Person));
        people[num_people - 1] = *person;
    }

    fclose(file);

    for (int i = 0; i < num_people; i++) {
        printf("Name: %s\n", people[i].name);
        printf("Age: %d\n", people[i].age);
        printf("Email: %s\n", people[i].email);
        free(people[i].name);
        free(people[i].email);
    }

    free(people);

    return 0;
}
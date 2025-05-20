//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 500

typedef struct {
    char *name;
    int age;
    char *occupation;
} Person;

void read_csv_file(FILE *file, Person **people, int *num_people) {
    char line[MAX_LINE_SIZE];
    char *token;
    int i = 0;

    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        token = strtok(line, ",");
        if (token == NULL) {
            break;
        }

        Person *new_person = malloc(sizeof(Person));
        new_person->name = token;
        token = strtok(NULL, ",");
        new_person->age = atoi(token);
        token = strtok(NULL, ",");
        new_person->occupation = token;

        (*num_people)++;
        (*people) = realloc(*people, (*num_people) * sizeof(Person));
        (*people)[i] = *new_person;
        i++;
    }
}

void print_people(Person *people, int num_people) {
    for (int i = 0; i < num_people; i++) {
        printf("Name: %s\n", people[i].name);
        printf("Age: %d\n", people[i].age);
        printf("Occupation: %s\n\n", people[i].occupation);
    }
}

int main() {
    FILE *file = fopen("people.csv", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    Person *people = NULL;
    int num_people = 0;

    read_csv_file(file, &people, &num_people);
    print_people(people, num_people);

    free(people);
    fclose(file);

    return 0;
}
//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: happy
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LENGTH 1000

typedef struct {
    char name[MAX_LENGTH];
    int age;
    char gender;
} Person;

typedef struct {
    Person **people;
    int length;
} PersonList;

void readCSV(char *fileName, PersonList *list) {
    FILE *file = fopen(fileName, "r");

    if (!file) {
        printf("File not found.\n");
        return;
    }

    char buffer[MAX_LENGTH];
    int lineNumber = 0;

    while (fgets(buffer, MAX_LENGTH, file)) {
        lineNumber++;

        if (lineNumber == 1) {
            continue; // Skip header
        }

        char *name = strtok(buffer, ",");
        char *ageStr = strtok(NULL, ",");
        char *genderStr = strtok(NULL, ",");

        if (!name || !ageStr || !genderStr) {
            printf("Invalid CSV format on line %d.\n", lineNumber);
            continue;
        }

        int age = atoi(ageStr);
        char gender = genderStr[0];

        Person *person = malloc(sizeof(Person));
        strncpy(person->name, name, MAX_LENGTH);
        person->age = age;
        person->gender = gender;

        list->people = realloc(list->people, (list->length + 1) * sizeof(Person *));
        list->people[list->length] = person;

        list->length++;
    }

    fclose(file);
}

void printPerson(Person *person) {
    printf("Name: %s\nAge: %d\nGender: %c\n", person->name, person->age, person->gender);
}

void printPeople(PersonList *list) {
    for (int i = 0; i < list->length; i++) {
        printf("Person %d:\n", i+1);
        printPerson(list->people[i]);
        printf("\n");
    }
}

int main() {
    PersonList list = {NULL, 0};

    readCSV("people.csv", &list);

    if (list.length > 0) {
        printPeople(&list);
    } else {
        printf("No people found in CSV.\n");
    }

    for (int i = 0; i < list.length; i++) {
        free(list.people[i]);
    }

    free(list.people);

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Database querying ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_TOKENS 64

typedef struct {
    char *name;
    int age;
} Person;

typedef struct {
    Person *data;
    int count;
    int capacity;
} PersonArray;

void initPersonArray(PersonArray *array) {
    array->data = (Person *)malloc(10 * sizeof(Person));
    array->count = 0;
    array->capacity = 10;
}

void freePersonArray(PersonArray *array) {
    for (int i = 0; i < array->count; i++) {
        free(array->data[i].name);
    }
    free(array->data);
}

void addPerson(PersonArray *array, char *name, int age) {
    if (array->count >= array->capacity) {
        array->capacity *= 2;
        array->data = (Person *)realloc(array->data, array->capacity * sizeof(Person));
    }
    array->data[array->count++] = (Person){
       .name = strdup(name),
       .age = age,
    };
}

void printPersonArray(PersonArray *array) {
    for (int i = 0; i < array->count; i++) {
        printf("%s (%d)\n", array->data[i].name, array->data[i].age);
    }
}

int main() {
    char line[MAX_LINE_LENGTH];
    char *token;
    PersonArray people;

    initPersonArray(&people);

    while (fgets(line, MAX_LINE_LENGTH, stdin)!= NULL) {
        token = strtok(line, ",");
        while (token!= NULL) {
            if (strlen(token) == 0) {
                printf("Error: missing name\n");
                return 1;
            }
            addPerson(&people, token, atoi(strtok(NULL, ",")));
        }
    }

    printf("All people:\n");
    printPersonArray(&people);

    printf("\nPeople aged 25:\n");
    for (int i = 0; i < people.count; i++) {
        if (people.data[i].age == 25) {
            printf("%s\n", people.data[i].name);
        }
    }

    freePersonArray(&people);

    return 0;
}
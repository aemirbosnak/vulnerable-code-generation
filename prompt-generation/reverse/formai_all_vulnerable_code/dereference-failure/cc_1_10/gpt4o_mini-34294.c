//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define INITIAL_CAPACITY 5

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
} Person;

typedef struct {
    Person *data;
    size_t size;
    size_t capacity;
} PersonArray;

void initializePersonArray(PersonArray *arr) {
    arr->data = malloc(INITIAL_CAPACITY * sizeof(Person));
    arr->size = 0;
    arr->capacity = INITIAL_CAPACITY;
}

void freePersonArray(PersonArray *arr) {
    free(arr->data);
    arr->data = NULL;
    arr->size = 0;
    arr->capacity = 0;
}

void resizePersonArray(PersonArray *arr) {
    size_t new_capacity = arr->capacity * 2;
    Person *new_data = realloc(arr->data, new_capacity * sizeof(Person));
    if (new_data) {
        arr->data = new_data;
        arr->capacity = new_capacity;
    } else {
        perror("Failed to resize person array");
        exit(EXIT_FAILURE);
    }
}

void addPerson(PersonArray *arr, const char *name, int age) {
    if (arr->size == arr->capacity) {
        resizePersonArray(arr);
    }
    strncpy(arr->data[arr->size].name, name, MAX_NAME_LENGTH - 1);
    arr->data[arr->size].name[MAX_NAME_LENGTH - 1] = '\0'; // Ensure null termination
    arr->data[arr->size].age = age;
    arr->size++;
}

void printPersons(const PersonArray *arr) {
    printf("------- Persons List -------\n");
    for (size_t i = 0; i < arr->size; i++) {
        printf("Name: %s, Age: %d\n", arr->data[i].name, arr->data[i].age);
    }
    printf("---------------------------\n");
}

void readPersonsFromFile(PersonArray *arr, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    char name[MAX_NAME_LENGTH];
    int age;
    while (fscanf(file, "%49s %d", name, &age) == 2) {
        addPerson(arr, name, age);
    }
    fclose(file);
}

void findOldestPerson(const PersonArray *arr) {
    if (arr->size == 0) {
        printf("No persons in the list.\n");
        return;
    }

    int oldest_age = arr->data[0].age;
    char *oldest_name = arr->data[0].name;

    for (size_t i = 1; i < arr->size; i++) {
        if (arr->data[i].age > oldest_age) {
            oldest_age = arr->data[i].age;
            oldest_name = arr->data[i].name;
        }
    }
    printf("The oldest person is %s, Age: %d\n", oldest_name, oldest_age);
}

int main() {
    PersonArray persons;
    initializePersonArray(&persons);

    addPerson(&persons, "Alice", 30);
    addPerson(&persons, "Bob", 25);
    addPerson(&persons, "Charlie", 35);
    addPerson(&persons, "Diana", 28);
    addPerson(&persons, "Emma", 22);  // This will trigger resizing

    // Print all persons added
    printPersons(&persons);

    // Read more persons from a text file named "persons.txt"
    readPersonsFromFile(&persons, "persons.txt");
    printPersons(&persons);

    // Find the oldest person
    findOldestPerson(&persons);

    // Clean up memory
    freePersonArray(&persons);
    return 0;
}
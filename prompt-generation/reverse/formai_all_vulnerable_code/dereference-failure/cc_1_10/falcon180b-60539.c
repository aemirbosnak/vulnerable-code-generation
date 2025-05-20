//Falcon-180B DATASET v1.0 Category: File handling ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1000

typedef struct {
    char *name;
    int age;
} Person;

typedef struct {
    Person *data;
    int size;
    int capacity;
} PeopleArray;

void init_people_array(PeopleArray *array, int capacity) {
    array->data = (Person *)malloc(capacity * sizeof(Person));
    array->size = 0;
    array->capacity = capacity;
}

void free_people_array(PeopleArray *array) {
    free(array->data);
}

void add_person(PeopleArray *array, const char *name, int age) {
    if (array->size >= array->capacity) {
        printf("Error: Array is full\n");
        return;
    }

    Person *person = &array->data[array->size];
    person->name = strdup(name);
    person->age = age;

    array->size++;
}

void print_people(const PeopleArray *array) {
    for (int i = 0; i < array->size; i++) {
        printf("%s (%d)\n", array->data[i].name, array->data[i].age);
    }
}

int main() {
    PeopleArray people;
    init_people_array(&people, 10);

    FILE *file = fopen("people.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file\n");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        char *name = strtok(line, " ");
        int age = atoi(strtok(NULL, " "));
        add_person(&people, name, age);
    }

    fclose(file);

    print_people(&people);

    free_people_array(&people);

    return 0;
}
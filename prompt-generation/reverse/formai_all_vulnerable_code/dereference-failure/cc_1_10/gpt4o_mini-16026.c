//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define INITIAL_CAPACITY 5

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    float height;
} Person;

typedef struct {
    Person *people;
    int size;
    int capacity;
} PeopleList;

PeopleList* createPeopleList() {
    PeopleList *list = (PeopleList *)malloc(sizeof(PeopleList));
    list->people = (Person *)malloc(sizeof(Person) * INITIAL_CAPACITY);
    list->size = 0;
    list->capacity = INITIAL_CAPACITY;
    return list;
}

void freePeopleList(PeopleList *list) {
    if (list) {
        free(list->people);
        free(list);
    }
}

void expandCapacity(PeopleList *list) {
    list->capacity *= 2;
    list->people = (Person *)realloc(list->people, sizeof(Person) * list->capacity);
    if (!list->people) {
        fprintf(stderr, "Reallocation failed!\n");
        exit(EXIT_FAILURE);
    }
}

void addPerson(PeopleList *list, const char *name, int age, float height) {
    if (list->size >= list->capacity) {
        expandCapacity(list);
    }
    strncpy(list->people[list->size].name, name, MAX_NAME_LENGTH - 1);
    list->people[list->size].name[MAX_NAME_LENGTH - 1] = '\0'; // Ensure null termination
    list->people[list->size].age = age;
    list->people[list->size].height = height;
    list->size++;
}

void printPeopleList(PeopleList *list) {
    printf("People List:\n");
    for (int i = 0; i < list->size; i++) {
        printf("Name: %s, Age: %d, Height: %.2f\n", 
               list->people[i].name, 
               list->people[i].age, 
               list->people[i].height);
    }
}

void readPeopleFromFile(PeopleList *list, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open file %s for reading.\n", filename);
        return;
    }

    char name[MAX_NAME_LENGTH];
    int age;
    float height;

    while (fscanf(file, "%49s %d %f", name, &age, &height) == 3) {
        addPerson(list, name, age, height);
    }
    fclose(file);
}

void writePeopleToFile(PeopleList *list, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        fprintf(stderr, "Could not open file %s for writing.\n", filename);
        return;
    }

    for (int i = 0; i < list->size; i++) {
        fprintf(file, "%s %d %.2f\n", 
                list->people[i].name, 
                list->people[i].age, 
                list->people[i].height);
    }
    fclose(file);
}

int main() {
    PeopleList *myPeople = createPeopleList();
    
    addPerson(myPeople, "Alice", 25, 5.5);
    addPerson(myPeople, "Bob", 30, 6.0);
    addPerson(myPeople, "Charlie", 35, 5.9);
    addPerson(myPeople, "David", 22, 5.8);
    addPerson(myPeople, "Eve", 28, 5.4);

    printPeopleList(myPeople);
    
    writePeopleToFile(myPeople, "people.txt");

    // Now, let's create another list from file
    PeopleList *filePeople = createPeopleList();
    readPeopleFromFile(filePeople, "people.txt");
    
    printf("\nPeople read from file:\n");
    printPeopleList(filePeople);
    
    // Clean up memory
    freePeopleList(myPeople);
    freePeopleList(filePeople);
    
    return 0;
}
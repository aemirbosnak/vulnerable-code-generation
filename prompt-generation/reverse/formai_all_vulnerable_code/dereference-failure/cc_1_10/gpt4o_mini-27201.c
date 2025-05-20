//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
} Person;

typedef struct {
    Person *people;
    int count;
} PeopleList;

// Function to create a new PeopleList
PeopleList* createPeopleList() {
    PeopleList *list = (PeopleList*)malloc(sizeof(PeopleList));
    
    if (list == NULL) {
        perror("Failed to create people list");
        exit(EXIT_FAILURE);
    }
    
    list->people = NULL;
    list->count = 0;

    return list;
}

// Function to add a person to the list
void addPerson(PeopleList *list, const char *name, int age) {
    // Resize the memory for the new person
    list->people = (Person*)realloc(list->people, (list->count + 1) * sizeof(Person));
    
    if (list->people == NULL) {
        perror("Failed to add person to the list");
        exit(EXIT_FAILURE);
    }

    // Copy the new person's data
    strcpy(list->people[list->count].name, name);
    list->people[list->count].age = age;
    list->count++;
}

// Function to display all people in the list
void displayPeople(const PeopleList *list) {
    printf("People List:\n");
    for (int i = 0; i < list->count; i++) {
        printf("Name: %s, Age: %d\n", list->people[i].name, list->people[i].age);
    }
}

// Function to free the memory associated with the PeopleList
void freePeopleList(PeopleList *list) {
    if (list->people != NULL) {
        free(list->people);
    }
    free(list);
}

int main() {
    PeopleList *list = createPeopleList();
    
    addPerson(list, "Alice", 30);
    addPerson(list, "Bob", 25);
    addPerson(list, "Charlie", 35);
    
    displayPeople(list);

    // Free memory before exiting
    freePeopleList(list);
    
    printf("Memory cleaned up. Exiting program.\n");
    
    return 0;
}
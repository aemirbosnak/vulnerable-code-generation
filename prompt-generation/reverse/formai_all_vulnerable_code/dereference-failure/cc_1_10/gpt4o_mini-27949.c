//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define INITIAL_CAPACITY 2

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
} Person;

typedef struct {
    Person *people;      // dynamically allocated array of Person
    size_t size;         // current number of people in the array
    size_t capacity;     // maximum capacity of the array
} PeopleList;

// Function to create a new PeopleList
PeopleList* create_people_list() {
    PeopleList *list = (PeopleList*)malloc(sizeof(PeopleList));
    if (!list) {
        perror("Failed to allocate memory for PeopleList");
        exit(EXIT_FAILURE);
    }
    list->size = 0;
    list->capacity = INITIAL_CAPACITY;
    list->people = (Person*)malloc(sizeof(Person) * list->capacity);
    
    if (!list->people) {
        perror("Failed to allocate memory for people array");
        free(list);
        exit(EXIT_FAILURE);
    }
    return list;
}

// Function to resize the people array
void resize_people_list(PeopleList *list) {
    list->capacity *= 2;
    list->people = (Person*)realloc(list->people, sizeof(Person) * list->capacity);
    
    if (!list->people) {
        perror("Failed to reallocate memory for people array");
        free(list);
        exit(EXIT_FAILURE);
    }
}

// Function to add a new person to the list
void add_person(PeopleList *list, const char *name, int age) {
    if (list->size >= list->capacity) {
        resize_people_list(list);
    }
    strncpy(list->people[list->size].name, name, MAX_NAME_LENGTH);
    list->people[list->size].age = age;
    list->size++;
}

// Function to print the list of people
void print_people_list(const PeopleList *list) {
    printf("People List:\n");
    for (size_t i = 0; i < list->size; i++) {
        printf("Name: %s, Age: %d\n", list->people[i].name, list->people[i].age);
    }
}

// Function to free the allocated memory for people list
void free_people_list(PeopleList *list) {
    free(list->people);
    free(list);
}

// Main function
int main() {
    PeopleList *myFriends = create_people_list();

    printf("Adding people to the list...\n");
    
    add_person(myFriends, "Alice", 30);
    add_person(myFriends, "Bob", 25);
    add_person(myFriends, "Charlie", 35);
    add_person(myFriends, "Diana", 28);
    add_person(myFriends, "Ethan", 22);

    print_people_list(myFriends);

    printf("Freeing the memory...\n");
    free_people_list(myFriends);
    
    return 0;
}
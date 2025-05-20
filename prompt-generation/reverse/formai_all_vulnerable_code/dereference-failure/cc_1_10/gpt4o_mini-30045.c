//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: ultraprecise
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
    Person* people;
    size_t size;
    size_t capacity;
} PeopleList;

// Function prototypes
PeopleList* create_people_list();
void add_person(PeopleList* list, const char* name, int age);
void free_people_list(PeopleList* list);
void print_people_list(const PeopleList* list);
void resize_people_list(PeopleList* list);

// Function implementations
PeopleList* create_people_list() {
    PeopleList* list = (PeopleList*)malloc(sizeof(PeopleList));
    if (!list) {
        perror("Failed to create list");
        exit(EXIT_FAILURE);
    }
    list->people = (Person*)malloc(INITIAL_CAPACITY * sizeof(Person));
    if (!list->people) {
        free(list);
        perror("Failed to allocate memory for people");
        exit(EXIT_FAILURE);
    }
    list->size = 0;
    list->capacity = INITIAL_CAPACITY;
    return list;
}

void add_person(PeopleList* list, const char* name, int age) {
    if (list->size >= list->capacity) {
        resize_people_list(list);
    }
    strncpy(list->people[list->size].name, name, MAX_NAME_LENGTH);
    list->people[list->size].name[MAX_NAME_LENGTH - 1] = '\0'; // Ensure null termination
    list->people[list->size].age = age;
    list->size++;
}

void resize_people_list(PeopleList* list) {
    size_t new_capacity = list->capacity * 2;
    Person* new_people = (Person*)realloc(list->people, new_capacity * sizeof(Person));
    if (!new_people) {
        perror("Failed to resize list");
        exit(EXIT_FAILURE);
    }
    list->people = new_people;
    list->capacity = new_capacity;
}

void free_people_list(PeopleList* list) {
    if (list) {
        free(list->people);
        free(list);
    }
}

void print_people_list(const PeopleList* list) {
    printf("People List:\n");
    for (size_t i = 0; i < list->size; ++i) {
        printf("Name: %s, Age: %d\n", list->people[i].name, list->people[i].age);
    }
}

int main() {
    PeopleList* my_list = create_people_list();
    
    add_person(my_list, "Alice", 30);
    add_person(my_list, "Bob", 25);
    add_person(my_list, "Charlie", 35);
    add_person(my_list, "David", 28);
    add_person(my_list, "Eve", 22);
    
    print_people_list(my_list);
    
    free_people_list(my_list);
    
    return 0;
}
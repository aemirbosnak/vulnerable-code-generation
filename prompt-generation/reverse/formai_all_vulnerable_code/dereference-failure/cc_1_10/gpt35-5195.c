//FormAI DATASET v1.0 Category: Data structures visualization ; Style: funny
#include <stdio.h>
#include <stdlib.h>

// Define our custom data structure
typedef struct {
    int id;
    char name[20];
    int age;
} Person;

// Define a function to generate a random Person object
Person createRandomPerson() {
    Person p;
    p.id = rand() % 1000 + 1;
    sprintf(p.name, "Person%d", p.id);
    p.age = rand() % 50 + 18;
    return p;
}

// Define a function to print a Person object
void printPerson(Person p) {
    printf("ID: %d, Name: %s, Age: %d\n", p.id, p.name, p.age);
}

// Define our custom List data structure
typedef struct {
    Person *items;
    int size;
    int capacity;
} List;

// Define a function to initialize the List with a default capacity
List initList() {
    List l;
    l.size = 0;
    l.capacity = 10;
    l.items = (Person*) malloc(l.capacity * sizeof(Person));
    return l;
}

// Define a function to add an item to the end of the List
void add(List *l, Person p) {
    if (l->size == l->capacity) {
        // If the List is full, double the capacity
        l->capacity *= 2;
        l->items = (Person*) realloc(l->items, l->capacity * sizeof(Person));
    }
    l->items[l->size] = p;
    l->size++;
}

// Define a function to print all the items in the List
void printList(List l) {
    printf("List size: %d, List capacity: %d\n", l.size, l.capacity);
    for (int i = 0; i < l.size; i++) {
        printPerson(l.items[i]);
    }
}

int main() {
    printf("Starting C Data Structures Visualizer...\n");

    // Initialize the List
    List myList = initList();

    // Add some random Persons to the List
    for (int i = 0; i < 20; i++) {
        add(&myList, createRandomPerson());
    }

    // Print the List
    printList(myList);

    printf("C Data Structures Visualizer finished successfully!\n");

    return 0;
}
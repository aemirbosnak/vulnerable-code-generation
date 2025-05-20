//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define database structure
typedef struct {
    char name[50];
    int age;
} person;

// Define database functions
person *get_person(int id) {
    person *ptr = NULL;
    if (id == 1) {
        ptr = (person *)malloc(sizeof(person));
        strcpy(ptr->name, "Alice");
        ptr->age = 25;
    } else if (id == 2) {
        ptr = (person *)malloc(sizeof(person));
        strcpy(ptr->name, "Bob");
        ptr->age = 30;
    } else {
        printf("Error: Person not found\n");
    }
    return ptr;
}

void add_person(int id, char *name, int age) {
    person *ptr = (person *)malloc(sizeof(person));
    strcpy(ptr->name, name);
    ptr->age = age;
    if (id == 1) {
        printf("Error: Person already exists\n");
    } else {
        printf("Person added successfully\n");
    }
}

void update_person(int id, char *name, int age) {
    person *ptr = get_person(id);
    if (ptr == NULL) {
        printf("Error: Person not found\n");
    } else {
        strcpy(ptr->name, name);
        ptr->age = age;
        printf("Person updated successfully\n");
    }
}

void delete_person(int id) {
    person *ptr = get_person(id);
    if (ptr == NULL) {
        printf("Error: Person not found\n");
    } else {
        free(ptr);
        printf("Person deleted successfully\n");
    }
}

int main() {
    srand(time(NULL));

    // Create a database with 3 people
    person *person1 = (person *)malloc(sizeof(person));
    person1->name[0] = 'A';
    person1->age = 25;
    person *person2 = (person *)malloc(sizeof(person));
    person2->name[0] = 'B';
    person2->age = 30;
    person *person3 = (person *)malloc(sizeof(person));
    person3->name[0] = 'C';
    person3->age = 35;

    // Add people to the database
    add_person(1, "Alice", 25);
    add_person(2, "Bob", 30);
    add_person(3, "Charlie", 35);

    // Update people in the database
    update_person(1, "Alice", 30);
    update_person(2, "Bob", 40);
    update_person(3, "Charlie", 45);

    // Delete people from the database
    delete_person(1);
    delete_person(2);
    delete_person(3);

    return 0;
}
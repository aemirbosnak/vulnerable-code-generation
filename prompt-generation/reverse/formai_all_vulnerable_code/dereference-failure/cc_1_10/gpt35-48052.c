//FormAI DATASET v1.0 Category: Data structures visualization ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a person
typedef struct Person {
    char name[50];
    int age;
    float height;
    struct Person *next;
} Person;

// Function to create a new person
Person *create_person(char name[], int age, float height) {
    Person *new_person = (Person *) malloc(sizeof(Person));
    strcpy(new_person->name, name);
    new_person->age = age;
    new_person->height = height;
    new_person->next = NULL;

    return new_person;
}

// Function to add a new person to the linked list
void add_person(Person **head, char name[], int age, float height) {
    Person *new_person = create_person(name, age, height);

    if (*head == NULL) {
        *head = new_person;
    } else {
        Person *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_person;
    }
}

// Function to print the linked list
void print_list(Person *head) {
    Person *current = head;
    while (current != NULL) {
        printf("Name: %s\n", current->name);
        printf("Age: %d\n", current->age);
        printf("Height: %.2f\n\n", current->height);
        current = current->next;
    }
}

int main() {
    Person *head = NULL;

    // Add some people to the linked list
    add_person(&head, "John", 32, 6.1);
    add_person(&head, "Jane", 27, 5.5);
    add_person(&head, "Tom", 42, 5.9);
    add_person(&head, "Sue", 23, 5.2);

    // Print the linked list
    print_list(head);

    return 0;
}
//MISTRAL-7B DATASET v1.0 Category: Networking ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define person struct
typedef struct Person {
    char name[50];
    int age;
    struct Person *next;
} Person;

int main() {
    // Allocate memory for an empty person linked list
    Person *head = NULL;

    // Define functions
    void add_person(Person *head, const char *name, int age);
    void display_list(Person *head);

    // Add three persons to the list
    add_person(head, "Alice", 30);
    add_person(head, "Bob", 25);
    add_person(head, "Charlie", 35);

    // Display the list
    printf("List:\n");
    display_list(head);

    // Free memory
    while (head != NULL) {
        Person *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

// Function to add a person to the list
void add_person(Person *head, const char *name, int age) {
    Person *new_person = (Person *)calloc(1, sizeof(Person));
    strcpy(new_person->name, name);
    new_person->age = age;

    if (head == NULL) {
        head = new_person;
    } else {
        Person *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_person;
    }
}

// Function to display the list
void display_list(Person *head) {
    while (head != NULL) {
        printf("%s (%d years old)\n", head->name, head->age);
        head = head->next;
    }
}
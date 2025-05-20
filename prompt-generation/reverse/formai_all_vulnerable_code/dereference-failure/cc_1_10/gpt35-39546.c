//FormAI DATASET v1.0 Category: Linked list operations ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Person {
    char name[30];
    int age;
    float height;
    struct Person* next;
};

typedef struct Person Person;

void addPerson(Person* head, Person* newPerson) {
    Person* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newPerson;
}

void printList(Person* head) {
    Person* current = head;
    while (current != NULL) {
        printf("Name: %s\n", current->name);
        printf("Age: %d\n", current->age);
        printf("Height: %.2f\n", current->height);
        current = current->next;
    }
}

void deleteList(Person** head) {
    Person* current = *head;
    Person* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}

int main() {
    Person* head = (Person*)malloc(sizeof(Person));
    head->next = NULL;

    Person* person1 = (Person*)malloc(sizeof(Person));
    strcpy(person1->name, "John");
    person1->age = 25;
    person1->height = 1.75;
    person1->next = NULL;

    Person* person2 = (Person*)malloc(sizeof(Person));
    strcpy(person2->name, "Sarah");
    person2->age = 22;
    person2->height = 1.60;
    person2->next = NULL;

    addPerson(head, person1);
    addPerson(head, person2);

    printList(head);

    deleteList(&head);

    return 0;
}
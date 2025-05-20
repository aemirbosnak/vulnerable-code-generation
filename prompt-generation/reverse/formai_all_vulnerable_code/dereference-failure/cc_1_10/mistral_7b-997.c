//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Person {
    char name[50];
    int age;
    struct Person *next;
} Person;

void display(Person *head) {
    printf("List:\n");
    Person *temp = head;
    while (temp != NULL) {
        printf("%s (%d years)\n", temp->name, temp->age);
        temp = temp->next;
    }
}

Person *createPerson(char *name, int age) {
    Person *newPerson = (Person *)malloc(sizeof(Person));
    strcpy(newPerson->name, name);
    newPerson->age = age;
    newPerson->next = NULL;
    return newPerson;
}

void insertAtBeginning(Person **head, char *name, int age) {
    Person *newPerson = createPerson(name, age);
    newPerson->next = *head;
    *head = newPerson;
}

bool search(Person *head, char *nameToFind) {
    Person *temp = head;
    while (temp != NULL) {
        if (strcmp(temp->name, nameToFind) == 0) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void delete(Person **head, char *nameToDelete) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (strcmp((*head)->name, nameToDelete) == 0) {
        Person *temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    Person *current = *head;
    Person *previous = NULL;

    while (current != NULL && strcmp(current->name, nameToDelete) != 0) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Person not found.\n");
        return;
    }

    previous->next = current->next;
    free(current);
}

int main() {
    Person *head = NULL;

    insertAtBeginning(&head, "John Doe", 30);
    insertAtBeginning(&head, "Jane Doe", 25);
    insertAtBeginning(&head, "Bob Smith", 45);

    display(head);

    printf("Searching for Jane Doe...\n");
    if (search(head, "Jane Doe")) {
        printf("Found!\n");
    } else {
        printf("Not found.\n");
    }

    printf("Deleting Bob Smith...\n");
    delete(&head, "Bob Smith");
    display(head);

    return 0;
}
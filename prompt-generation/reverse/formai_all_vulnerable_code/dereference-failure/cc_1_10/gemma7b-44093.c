//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255
#define MAX_ADDRESS_LENGTH 255

typedef struct Person {
    char name[MAX_NAME_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
    int age;
    struct Person* next;
} Person;

void insertPerson(Person** head, char* name, char* address, int age) {
    Person* newPerson = (Person*)malloc(sizeof(Person));
    strcpy(newPerson->name, name);
    strcpy(newPerson->address, address);
    newPerson->age = age;
    newPerson->next = NULL;

    if (*head == NULL) {
        *head = newPerson;
    } else {
        (*head)->next = newPerson;
    }
}

void searchPerson(Person* head, char* name) {
    while (head) {
        if (strcmp(head->name, name) == 0) {
            printf("Name: %s\n", head->name);
            printf("Address: %s\n", head->address);
            printf("Age: %d\n", head->age);
            return;
        }
        head = head->next;
    }

    printf("Person not found.\n");
}

int main() {
    Person* head = NULL;

    insertPerson(&head, "Sherlock Holmes", "221B Baker St.", 45);
    insertPerson(&head, "John Watson", "221B Baker St.", 32);
    insertPerson(&head, "Inspector Lestrade", "121B Great St. Bernard's St.", 50);

    searchPerson(head, "Sherlock Holmes");

    return 0;
}
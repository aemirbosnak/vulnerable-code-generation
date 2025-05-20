//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 255

typedef struct Person {
    char name[MAX_NAME_LENGTH];
    int age;
    struct Person* next;
} Person;

void insertPerson(Person** head, char* name, int age) {
    Person* newPerson = (Person*)malloc(sizeof(Person));
    strcpy(newPerson->name, name);
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
            printf("Found: %s, Age: %d\n", head->name, head->age);
            return;
        }
        head = head->next;
    }

    printf("Not found.\n");
}

int main() {
    Person* head = NULL;

    insertPerson(&head, "Sherlock Holmes", 42);
    insertPerson(&head, "John Watson", 32);
    insertPerson(&head, "Dr. Watson", 55);
    insertPerson(&head, "Mary Morstan", 24);

    searchPerson(head, "Mary Morstan");

    return 0;
}
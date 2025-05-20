//Falcon-180B DATASET v1.0 Category: Memory management ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 1000
#define TRUE 1
#define FALSE 0

typedef struct {
    char *name;
    int age;
    char *occupation;
    struct person *next;
} Person;

Person *head = NULL;

void addPerson(char *name, int age, char *occupation) {
    Person *person = (Person*) malloc(sizeof(Person));

    if (person == NULL) {
        printf("Memory error!\n");
        exit(1);
    }

    person->name = (char*) malloc(strlen(name) + 1);
    strcpy(person->name, name);

    person->age = age;

    person->occupation = (char*) malloc(strlen(occupation) + 1);
    strcpy(person->occupation, occupation);

    person->next = NULL;

    if (head == NULL) {
        head = person;
    } else {
        Person *temp = head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = person;
    }
}

void deletePerson(char *name) {
    Person *temp = head;
    Person *prev = NULL;

    while (temp!= NULL && strcmp(temp->name, name)!= 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Person not found!\n");
    } else {
        if (prev == NULL) {
            head = temp->next;
        } else {
            prev->next = temp->next;
        }

        free(temp->name);
        free(temp->occupation);
        free(temp);
    }
}

void printList() {
    Person *temp = head;

    while (temp!= NULL) {
        printf("Name: %s\n", temp->name);
        printf("Age: %d\n", temp->age);
        printf("Occupation: %s\n\n", temp->occupation);

        temp = temp->next;
    }
}

int main() {
    addPerson("John", 25, "Software Engineer");
    addPerson("Jane", 30, "Data Analyst");
    addPerson("Bob", 40, "Project Manager");

    printList();

    deletePerson("Jane");

    printList();

    return 0;
}
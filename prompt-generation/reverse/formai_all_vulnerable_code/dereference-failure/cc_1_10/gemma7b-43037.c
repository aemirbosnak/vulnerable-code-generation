//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Person {
    char name[20];
    int age;
    struct Person* next;
} Person;

int main() {
    // Create two linked lists for the Montagues and Capulets
    Person* montagueHead = NULL;
    Person* capuletHead = NULL;

    // Create some sample persons
    Person* montague1 = malloc(sizeof(Person));
    strcpy(montague1->name, "Montague");
    montague1->age = 25;
    montague1->next = NULL;

    Person* montague2 = malloc(sizeof(Person));
    strcpy(montague2->name, "Montague");
    montague2->age = 18;
    montague2->next = montague1;

    Person* capulet1 = malloc(sizeof(Person));
    strcpy(capulet1->name, "Capulet");
    capulet1->age = 30;
    capulet1->next = NULL;

    Person* capulet2 = malloc(sizeof(Person));
    strcpy(capulet2->name, "Capulet");
    capulet2->age = 16;
    capulet2->next = capulet1;

    // Add the persons to their respective lists
    montagueHead = montague2;
    capuletHead = capulet2;

    // Simulate a conflict between the Montagues and Capulets
    printf("Montague: %s\n", montagueHead->name);
    printf("Capulet: %s\n", capuletHead->name);

    // Create a truce between the Montagues and Capulets
    printf("Peace!\n");

    return 0;
}
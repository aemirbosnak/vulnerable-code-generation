//MISTRAL-7B DATASET v1.0 Category: Memory management ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Person {
    char name[20];
    int age;
    char status;
} Person;

void die(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

Person *createPerson(const char *name, int age) {
    Person *person = malloc(sizeof(Person));
    if (!person) die("Memory allocation failed.");

    strcpy(person->name, name);
    person->age = age;
    person->status = 'S'; // Single

    return person;
}

void printPerson(const Person *person) {
    printf("%s (%d years old) %s\n", person->name, person->age,
           person->status == 'M' ? "is married" : "is single");
}

void marry(Person *person1, Person *person2) {
    if (person1->status != 'S' || person2->status != 'S') {
        fprintf(stderr, "Cannot marry. One or both persons are already married.\n");
        return;
    }

    person1->status = 'M';
    person2->status = 'M';
}

int main() {
    Person *romeo = createPerson("Romeo Montague", 16);
    Person *juliet = createPerson("Juliet Capulet", 13);

    printf("Romeo: "); printPerson(romeo);
    printf("Juliet: "); printPerson(juliet);

    // They meet secretly and fall in love
    printf("\nAct II, Scene II: The secret love of Romeo and Juliet.\n");

    marry(romeo, juliet);

    printf("\nAct III, Scene V: The tragic consequence of their love.\n");

    // They are discovered, leading to a series of tragic events
    free(romeo);
    free(juliet);

    return EXIT_SUCCESS;
}
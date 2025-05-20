//Falcon-180B DATASET v1.0 Category: Memory management ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char *name;
    int age;
} Person;

void init(Person *p) {
    p->name = (char *)malloc(MAX_SIZE * sizeof(char));
    p->age = 0;
}

void setName(Person *p, char *name) {
    strcpy(p->name, name);
}

void setAge(Person *p, int age) {
    p->age = age;
}

void printPerson(Person *p) {
    printf("Name: %s\nAge: %d\n", p->name, p->age);
}

void deletePerson(Person *p) {
    free(p->name);
    free(p);
}

int main() {
    Person *person1 = (Person *)malloc(sizeof(Person));
    init(person1);
    setName(person1, "John");
    setAge(person1, 25);
    printPerson(person1);

    Person *person2 = (Person *)malloc(sizeof(Person));
    init(person2);
    setName(person2, "Jane");
    setAge(person2, 30);
    printPerson(person2);

    deletePerson(person1);
    deletePerson(person2);

    return 0;
}
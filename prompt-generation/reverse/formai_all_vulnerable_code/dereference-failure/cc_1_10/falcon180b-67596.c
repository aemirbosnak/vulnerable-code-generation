//Falcon-180B DATASET v1.0 Category: Memory management ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int age;
    int size;
} Person;

void init(Person *p) {
    p->name = NULL;
    p->age = 0;
    p->size = 0;
}

void setName(Person *p, char *name) {
    if (p->name!= NULL) {
        free(p->name);
    }
    p->name = strdup(name);
    p->size += strlen(name) + 1;
}

void setAge(Person *p, int age) {
    p->age = age;
    p->size += sizeof(int);
}

void printPerson(Person *p) {
    printf("Name: %s\n", p->name);
    printf("Age: %d\n", p->age);
    printf("Size: %d\n", p->size);
}

void freePerson(Person *p) {
    if (p->name!= NULL) {
        free(p->name);
    }
    free(p);
}

int main() {
    Person *person = malloc(sizeof(Person));
    init(person);

    setName(person, "John");
    setAge(person, 25);

    printPerson(person);

    freePerson(person);
    return 0;
}
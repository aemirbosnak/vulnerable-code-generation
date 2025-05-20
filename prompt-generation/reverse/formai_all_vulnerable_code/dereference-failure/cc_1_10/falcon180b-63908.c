//Falcon-180B DATASET v1.0 Category: Memory management ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char *name;
    int age;
    int height;
} Person;

void init_person(Person *p) {
    p->name = NULL;
    p->age = 0;
    p->height = 0;
}

void set_name(Person *p, char *name) {
    if (p->name!= NULL) {
        free(p->name);
    }
    p->name = strdup(name);
}

void set_age(Person *p, int age) {
    p->age = age;
}

void set_height(Person *p, int height) {
    p->height = height;
}

void print_person(Person *p) {
    printf("Name: %s\n", p->name);
    printf("Age: %d\n", p->age);
    printf("Height: %d\n", p->height);
}

void delete_person(Person *p) {
    if (p->name!= NULL) {
        free(p->name);
        p->name = NULL;
    }
}

int main() {
    Person *person = (Person *) malloc(sizeof(Person));
    init_person(person);

    set_name(person, "John Doe");
    set_age(person, 30);
    set_height(person, 180);

    print_person(person);

    set_name(person, "Jane Doe");
    set_age(person, 25);
    set_height(person, 170);

    print_person(person);

    delete_person(person);
    free(person);

    return 0;
}
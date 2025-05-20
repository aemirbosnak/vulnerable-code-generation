//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char *name;
    int age;
} Person;

void print_person(Person *p) {
    printf("Name: %s\nAge: %d\n", p->name, p->age);
}

void delete_person(Person *p) {
    free(p->name);
    free(p);
}

void shift_person(Person *p) {
    char *temp = p->name;
    p->name = malloc(strlen(temp) + 1);
    strcpy(p->name, temp);
    free(temp);
}

int main() {
    Person *p1 = malloc(sizeof(Person));
    Person *p2 = malloc(sizeof(Person));

    p1->name = "Alice";
    p1->age = 25;

    p2->name = "Bob";
    p2->age = 30;

    print_person(p1);
    print_person(p2);

    shift_person(p1);
    shift_person(p2);

    print_person(p1);
    print_person(p2);

    delete_person(p1);
    delete_person(p2);

    return 0;
}
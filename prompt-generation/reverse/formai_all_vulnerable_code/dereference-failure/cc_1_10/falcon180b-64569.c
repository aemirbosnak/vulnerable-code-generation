//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int age;
} Person;

typedef struct {
    char *name;
    int age;
    Person *parent;
} Cat;

void create_person(Person **person, char *name, int age) {
    *person = malloc(sizeof(Person));
    (*person)->name = strdup(name);
    (*person)->age = age;
}

void create_cat(Cat **cat, char *name, int age, Person *parent) {
    *cat = malloc(sizeof(Cat));
    (*cat)->name = strdup(name);
    (*cat)->age = age;
    (*cat)->parent = parent;
}

void print_person(Person *person) {
    printf("Name: %s, Age: %d\n", person->name, person->age);
}

void print_cat(Cat *cat) {
    printf("Name: %s, Age: %d, Parent's Name: %s, Parent's Age: %d\n", cat->name, cat->age, cat->parent->name, cat->parent->age);
}

int main() {
    Person *person1, *person2;
    Cat *cat1, *cat2;

    create_person(&person1, "Alice", 25);
    create_person(&person2, "Bob", 30);

    printf("Person 1:\n");
    print_person(person1);

    printf("Person 2:\n");
    print_person(person2);

    create_cat(&cat1, "Charlie", 5, person1);
    create_cat(&cat2, "David", 8, person2);

    printf("\nCat 1:\n");
    print_cat(cat1);

    printf("\nCat 2:\n");
    print_cat(cat2);

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Educational ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *name;
    int age;
} Person;

typedef struct {
    Person **people;
    int count;
} AddressBook;

void add_person(AddressBook *ab, char *name, int age) {
    Person *p = malloc(sizeof(Person));
    p->name = strdup(name);
    p->age = age;
    ab->people = realloc(ab->people, sizeof(Person *) * ++ab->count);
    ab->people[ab->count - 1] = p;
}

void delete_person(AddressBook *ab, int index) {
    free(ab->people[index]->name);
    free(ab->people[index]);
    ab->people = realloc(ab->people, sizeof(Person *) * --ab->count);
}

void print_person(Person *p) {
    printf("Name: %s\nAge: %d\n", p->name, p->age);
}

void print_address_book(AddressBook *ab) {
    for (int i = 0; i < ab->count; i++) {
        print_person(ab->people[i]);
        printf("\n");
    }
}

int main() {
    AddressBook ab;
    ab.people = NULL;
    ab.count = 0;

    add_person(&ab, "John", 25);
    add_person(&ab, "Jane", 30);

    print_address_book(&ab);

    delete_person(&ab, 0);

    print_address_book(&ab);

    return 0;
}
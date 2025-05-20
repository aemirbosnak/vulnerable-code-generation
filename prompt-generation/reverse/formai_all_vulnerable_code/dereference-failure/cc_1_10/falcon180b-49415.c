//Falcon-180B DATASET v1.0 Category: Memory management ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char *name;
    int age;
    int height;
} Person;

void init_person(Person *person) {
    person->name = NULL;
    person->age = 0;
    person->height = 0;
}

Person *create_person() {
    Person *person = (Person *)malloc(sizeof(Person));
    init_person(person);
    return person;
}

void set_name(Person *person, char *name) {
    if (person->name!= NULL) {
        free(person->name);
    }
    person->name = strdup(name);
}

void set_age(Person *person, int age) {
    person->age = age;
}

void set_height(Person *person, int height) {
    person->height = height;
}

void print_person(Person *person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
    printf("Height: %d\n", person->height);
}

void destroy_person(Person *person) {
    if (person->name!= NULL) {
        free(person->name);
    }
    free(person);
}

int main() {
    Person *person1 = create_person();
    set_name(person1, "Alice");
    set_age(person1, 25);
    set_height(person1, 165);

    Person *person2 = create_person();
    set_name(person2, "Bob");
    set_age(person2, 30);
    set_height(person2, 180);

    print_person(person1);
    print_person(person2);

    destroy_person(person1);
    destroy_person(person2);

    return 0;
}
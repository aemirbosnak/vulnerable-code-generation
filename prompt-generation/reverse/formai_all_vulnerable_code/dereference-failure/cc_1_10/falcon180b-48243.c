//Falcon-180B DATASET v1.0 Category: Memory management ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int age;
    char *message;
} Person;

void init(Person *person) {
    person->name = NULL;
    person->age = 0;
    person->message = NULL;
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

void set_message(Person *person, char *message) {
    if (person->message!= NULL) {
        free(person->message);
    }
    person->message = strdup(message);
}

void print_person(Person *person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
    printf("Message: %s\n", person->message);
}

void delete_person(Person *person) {
    if (person->name!= NULL) {
        free(person->name);
    }
    if (person->message!= NULL) {
        free(person->message);
    }
    free(person);
}

int main() {
    Person *person1 = malloc(sizeof(Person));
    init(person1);

    set_name(person1, "John");
    set_age(person1, 25);
    set_message(person1, "I love you");

    print_person(person1);

    set_name(person1, "Jane");
    set_age(person1, 30);
    set_message(person1, "You are my world");

    print_person(person1);

    delete_person(person1);
    return 0;
}
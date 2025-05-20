//MISTRAL-7B DATASET v1.0 Category: Error handling ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_LENGTH 100
#define BUFFER_SIZE 20

typedef struct {
    char name[MAX_LENGTH];
    int age;
} Person;

void print_error(const char *msg, int err_num) {
    char err_msg[BUFFER_SIZE];

    strerror_r(err_num, err_msg, BUFFER_SIZE);
    fprintf(stderr, "%s: %s\n", msg, err_msg);
}

Person *create_person(const char *name, int age) {
    Person *person = malloc(sizeof(Person));

    if (person == NULL) {
        print_error("Memory allocation failed.", errno);
        return NULL;
    }

    strncpy(person->name, name, MAX_LENGTH);
    person->age = age;

    if (strlen(person->name) > MAX_LENGTH) {
        print_error("Name too long.", ENAMETOOLONG);
        free(person);
        return NULL;
    }

    return person;
}

int main() {
    Person *person;
    char name[MAX_LENGTH] = "John Doe";
    int age = 30;

    person = create_person(name, age);

    if (person == NULL) {
        printf("Program terminated with an error.\n");
        return 1;
    }

    printf("Name: %s\nAge: %d\n", person->name, person->age);

    free(person);
    return 0;
}
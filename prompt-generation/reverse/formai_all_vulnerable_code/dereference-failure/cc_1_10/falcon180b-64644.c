//Falcon-180B DATASET v1.0 Category: Memory management ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int age;
} Person;

void *my_alloc(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        printf("Out of memory\n");
        exit(1);
    }
    return ptr;
}

void my_free(void *ptr) {
    free(ptr);
}

Person *create_person(const char *name, int age) {
    Person *person = my_alloc(sizeof(Person));
    person->name = my_alloc(strlen(name) + 1);
    strcpy(person->name, name);
    person->age = age;
    return person;
}

void delete_person(Person *person) {
    my_free(person->name);
    my_free(person);
}

void print_person(const Person *person) {
    printf("Name: %s, Age: %d\n", person->name, person->age);
}

int main() {
    Person *p1 = create_person("John", 25);
    Person *p2 = create_person("Jane", 30);

    print_person(p1);
    print_person(p2);

    delete_person(p1);
    delete_person(p2);

    return 0;
}
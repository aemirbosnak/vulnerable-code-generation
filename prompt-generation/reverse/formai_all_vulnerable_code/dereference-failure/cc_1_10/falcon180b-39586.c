//Falcon-180B DATASET v1.0 Category: Memory management ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char *name;
    int age;
} person;

void initialize(void) {
    person *people = (person*)malloc(MAX_SIZE * sizeof(person));
    int i;
    for (i = 0; i < MAX_SIZE; i++) {
        people[i].name = (char*)malloc(20 * sizeof(char));
        people[i].age = 0;
    }
}

void add_person(char *name, int age) {
    person *people = (person*)malloc(MAX_SIZE * sizeof(person));
    int i;
    for (i = 0; i < MAX_SIZE; i++) {
        if (people[i].name == NULL) {
            people[i].name = (char*)malloc(20 * sizeof(char));
            people[i].age = age;
            strcpy(people[i].name, name);
            break;
        }
    }
}

void print_people(void) {
    person *people = (person*)malloc(MAX_SIZE * sizeof(person));
    int i;
    for (i = 0; i < MAX_SIZE; i++) {
        if (people[i].name!= NULL) {
            printf("Name: %s, Age: %d\n", people[i].name, people[i].age);
        }
    }
}

int main() {
    initialize();
    add_person("John", 25);
    add_person("Jane", 30);
    print_people();
    return 0;
}
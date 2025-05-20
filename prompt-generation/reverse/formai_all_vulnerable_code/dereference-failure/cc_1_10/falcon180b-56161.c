//Falcon-180B DATASET v1.0 Category: Educational ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char *name;
    int age;
    char gender;
} person;

void init_person(person *p, char *name, int age, char gender) {
    p->name = strdup(name);
    p->age = age;
    p->gender = gender;
}

void print_person(person *p) {
    printf("Name: %s\n", p->name);
    printf("Age: %d\n", p->age);
    printf("Gender: %c\n", p->gender);
}

void free_person(person *p) {
    free(p->name);
    free(p);
}

int main() {
    srand(time(NULL));
    int num_people = rand() % 10 + 1;
    person *people = malloc(sizeof(person) * num_people);

    for (int i = 0; i < num_people; i++) {
        char name[10];
        sprintf(name, "Person %d", i + 1);
        init_person(&people[i], name, rand() % 100, rand() % 2? 'M' : 'F');
    }

    for (int i = 0; i < num_people; i++) {
        print_person(&people[i]);
    }

    for (int i = 0; i < num_people; i++) {
        free_person(&people[i]);
    }

    free(people);

    return 0;
}
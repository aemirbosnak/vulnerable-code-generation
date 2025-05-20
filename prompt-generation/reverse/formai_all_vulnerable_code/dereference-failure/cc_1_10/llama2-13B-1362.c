//LLAMA2-13B DATASET v1.0 Category: Game ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define PRINT_ERROR(x) printf("Error: %s\n", x)
#define PRINT_WARNING(x) printf("Warning: %s\n", x)

#define MAX_NAME_LENGTH 20
#define MAX_AGE 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
} person_t;

person_t create_person(char *name, int age) {
    person_t p;
    strcpy(p.name, name);
    p.age = age;
    return p;
}

void print_person(person_t p) {
    printf("Name: %s, Age: %d\n", p.name, p.age);
}

int main() {
    person_t *people = malloc(5 * sizeof(person_t));
    int i;

    for (i = 0; i < 5; i++) {
        char name[MAX_NAME_LENGTH];
        int age;

        printf("Enter name: ");
        fgets(name, MAX_NAME_LENGTH, stdin);
        age = atoi(name);

        people[i] = create_person(name, age);
    }

    for (i = 0; i < 5; i++) {
        print_person(people[i]);
    }

    free(people);

    return 0;
}
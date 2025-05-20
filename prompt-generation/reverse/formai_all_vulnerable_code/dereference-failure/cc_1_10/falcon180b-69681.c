//Falcon-180B DATASET v1.0 Category: Memory management ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char *name;
    int age;
} Person;

void init_person(Person *p, char *name, int age) {
    p->name = strdup(name);
    p->age = age;
}

void print_person(Person *p) {
    printf("Name: %s, Age: %d\n", p->name, p->age);
}

void free_person(Person *p) {
    free(p->name);
    free(p);
}

int main() {
    Person *people[MAX_SIZE];
    int count = 0;

    while (1) {
        printf("Enter name and age (or type 'quit' to exit):\n");
        char name[20];
        scanf("%s", name);

        if (strcmp(name, "quit") == 0) {
            break;
        }

        int age;
        scanf("%d", &age);

        if (count >= MAX_SIZE) {
            printf("Error: too many people.\n");
            continue;
        }

        people[count] = malloc(sizeof(Person));
        init_person(people[count], name, age);
        count++;
    }

    printf("People:\n");
    for (int i = 0; i < count; i++) {
        print_person(people[i]);
    }

    for (int i = 0; i < count; i++) {
        free_person(people[i]);
    }

    return 0;
}
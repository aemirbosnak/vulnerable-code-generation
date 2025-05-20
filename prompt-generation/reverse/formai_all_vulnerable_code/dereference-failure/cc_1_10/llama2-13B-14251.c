//LLAMA2-13B DATASET v1.0 Category: Game ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_LENGTH 1024
#define MAGIC_NUMBER 42

typedef struct {
    char name[MAX_LENGTH];
    int age;
} person_t;

void init_person(person_t* p) {
    srand(time(NULL));
    p->age = rand() % 100;
    strcpy(p->name, "Person ");
    strcat(p->name, "");
}

void print_person(person_t* p) {
    printf("Name: %s\nAge: %d\n", p->name, p->age);
}

int main() {
    person_t* p1, *p2, *p3;
    int i;

    // Initialize three persons
    p1 = malloc(sizeof(person_t));
    init_person(p1);
    p2 = malloc(sizeof(person_t));
    init_person(p2);
    p3 = malloc(sizeof(person_t));
    init_person(p3);

    // Perform some magic with the persons
    for (i = 0; i < 10; i++) {
        p1->age += MAGIC_NUMBER;
        p2->age -= MAGIC_NUMBER;
        p3->age *= MAGIC_NUMBER;
    }

    // Print the persons
    print_person(p1);
    print_person(p2);
    print_person(p3);

    // Free the memory
    free(p1);
    free(p2);
    free(p3);

    return 0;
}
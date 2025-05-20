//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    int x, y, z;
} Vector;

typedef struct {
    char* name;
    int age;
    Vector position;
} Person;

void init_person(Person* p, char* name, int age, Vector position) {
    p->name = name;
    p->age = age;
    p->position = position;
}

void print_person(Person* p) {
    printf("Name: %s\n", p->name);
    printf("Age: %d\n", p->age);
    printf("Position: (%d, %d, %d)\n", p->position.x, p->position.y, p->position.z);
}

int main() {
    srand(time(NULL));

    Person* people = malloc(MAX_SIZE * sizeof(Person));

    int num_people = rand() % MAX_SIZE + 1;

    for (int i = 0; i < num_people; i++) {
        char* name = malloc(20 * sizeof(char));
        sprintf(name, "Person %d", i+1);

        int age = rand() % 100 + 1;

        Vector position;
        position.x = rand() % 1000 - 500;
        position.y = rand() % 1000 - 500;
        position.z = rand() % 1000 - 500;

        init_person(&people[i], name, age, position);
    }

    for (int i = 0; i < num_people; i++) {
        print_person(&people[i]);
    }

    free(people);

    return 0;
}
//GEMINI-pro DATASET v1.0 Category: Procedural Space Adventure ; Style: ephemeral
#define SYS_TIME 100
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

typedef struct {
    char *name;
    int pop;
    int minerals;
    int food;
    int morale;
} planet;

planet *create_planet(char *name, int pop, int minerals, int food, int morale) {
    planet *p = malloc(sizeof(planet));
    p->name = malloc(strlen(name) + 1);
    strcpy(p->name, name);
    p->pop = pop;
    p->minerals = minerals;
    p->food = food;
    p->morale = morale;
    return p;
}

void print_planet(planet *p) {
    printf("Planet: %s\n", p->name);
    printf("Population: %d\n", p->pop);
    printf("Minerals: %d\n", p->minerals);
    printf("Food: %d\n", p->food);
    printf("Morale: %d\n", p->morale);
}

int main() {
    srand(time(NULL));

    int num_planets = 10;
    planet *planets[num_planets];

    for (int i = 0; i < num_planets; i++) {
        char *name = malloc(10);
        sprintf(name, "Planet %d", i);
        planets[i] = create_planet(name, rand() % 1000, rand() % 1000, rand() % 1000, rand() % 1000);
    }

    for (int i = 0; i < num_planets; i++) {
        print_planet(planets[i]);
    }

    return 0;
}
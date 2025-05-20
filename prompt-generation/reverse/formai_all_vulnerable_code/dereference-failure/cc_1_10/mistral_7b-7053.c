//MISTRAL-7B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_PLANETS 10
#define ALIEN_PROBABILITY 0.05

typedef struct {
    char name[20];
    int population;
    int defense_level;
} Planet;

Planet* planets;
int num_invaded = 0;

void generate_planets() {
    int i;
    srand(time(NULL));

    planets = (Planet*)calloc(NUM_PLANETS, sizeof(Planet));

    for (i = 0; i < NUM_PLANETS; i++) {
        sprintf(planets[i].name, "Planet %d", i+1);
        planets[i].population = rand() % 10000000 + 1;
        planets[i].defense_level = rand() % 10 + 1;
    }
}

int calculate_invasion_probability(Planet p) {
    return (rand() % 100 + 1) < (ALIEN_PROBABILITY * p.population);
}

void invade_planet(Planet* p) {
    printf("\nAliens invade %s!", p->name);
    num_invaded++;
    p->defense_level = 0;
}

void print_planets() {
    int i;

    printf("\nCurrent status:\n");

    for (i = 0; i < NUM_PLANETS; i++) {
        printf("%s: Population %d, Defense level %d\n", planets[i].name, planets[i].population, planets[i].defense_level);
    }
}

void calculate_invasion() {
    int i;

    for (i = 0; i < NUM_PLANETS; i++) {
        if (calculate_invasion_probability(planets[i])) {
            invade_planet(&planets[i]);
        }
    }

    print_planets();
}

int main() {
    generate_planets();
    int choice;

    do {
        printf("\nPress 1 to calculate invasion probability\nPress 0 to exit\nYour choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            calculate_invasion();
        }
    } while (choice != 0);

    free(planets);

    return 0;
}
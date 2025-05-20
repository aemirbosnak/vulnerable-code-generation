//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define NUM_CIVS 1000
#define LAND_MASS 510
#define WATER_MASS 510
#define MIN_POP 1000000
#define MAX_POP 1000000000
#define MIN_TECH 1
#define MAX_TECH 10
#define MIN_DEFENSE 1
#define MAX_DEFENSE 10
#define MIN_HAPPINESS 1
#define MAX_HAPPINESS 10
#define MIN_INCOME 1
#define MAX_INCOME 10

typedef struct {
    int civ_id;
    int pop;
    int tech;
    int defense;
    int happiness;
    int income;
} Civilization;

Civilization *civs;

void init_civs() {
    srand(time(NULL));
    civs = malloc(NUM_CIVS * sizeof(Civilization));
    for (int i = 0; i < NUM_CIVS; i++) {
        civs[i].civ_id = i;
        civs[i].pop = rand() % (MAX_POP - MIN_POP + 1) + MIN_POP;
        civs[i].tech = rand() % (MAX_TECH - MIN_TECH + 1) + MIN_TECH;
        civs[i].defense = rand() % (MAX_DEFENSE - MIN_DEFENSE + 1) + MIN_DEFENSE;
        civs[i].happiness = rand() % (MAX_HAPPINESS - MIN_HAPPINESS + 1) + MIN_HAPPINESS;
        civs[i].income = rand() % (MAX_INCOME - MIN_INCOME + 1) + MIN_INCOME;
    }
}

void print_civ(int civ_id) {
    for (int i = 0; i < NUM_CIVS; i++) {
        if (civs[i].civ_id == civ_id) {
            printf("Civilization %d:\n", civs[i].civ_id);
            printf("Population: %d\n", civs[i].pop);
            printf("Technology Level: %d\n", civs[i].tech);
            printf("Defense: %d\n", civs[i].defense);
            printf("Happiness: %d\n", civs[i].happiness);
            printf("Income: $%d\n", civs[i].income);
        }
    }
}

int main() {
    init_civs();
    int civ_id;
    printf("Enter civilization ID: ");
    scanf("%d", &civ_id);
    print_civ(civ_id);
    return 0;
}
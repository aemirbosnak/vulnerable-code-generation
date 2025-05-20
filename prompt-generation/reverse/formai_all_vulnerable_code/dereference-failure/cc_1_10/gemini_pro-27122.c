//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Ye olde data structures
typedef struct {
    char *name;
    int age;
    int health;
} Peasant;

typedef struct {
    char *name;
    int strength;
    int damage;
} Knight;

// Ye olde functions
void createPeasant(Peasant *p, char *name, int age, int health) {
    p->name = strdup(name);
    p->age = age;
    p->health = health;
}

void createKnight(Knight *k, char *name, int strength, int damage) {
    k->name = strdup(name);
    k->strength = strength;
    k->damage = damage;
}

void printPeasant(Peasant *p) {
    printf("Peasant: %s, age: %d, health: %d\n", p->name, p->age, p->health);
}

void printKnight(Knight *k) {
    printf("Knight: %s, strength: %d, damage: %d\n", k->name, k->strength, k->damage);
}

// Ye olde main function
int main(void) {
    // Ye olde variables
    Peasant *p = malloc(sizeof(Peasant));
    Knight *k = malloc(sizeof(Knight));

    // Ye olde data initialization
    createPeasant(p, "Peasant", 20, 100);
    createKnight(k, "Knight", 50, 20);

    // Ye olde output
    printPeasant(p);
    printKnight(k);

    // Ye olde cleanup
    free(p->name);
    free(p);
    free(k->name);
    free(k);

    return 0;
}
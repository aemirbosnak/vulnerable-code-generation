//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char *name;
    int age;
    int strength;
} Knight;

Knight *create_knight(char *name, int age, int strength) {
    Knight *knight = malloc(sizeof(Knight));
    if (knight == NULL) {
        printf("Error: Failed to allocate memory for knight.\n");
        exit(1);
    }

    knight->name = strdup(name);
    if (knight->name == NULL) {
        printf("Error: Failed to allocate memory for knight name.\n");
        exit(1);
    }

    knight->age = age;
    knight->strength = strength;

    return knight;
}

void print_knight(Knight *knight) {
    printf("Name: %s\n", knight->name);
    printf("Age: %d\n", knight->age);
    printf("Strength: %d\n", knight->strength);
}

void delete_knight(Knight *knight) {
    free(knight->name);
    free(knight);
}

void joust(Knight *knight1, Knight *knight2) {
    int total_strength = knight1->strength + knight2->strength;
    int winner_strength = total_strength / 2 + 1;

    if (knight1->strength >= winner_strength) {
        printf("%s has won the joust!\n", knight1->name);
    } else {
        printf("%s has won the joust!\n", knight2->name);
    }
}

int main() {
    Knight *sir_lancelot = create_knight("Sir Lancelot", 35, 80);
    Knight *sir_galahad = create_knight("Sir Galahad", 28, 70);

    print_knight(sir_lancelot);
    print_knight(sir_galahad);

    joust(sir_lancelot, sir_galahad);

    delete_knight(sir_lancelot);
    delete_knight(sir_galahad);

    return 0;
}
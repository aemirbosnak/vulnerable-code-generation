//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: medieval
#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int attack;
    int defense;
    int health;
} Unit;

typedef struct {
    int size;
    Unit *units;
} Army;

void army_init(Army *army) {
    army->size = 0;
    army->units = NULL;
}

void army_add_unit(Army *army, Unit *unit) {
    if (army->size == 0) {
        army->units = malloc(sizeof(Unit));
    } else {
        army->units = realloc(army->units, sizeof(Unit) * (army->size + 1));
    }

    army->units[army->size] = *unit;
    army->size++;
}

int army_get_total_attack(Army *army) {
    int total_attack = 0;

    for (int i = 0; i < army->size; i++) {
        total_attack += army->units[i].attack;
    }

    return total_attack;
}

int army_get_total_defense(Army *army) {
    int total_defense = 0;

    for (int i = 0; i < army->size; i++) {
        total_defense += army->units[i].defense;
    }

    return total_defense;
}

int army_get_total_health(Army *army) {
    int total_health = 0;

    for (int i = 0; i < army->size; i++) {
        total_health += army->units[i].health;
    }

    return total_health;
}

void army_print(Army *army) {
    printf("Army:\n");

    for (int i = 0; i < army->size; i++) {
        printf("    Unit %d:\n", i + 1);
        printf("        Attack: %d\n", army->units[i].attack);
        printf("        Defense: %d\n", army->units[i].defense);
        printf("        Health: %d\n", army->units[i].health);
    }
}

int main() {
    Army my_army;
    Unit my_unit;

    army_init(&my_army);

    // Add some units to the army
    my_unit.attack = 10;
    my_unit.defense = 5;
    my_unit.health = 100;
    army_add_unit(&my_army, &my_unit);

    my_unit.attack = 12;
    my_unit.defense = 6;
    my_unit.health = 120;
    army_add_unit(&my_army, &my_unit);

    // Print the army
    army_print(&my_army);

    // Get the army's total attack, defense, and health
    int total_attack = army_get_total_attack(&my_army);
    int total_defense = army_get_total_defense(&my_army);
    int total_health = army_get_total_health(&my_army);

    // Print the army's total attack, defense, and health
    printf("Total Attack: %d\n", total_attack);
    printf("Total Defense: %d\n", total_defense);
    printf("Total Health: %d\n", total_health);

    return 0;
}
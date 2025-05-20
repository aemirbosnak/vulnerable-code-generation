//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_TROOPS 100

typedef struct Knight {
    char name[20];
    int strength, armor, health;
    struct Knight* next;
} Knight;

Knight* createKnight(char* name, int strength, int armor, int health) {
    Knight* knight = (Knight*)malloc(sizeof(Knight));
    strcpy(knight->name, name);
    knight->strength = strength;
    knight->armor = armor;
    knight->health = health;
    knight->next = NULL;
    return knight;
}

void battle(Knight* a, Knight* b) {
    while (a->health > 0 && b->health > 0) {
        int damage = a->strength - b->armor;
        if (damage > 0) {
            b->health -= damage;
            printf("%s attacks %s and deals %d damage!\n", a->name, b->name, damage);
        } else {
            printf("%s's attack failed!\n", a->name);
        }
        // Rest for the next round
        sleep(1);
    }

    if (a->health <= 0) {
        printf("%s has been slain by %s!\n", a->name, b->name);
    } else if (b->health <= 0) {
        printf("%s has been slain by %s!\n", b->name, a->name);
    } else {
        printf("It's a draw!\n");
    }
}

int main() {
    Knight* a = createKnight("Sir William", 15, 5, 100);
    Knight* b = createKnight("Lady Catherine", 12, 3, 80);

    battle(a, b);

    return 0;
}
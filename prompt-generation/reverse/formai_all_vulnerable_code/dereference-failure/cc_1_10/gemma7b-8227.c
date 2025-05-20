//Gemma-7B DATASET v1.0 Category: Performance-Critical Component ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HEIRLOOM_SIZE 10

typedef struct Knight
{
    char name[20];
    int strength;
    int agility;
    int courage;
    struct Knight* next;
} Knight;

Knight* createKnight(char* name, int strength, int agility, int courage)
{
    Knight* newKnight = malloc(sizeof(Knight));
    strcpy(newKnight->name, name);
    newKnight->strength = strength;
    newKnight->agility = agility;
    newKnight->courage = courage;
    newKnight->next = NULL;
    return newKnight;
}

void battle(Knight* knight1, Knight* knight2)
{
    int battleStrength = knight1->strength + knight2->strength;
    int battleAgility = knight1->agility + knight2->agility;
    int battleCourage = knight1->courage + knight2->courage;

    if (battleStrength > battleAgility && battleStrength > battleCourage)
    {
        printf("%s won the battle!", knight1->name);
    }
    else if (battleAgility > battleStrength && battleAgility > battleCourage)
    {
        printf("%s won the battle!", knight2->name);
    }
    else if (battleCourage > battleStrength && battleCourage > battleAgility)
    {
        printf("%s won the battle!", knight1->name);
    }
    else
    {
        printf("It was a draw.");
    }
}

int main()
{
    Knight* hero = createKnight("Sir Robin", 10, 8, 9);
    Knight* villain = createKnight("The Evil Sorcerer", 12, 6, 8);

    battle(hero, villain);

    return 0;
}
//GEMINI-pro DATASET v1.0 Category: Educational ; Style: all-encompassing
// Embark on a journey through the labyrinth of code, where creativity reigns supreme.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Declare a kaleidoscope of data structures to ignite your imagination.
typedef struct Weapon {
    char name[32];
    int attack, defense, range;
} Weapon;

typedef struct Hero {
    char name[32];
    int health, attack, defense;
    Weapon* weapon;
} Hero;

typedef struct Monster {
    char name[32];
    int health, attack, defense, speed;
} Monster;

// Cast an ethereal summoner spell to generate random entities from the void.
Hero* summonHero() {
    static const char* heroNames[] = {"Valiant", "Swift", "Arcane", "Stalwart", "Guileful"};
    static const char* weaponNames[] = {"Sword of Valor", "Bow of Zephyr", "Staff of the Arcanist", "Shield of Bastion", "Blade of Deception"};
    Hero* hero = malloc(sizeof(Hero));
    strcpy(hero->name, heroNames[rand() % 5]);
    hero->health = 100 + (rand() % 5) * 20;
    hero->attack = 10 + (rand() % 5) * 10;
    hero->defense = 10 + (rand() % 5) * 5;
    hero->weapon = malloc(sizeof(Weapon));
    strcpy(hero->weapon->name, weaponNames[rand() % 5]);
    hero->weapon->attack = 10 + (rand() % 5) * 5;
    hero->weapon->defense = 5 + (rand() % 5) * 2;
    hero->weapon->range = 1 + (rand() % 5) * 2;
    return hero;
}

Monster* conjureMonster() {
    static const char* monsterNames[] = {"Goblin", "Orc", "Troll", "Dragon", "Demon"};
    Monster* monster = malloc(sizeof(Monster));
    strcpy(monster->name, monsterNames[rand() % 5]);
    monster->health = 100 + (rand() % 5) * 20;
    monster->attack = 10 + (rand() % 5) * 10;
    monster->defense = 10 + (rand() % 5) * 5;
    monster->speed = 10 + (rand() % 5) * 5;
    return monster;
}

// Weave a tapestry of combat, where heroes and monsters clash in an epic struggle.
void engageInBattle(Hero* hero, Monster* monster) {
    printf("\n%s, the valiant hero, with their trusty %s, stands ready to face %s, the formidable monster.\n", hero->name, hero->weapon->name, monster->name);
    int turn = 0;
    while (hero->health > 0 && monster->health > 0) {
        if (turn % 2 == 0) {
            int damage = hero->attack + hero->weapon->attack - monster->defense;
            monster->health -= damage >= 0 ? damage : 0;
            printf("%s strikes at %s for %d damage!\n", hero->name, monster->name, damage);
        } else {
            int damage = monster->attack - hero->defense;
            hero->health -= damage >= 0 ? damage : 0;
            printf("%s attacks %s for %d damage!\n", monster->name, hero->name, damage);
        }
        turn++;
    }
    if (hero->health <= 0) {
        printf("Alas, %s has fallen in the battle against %s.\n", hero->name, monster->name);
    } else {
        printf("Victory! %s has defeated %s!\n", hero->name, monster->name);
    }
    free(hero->weapon);
    free(hero);
    free(monster);
}

// Set the stage for an epic adventure, where heroes embark on a quest.
int main() {
    srand(time(NULL));
    int numHeroes, numMonsters;
    printf("Enter the number of heroes: ");
    scanf("%d", &numHeroes);
    printf("Enter the number of monsters: ");
    scanf("%d", &numMonsters);
    Hero** heroes = malloc(sizeof(Hero*) * numHeroes);
    Monster** monsters = malloc(sizeof(Monster*) * numMonsters);
    for (int i = 0; i < numHeroes; i++) {
        heroes[i] = summonHero();
    }
    for (int i = 0; i < numMonsters; i++) {
        monsters[i] = conjureMonster();
    }
    for (int i = 0; i < numHeroes; i++) {
        for (int j = 0; j < numMonsters; j++) {
            engageInBattle(heroes[i], monsters[j]);
        }
    }
    free(heroes);
    free(monsters);
    return 0;
}
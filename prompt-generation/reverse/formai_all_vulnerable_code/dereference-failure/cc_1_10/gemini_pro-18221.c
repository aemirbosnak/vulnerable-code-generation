//GEMINI-pro DATASET v1.0 Category: Procedural Space Adventure ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char *name;
    int health;
    int attack;
    int defense;
} Character;

typedef struct {
    char *name;
    int damage;
    int range;
    int ammo;
} Weapon;

typedef struct {
    Character *character;
    Weapon *weapon;
} Player;

typedef struct {
    char *name;
    int health;
    int attack;
    int defense;
    int experience;
} Enemy;

typedef struct {
    char *name;
    int level;
    int experience;
    int hp;
} Quest;

typedef struct {
    char *name;
    int level;
    int experience;
    int hp;
    int damage;
} Boss;

Player *create_player(char *name, Character *character, Weapon *weapon) {
    Player *player = malloc(sizeof(Player));
    player->character = character;
    player->weapon = weapon;
    return player;
}

Enemy *create_enemy(char *name, int health, int attack, int defense, int experience) {
    Enemy *enemy = malloc(sizeof(Enemy));
    enemy->name = name;
    enemy->health = health;
    enemy->attack = attack;
    enemy->defense = defense;
    enemy->experience = experience;
    return enemy;
}

Quest *create_quest(char *name, int level, int experience, int hp) {
    Quest *quest = malloc(sizeof(Quest));
    quest->name = name;
    quest->level = level;
    quest->experience = experience;
    quest->hp = hp;
    return quest;
}

Boss *create_boss(char *name, int level, int experience, int hp, int damage) {
    Boss *boss = malloc(sizeof(Boss));
    boss->name = name;
    boss->level = level;
    boss->experience = experience;
    boss->hp = hp;
    boss->damage = damage;
    return boss;
}

void print_player(Player *player) {
    printf("Name: %s\n", player->character->name);
    printf("Health: %d\n", player->character->health);
    printf("Attack: %d\n", player->character->attack);
    printf("Defense: %d\n", player->character->defense);
    printf("Weapon: %s\n", player->weapon->name);
    printf("Damage: %d\n", player->weapon->damage);
    printf("Range: %d\n", player->weapon->range);
    printf("Ammo: %d\n", player->weapon->ammo);
}

void print_enemy(Enemy *enemy) {
    printf("Name: %s\n", enemy->name);
    printf("Health: %d\n", enemy->health);
    printf("Attack: %d\n", enemy->attack);
    printf("Defense: %d\n", enemy->defense);
    printf("Experience: %d\n", enemy->experience);
}

void print_quest(Quest *quest) {
    printf("Name: %s\n", quest->name);
    printf("Level: %d\n", quest->level);
    printf("Experience: %d\n", quest->experience);
    printf("HP: %d\n", quest->hp);
}

void print_boss(Boss *boss) {
    printf("Name: %s\n", boss->name);
    printf("Level: %d\n", boss->level);
    printf("Experience: %d\n", boss->experience);
    printf("HP: %d\n", boss->hp);
    printf("Damage: %d\n", boss->damage);
}

int main() {
    srand(time(NULL));

    Character *character = malloc(sizeof(Character));
    character->name = "John Doe";
    character->health = 100;
    character->attack = 10;
    character->defense = 5;

    Weapon *weapon = malloc(sizeof(Weapon));
    weapon->name = "Pistol";
    weapon->damage = 10;
    weapon->range = 10;
    weapon->ammo = 100;

    Player *player = create_player("Player", character, weapon);

    Enemy *enemy = create_enemy("Enemy", 100, 10, 5, 10);

    Quest *quest = create_quest("Quest", 1, 10, 100);

    Boss *boss = create_boss("Boss", 10, 100, 1000, 50);

    print_player(player);
    print_enemy(enemy);
    print_quest(quest);
    print_boss(boss);

    return 0;
}
//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>

// Struct to hold player's information
typedef struct {
    int hp;
    int attack;
    int defense;
    int gold;
} Player;

// Enum to hold the different creatures
typedef enum {
    Monster_Skeleton,
    Monster_Goblin,
    Monster_Orc,
    Monster_Dragon
} Monster;

// Struct to hold creature's information
typedef struct {
    char* name;
    int hp;
    int attack;
    int defense;
    int gold;
} Creature;

// Function to create a new creature
Creature* new_creature(char* name, int hp, int attack, int defense, int gold) {
    Creature* creature = malloc(sizeof(Creature));
    creature->name = strdup(name);
    creature->hp = hp;
    creature->attack = attack;
    creature->defense = defense;
    creature->gold = gold;
    return creature;
}

// Function to create the creatures
void create_creatures(Creature** creatures) {
    creatures[Monster_Skeleton] = new_creature("Skeleton", 30, 10, 5, 10);
    creatures[Monster_Goblin] = new_creature("Goblin", 40, 15, 10, 20);
    creatures[Monster_Orc] = new_creature("Orc", 50, 20, 15, 30);
    creatures[Monster_Dragon] = new_creature("Dragon", 100, 40, 30, 100);
}

// Function to free memory
void free_creatures(Creature** creatures) {
    for(int i = 0; i < 4; i++) {
        free(creatures[i]->name);
        free(creatures[i]);
    }
}

// Function to display creature's statistics
void display_creature(Creature* creature) {
    printf("Name: %s, HP: %d, Attack: %d, Defense: %d, Gold: %d\n", creature->name, creature->hp, creature->attack, creature->defense, creature->gold);
}

// Function to attack creature
void attack_creature(Creature* creature, int attack_amount) {
    int damage = attack_amount - creature->defense;
    creature->hp -= damage;
    if(creature->hp < 0) creature->hp = 0;
    printf("You attack the %s and deal %d damage! The %s has %d HP left.\n", creature->name, damage, creature->name, creature->hp);
}

// Function to flee
bool flee() {
    printf("You flee!\n");
    return true;
}

// Function to fight creature
bool fight_creature(Player* player, Creature* creature) {
    while(player->hp > 0 && creature->hp > 0) {
        printf("Your HP: %d, %s's HP: %d\n", player->hp, creature->name, creature->hp);
        printf("What do you want to do? (Attack/Flee)\n");
        char option[10];
        fgets(option, 10, stdin);
        option[strlen(option) - 1] = '\0'; // Remove the newline character
        for(char* p = option; *p; p++) *p = toupper(*p); // Convert to uppercase
        if(strcmp(option, "ATTACK") == 0) {
            attack_creature(creature, player->attack);
        } else if(strcmp(option, "FLEE") == 0) {
            if(rand() % 2 == 0) return flee(); // 50% chance of fleeing
            printf("You failed to flee!\n");
        } else {
            printf("Invalid option. Try again!\n");
        }
        if(creature->hp > 0) {
            int damage = creature->attack - player->defense;
            player->hp -= damage;
            if(player->hp < 0) player->hp = 0;
            printf("The %s attacks you and deals %d damage! You have %d HP left.\n", creature->name, damage, player->hp);
        }
    }
    if(player->hp <= 0) {
        printf("Game Over! You are dead!\n");
        return false;
    }
    player->gold += creature->gold;
    printf("You killed the %s and gained %d gold!\n", creature->name, creature->gold);
    return true;
}

// Function to explore
bool explore(Player* player, Creature** creatures) {
    int random_number = rand() % 100;
    if(random_number < 30) {
        printf("You discover a Skeleton!\n");
        return fight_creature(player, creatures[Monster_Skeleton]);
    } else if(random_number < 60) {
        printf("You discover a Goblin!\n");
        return fight_creature(player, creatures[Monster_Goblin]);
    } else if(random_number < 80) {
        printf("You discover an Orc!\n");
        return fight_creature(player, creatures[Monster_Orc]);
    } else if(random_number < 100) {
        printf("You discover a Dragon!\n");
        return fight_creature(player, creatures[Monster_Dragon]);
    }
    return true;
}

int main() {
    srand(time(NULL)); // Seed the random function with the current time
    Creature* creatures[4];
    create_creatures(creatures);
    Player player = {100, 30, 15, 0};
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You are a brave adventurer in search of gold. You start with 100 HP, 30 Attack, and 15 Defense.\n");
    printf("You enter a dark dungeon and start your adventure.\n");
    while(player.hp > 0) {
        if(!explore(&player, creatures)) break;
        printf("You found some gold! You now have %d gold.\n", player.gold);
        printf("Do you want to continue exploring? (Yes/No)\n");
        char option[10];
        fgets(option, 10, stdin);
        option[strlen(option) - 1] = '\0'; // Remove the newline character
        for(char* p = option; *p; p++) *p = toupper(*p); // Convert to uppercase
        if(strcmp(option, "NO") == 0) {
            printf("You exit the dungeon as a rich adventurer!\n");
            break;
        }
    }
    free_creatures(creatures);
    return 0;
}
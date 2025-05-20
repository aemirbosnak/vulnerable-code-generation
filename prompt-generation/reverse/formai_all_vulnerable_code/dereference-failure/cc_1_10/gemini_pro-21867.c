//GEMINI-pro DATASET v1.0 Category: Terminal Based Game ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Player struct
typedef struct player {
    char name[20];
    int health;
    int attack;
    int defense;
} player;

// Enemy struct
typedef struct enemy {
    char name[20];
    int health;
    int attack;
    int defense;
} enemy;

// Function to create a new player
player *create_player() {
    player *p = malloc(sizeof(player));
    printf("Enter your name: ");
    scanf("%s", p->name);
    p->health = 100;
    p->attack = 10;
    p->defense = 10;
    return p;
}

// Function to create a new enemy
enemy *create_enemy(char *name, int health, int attack, int defense) {
    enemy *e = malloc(sizeof(enemy));
    strcpy(e->name, name);
    e->health = health;
    e->attack = attack;
    e->defense = defense;
    return e;
}

// Function to print the player's stats
void print_player_stats(player *p) {
    printf("Name: %s\n", p->name);
    printf("Health: %d\n", p->health);
    printf("Attack: %d\n", p->attack);
    printf("Defense: %d\n", p->defense);
}

// Function to print the enemy's stats
void print_enemy_stats(enemy *e) {
    printf("Name: %s\n", e->name);
    printf("Health: %d\n", e->health);
    printf("Attack: %d\n", e->attack);
    printf("Defense: %d\n", e->defense);
}

// Function to fight the enemy
void fight(player *p, enemy *e) {
    while (p->health > 0 && e->health > 0) {
        // Player's turn
        int damage = p->attack - e->defense;
        if (damage < 0) {
            damage = 0;
        }
        e->health -= damage;
        printf("%s attacks %s for %d damage!\n", p->name, e->name, damage);

        // Enemy's turn
        damage = e->attack - p->defense;
        if (damage < 0) {
            damage = 0;
        }
        p->health -= damage;
        printf("%s attacks %s for %d damage!\n", e->name, p->name, damage);
    }

    // Check who won the fight
    if (p->health > 0) {
        printf("%s wins the fight!\n", p->name);
        p->health += 10;
    } else {
        printf("%s loses the fight!\n", p->name);
        p->health = 0;
    }
}

// Main function
int main() {
    srand(time(NULL));

    // Create the player
    player *p = create_player();

    // Create the enemy
    enemy *e = create_enemy("Goblin", 100, 10, 10);

    // Print the player's stats
    print_player_stats(p);

    // Print the enemy's stats
    print_enemy_stats(e);

    // Fight the enemy
    fight(p, e);

    // Free the memory allocated for the player and the enemy
    free(p);
    free(e);

    return 0;
}
//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ENEMY_HEALTH 50
#define MAX_PLAYER_HEALTH 100
#define MAX_ENEMY_ATTACK 10
#define MAX_PLAYER_ATTACK 20

// Define an enemy struct
typedef struct {
    int health;
    int attack;
    char *name;
} Enemy;

// Define a player struct
typedef struct {
    int health;
    int attack;
    char *name;
} Player;

// Function to create a new enemy
Enemy *create_enemy(char *name) {
    Enemy *enemy = malloc(sizeof(Enemy));
    enemy->health = MAX_ENEMY_HEALTH;
    enemy->attack = rand() % MAX_ENEMY_ATTACK + 1;
    enemy->name = strdup(name);
    return enemy;
}

// Function to create a new player
Player *create_player(char *name) {
    Player *player = malloc(sizeof(Player));
    player->health = MAX_PLAYER_HEALTH;
    player->attack = rand() % MAX_PLAYER_ATTACK + 1;
    player->name = strdup(name);
    return player;
}

// Function to initiate a battle
void battle(Enemy *enemy, Player *player) {
    printf("A wild %s appears!\n\n", enemy->name);
    while (enemy->health > 0 && player->health > 0) {
        // Player turn
        int player_damage = rand() % player->attack + 1;
        printf("%s attacks for %d damage!\n", player->name, player_damage);
        enemy->health -= player_damage;
        if (enemy->health <= 0) {
            printf("%s defeated the enemy!\n", player->name);
            break;
        }
        // Enemy turn
        int enemy_damage = rand() % enemy->attack + 1;
        printf("%s attacks for %d damage!\n", enemy->name, enemy_damage);
        player->health -= enemy_damage;
        printf("%s has %d health remaining.\n\n", player->name, player->health);
        if (player->health <= 0) {
            printf("%s has been defeated by the enemy!\n", player->name);
            break;
        }
    }
}

int main() {
    srand(time(NULL)); // Seed random number generator
    printf("Welcome to the space adventure game!\n");

    printf("Please enter your name: ");
    char input_name[50];
    fgets(input_name, 50, stdin);
    strtok(input_name, "\n"); // Remove newline character

    printf("You wake up on a strange spaceship with no memory of how you got there.\n");
    printf("Looking around, you see a door on the other side of the room and a computer terminal nearby.\n");

    while (1) { // Game loop
        printf("What would you like to do? (1) Open door (2) Use computer (3) Quit\n");
        char input_action[10];
        fgets(input_action, 10, stdin);
        strtok(input_action, "\n"); // Remove newline character

        if (strcmp(input_action, "1") == 0) {
            printf("You open the door and find yourself in the middle of a space battle!\n");
            printf("An enemy ship appears on your radar, getting closer by the second.\n");
            printf("You hastily man the controls and prepare for battle.\n");
            Enemy *enemy = create_enemy("Alien");
            Player *player = create_player(input_name);
            battle(enemy, player);
            free(enemy);
            free(player);
        } else if (strcmp(input_action, "2") == 0) {
            printf("You approach the computer terminal and enter a command.\n");
            printf("The screen flashes to life and displays the message:\n\n");
            printf("You are on a mission to save the galaxy from an evil alien race.\n");
            printf("You were chosen for this mission because of your unique skills and abilities.\n");
            printf("Your objective is to find and destroy the mothership of the alien fleet.\n\n");
        } else if (strcmp(input_action, "3") == 0) {
            printf("Thanks for playing the space adventure game!\n");
            break;
        } else {
            printf("Invalid input. Please try again.\n");
        }
    }

    return 0;
}
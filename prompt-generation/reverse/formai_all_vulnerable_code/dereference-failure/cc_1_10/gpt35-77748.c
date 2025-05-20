//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Player structure definition
typedef struct {
    char *name;
    int health;
    int attack;
    int defense;
} Player;

// Enemy structure definition
typedef struct {
    char *name;
    int health;
    int attack;
    int defense;
} Enemy;

// Function to simulate a space battle between the player and the enemy
void *space_battle(void *arg) {
    Player *player = (Player *) arg;
    printf("%s is entering a space battle...\n", player->name);
    Enemy *enemy = malloc(sizeof(Enemy));
    enemy->name = "Alien Cruiser";
    enemy->health = 100;
    enemy->attack = 15;
    enemy->defense = 20;
    printf("An %s appears!\n", enemy->name);
    while (player->health > 0 && enemy->health > 0) {
        int player_damage = player->attack - enemy->defense;
        if (player_damage > 0) {
            enemy->health -= player_damage;
        }
        printf("%s does %d damage to %s!\n", player->name, player_damage, enemy->name);
        if (enemy->health <= 0) {
            printf("%s has defeated the %s!\n", player->name, enemy->name);
            break;
        }
        int enemy_damage = enemy->attack - player->defense;
        if (enemy_damage > 0) {
            player->health -= enemy_damage;
        }
        printf("%s does %d damage to %s!\n", enemy->name, enemy_damage, player->name);
        if (player->health <= 0) {
            printf("%s has been defeated by the %s...\n", player->name, enemy->name);
            break;
        }
    }
    free(enemy);
    pthread_exit(NULL);
}

int main() {
    // Create player object
    Player *player = malloc(sizeof(Player));
    player->name = "Captain Kirk";
    player->health = 100;
    player->attack = 20;
    player->defense = 10;

    // Create thread for the space battle simulation
    pthread_t battle_thread;
    pthread_create(&battle_thread, NULL, space_battle, (void *) player);

    // Wait for space battle thread to finish
    pthread_join(battle_thread, NULL);

    // Free memory for player object
    free(player);

    return 0;
}
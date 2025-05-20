//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENEMIES 10    // Maximum number of enemies
#define MAX_HEALTH 100    // Maximum health
#define MAX_STAMINA 50    // Maximum stamina
#define MOVE_COST 10      // Stamina cost per move
#define HEAL_COST 20      // Stamina cost per heal
#define ATK_COST 30       // Stamina cost per attack
#define CRIT_CHANCE 0.2   // Chance for a critical hit
#define CRIT_MULTIPLIER 2 // Multiplier for critical hits
#define RUN_CHANCE 0.5    // Chance to successfully run away

typedef struct {
    int health;
    int stamina;
} Player;

typedef struct {
    int health;
    int damage;
} Enemy;

void init_player(Player *player) {
    player->health = MAX_HEALTH;
    player->stamina = MAX_STAMINA;
}

void init_enemy(Enemy *enemy) {
    enemy->health = rand() % MAX_HEALTH;
    enemy->damage = rand() % (MAX_HEALTH / 2);
}

void print_status(Player player, Enemy *enemies, int num_enemies) {
    printf("\nPlayer Health: %d, Stamina: %d\n", player.health, player.stamina);
    for (int i = 0; i < num_enemies; i++) {
        printf("Enemy %d Health: %d\n", i + 1, enemies[i].health);
    }
    printf("\n");
}

int is_critical() {
    return ((double) rand() / RAND_MAX) < CRIT_CHANCE;
}

void attack(Enemy *enemy, int *stamina) {
    if (*stamina < ATK_COST) {
        printf("Not enough stamina to attack!\n");
        return;
    }

    *stamina -= ATK_COST;

    int damage = rand() % (MAX_HEALTH / 4) + (MAX_HEALTH / 4);
    if (is_critical()) {
        damage *= CRIT_MULTIPLIER;
        printf("Critical hit!\n");
    }

    enemy->health -= damage;

    printf("You attack for %d damage!\n", damage);

    if (enemy->health <= 0) {
        printf("Enemy defeated!\n");
    }
    else {
        printf("Enemy health remaining: %d\n", enemy->health);
    }
}

void heal(Player *player, int *stamina) {
    if (*stamina < HEAL_COST) {
        printf("Not enough stamina to heal!\n");
        return;
    }

    *stamina -= HEAL_COST;

    int healing = rand() % (MAX_HEALTH / 4) + (MAX_HEALTH / 4);
    player->health += healing;

    if (player->health > MAX_HEALTH) {
        player->health = MAX_HEALTH;
    }

    printf("You heal for %d health!\n", healing);
}

int run_away() {
    return ((double) rand() / RAND_MAX) < RUN_CHANCE;
}

int main() {
    srand(time(NULL));

    Player player;
    init_player(&player);

    int num_enemies = rand() % MAX_ENEMIES + 1;
    Enemy *enemies = malloc(num_enemies * sizeof(Enemy));
    for (int i = 0; i < num_enemies; i++) {
        init_enemy(&enemies[i]);
    }

    printf("You are under attack by %d enemies!\n", num_enemies);
    print_status(player, enemies, num_enemies);

    while (1) {
        int choice;
        printf("What do you want to do?\n"
               "1. Attack\n"
               "2. Heal\n"
               "3. Run away\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                if (num_enemies == 0) {
                    printf("There are no more enemies to attack!\n");
                }
                else {
                    int enemy_choice;
                    printf("Which enemy do you want to attack?\n");
                    for (int i = 0; i < num_enemies; i++) {
                        printf("%d. Enemy %d\n", i + 1, i + 1);
                    }
                    scanf("%d", &enemy_choice);

                    if (enemy_choice < 1 || enemy_choice > num_enemies) {
                        printf("Invalid choice!\n");
                    }
                    else {
                        attack(&enemies[enemy_choice - 1], &player.stamina);
                        if (enemies[enemy_choice - 1].health <= 0) {
                            num_enemies--;
                            for (int i = enemy_choice - 1; i < num_enemies; i++) {
                                enemies[i] = enemies[i + 1];
                            }
                            enemies = realloc(enemies, num_enemies * sizeof(Enemy));
                            printf("You defeated an enemy!\n");
                            print_status(player, enemies, num_enemies);
                        }
                        else {
                            print_status(player, enemies, num_enemies);
                            for (int i = 0; i < num_enemies; i++) {
                                if ((double) rand() / RAND_MAX < ((double) i / num_enemies)) {
                                    printf("Enemy %d attacks for %d damage!\n", i + 1, enemies[i].damage);
                                    player.health -= enemies[i].damage;
                                    if (player.health <= 0) {
                                        printf("You are defeated!\n");
                                        return 0;
                                    }
                                }
                            }
                        }
                    }
                }
                break;
            case 2:
                heal(&player, &player.stamina);
                print_status(player, enemies, num_enemies);
                for (int i = 0; i < num_enemies; i++) {
                    if ((double) rand() / RAND_MAX < ((double) i / num_enemies)) {
                        printf("Enemy %d attacks for %d damage!\n", i + 1, enemies[i].damage);
                        player.health -= enemies[i].damage;
                        if (player.health <= 0) {
                            printf("You are defeated!\n");
                            return 0;
                        }
                    }
                }
                break;
            case 3:
                if (run_away()) {
                    printf("You successfully run away!\n");
                    return 0;
                }
                else {
                    printf("You failed to run away!\n");
                    print_status(player, enemies, num_enemies);
                    for (int i = 0; i < num_enemies; i++) {
                        if ((double) rand() / RAND_MAX < ((double) i / num_enemies)) {
                            printf("Enemy %d attacks for %d damage!\n", i + 1, enemies[i].damage);
                            player.health -= enemies[i].damage;
                            if (player.health <= 0) {
                                printf("You are defeated!\n");
                                return 0;
                            }
                        }
                    }
                }
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }

        if (player.stamina < MOVE_COST) {
            printf("You are out of stamina and cannot move!\n");
            print_status(player, enemies, num_enemies);
            for (int i = 0; i < num_enemies; i++) {
                if ((double) rand() / RAND_MAX < ((double) i / num_enemies)) {
                    printf("Enemy %d attacks for %d damage!\n", i + 1, enemies[i].damage);
                    player.health -= enemies[i].damage;
                    if (player.health <= 0) {
                        printf("You are defeated!\n");
                        return 0;
                    }
                }
            }
            return 0;
        }
        else {
            player.stamina -= MOVE_COST;
        }
    }
}
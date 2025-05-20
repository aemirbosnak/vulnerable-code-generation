//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define INVASION_BEGIN do { \
    printf("Invasion begins...\n"); \
    srand(time(NULL)); \
    printf("Random seed: %d\n", rand()); \
    } while (0)

#define INVASION_END do { \
    printf("Invasion ends...\n"); \
    exit(EXIT_SUCCESS); \
    } while (0)

#define INVASION_ATTACK do { \
    printf("Attacking...\n"); \
    sleep(1); \
    } while (0)

#define INVASION_DEFEND do { \
    printf("Defending...\n"); \
    sleep(1); \
    } while (0)

int main(void) {
    INVASION_BEGIN;

    int army_size = 1000;
    int enemy_army_size = 500;
    int attacks = 0;

    int *army = calloc(army_size, sizeof(int));
    int *enemy_army = calloc(enemy_army_size, sizeof(int));

    for (int i = 0; i < army_size; i++) {
        army[i] = i % 2 == 0 ? 10 : 20;
    }

    for (int i = 0; i < enemy_army_size; i++) {
        enemy_army[i] = i % 2 == 0 ? 5 : 10;
    }

    while (1) {
        INVASION_ATTACK;

        for (int i = 0; i < army_size; i++) {
            int target = rand() % enemy_army_size;
            int damage = army[i] - enemy_army[target];
            if (damage > 0) {
                enemy_army[target] -= damage;
                attacks++;
            }
        }

        INVASION_DEFEND;

        if (attacks == army_size) {
            break;
        }
    }

    INVASION_END;

    free(army);
    free(enemy_army);

    return 0;
}
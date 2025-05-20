//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ALIENS 1000
#define MAX_ATTACKS 1000
#define MIN_TECH_LEVEL 1
#define MAX_TECH_LEVEL 10
#define MIN_DEFENSE_LEVEL 1
#define MAX_DEFENSE_LEVEL 10
#define MIN_DISTANCE 1
#define MAX_DISTANCE 10
#define EARTH_POPULATION 1000000000

struct alien {
    int tech_level;
    int defense_level;
    int distance;
};

int main() {
    srand(time(NULL));

    int num_aliens = rand() % MAX_ALIENS + 1;
    struct alien *aliens = malloc(num_aliens * sizeof(struct alien));

    for (int i = 0; i < num_aliens; i++) {
        aliens[i].tech_level = rand() % (MAX_TECH_LEVEL - MIN_TECH_LEVEL + 1) + MIN_TECH_LEVEL;
        aliens[i].defense_level = rand() % (MAX_DEFENSE_LEVEL - MIN_DEFENSE_LEVEL + 1) + MIN_DEFENSE_LEVEL;
        aliens[i].distance = rand() % (MAX_DISTANCE - MIN_DISTANCE + 1) + MIN_DISTANCE;
    }

    int num_attacks = rand() % MAX_ATTACKS + 1;
    int num_successful_attacks = 0;

    for (int i = 0; i < num_attacks; i++) {
        int attack_tech_level = rand() % (MAX_TECH_LEVEL - MIN_TECH_LEVEL + 1) + MIN_TECH_LEVEL;
        int attack_defense_level = rand() % (MAX_DEFENSE_LEVEL - MIN_DEFENSE_LEVEL + 1) + MIN_DEFENSE_LEVEL;
        int attack_distance = rand() % (MAX_DISTANCE - MIN_DISTANCE + 1) + MIN_DISTANCE;

        for (int j = 0; j < num_aliens; j++) {
            if (aliens[j].tech_level >= attack_tech_level && aliens[j].defense_level >= attack_defense_level && aliens[j].distance >= attack_distance) {
                continue;
            }

            num_successful_attacks++;
            break;
        }
    }

    double probability = ((double)num_successful_attacks / num_attacks) * 100.0;
    printf("The probability of a successful alien invasion is %.2f%%\n", probability);

    free(aliens);
    return 0;
}
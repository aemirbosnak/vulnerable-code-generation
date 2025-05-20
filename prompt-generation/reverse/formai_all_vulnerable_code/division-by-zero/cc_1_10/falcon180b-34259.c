//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM_OF_ALIENS 100
#define MAX_NUM_OF_ATTACKS 100

typedef struct {
    int number;
    char *name;
    int strength;
    int intelligence;
    int speed;
} Alien;

Alien aliens[MAX_NUM_OF_ALIENS];

int main() {
    int num_of_aliens, num_of_attacks;
    srand(time(NULL));

    printf("Welcome to the Alien Invasion Probability Calculator!\n\n");

    printf("How many aliens do you want to simulate? (Max: %d): ", MAX_NUM_OF_ALIENS);
    scanf("%d", &num_of_aliens);

    for (int i = 0; i < num_of_aliens; i++) {
        aliens[i].number = i + 1;
        aliens[i].name = (char *)malloc(10 * sizeof(char));
        sprintf(aliens[i].name, "Alien %d", aliens[i].number);
        aliens[i].strength = rand() % 10 + 1;
        aliens[i].intelligence = rand() % 10 + 1;
        aliens[i].speed = rand() % 10 + 1;
        printf("Alien %d: %s\n", aliens[i].number, aliens[i].name);
        printf("Strength: %d\n", aliens[i].strength);
        printf("Intelligence: %d\n", aliens[i].intelligence);
        printf("Speed: %d\n\n", aliens[i].speed);
    }

    printf("How many attacks do you want to simulate? (Max: %d): ", MAX_NUM_OF_ATTACKS);
    scanf("%d", &num_of_attacks);

    int num_of_successful_attacks = 0;

    for (int i = 0; i < num_of_attacks; i++) {
        int alien_index = rand() % num_of_aliens;
        int attack_strength = rand() % 10 + 1;
        int defense_strength = rand() % 10 + 1;

        if (attack_strength > defense_strength) {
            printf("Attack %d was successful!\n", i + 1);
            num_of_successful_attacks++;
        } else {
            printf("Attack %d was unsuccessful.\n", i + 1);
        }
    }

    double probability = (double)num_of_successful_attacks / num_of_attacks;

    printf("\nThe probability of a successful alien invasion is %.2f%%\n", probability * 100);

    return 0;
}
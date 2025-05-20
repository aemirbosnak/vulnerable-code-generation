//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ALIENS 1000
#define MAX_ATTACKS 100

struct Alien {
    int id;
    int strength;
    int intelligence;
};

struct Attack {
    int year;
    int number_of_aliens;
    int success;
};

void generate_aliens(struct Alien aliens[], int num_aliens) {
    srand(time(NULL));
    for (int i = 0; i < num_aliens; i++) {
        aliens[i].id = i;
        aliens[i].strength = rand() % 101;
        aliens[i].intelligence = rand() % 101;
    }
}

void simulate_attacks(struct Alien aliens[], int num_aliens, int num_attacks, struct Attack attacks[]) {
    for (int i = 0; i < num_attacks; i++) {
        int year = 2050 + i;
        int num_participants = rand() % num_aliens + 1;
        int success = 0;
        for (int j = 0; j < num_participants; j++) {
            struct Alien* alien = &aliens[rand() % num_aliens];
            if (alien->strength >= 80 && alien->intelligence >= 80) {
                success++;
            }
        }
        attacks[i].year = year;
        attacks[i].number_of_aliens = num_participants;
        attacks[i].success = success;
    }
}

void print_attacks(struct Attack attacks[], int num_attacks) {
    for (int i = 0; i < num_attacks; i++) {
        printf("In %d, %d aliens attacked Earth. %d of them were successful.\n", attacks[i].year, attacks[i].number_of_aliens, attacks[i].success);
    }
}

int main() {
    struct Alien aliens[MAX_ALIENS];
    struct Attack attacks[MAX_ATTACKS];

    int num_aliens, num_attacks;

    printf("Enter the number of aliens: ");
    scanf("%d", &num_aliens);

    printf("Enter the number of attacks to simulate: ");
    scanf("%d", &num_attacks);

    generate_aliens(aliens, num_aliens);
    simulate_attacks(aliens, num_aliens, num_attacks, attacks);
    print_attacks(attacks, num_attacks);

    return 0;
}
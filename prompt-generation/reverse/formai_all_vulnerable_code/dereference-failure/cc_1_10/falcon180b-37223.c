//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISTANCE 1000000000L
#define MAX_TIME 365*24*60*60
#define NUM_ALIENS 1000
#define MAX_SPEED 1000000
#define MIN_SPEED 1000
#define MAX_SIZE 10000
#define MIN_SIZE 1
#define PROBABILITY_OF_LIFE 0.01
#define PROBABILITY_OF_INTELLIGENCE 0.001
#define PROBABILITY_OF_TECHNOLOGY 0.0001
#define PROBABILITY_OF_AGGRESSION 0.00001

typedef struct {
    double distance;
    double speed;
    double size;
    int is_hostile;
} Alien;

Alien* create_alien(double speed, double size, int is_hostile) {
    Alien* alien = malloc(sizeof(Alien));
    alien->distance = rand() % MAX_DISTANCE;
    alien->speed = rand() % (MAX_SPEED - MIN_SPEED + 1) + MIN_SPEED;
    alien->size = rand() % (MAX_SIZE - MIN_SIZE + 1) + MIN_SIZE;
    alien->is_hostile = is_hostile;
    return alien;
}

int main() {
    srand(time(NULL));

    int num_invasions = 0;
    int num_hostile_invasions = 0;

    for (int i = 0; i < NUM_ALIENS; i++) {
        Alien* alien = create_alien(MAX_SPEED, MAX_SIZE, i % 2);
        double time_to_earth = (MAX_DISTANCE - alien->distance) / alien->speed;
        if (time_to_earth <= MAX_TIME) {
            num_invasions++;
            if (alien->is_hostile) {
                num_hostile_invasions++;
            }
        }
    }

    double probability_of_invasion = (double)num_invasions / NUM_ALIENS;
    double probability_of_hostile_invasion = (double)num_hostile_invasions / NUM_ALIENS;

    printf("Probability of alien invasion: %.2f%%\n", probability_of_invasion * 100);
    printf("Probability of hostile alien invasion: %.2f%%\n", probability_of_hostile_invasion * 100);

    return 0;
}
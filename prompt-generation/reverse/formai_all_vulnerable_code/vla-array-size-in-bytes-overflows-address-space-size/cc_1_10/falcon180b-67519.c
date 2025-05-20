//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ALIENS 1000
#define MAX_YEARS 100
#define PROBABILITY_PER_YEAR 0.01

struct Alien {
    int year;
    int planet;
    int strength;
};

void initAliens(struct Alien aliens[], int numAliens) {
    for(int i = 0; i < numAliens; i++) {
        aliens[i].year = 0;
        aliens[i].planet = rand() % MAX_ALIENS;
        aliens[i].strength = rand() % 101;
    }
}

void printAliens(struct Alien aliens[], int numAliens) {
    for(int i = 0; i < numAliens; i++) {
        printf("Alien %d arrived in year %d from planet %d with strength %d\n", i+1, aliens[i].year, aliens[i].planet, aliens[i].strength);
    }
}

int main() {
    srand(time(NULL));

    int numAliens;
    printf("Enter the number of aliens: ");
    scanf("%d", &numAliens);

    struct Alien aliens[numAliens];
    initAliens(aliens, numAliens);

    int years;
    printf("Enter the number of years to simulate: ");
    scanf("%d", &years);

    for(int i = 0; i < years; i++) {
        for(int j = 0; j < numAliens; j++) {
            if(aliens[j].year == i) {
                printf("Alien %d arrived this year!\n", j+1);
            }
        }
        for(int j = 0; j < numAliens; j++) {
            if(aliens[j].year == i) {
                int strength = aliens[j].strength * 2;
                printf("Alien %d doubles in strength this year!\n", j+1);
                aliens[j].strength = strength;
            }
        }
    }

    return 0;
}
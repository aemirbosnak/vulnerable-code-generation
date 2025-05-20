//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ATTEMPTS 1000
#define MAX_ALIENS 100

struct Alien {
    int intelligence;
    int hostility;
    int technology;
    int likelihood;
};

void generateAliens(struct Alien aliens[], int numAliens) {
    for(int i = 0; i < numAliens; i++) {
        aliens[i].intelligence = rand() % 101;
        aliens[i].hostility = rand() % 101;
        aliens[i].technology = rand() % 101;
        aliens[i].likelihood = (aliens[i].intelligence + aliens[i].hostility + aliens[i].technology) / 3;
    }
}

int main() {
    srand(time(0));

    int numAliens = rand() % MAX_ALIENS + 1;
    struct Alien aliens[MAX_ALIENS];

    generateAliens(aliens, numAliens);

    int numAttempts = 0;
    int numInvasions = 0;

    while(numInvasions < MAX_ATTEMPTS && numAttempts < 1000) {
        numAttempts++;

        int invasionLikelihood = 0;
        for(int i = 0; i < numAliens; i++) {
            invasionLikelihood += aliens[i].likelihood;
        }

        int invasionRoll = rand() % invasionLikelihood;

        for(int i = 0; i < numAliens; i++) {
            if(invasionRoll <= aliens[i].likelihood) {
                numInvasions++;
                printf("Invasion by %d\n", i+1);
                break;
            }
            invasionRoll -= aliens[i].likelihood;
        }
    }

    if(numInvasions >= MAX_ATTEMPTS) {
        printf("No invasions after %d attempts.\n", numAttempts);
    }

    return 0;
}
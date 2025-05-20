//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_INVADERS 1000
#define MIN_RANGE 1
#define MAX_RANGE 1000

// Function to generate a random number between min and max
int rand_range(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to simulate an alien invasion
void invasion(int num_invaders, int invader_range, int earth_range) {
    int i;
    int earth_destroyed = 0;

    for (i = 0; i < num_invaders; i++) {
        int invader_range_temp = rand_range(invader_range, earth_range);
        int earth_range_temp = rand_range(1, earth_range);

        if (invader_range_temp <= earth_range_temp) {
            printf("Alien invasion successful! Earth destroyed!\n");
            earth_destroyed = 1;
            break;
        }
    }

    if (!earth_destroyed) {
        printf("Alien invasion failed. Earth is safe.\n");
    }
}

int main() {
    int num_invaders;
    int invader_range;
    int earth_range;

    // Seed the random number generator
    srand(time(NULL));

    // Get input from user
    printf("Enter the number of invaders: ");
    scanf("%d", &num_invaders);

    printf("Enter the range of the invaders' weapons (1-%d): ", MAX_RANGE);
    scanf("%d", &invader_range);

    printf("Enter the range of Earth's defense system (1-%d): ", MAX_RANGE);
    scanf("%d", &earth_range);

    // Simulate the invasion
    invasion(num_invaders, invader_range, earth_range);

    return 0;
}
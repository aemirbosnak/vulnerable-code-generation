//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_INPUT_LENGTH 1000
#define MAX_PROBABILITY 1000
#define MAX_DISTANCE 10000
#define MAX_TIME_TO_REACH 100000
#define MAX_SIGHTING_PER_YEAR 1000

typedef struct {
    char name[MAX_INPUT_LENGTH];
    int probability;
    int distance;
    int time_to_reach;
    int sighting_per_year;
} ALIEN;

void read_input(ALIEN *alien) {
    printf("Enter the name of the alien species: ");
    scanf("%s", alien->name);

    printf("Enter the probability of invasion (0-100): ");
    scanf("%d", &alien->probability);

    printf("Enter the distance of the alien planet (in light years): ");
    scanf("%d", &alien->distance);

    printf("Enter the time it would take for the aliens to reach Earth (in years): ");
    scanf("%d", &alien->time_to_reach);

    printf("Enter the number of sightings per year: ");
    scanf("%d", &alien->sighting_per_year);
}

void calculate_invasion_probability(ALIEN alien) {
    int current_year = 2022; // The current year
    int num_sightings = 0; // The number of sightings this year

    srand(time(NULL)); // Seed the random number generator with the current time

    while (current_year <= alien.time_to_reach) {
        int num_sightings_this_year = rand() % alien.sighting_per_year + 1; // Generate a random number of sightings for this year
        num_sightings += num_sightings_this_year; // Add the number of sightings this year to the total
        current_year++; // Increment the current year
    }

    float invasion_probability = ((float) num_sightings / (current_year - 2022)) * 100; // Calculate the probability of invasion

    printf("The probability of an invasion by the %s is %.2f%%\n", alien.name, invasion_probability);
}

int main() {
    ALIEN alien;

    printf("Welcome to the Alien Invasion Probability Calculator!\n");

    read_input(&alien);

    calculate_invasion_probability(alien);

    return 0;
}
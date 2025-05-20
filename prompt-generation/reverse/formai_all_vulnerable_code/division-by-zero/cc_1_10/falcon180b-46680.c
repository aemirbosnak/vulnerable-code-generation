//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int user_input;
    int num_civilizations;
    int num_hostile;
    int num_visits;
    int num_invasions;
    int num_inhabited_planets;
    int num_inhabited_planets_destroyed;
    float invasion_probability;
    float chance_of_survival;

    // Initialize random seed
    srand(time(NULL));

    // Get user input for number of civilizations
    printf("Enter the number of civilizations in the galaxy: ");
    scanf("%d", &num_civilizations);

    // Get user input for number of hostile civilizations
    printf("Enter the number of hostile civilizations: ");
    scanf("%d", &num_hostile);

    // Calculate number of visits from hostile civilizations
    num_visits = num_hostile * num_civilizations;

    // Calculate number of invasions
    num_invasions = num_visits / 10;

    // Calculate number of inhabited planets
    printf("Enter the number of inhabited planets in the galaxy: ");
    scanf("%d", &num_inhabited_planets);

    // Calculate number of inhabited planets destroyed
    num_inhabited_planets_destroyed = num_invasions * num_inhabited_planets / num_civilizations;

    // Calculate invasion probability
    invasion_probability = (float)num_invasions / num_civilizations;

    // Calculate chance of survival
    chance_of_survival = (float)(num_inhabited_planets - num_inhabited_planets_destroyed) / num_inhabited_planets;

    // Print results
    printf("The probability of an alien invasion is %.2f%%\n", invasion_probability * 100);
    printf("The chance of survival for inhabited planets is %.2f%%\n", chance_of_survival * 100);

    return 0;
}
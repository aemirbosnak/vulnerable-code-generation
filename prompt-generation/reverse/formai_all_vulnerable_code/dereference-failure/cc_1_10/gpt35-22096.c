//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Struct for Planet Data
typedef struct Planet {
    char name[20];
    char biome[20];
    int resources;
} Planet;

Planet * generate_planet() {
    // Array of Possible Planet Names
    char *names[] = {"Tatooine", "Hoth", "Endor", "Naboo", "Coruscant", "Alderaan", "Kashyyyk", "Dagobah", "Geonosis", "Mustafar"};
    // Array of Possible Planet Biomes
    char *biomes[] = {"Desert", "Tundra", "Forest", "Grassland", "Urban", "Mountain", "Swamp", "Jungle", "Canyon", "Volcanic"};
    // Generate Random Planet Data
    Planet *planet = malloc(sizeof(Planet));
    strcpy(planet->name, names[rand() % 10]);
    strcpy(planet->biome, biomes[rand() % 10]);
    planet->resources = rand() % 100 + 1;
    // Return Generated Planet
    return planet;
}

int main() {
    srand(time(NULL)); // Initialize Random Seed
    printf("Welcome to the Procedural Space Adventure!\n");
    printf("-----------------------------------------\n");
    printf("You are the captain of the spaceship USS Voyager.\n");
    printf("Your mission is to explore the galaxy and discover new planets.\n");
    printf("You have just arrived in a new star system.\n");
    printf("Scanning for planets...\n");
    printf("-----------------------------------------\n");
    // Generate 3 Random Planets
    Planet *planet1 = generate_planet();
    Planet *planet2 = generate_planet();
    Planet *planet3 = generate_planet();
    // Present Planets to Player
    printf("Planet 1: %s, %s, %d resources\n", planet1->name, planet1->biome, planet1->resources);
    printf("Planet 2: %s, %s, %d resources\n", planet2->name, planet2->biome, planet2->resources);
    printf("Planet 3: %s, %s, %d resources\n", planet3->name, planet3->biome, planet3->resources);
    printf("-----------------------------------------\n");
    // Ask Player to Choose a Planet to Visit
    int choice;
    do {
        printf("Which planet would you like to visit? (1, 2, or 3): ");
        scanf("%d", &choice);
        if (choice < 1 || choice > 3) {
            printf("Invalid choice. Please choose 1, 2, or 3.\n");
        }
    } while (choice < 1 || choice > 3);
    // Visit Chosen Planet
    printf("-----------------------------------------\n");
    printf("Preparing to travel to Planet %d...\n", choice);
    Planet *chosen_planet;
    switch (choice) {
        case 1:
            chosen_planet = planet1;
            break;
        case 2:
            chosen_planet = planet2;
            break;
        case 3:
            chosen_planet = planet3;
            break;
        default:
            break;
    }
    printf("Welcome to Planet %s!\n", chosen_planet->name);
    printf("This planet has a %s biome and %d resources.\n", chosen_planet->biome, chosen_planet->resources);
    printf("-----------------------------------------\n");
    // End Program
    free(planet1);
    free(planet2);
    free(planet3);
    return 0;
}
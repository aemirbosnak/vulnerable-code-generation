//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define the maximum size of the galaxy map
#define GALAXY_SIZE 10

// Define the maximum size of the player name
#define NAME_SIZE 20

// Define the structure for the player
typedef struct Player {
    char name[NAME_SIZE];
    int x;
    int y;
} Player;

// Define the structure for the planet
typedef struct Planet {
    char name[NAME_SIZE];
    char description[100];
    int x;
    int y;
} Planet;

// Define the galaxy map as a 2D array of planets
Planet galaxyMap[GALAXY_SIZE][GALAXY_SIZE];

// Define the function to generate a random planet
void generatePlanet(Planet *planet) {
    char *names[] = {"Earth", "Mars", "Jupiter", "Saturn", "Venus", "Mercury", "Uranus", "Neptune", "Pluto", "Xanthe"};
    char *descriptions[] = {"A blue and green planet rich in life", "A red planet with a thin atmosphere", "A giant gas planet with many moons",
                            "A ringed planet with beautiful auroras", "A hot and inhospitable planet covered in volcanic rock", "A small, rocky planet closest to the Sun",
                            "A blue-green gas giant with faint rings and a tilted axis", "A large ice giant with faint rings and many moons", "A dwarf planet at the edge of the solar system", 
                            "A desert planet with ancient ruins and creatures that bury themselves in the sand"};
    int randNum = rand() % 10;
    strcpy(planet->name, names[randNum]);
    strcpy(planet->description, descriptions[randNum]);
    planet->x = rand() % GALAXY_SIZE;
    planet->y = rand() % GALAXY_SIZE;
}

// Define the function to print the player's current location
void printLocation(Player player) {
    printf("You are currently located at (%d, %d)\n", player.x, player.y);
}

// Define the function to check if the player has reached the goal planet
bool reachedGoal(Player player, Planet goal) {
    if (player.x == goal.x && player.y == goal.y) {
        printf("Congratulations! You have reached the goal planet - %s\n", goal.name);
        printf("Description: %s\n", goal.description);
        return true;
    }
    return false;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Initialize the player and generate a random starting planet
    Player player;
    printf("Welcome to the Procedural Space Adventure Game!\n");
    printf("Please enter your name: ");
    fgets(player.name, NAME_SIZE, stdin);
    player.name[strcspn(player.name, "\n")] = '\0'; // remove newline
    printf("Hello, %s! Let's begin your adventure.\n\n", player.name);
    generatePlanet(&galaxyMap[player.x][player.y]);

    // Print the initial location and instructions
    printLocation(player);
    printf("\nInstructions:\n");
    printf("- Use the arrow keys to move around the galaxy\n");
    printf("- Your goal is to reach the planet at the coordinate (5, 5)\n\n");

    // Main game loop
    int input;
    while (true) {
        input = getchar();

        switch (input) {
            // Move up
            case 'w':
                if (player.y > 0) {
                    player.y--;
                }
                break;
            // Move down
            case 's':
                if (player.y < GALAXY_SIZE - 1) {
                    player.y++;
                }
                break;
            // Move left
            case 'a':
                if (player.x > 0) {
                    player.x--;
                }
                break;
            // Move right
            case 'd':
                if (player.x < GALAXY_SIZE - 1) {
                    player.x++;
                }
                break;
        }

        // Update the player's location and print it
        printLocation(player);

        // Check if the player has reached the goal planet
        Planet goal;
        goal.x = 5;
        goal.y = 5;
        if (reachedGoal(player, goal)) {
            break;
        }
    }

    printf("\nThanks for playing the Procedural Space Adventure Game, %s!\n", player.name);

    return 0;
}
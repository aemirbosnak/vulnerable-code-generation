//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to randomly generate space names
char* generate_space_name() {
    char* space_names[10] = {"Galaxia", "Nova", "Supernova", "Starburst", "Celestial", "Cosmic", "Astro", "Nebula", "Orbit", "Comet"};
    char* suffixes[3] = {" Prime", " Alpha", " Beta"};
    char* space_name = (char*) malloc(sizeof(char) * 15);
    int index = rand() % 10;
    strcpy(space_name, space_names[index]);
    index = rand() % 3;
    strcat(space_name, suffixes[index]);
    return space_name;
}

// Function to initialize player stats
void init_player_stats(int* player_stats) {
    player_stats[0] = 100; // health
    player_stats[1] = 50; // fuel
    player_stats[2] = 0; // score
}

// Function to display player stats
void display_player_stats(int* player_stats) {
    printf("Health: %d\nFuel: %d\nScore: %d\n", player_stats[0], player_stats[1], player_stats[2]);
}

// Function to simulate a random space encounter
int space_encounter(int* player_stats) {
    int encounter_type = rand() % 3;
    int encounter_result = 0;
    switch (encounter_type) {
        case 0:
            printf("You encounter a friendly space crew who give you 10 fuel!\n");
            player_stats[1] += 10;
            break;
        case 1:
            printf("You encounter space pirates who damage your ship by 10, but you defeat them and earn 20 points!\n");
            player_stats[0] -= 10;
            player_stats[2] += 20;
            break;
        case 2:
            printf("You encounter an alien race who challenge you to a dance-off. You win and gain 30 points!\n");
            player_stats[2] += 30;
            break;
    }
    if (player_stats[0] <= 0) {
        printf("You were defeated by the space pirates and lost all your fuel! Game over.\n");
        encounter_result = -1;
    }
    return encounter_result;
}

int main() {
    srand(time(NULL));
    printf("*** Welcome to the Galactic Odyssey! ***\n");
    char* space_name = generate_space_name();
    printf("You are on board the space vessel \"%s\".\n", space_name);
    printf("Your mission is to explore the galaxy and achieve the highest score possible!\n");
    printf("Good luck!\n");

    int player_stats[3]; // 0 = health, 1 = fuel, 2 = score
    init_player_stats(player_stats);
    display_player_stats(player_stats);

    int game_over = 0;
    while (!game_over) {
        int encounter_result = space_encounter(player_stats);
        if (encounter_result == -1) {
            game_over = 1;
        } else {
            display_player_stats(player_stats);
        }
    }

    printf("*** Game Over! Thanks for playing! ***\n");
    return 0;
}
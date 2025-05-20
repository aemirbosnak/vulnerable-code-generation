//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 4
#define MAX_NAME_LENGTH 32
#define MAX_CSV_LINE_LENGTH 256

typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
} player_t;

player_t players[MAX_PLAYERS];

int main() {
    FILE *fp;
    char line[MAX_CSV_LINE_LENGTH];
    int num_players = 0;

    // Open the CSV file for reading
    fp = fopen("players.csv", "r");
    if (fp == NULL) {
        perror("Error opening players.csv");
        return EXIT_FAILURE;
    }

    // Read the CSV file line by line
    while (fgets(line, MAX_CSV_LINE_LENGTH, fp)) {
        // Parse the CSV line into player data
        char *name = strtok(line, ",");
        char *score_str = strtok(NULL, ",");
        int score = atoi(score_str);

        // Add the player to the players array
        if (num_players < MAX_PLAYERS) {
            strcpy(players[num_players].name, name);
            players[num_players].score = score;
            num_players++;
        }
    }

    // Close the CSV file
    fclose(fp);

    // Print the player data
    for (int i = 0; i < num_players; i++) {
        printf("Player %d: %s (%d points)\n", i + 1, players[i].name, players[i].score);
    }

    return EXIT_SUCCESS;
}
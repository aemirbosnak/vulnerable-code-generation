//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 10
#define MAX_NAME_LENGTH 20

typedef struct player {
    char name[MAX_NAME_LENGTH];
    int score;
} Player;

int main() {
    Player players[MAX_PLAYERS];
    int num_players = 0;

    // Open the CSV file for reading
    FILE *csv_file = fopen("players.csv", "r");

    // Read the header line (assuming it exists)
    char header[100];
    fgets(header, 100, csv_file);

    // Read the rest of the lines
    char line[100];
    while (fgets(line, 100, csv_file) != NULL) {
        // Parse the line
        char *name = strtok(line, ",");
        char *score_str = strtok(NULL, ",");
        int score = atoi(score_str);

        // Create a new player
        Player p;
        strcpy(p.name, name);
        p.score = score;

        // Add the player to the array
        players[num_players] = p;
        num_players++;
    }

    // Close the CSV file
    fclose(csv_file);

    // Print out the players
    printf("Scoreboard:\n");
    for (int i = 0; i < num_players; i++) {
        printf("%s:\t%d\n", players[i].name, players[i].score);
    }

    return 0;
}
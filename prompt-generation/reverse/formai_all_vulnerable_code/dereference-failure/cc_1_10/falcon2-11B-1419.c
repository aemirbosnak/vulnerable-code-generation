//Falcon2-11B DATASET v1.0 Category: Database querying ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

// Define a struct to represent a player
typedef struct {
    char name[50];
    int score;
} Player;

// Function to read players from a file
Player* readPlayersFromFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    Player* players = (Player*)malloc(sizeof(Player));
    if (players == NULL) {
        perror("Error allocating memory");
        exit(EXIT_FAILURE);
    }

    char line[100];
    while (fgets(line, sizeof(line), file)!= NULL) {
        sscanf(line, "%s %d", players->name, &players->score);
    }

    return players;
}

// Function to write players to a file
void writePlayersToFile(const char* filename, Player* players, int numPlayers) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < numPlayers; i++) {
        fprintf(file, "%s %d\n", players[i].name, players[i].score);
    }

    fclose(file);
}

// Function to update scores in the database
void updateScores(const char* filename, Player* players, int numPlayers) {
    int i;
    for (i = 0; i < numPlayers; i++) {
        players[i].score += 10;
    }

    // Update the scores in the database
    writePlayersToFile(filename, players, numPlayers);
}

int main() {
    // Read players from a file
    Player* players = readPlayersFromFile("players.txt");
    int numPlayers = 5; // Number of players

    // Update scores in the database
    updateScores("scores.txt", players, numPlayers);

    // Print the updated scores
    printf("Updated scores:\n");
    for (int i = 0; i < numPlayers; i++) {
        printf("%s %d\n", players[i].name, players[i].score);
    }

    free(players); // Free allocated memory

    return 0;
}
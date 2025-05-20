//FormAI DATASET v1.0 Category: System boot optimizer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // Initialize variables
    char username[20];
    int num_players;

    // Get user input
    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter number of players (2-4): ");
    scanf("%d", &num_players);

    // Check for valid input
    if(num_players < 2 || num_players > 4) {
        printf("Invalid number of players!\n");
        return 1;
    }

    // Create player array
    char **players = (char**)malloc(num_players * sizeof(char*));

    // Add user as first player
    players[0] = (char*)malloc(strlen(username) + 1);
    strcpy(players[0], username);

    // Get other player names
    for(int i = 1; i < num_players; i++) {
        printf("Enter player %d name: ", i);
        char name[20];
        scanf("%s", name);
        players[i] = (char*)malloc(strlen(name) + 1);
        strcpy(players[i], name);
    }

    // Print player names
    printf("Players are: ");
    for(int i = 0; i < num_players; i++) {
        printf("%s ", players[i]);
    }
    printf("\n");

    // Clean up
    for(int i = 0; i < num_players; i++) {
        free(players[i]);
    }
    free(players);

    return 0;
}
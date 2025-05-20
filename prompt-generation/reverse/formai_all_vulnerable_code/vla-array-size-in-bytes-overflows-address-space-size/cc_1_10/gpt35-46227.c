//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Function to generate random download speeds
int generateDownloadSpeed() {
    return rand() % 101;
}

// Function to generate random upload speeds
int generateUploadSpeed() {
    return rand() % 101;
}

// Struct to hold each player's speed test results
struct Player {
    char name[30];
    int downloadSpeed;
    int uploadSpeed;
};

int main() {
    srand(time(NULL)); // Seed the random number generator

    int numPlayers;
    printf("How many players are in the game?\n");
    scanf("%d", &numPlayers);

    struct Player players[numPlayers]; // Create an array of player structs

    // Loop through each player, prompt for their name, and generate their speed results
    for (int i = 0; i < numPlayers; i++) {
        printf("Enter player %d's name:\n", i+1);
        scanf("%s", players[i].name);
        players[i].downloadSpeed = generateDownloadSpeed();
        players[i].uploadSpeed = generateUploadSpeed();
        printf("%s's download speed: %d Mbps\n", players[i].name, players[i].downloadSpeed);
        printf("%s's upload speed: %d Mbps\n\n", players[i].name, players[i].uploadSpeed);
    }

    // Determine the player with the highest download speed and the player with the highest upload speed
    int maxDownloadSpeed = 0;
    int maxUploadSpeed = 0;
    char maxDownloadPlayer[30];
    char maxUploadPlayer[30];
    for (int i = 0; i < numPlayers; i++) {
        if (players[i].downloadSpeed > maxDownloadSpeed) {
            maxDownloadSpeed = players[i].downloadSpeed;
            strcpy(maxDownloadPlayer, players[i].name);
        }
        if (players[i].uploadSpeed > maxUploadSpeed) {
            maxUploadSpeed = players[i].uploadSpeed;
            strcpy(maxUploadPlayer, players[i].name);
        }
    }

    // Print out the winners for each category
    printf("The winner for highest download speed is %s with a speed of %d Mbps!\n", maxDownloadPlayer, maxDownloadSpeed);
    printf("The winner for highest upload speed is %s with a speed of %d Mbps!\n", maxUploadPlayer, maxUploadSpeed);

    return 0;
}
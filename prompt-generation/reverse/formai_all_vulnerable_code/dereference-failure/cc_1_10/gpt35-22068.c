//FormAI DATASET v1.0 Category: QR code reader ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Define struct for player
typedef struct {
    char name[20];
    int score;
} Player;

// Function declarations
void printInstructions();
void scanQR(char qrCode[20]);
bool checkQR(char qrCode[20], Player *player);
void updateScore(Player *player, int scoreToAdd);
void printScoreboard(Player *players[], int numPlayers);

int main() {
    // Initialize players
    Player *p1 = malloc(sizeof(Player));
    Player *p2 = malloc(sizeof(Player));
    strcpy(p1->name, "Player 1");
    strcpy(p2->name, "Player 2");
    p1->score = 0;
    p2->score = 0;
    Player *players[] = {p1, p2};
    int numPlayers = 2;
    
    // Print instructions
    printInstructions();
    
    // Begin game loop
    bool gameActive = true;
    while (gameActive) {
        char qrCode[20];
        scanQR(qrCode);
        for (int i = 0; i < numPlayers; i++) {
            if (checkQR(qrCode, players[i])) {
                updateScore(players[i], 10);
            }
        }
        printScoreboard(players, numPlayers);
        char playAgain;
        printf("Play again? (y/n): ");
        scanf(" %c", &playAgain);
        if (playAgain == 'n') {
            gameActive = false;
        }
    }
    
    // Free memory and exit program
    free(p1);
    free(p2);
    return 0;
}

// Function to print instructions
void printInstructions() {
    printf("Welcome to the QR code reader game!\n\n");
    printf("Scan QR codes to earn points.\n");
    printf("Each QR code is worth 10 points.\n");
    printf("The game will end when you choose not to play again.\n\n");
}

// Function to simulate scanning a QR code
void scanQR(char qrCode[20]) {
    printf("Scan QR code: ");
    scanf("%s", qrCode);
}

// Function to check if QR code is valid and update player's score
bool checkQR(char qrCode[20], Player *player) {
    // In a real program, this function would check if the QR code is valid
    // For this example, we'll assume any QR code is valid
    if (strcmp(qrCode, "abcd1234") == 0) {
        updateScore(player, 10);
        return true;
    } else {
        return false;
    }
}

// Function to update player's score
void updateScore(Player *player, int scoreToAdd) {
    player->score += scoreToAdd;
}

// Function to print scoreboard
void printScoreboard(Player *players[], int numPlayers) {
    printf("\nScoreboard:\n");
    for (int i = 0; i < numPlayers; i++) {
        printf("%s: %d\n", players[i]->name, players[i]->score);
    }
    printf("\n");
}
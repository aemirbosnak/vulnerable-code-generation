//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// Function to convert decimal to binary
void decimalToBinary(int decimal) {
    if (decimal == 0) {
        printf("Binary: 0\n");
        return;
    }
    
    int binary[32]; // Assuming a maximum of 32 bits
    int index = 0;

    while (decimal > 0) {
        binary[index++] = decimal % 2;
        decimal /= 2;
    }

    printf("Binary: ");
    for (int j = index - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }
    printf("\n");
}

// Function to handle a player's request
void playGame(int playerId) {
    int decimalNumber;

    printf("Player %d, enter a decimal number to convert: ", playerId);
    scanf("%d", &decimalNumber);
    
    printf("Player %d converting...\n", playerId);
    decimalToBinary(decimalNumber);
    printf("Player %d finished conversion!\n", playerId);
}

int main() {
    int numPlayers;

    printf("Welcome to the Multiplayer Binary Converter!\n");
    printf("Enter the number of players: ");
    scanf("%d", &numPlayers);

    pid_t pids[numPlayers]; // Array to store process IDs

    for (int i = 0; i < numPlayers; i++) {
        pids[i] = fork(); // Create a new process for each player

        if (pids[i] < 0) {
            fprintf(stderr, "Fork failed for player %d\n", i + 1);
            exit(1);
        } else if (pids[i] == 0) {
            // Child process
            playGame(i + 1);
            exit(0); // Ensure child terminates properly
        }
    }

    // Parent process waits for all children to finish
    for (int i = 0; i < numPlayers; i++) {
        wait(NULL);
    }

    printf("All players completed their conversions. Thank you for playing!\n");
    return 0;
}
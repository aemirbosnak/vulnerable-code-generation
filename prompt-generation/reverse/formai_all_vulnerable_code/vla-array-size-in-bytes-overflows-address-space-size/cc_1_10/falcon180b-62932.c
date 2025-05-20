//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to check if a number is prime
int isPrime(int num) {
    int i;
    for (i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Function to generate a prime number
int generatePrime() {
    int num = rand() % 100000 + 1;
    while (!isPrime(num)) {
        num = rand() % 100000 + 1;
    }
    return num;
}

// Function to print a message to all players
void broadcastMessage(char* message) {
    printf("%s\n", message);
}

// Function to handle player input
void handleInput(char* input, int playerID) {
    if (strcmp(input, "generatePrime") == 0) {
        int prime = generatePrime();
        printf("Player %d generated prime number %d\n", playerID, prime);
    } else {
        printf("Invalid input from player %d\n", playerID);
    }
}

int main() {
    int numPlayers;
    printf("Enter number of players: ");
    scanf("%d", &numPlayers);

    // Initialize player IDs
    int playerIDs[numPlayers];
    for (int i = 0; i < numPlayers; i++) {
        playerIDs[i] = i + 1;
    }

    // Shuffle player IDs
    for (int i = 0; i < numPlayers; i++) {
        int j = rand() % numPlayers;
        int temp = playerIDs[i];
        playerIDs[i] = playerIDs[j];
        playerIDs[j] = temp;
    }

    // Print player IDs
    printf("Player IDs:\n");
    for (int i = 0; i < numPlayers; i++) {
        printf("%d: %d\n", i + 1, playerIDs[i]);
    }

    // Main game loop
    while (1) {
        char input[100];
        for (int i = 0; i < numPlayers; i++) {
            printf("Player %d, enter your command: ", playerIDs[i]);
            scanf("%s", input);
            handleInput(input, playerIDs[i]);
        }
    }

    return 0;
}
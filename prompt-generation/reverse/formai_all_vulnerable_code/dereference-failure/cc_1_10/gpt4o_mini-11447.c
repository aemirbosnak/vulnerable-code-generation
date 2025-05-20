//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 100
#define BUCKET_SIZE 10

// Structure to hold player data
typedef struct {
    char name[30];
    int score;
} Player;

// Function to create and initialize buckets
void createBuckets(Player** buckets, int* bucketCount, int maxScore) {
    *bucketCount = (maxScore / BUCKET_SIZE) + 1;

    // Allocate memory for buckets
    *buckets = (Player*) malloc(sizeof(Player) * MAX_PLAYERS * (*bucketCount));
    for (int i = 0; i < (*bucketCount); i++) {
        for (int j = 0; j < MAX_PLAYERS; j++) {
            (*buckets)[i * MAX_PLAYERS + j].score = -1; // Initialize with invalid scores
        }
    }
}

// Function to add a player to a bucket
void addToBucket(Player* buckets, int bucketIndex, Player player) {
    for (int i = 0; i < MAX_PLAYERS; i++) {
        if (buckets[bucketIndex * MAX_PLAYERS + i].score == -1) {
            buckets[bucketIndex * MAX_PLAYERS + i] = player;
            break;
        }
    }
}

// Function to sort players in each bucket
void sortBucket(Player* bucket) {
    int i, j;
    Player temp;

    // Simple selection sort for each bucket
    for (i = 0; i < MAX_PLAYERS - 1; i++) {
        for (j = i + 1; j < MAX_PLAYERS; j++) {
            if (bucket[j].score != -1 && (bucket[i].score == -1 || bucket[j].score < bucket[i].score)) {
                temp = bucket[i];
                bucket[i] = bucket[j];
                bucket[j] = temp;
            }
        }
    }
}

// Function to display players and their scores
void displayPlayers(Player* buckets, int bucketCount) {
    printf("\nSorted Player Scores:\n");
    for (int i = 0; i < bucketCount; i++) {
        for (int j = 0; j < MAX_PLAYERS; j++) {
            if (buckets[i * MAX_PLAYERS + j].score != -1) {
                printf("%s: %d\n", buckets[i * MAX_PLAYERS + j].name, buckets[i * MAX_PLAYERS + j].score);
            }
        }
    }
}

// Main function to drive the program
int main() {
    Player players[MAX_PLAYERS];
    Player* buckets = NULL;
    int bucketCount = 0, playerCount = 0;

    // Input player data
    printf("Enter the number of players (max %d): ", MAX_PLAYERS);
    scanf("%d", &playerCount);
    if (playerCount > MAX_PLAYERS) {
        printf("Player count exceeds maximum allowed.\n");
        return 1;
    }

    int maxScore = 0;
    for (int i = 0; i < playerCount; i++) {
        printf("Enter name of player %d: ", i + 1);
        scanf("%s", players[i].name);
        printf("Enter score of player %d: ", i + 1);
        scanf("%d", &players[i].score);
        if (players[i].score > maxScore) {
            maxScore = players[i].score; // Find the maximum score
        }
    }

    // Create buckets based on maximum score
    createBuckets(&buckets, &bucketCount, maxScore);

    // Distribute players into buckets
    for (int i = 0; i < playerCount; i++) {
        int bucketIndex = players[i].score / BUCKET_SIZE;
        addToBucket(buckets, bucketIndex, players[i]);
    }

    // Sort each bucket
    for (int i = 0; i < bucketCount; i++) {
        sortBucket(&buckets[i * MAX_PLAYERS]);
    }

    // Display sorted players
    displayPlayers(buckets, bucketCount);

    // Cleanup memory
    free(buckets);
    return 0;
}
//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_LENGTH 10 // Length of genome sequences
#define NUM_PLAYERS 2 // Number of players

// Function to generate random genome sequence
char* generate_genome() {
    static const char nucleotides[] = "ACGT";
    char* genome = malloc(GENOME_LENGTH + 1);
    for (int i = 0; i < GENOME_LENGTH; i++) {
        genome[i] = nucleotides[rand() % 4];
    }
    genome[GENOME_LENGTH] = '\0'; // Null-terminate the string
    return genome;
}

// Function to compare two genome sequences
int compare_genomes(char* genome1, char* genome2) {
    int match_count = 0;
    for (int i = 0; i < GENOME_LENGTH; i++) {
        if (genome1[i] == genome2[i]) {
            match_count++;
        }
    }
    return match_count;
}

int main() {
    srand(time(NULL)); // Seed the random number generator with current time
    int scores[NUM_PLAYERS] = {}; // Initialize all scores to zero
    char* genomes[NUM_PLAYERS];

    for (int i = 0; i < NUM_PLAYERS; i++) {
        genomes[i] = generate_genome();
        printf("Player %d: %s\n", i + 1, genomes[i]);
    }

    printf("Let the game begin!\n");

    while (1) {

        // Get player inputs
        int choices[NUM_PLAYERS];
        for (int i = 0; i < NUM_PLAYERS; i++) {
            printf("Player %d: Choose a player to compare with (1-%d): ", i + 1, NUM_PLAYERS);
            scanf("%d", &choices[i]);
            while (choices[i] < 1 || choices[i] > NUM_PLAYERS || choices[i] == i + 1) {
                printf("Invalid choice. Player %d, please choose a different player: ", i + 1);
                scanf("%d", &choices[i]);
            }
        }

        // Calculate scores
        for (int i = 0; i < NUM_PLAYERS; i++) {
            int match_count = compare_genomes(genomes[i], genomes[choices[i] - 1]);
            scores[i] += match_count;
        }

        // Print scores
        printf("Scores:\n");
        for (int i = 0; i < NUM_PLAYERS; i++) {
            printf("Player %d: %d\n", i + 1, scores[i]);
        }

        // Check for winner
        int max_score = scores[0];
        int winner = 1;
        for (int i = 1; i < NUM_PLAYERS; i++) {
            if (scores[i] > max_score) {
                max_score = scores[i];
                winner = i + 1;
            } else if (scores[i] == max_score) {
                winner = 0; // Tie
            }
        }

        if (winner) {
            printf("Player %d is currently in the lead.\n", winner);
        } else {
            printf("It's a tie!\n");
        }

        // Check if game over
        int game_over = 0;
        for (int i = 0; i < NUM_PLAYERS; i++) {
            if (scores[i] == GENOME_LENGTH) {
                printf("Player %d wins!\n", i + 1);
                game_over = 1;
                break;
            }
        }

        if (game_over) {
            break;
        }

        printf("\n"); // Add some spacing before next round
    }

    // Free memory
    for (int i = 0; i < NUM_PLAYERS; i++) {
        free(genomes[i]);
    }

    return 0;
}
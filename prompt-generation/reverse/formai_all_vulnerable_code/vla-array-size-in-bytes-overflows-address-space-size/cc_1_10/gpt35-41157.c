//FormAI DATASET v1.0 Category: Text Summarizer ; Style: multiplayer
// Text Summarizer Multiplayer Game
//
// In this game, multiple players compete against each other to create the most accurate text summaries.
// Each player takes turns entering a passage of text, and then all players vote on the best summary.
// The summary with the most votes wins, and the winner gets points.
// The game continues until a pre-determined number of points is reached.
//
// Created by [Your Name]

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT_SIZE 1000
#define MAX_SUMMARY_SIZE 100

int main() {
    char text[MAX_TEXT_SIZE];
    char summary[MAX_SUMMARY_SIZE];
    int num_players, max_points, curr_points;
    
    // Get input from the user
    printf("Welcome to Text Summarizer! How many players will be playing?\n");
    scanf("%d", &num_players);
    printf("What is the maximum number of points to win?\n");
    scanf("%d", &max_points);
    
    // Initialize points
    int player_points[num_players];
    for (int i = 0; i < num_players; i++) {
        player_points[i] = 0;
    }
    
    // Game loop
    while (1) {
        // Get passage of text from player
        printf("Player %d, please enter a passage of text (max %d characters):\n", curr_points % num_players, MAX_TEXT_SIZE);
        fflush(stdin); // Clear input buffer
        fgets(text, MAX_TEXT_SIZE, stdin);
        
        // Get summary from player
        printf("Player %d, please enter a summary of the text (max %d characters):\n", curr_points % num_players, MAX_SUMMARY_SIZE);
        fflush(stdin); // Clear input buffer
        fgets(summary, MAX_SUMMARY_SIZE, stdin);
        
        // Display summaries and get player votes
        int votes[num_players];
        for (int i = 0; i < num_players; i++) {
            printf("Summary from Player %d: %s", i, summary);
            printf("Do you think Player %d's summary is the best? (1 for yes, 0 for no)\n", i);
            scanf("%d", &votes[i]);
        }
        
        // Calculate total votes and update points
        int total_votes = 0;
        for (int i = 0; i < num_players; i++) {
            total_votes += votes[i];
        }
        if (total_votes == 1) {
            for (int i = 0; i < num_players; i++) {
                if (votes[i] == 1) {
                    player_points[i]++;
                }
            }
        }
        
        // Check for game over
        for (int i = 0; i < num_players; i++) {
            if (player_points[i] == max_points) {
                printf("Player %d wins with %d points!", i, max_points);
                exit(0);
            }
        }
        
        // Move to next player
        curr_points++;
    }
    
    return 0;
}
//FormAI DATASET v1.0 Category: Math exercise ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate problems
void ask_question(int player_num, int* answer, int* score) {
    int operand1 = rand() % 10;
    int operand2 = rand() % 10;
    char operator = rand() % 3 == 0 ? '+' : '-';
    
    printf("Player %d: What is %d %c %d? ", player_num, operand1, operator, operand2);
    
    // Get player's answer
    int player_answer;
    scanf("%d", &player_answer);
    
    // Check player's answer
    if (player_answer == (operator == '+' ? operand1 + operand2 : operand1 - operand2)) {
        printf("Correct!\n");
        *score += 1;
    } else {
        printf("Incorrect!\n");
    }
    printf("Player %d's score: %d\n", player_num, *score);
}

int main() {
    // Set seed for random numbers
    srand(time(NULL));
    
    // Get number of players
    int num_players;
    printf("How many players? ");
    scanf("%d", &num_players);
    
    // Create array of player scores
    int scores[num_players];
    for (int i = 0; i < num_players; i++) {
        scores[i] = 0;
    }
    
    // Play game until one player reaches score of 10
    int winner = -1; // -1 signifies no winner yet
    while (winner == -1) {
        for (int i = 0; i < num_players; i++) {
            printf("\n");
            int answer, score;
            score = scores[i];
            ask_question(i+1, &answer, &score);
            scores[i] = score;
            if (scores[i] == 10) {
                winner = i+1;
                break;
            }
        }
    }
    
    // Print winner
    printf("\nPlayer %d wins!\n", winner);
    
    return 0;
}
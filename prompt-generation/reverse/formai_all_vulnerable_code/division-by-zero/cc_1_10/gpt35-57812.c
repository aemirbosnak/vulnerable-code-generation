//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random number
int get_random_number(int range) {
    return rand() % range + 1;
}

// Struct to store player information
typedef struct {
    char name[20];
    int score;
    int chance;
} Player;

// Function to play the game
void play_game(Player *players, int num_players, int range) {
    int target_number = get_random_number(range);
    int winner_index = -1;
    int remaining_players = num_players;

    while (remaining_players > 0) {
        for (int i = 0; i < num_players; i++) {
            // Player gets a chance only if they have remaining chances
            if (players[i].chance > 0) {
                printf("\n%s, enter your guess: ", players[i].name);
                int guess;
                scanf("%d", &guess);
                
                // Validate the guess
                if (guess < 1 || guess > range) {
                    printf("Invalid input. Try again.\n");
                    i--;
                    continue;
                }

                players[i].chance--;

                // Increase the score if the guess is correct
                if (guess == target_number) {
                    players[i].score++;
                    winner_index = i;
                    remaining_players--;
                    printf("\nCongratulations, %s! You have won the game.", players[i].name);
                    break;
                }
                else if (guess < target_number) {
                    printf("\n%s, your guess is too low. You have %d chances left.", players[i].name, players[i].chance);
                }
                else {
                    printf("\n%s, your guess is too high. You have %d chances left.", players[i].name, players[i].chance);
                }
            }
            else {
                printf("\n%s, you have no chances left.", players[i].name);
                remaining_players--;
            }
        }
    }

    // Declare the winner
    if (winner_index != -1) {
        printf("\n\nThe winner is %s with %d points.\n", players[winner_index].name, players[winner_index].score);
    }
}

int main() {
    srand(time(NULL));

    // Get user input
    int num_players, range;
    printf("Enter the number of players: ");
    scanf("%d", &num_players);
    printf("Enter the range of numbers (1 - ?): ");
    scanf("%d", &range);

    // Initialize player struct array
    Player players[num_players];
    for (int i = 0; i < num_players; i++) {
        printf("Enter Player %d name: ", i+1);
        scanf("%s", players[i].name);
        players[i].score = 0;
        players[i].chance = 3;
    }

    // Play the game
    play_game(players, num_players, range);

    return 0;
}
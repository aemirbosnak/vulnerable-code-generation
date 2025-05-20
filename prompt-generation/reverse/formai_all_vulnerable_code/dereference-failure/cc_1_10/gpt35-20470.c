//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: multiplayer
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

void multiplayer_game(char *word, int size) {
    int player1_score = 0, player2_score = 0;
    int turn = 1;

    while(size > 0) {
        printf("Turn %d\n", turn);
        printf("Player %d, enter your palindrome: ", turn);

        char *input = NULL;
        size_t len = 0;
        getline(&input, &len, stdin);

        // Remove newline character from input
        input[strcspn(input, "\n")] = 0;

        // Convert input to lowercase
        for(int i=0; i<size; i++) {
            word[i] = tolower(word[i]);
        }
        for(int i=0; i<strlen(input); i++) {
            input[i] = tolower(input[i]);
        }

        // Check if input is a palindrome
        int is_palindrome = 1;
        for(int i=0; i<strlen(input)/2; i++) {
            if(input[i] != input[strlen(input)-1-i]) {
                is_palindrome = 0;
                break;
            }
        }

        if(!is_palindrome) {
            printf("Oops, %s is not a palindrome.\n", input);
            player1_score += turn == 1 ? -1 : 0;
            player2_score += turn == 2 ? -1 : 0;
            turn = turn == 1 ? 2 : 1;
        } else {
            printf("Good job, %s is a palindrome!\n", input);
            size -= strlen(input);
            player1_score += turn == 1 ? strlen(input) : 0;
            player2_score += turn == 2 ? strlen(input) : 0;
        }

        printf("Player 1 score: %d\n", player1_score);
        printf("Player 2 score: %d\n\n", player2_score);

        free(input);
    }

    if(player1_score > player2_score) {
        printf("Player 1 wins!\n");
    } else if(player2_score > player1_score) {
        printf("Player 2 wins!\n");
    } else {
        printf("Tie game!\n");
    }
}

int main() {
    char word[] = "racecarlevelhello";
    int size = sizeof(word)-1;
    multiplayer_game(word, size);
    return 0;
}
//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: multiplayer
#include <stdio.h>
#include <string.h>

#define MAX_WORD_LEN 20
#define MAX_PLAYERS 4

int distance(const char *s1, const char *s2);

int main() {
    char players[MAX_PLAYERS][MAX_WORD_LEN];
    int num_players;
    
    printf("Enter the number of players (up to %d): ", MAX_PLAYERS);
    scanf("%d", &num_players);
    
    // get player names and ensure they are unique
    for (int i = 0; i < num_players; i++) {
        printf("Enter the name of player %d: ", i+1);
        scanf("%s", players[i]);
        
        // check if name already taken
        for (int j = 0; j < i; j++) {
            if (strcmp(players[i], players[j]) == 0) {
                printf("That name is already taken. Please choose another.\n");
                i--; // go back one iteration to prompt again
                break;
            }
        }
    }
    
    // print out player names for reference
    printf("Players: ");
    for (int i = 0; i < num_players; i++)
        printf("%s ", players[i]);
    printf("\n\n");
    
    // get target word
    char target_word[MAX_WORD_LEN];
    printf("Enter the target word (up to %d characters): ", MAX_WORD_LEN-1);
    scanf("%s", target_word);
    printf("\n\n");
    
    int num_guesses = 0;
    
    // game loop
    while (1) {
        char current_word[MAX_WORD_LEN];
        printf("Current word: %s\n", target_word);
        printf("Player %d, enter your guess (up to %d characters): ", (num_guesses % num_players) + 1, MAX_WORD_LEN-1);
        scanf("%s", current_word);
        printf("\n");
        
        // get Levenshtein distance between current word and target word
        int dist = distance(current_word, target_word);
        printf("Levenshtein distance: %d\n\n", dist);
        
        // check if guess is valid
        if (dist == 1 && strlen(current_word) == strlen(target_word)) {
            printf("Player %d wins!\n", (num_guesses % num_players) + 1);
            break;
        }
        else if (dist == 0 || dist > 1) {
            printf("Sorry, that guess is not valid. Please try again.\n\n");
            continue;
        }
        else {
            // update target word for next guess
            printf("Player %d has changed the word to %s\n\n", (num_guesses % num_players) + 1, current_word);
            strcpy(target_word, current_word);
        }
        
        num_guesses++;
    }
    
    return 0;
}

int distance(const char *s1, const char *s2) {
    unsigned int x, y, s1len, s2len;
    s1len = strlen(s1);
    s2len = strlen(s2);
    unsigned int matrix[MAX_WORD_LEN][MAX_WORD_LEN];
    matrix[0][0] = 0;
    for (x = 1; x <= s2len; x++)
        matrix[x][0] = matrix[x-1][0] + 1;
    for (y = 1; y <= s1len; y++)
        matrix[0][y] = matrix[0][y-1] + 1;
    for (x = 1; x <= s2len; x++)
        for (y = 1; y <= s1len; y++)
            matrix[x][y] = minimum(matrix[x-1][y]+1,
                                    matrix[x][y-1]+1,
                                    matrix[x-1][y-1]+((s1[y-1]==s2[x-1])?0:1));
    return(matrix[s2len][s1len]);
}

int minimum(int a, int b, int c) {
    int min = a;
    if (b < min)
        min = b;
    if (c < min)
        min = c;
    return(min);
}
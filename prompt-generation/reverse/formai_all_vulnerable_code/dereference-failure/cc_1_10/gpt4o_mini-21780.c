//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LENGTH 100

int min(int a, int b) {
    return (a < b) ? a : b;
}

int levenshtein_distance(const char *s, const char *t) {
    int len_s = strlen(s);
    int len_t = strlen(t);
    int **d = malloc((len_s + 1) * sizeof(int *));
    
    for (int i = 0; i <= len_s; i++) {
        d[i] = malloc((len_t + 1) * sizeof(int));
    }

    for (int i = 0; i <= len_s; i++) {
        d[i][0] = i;
    }

    for (int j = 0; j <= len_t; j++) {
        d[0][j] = j;
    }

    for (int i = 1; i <= len_s; i++) {
        for (int j = 1; j <= len_t; j++) {
            int cost = (s[i - 1] == t[j - 1]) ? 0 : 1;
            d[i][j] = min(min(d[i - 1][j] + 1, d[i][j - 1] + 1), d[i - 1][j - 1] + cost);
        }
    }

    int distance = d[len_s][len_t];

    for (int i = 0; i <= len_s; i++) {
        free(d[i]);
    }
    free(d);

    return distance;
}

void get_input(char *prompt, char *buffer, int buffer_length) {
    printf("%s", prompt);
    fgets(buffer, buffer_length, stdin);
    buffer[strcspn(buffer, "\n")] = 0;  // Remove newline character
}

int main() {
    char player1[MAX_STR_LENGTH];
    char player2[MAX_STR_LENGTH];

    printf("Welcome to the Multiplayer Levenshtein Distance Calculator!\n");
    printf("Two players will input their strings, and we will compute the distance between them.\n\n");

    get_input("Player 1, please enter your string: ", player1, MAX_STR_LENGTH);
    get_input("Player 2, please enter your string: ", player2, MAX_STR_LENGTH);

    int distance = levenshtein_distance(player1, player2);
    printf("\nThe Levenshtein distance between:\n");
    printf("Player 1's string: \"%s\"\n", player1);
    printf("Player 2's string: \"%s\"\n", player2);
    printf("is: %d\n", distance);

    return 0;
}
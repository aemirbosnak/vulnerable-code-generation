//FormAI DATASET v1.0 Category: Spell checking ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000
#define MAX_PLAYERS 4

char dictionary[MAX_LENGTH][MAX_LENGTH];
int dictSize = 0;

void loadDictionary() {
    FILE* dictFile = fopen("dictionary.txt", "r");
    char word[MAX_LENGTH];
    while (fgets(word, MAX_LENGTH, dictFile) != NULL) {
        word[strcspn(word, "\n")] = '\0';  // remove new line character
        strcpy(dictionary[dictSize], word);
        dictSize++;
    }
    fclose(dictFile);
}

int checkWord(char* word) {
    int len = strlen(word);
    if (len < 3 || len > 15) {
        return 0;  // words must be between 3 and 15 characters long
    }
    for (int i = 0; i < len; i++) {
        if (!isalpha(word[i])) {
            return 0;  // words can only contain alphabetical characters
        }
    }
    for (int i = 0; i < dictSize; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1;  // word matches dictionary
        }
    }
    return 0;  // word not in dictionary
}

int main() {
    loadDictionary();
    char word[MAX_LENGTH];
    int playerScores[MAX_PLAYERS] = {0};
    int currentPlayer = 0;
    printf("Welcome to Multiplayer Spell Check!\n\n");
    
    while (1) {
        printf("Player %d: Please enter a word (or enter 'EXIT' to end game): ", currentPlayer+1);
        scanf("%s", word);
        if (strcmp(word, "EXIT") == 0) {
            printf("\nFinal Scores\n");
            for (int i = 0; i < MAX_PLAYERS; i++) {
                printf("Player %d: %d\n", i+1, playerScores[i]);
            }
            break;
        }
        if (checkWord(word)) {
            printf("Correct!\n\n");
            playerScores[currentPlayer]++;
        } else {
            printf("Incorrect!\n\n");
        }
        currentPlayer++;
        if (currentPlayer == MAX_PLAYERS) {
            currentPlayer = 0;
        }
    }
    
    return 0;
}
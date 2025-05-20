//FormAI DATASET v1.0 Category: Spell checking ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 50
#define DICTIONARY_FILE "dictionary.txt"

// Function to check if a word is spelled correctly
int is_spelled_correctly(char *word, char *dictionary[]) {
    int i;
    for (i = 0; dictionary[i] != NULL; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char *dictionary[MAX_WORD_LEN];
    char word[MAX_WORD_LEN];
    int correct = 0, incorrect = 0;

    // Load dictionary file
    FILE *fp = fopen(DICTIONARY_FILE, "r");
    if (fp == NULL) {
        printf("Error: could not open dictionary file!\n");
        return 1;
    }
    int i = 0;
    while (!feof(fp)) {
        dictionary[i] = malloc(MAX_WORD_LEN);
        fgets(dictionary[i], MAX_WORD_LEN, fp);
        // Remove newline character if present on last word
        if (dictionary[i][strlen(dictionary[i])-1] == '\n') {
            dictionary[i][strlen(dictionary[i])-1] = '\0';
        }
        i++;
    }
    dictionary[i-1] = NULL;
    fclose(fp);

    // Ask user to enter words to check
    printf("Enter a word (q to quit): ");
    fgets(word, MAX_WORD_LEN, stdin);
    while (strcmp(word, "q\n") != 0) {
        // Remove newline character
        if (word[strlen(word)-1] == '\n') {
            word[strlen(word)-1] = '\0';
        }

        // Check if word is spelled correctly
        if (is_spelled_correctly(word, dictionary)) {
            printf("%s is spelled correctly!\n", word);
            correct++;
        } else {
            printf("%s is spelled incorrectly!\n", word);
            incorrect++;
        }

        // Ask user for next word
        printf("Enter a word (q to quit): ");
        fgets(word, MAX_WORD_LEN, stdin);
    }

    // Print summary of correct/incorrect words
    printf("Correctly spelled: %d\n", correct);
    printf("Incorrectly spelled: %d\n", incorrect);

    // Free memory used by dictionary
    for (i = 0; dictionary[i] != NULL; i++) {
        free(dictionary[i]);
    }

    return 0;
}
//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_LENGTH 256
#define MAX_WORDS 100
#define DELIMITER " "

typedef struct {
    char *word;
    int length;
} Word;

int main() {
    char input[MAX_LENGTH];
    Word words[MAX_WORDS];
    int numWords = 0;
    int i, j, k;
    srand(time(NULL));

    // Prompt user for input
    printf("Enter a string: ");
    fgets(input, MAX_LENGTH, stdin);

    // Remove newline character
    input[strcspn(input, "\n")] = '\0';

    // Convert all characters to lowercase
    for (i = 0; input[i]!= '\0'; i++) {
        input[i] = tolower(input[i]);
    }

    // Split input into words
    char *token = strtok(input, DELIMITER);
    while (token!= NULL) {
        if (numWords >= MAX_WORDS) {
            printf("Error: Too many words.\n");
            exit(1);
        }
        words[numWords].word = malloc(strlen(token) + 1);
        strcpy(words[numWords].word, token);
        words[numWords].length = strlen(token);
        numWords++;
        token = strtok(NULL, DELIMITER);
    }

    // Sort words by length
    for (i = 0; i < numWords - 1; i++) {
        for (j = i + 1; j < numWords; j++) {
            if (words[j].length < words[i].length) {
                Word temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }

    // Print sorted words
    printf("Sorted words by length:\n");
    for (i = 0; i < numWords; i++) {
        printf("%s (%d)\n", words[i].word, words[i].length);
    }

    // Free memory
    for (i = 0; i < numWords; i++) {
        free(words[i].word);
    }

    return 0;
}
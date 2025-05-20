//FormAI DATASET v1.0 Category: Text processing ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold each word and its count
struct WordCount {
    char word[50];
    int count;
};

void processFile(FILE *file, struct WordCount *wordCounts, int *numWords) {
    char line[100];
    while (fgets(line, sizeof(line), file)) {
        // Remove new line character from the end of the line
        char *pos;
        if ((pos = strchr(line, '\n')) != NULL) {
            *pos = '\0';
        }

        // Tokenize the line
        char *token = strtok(line, " ");
        while (token != NULL) {
            // Look for the token in the wordCounts array
            int i;
            for (i = 0; i < *numWords; i++) {
                if (strcmp(wordCounts[i].word, token) == 0) {
                    // If found, increment the count
                    wordCounts[i].count++;
                    break;
                }
            }

            // If the token is not in the wordCounts array, add it
            if (i == *numWords) {
                strcpy(wordCounts[i].word, token);
                wordCounts[i].count = 1;
                (*numWords)++;
            }

            token = strtok(NULL, " ");
        }
    }
}

int main() {
    // Open the file
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    // Allocate space for an array of WordCount structures
    struct WordCount *wordCounts = malloc(100 * sizeof(struct WordCount));

    // Process the file and count the words
    int numWords = 0;
    processFile(file, wordCounts, &numWords);

    // Close the file
    fclose(file);

    // Print out the word counts
    int i;
    for (i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }

    // Free the memory allocated for the wordCounts array
    free(wordCounts);

    return 0;
}
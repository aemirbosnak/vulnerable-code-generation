//Falcon-180B DATASET v1.0 Category: Image Classification system ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_NUM_WORDS 100

typedef struct {
    char *word;
    int count;
} WordCount;

int main() {
    FILE *file;
    char line[MAX_WORD_LENGTH];
    char *word;
    WordCount words[MAX_NUM_WORDS];
    int numWords = 0;
    int i;

    // Open file for reading
    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    // Read file line by line
    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        // Remove newline character
        line[strcspn(line, "\n")] = '\0';

        // Convert line to lowercase
        for (i = 0; line[i]!= '\0'; i++) {
            line[i] = tolower(line[i]);
        }

        // Count number of words in line
        word = strtok(line, " ");
        while (word!= NULL) {
            numWords++;
            if (numWords >= MAX_NUM_WORDS) {
                printf("Error: too many words in line.\n");
                fclose(file);
                return 1;
            }

            // Check if word already exists in hash table
            int j;
            for (j = 0; j < numWords - 1; j++) {
                if (strcmp(words[j].word, word) == 0) {
                    words[j].count++;
                    break;
                }
            }

            // Add new word to hash table
            if (j == numWords - 1) {
                words[numWords - 1].word = strdup(word);
                words[numWords - 1].count = 1;
            }

            word = strtok(NULL, " ");
        }
    }

    // Close file
    fclose(file);

    // Print word count
    printf("Word count:\n");
    for (i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}
//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_SIZE 256
#define MAX_WORDS 1000
#define WORD_SIZE 32

int main()
{
    // Declare variables
    FILE *fp;
    char line[LINE_SIZE];
    char words[MAX_WORDS][WORD_SIZE];
    int count[MAX_WORDS] = {0};
    int wordsCount = 0;
    int i, j, k;

    // Open file
    fp = fopen("example.txt", "r");

    // Read file line by line
    while (fgets(line, LINE_SIZE, fp)) {
        // Convert line to lowercase
        for (i = 0; line[i]; i++) {
            line[i] = tolower(line[i]);
        }
        // Tokenize line and count words
        char *token = strtok(line, " ,.-\n");
        while (token) {
            // Add word to array if it doesn't already exist
            if (!strcmp(token, "\n")) {
                token = strtok(NULL, " ,.-\n");
                continue;
            }
            int found = 0;
            for (i = 0; i < wordsCount; i++) {
                if (!strcmp(token, words[i])) {
                    count[i]++;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                strcpy(words[wordsCount], token);
                count[wordsCount]++;
                wordsCount++;
            }
            // Get next token
            token = strtok(NULL, " ,.-\n");
        }
    }
    // Print word frequency
    printf("Word Frequency:\n");
    for (i = 0; i < wordsCount; i++) {
        printf("%s: %d\n", words[i], count[i]);
    }
    // Close file
    fclose(fp);

    return 0;
}
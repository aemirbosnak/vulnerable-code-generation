//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: sophisticated
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000

int main() {
    char text[MAX_WORDS];
    int wordCount = 0;
    int freqCount[MAX_WORDS] = {0};

    printf("Enter some text (1000 max chars):\n");
    fgets(text, MAX_WORDS, stdin);

    char *word = strtok(text, " ");

    while (word != NULL) {
        wordCount++;

        char lowerWord[strlen(word)];
        int i;
        for (i = 0; i < strlen(word); i++) {
            lowerWord[i] = tolower(word[i]); // Convert word to lowercase
        }

        int found = 0;
        int j;
        for (j = 0; j < wordCount; j++) {
            if (strcmp(lowerWord, text[j]) == 0) { // Check if word is already in array
                freqCount[j]++; // Increment frequency counter
                found = 1;
                break;
            }
        }

        if (!found) {
            strcpy(text[wordCount], lowerWord); // Add word to array
            freqCount[wordCount]++; // Increment frequency counter
        }

        word = strtok(NULL, " ");
    }

    printf("Word Frequency Count:\n");
    int k;
    for (k = 0; k <= wordCount; k++) {
        if (freqCount[k] > 0) {
            printf("%s: %d\n", text[k], freqCount[k]);
        }
    }

    return 0;
}
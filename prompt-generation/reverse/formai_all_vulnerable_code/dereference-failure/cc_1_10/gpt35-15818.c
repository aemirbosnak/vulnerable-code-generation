//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: beginner-friendly
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_SIZE 50

int main() {
    char text[MAX_WORDS];
    int i, j, k, count;
    char word[MAX_WORD_SIZE];
    int freq[MAX_WORDS];

    printf("Enter some text (less than 1000 words):\n");
    fgets(text, MAX_WORDS, stdin);

    // Convert all letters to lower case for case-insensitive matching
    for(i = 0; text[i]; i++) {
        text[i] = tolower(text[i]);
    }

    // Count frequency of each word in the text
    k = 0;
    for(i = 0; text[i]; i++) {
        // Skip non-alphabetic characters
        if(!isalpha(text[i])) {
            continue;
        }
        // Build a word by appending alphabetic characters
        j = 0;
        while(isalpha(text[i])) {
            word[j++] = text[i++];
        }
        word[j] = '\0';
        // Check if the word already exists in the frequency table
        count = -1;
        for(j = 0; j < k; j++) {
            if(strcmp(word, word[j]) == 0) {
                count = freq[j];
                break;
            }
        }
        // If the word does not exist, add it to the frequency table
        if(count == -1) {
            strcpy(word[k], word);
            freq[k] = 1;
            k++;
        }
        // If the word already exists, increment its frequency
        else {
            freq[j]++;
        }
    }

    // Print the frequency table
    printf("\nFrequency table:\n");
    for(i = 0; i < k; i++) {
        printf("%s: %d\n", word[i], freq[i]);
    }

    return 0;
}
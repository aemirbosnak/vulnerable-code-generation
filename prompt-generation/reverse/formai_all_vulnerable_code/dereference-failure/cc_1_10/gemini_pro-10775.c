//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compare(const void *a, const void *b) {
    return strcmp(((WordCount *)a)->word, ((WordCount *)b)->word);
}

int main() {
    char *text = "This is a sample text to demonstrate the word frequency counter. The text contains some common words like 'this', 'is', 'a', 'the', 'and', etc. The counter will count the occurrences of all the words in the text and display them in the descending order of their frequency.";

    int num_words = 0;
    WordCount words[MAX_WORDS];

    // Tokenize the text and count the words.
    char *token = strtok(text, " ");
    while (token != NULL) {
        // Convert the word to lowercase and remove punctuation.
        for (int i = 0; i < strlen(token); i++) {
            token[i] = tolower(token[i]);
            if (!isalpha(token[i])) {
                token[i] = '\0';
                break;
            }
        }

        // Check if the word is already in the list.
        int found = 0;
        for (int i = 0; i < num_words; i++) {
            if (strcmp(words[i].word, token) == 0) {
                words[i].count++;
                found = 1;
                break;
            }
        }

        // If the word is not in the list, add it.
        if (!found) {
            strcpy(words[num_words].word, token);
            words[num_words].count = 1;
            num_words++;
        }

        token = strtok(NULL, " ");
    }

    // Sort the words in descending order of frequency.
    qsort(words, num_words, sizeof(WordCount), compare);

    // Print the word counts.
    printf("Word frequency:\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}
//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: high level of detail
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 100
#define MAX_SENTENCE_LENGTH 200

typedef struct SpamWord {
    char *word;
    int frequency;
} SpamWord;

SpamWord **loadSpamWords(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    SpamWord **words = malloc(MAX_WORDS * sizeof(SpamWord));
    int i = 0;

    char line[MAX_SENTENCE_LENGTH];
    while (fgets(line, MAX_SENTENCE_LENGTH, fp) != NULL) {
        char *word = strtok(line, " ");
        while (word) {
            SpamWord *wordEntry = malloc(sizeof(SpamWord));
            wordEntry->word = strdup(word);
            wordEntry->frequency = 0;
            words[i++] = wordEntry;
            word = strtok(NULL, " ");
        }
    }

    fclose(fp);
    return words;
}

int main() {
    SpamWord **words = loadSpamWords("spam_words.txt");

    // Use the words list to detect spam
    char *sentence = "This is a spam message with many words that are commonly used in spam.";
    int sentenceLength = strlen(sentence);

    int i = 0;
    for (SpamWord *word = words[0]; word != NULL; word++) {
        int wordLength = strlen(word->word);
        for (int j = 0; j < sentenceLength - wordLength; j++) {
            if (sentence[j] == word->word[0] && strncmp(sentence + j, word->word, wordLength) == 0) {
                word->frequency++;
            }
        }
    }

    // Print the words with highest frequency
    for (SpamWord *word = words[0]; word != NULL; word++) {
        printf("%s: %d\n", word->word, word->frequency);
    }

    return 0;
}
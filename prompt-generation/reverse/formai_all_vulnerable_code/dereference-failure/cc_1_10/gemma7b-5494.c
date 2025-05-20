//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000

typedef struct Word {
    char *word;
    int frequency;
} Word;

Word *createWord(char *word) {
    Word *newWord = malloc(sizeof(Word));
    newWord->word = strdup(word);
    newWord->frequency = 0;
    return newWord;
}

void incrementWord(Word *word) {
    word->frequency++;
}

int main() {
    char text[] = "This is a sample text with many words. Some words are repeated multiple times. The quick brown fox jumps over the lazy dog.";

    Word **words = NULL;
    int wordCount = 0;

    // Tokenize the text
    char *token = strtok(text, " ");

    // Create a word list
    while (token) {
        Word *newWord = createWord(token);
        incrementWord(newWord);
        words = realloc(words, (wordCount + 1) * sizeof(Word));
        words[wordCount++] = newWord;
        token = strtok(NULL, " ");
    }

    // Print the word frequency
    for (int i = 0; i < wordCount; i++) {
        printf("%s: %d\n", words[i]->word, words[i]->frequency);
    }

    // Free the memory
    for (int i = 0; i < wordCount; i++) {
        free(words[i]->word);
        free(words[i]);
    }
    free(words);

    return 0;
}
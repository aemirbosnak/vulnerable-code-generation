//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordCount;

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char) str[i]);
    }
}

bool isValidCharacter(char c) {
    return isalnum(c) || c == '\''; // considering apostrophes for words like 'can't'
}

void prepareWord(char *word) {
    char *start = word;
    char *end = word + strlen(word) - 1;

    while (*start && !isValidCharacter(*start)) start++;
    while (end > start && !isValidCharacter(*end)) end--;

    if (start > end) {
        *start = '\0'; // word becomes empty if no valid char found
    } else {
        *(end + 1) = '\0'; // null terminate after last valid char
        toLowerCase(start); // convert to lowercase
    }
}

void addWord(WordCount *words, int *numWords, const char *word) {
    for (int i = 0; i < *numWords; i++) {
        if (strcmp(words[i].word, word) == 0) {
            words[i].frequency++;
            return;
        }
    }
    strcpy(words[*numWords].word, word);
    words[*numWords].frequency = 1;
    (*numWords)++;
}

void sortWords(WordCount *words, int numWords) {
    for (int i = 0; i < numWords - 1; i++) {
        for (int j = 0; j < numWords - i - 1; j++) {
            if (words[j].frequency < words[j + 1].frequency) {
                WordCount temp = words[j];
                words[j] = words[j + 1];
                words[j + 1] = temp;
            }
        }
    }
}

void displayWordFrequencies(WordCount *words, int numWords) {
    printf("\nWord Frequencies:\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }
}

int main() {
    char *filename = "text.txt"; 
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error: Could not open file %s\n", filename);
        return 1;
    }

    WordCount words[MAX_WORDS] = {0};
    int numWords = 0;

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word) != EOF) {
        prepareWord(word);
        if (strlen(word) > 0) {
            addWord(words, &numWords, word);
        }
    }

    fclose(file);

    sortWords(words, numWords);
    displayWordFrequencies(words, numWords);

    return 0;
}
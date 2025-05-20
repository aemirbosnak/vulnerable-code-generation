//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 100
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordFrequency;

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

int addWord(WordFrequency *words, int *size, const char *word) {
    for (int i = 0; i < *size; i++) {
        if (strcmp(words[i].word, word) == 0) {
            words[i].count++;
            return *size;
        }
    }
    strcpy(words[*size].word, word);
    words[*size].count = 1;
    (*size)++;
    return *size;
}

void printWordFrequencies(WordFrequency *words, int size) {
    printf("🎉 Word Frequency Count 🎉\n");
    printf("----------------------------\n");
    for (int i = 0; i < size; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

void cleanWord(char *word) {
    char *start = word;
    while (*start && !isalnum((unsigned char)*start)) start++;
    char *end = start + strlen(start) - 1;
    while (end > start && !isalnum((unsigned char)*end)) end--;
    end[1] = '\0';
    strcpy(word, start);
}

void processFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("🚫 Could not open file %s\n", filename);
        return;
    }

    WordFrequency words[MAX_WORDS];
    int size = 0;
    char word[MAX_WORD_LEN];

    while (fscanf(file, "%s", word) != EOF) {
        cleanWord(word);
        if (strlen(word) > 0) {
            toLowerCase(word);
            addWord(words, &size, word);
        }
    }

    fclose(file);
    printWordFrequencies(words, size);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("🎈 Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    processFile(argv[1]);
    return 0;
}
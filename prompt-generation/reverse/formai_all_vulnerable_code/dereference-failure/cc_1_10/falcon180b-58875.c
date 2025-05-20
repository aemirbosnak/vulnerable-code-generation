//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    WordFrequency *wordA = (WordFrequency *)a;
    WordFrequency *wordB = (WordFrequency *)b;
    return strcmp(wordA->word, wordB->word);
}

void countWords(char *text, WordFrequency *wordFrequencies) {
    char *word = strtok(text, ",.!?;:\"'");
    while (word!= NULL) {
        int len = strlen(word);
        if (len > MAX_WORD_LENGTH) {
            len = MAX_WORD_LENGTH;
        }
        strncpy(wordFrequencies->word, word, len);
        wordFrequencies->word[len] = '\0';
        wordFrequencies->frequency++;
        word = strtok(NULL, ",.!?;:\"'");
    }
}

void printFrequencies(WordFrequency *wordFrequencies, int numWords) {
    qsort(wordFrequencies, numWords, sizeof(WordFrequency), compareWords);
    for (int i = 0; i < numWords; i++) {
        printf("%s %d\n", wordFrequencies[i].word, wordFrequencies[i].frequency);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    char *text = NULL;
    size_t textSize = 0;
    if (fseek(file, 0, SEEK_END)!= 0) {
        printf("Error seeking end of file.\n");
        fclose(file);
        return 1;
    }
    textSize = ftell(file);
    if (textSize == 0) {
        printf("Empty file.\n");
        fclose(file);
        return 0;
    }
    text = malloc(textSize + 1);
    if (text == NULL) {
        printf("Memory error.\n");
        fclose(file);
        return 1;
    }
    if (fseek(file, 0, SEEK_SET)!= 0) {
        printf("Error seeking start of file.\n");
        free(text);
        fclose(file);
        return 1;
    }
    if (fread(text, 1, textSize, file)!= textSize) {
        printf("Error reading file.\n");
        free(text);
        fclose(file);
        return 1;
    }
    text[textSize] = '\0';
    fclose(file);
    WordFrequency wordFrequencies[MAX_WORDS];
    int numWords = 0;
    countWords(text, wordFrequencies);
    printFrequencies(wordFrequencies, numWords);
    free(text);
    return 0;
}
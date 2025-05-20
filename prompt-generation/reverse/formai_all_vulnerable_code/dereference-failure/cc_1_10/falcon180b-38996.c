//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 10000

struct WordFrequency {
    char word[MAX_LENGTH];
    int frequency;
};

void readText(FILE *file, char *text) {
    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    rewind(file);

    fread(text, sizeof(char), size, file);
    text[size] = '\0';
}

void tokenize(char *text, struct WordFrequency *words, int numWords) {
    char *token = strtok(text, ",.!?;:\"'");
    int i = 0;

    while (token!= NULL && i < numWords) {
        strcpy(words[i].word, token);
        i++;
        token = strtok(NULL, ",.!?;:\"'");
    }
}

void sortWords(struct WordFrequency *words, int numWords) {
    for (int i = 0; i < numWords - 1; i++) {
        for (int j = i + 1; j < numWords; j++) {
            if (words[j].frequency < words[i].frequency) {
                struct WordFrequency temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }
}

void printSummary(struct WordFrequency *words, int numWords, int numToShow) {
    printf("Top %d most frequent words:\n", numToShow);

    for (int i = 0; i < numToShow && i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }
}

int main() {
    FILE *file;
    char text[MAX_LENGTH];
    struct WordFrequency words[100];
    int numWords = 0;

    file = fopen("input.txt", "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    readText(file, text);
    tokenize(text, words, 100);
    sortWords(words, numWords);
    printSummary(words, numWords, 10);

    fclose(file);
    return 0;
}
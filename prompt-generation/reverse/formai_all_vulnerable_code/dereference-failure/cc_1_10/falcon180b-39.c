//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50
#define MIN_WORD_LENGTH 3

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

void read_file(FILE* fp, char* text) {
    char ch;
    int i = 0;
    while ((ch = fgetc(fp))!= EOF) {
        if (isalpha(ch)) {
            text[i++] = tolower(ch);
        }
    }
    text[i] = '\0';
}

void tokenize(char* text, char* words[], int max_words) {
    char* token = strtok(text, ",.!?;:");
    int i = 0;
    while (token!= NULL && i < max_words) {
        if (strlen(token) >= MIN_WORD_LENGTH) {
            strcpy(words[i], token);
            i++;
        }
        token = strtok(NULL, ",.!?;:");
    }
}

void count_words(char* words[], int num_words, WordFrequency freq[]) {
    for (int i = 0; i < num_words; i++) {
        int j;
        for (j = 0; j < MAX_WORD_LENGTH; j++) {
            if (words[i][j] == '\0') {
                break;
            }
            freq[i].word[j] = tolower(words[i][j]);
        }
        freq[i].word[j] = '\0';
        freq[i].count = 1;
    }
}

void print_word_frequencies(WordFrequency freq[], int num_words) {
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", freq[i].word, freq[i].count);
    }
}

int main() {
    FILE* fp;
    char text[MAX_WORDS * MAX_WORD_LENGTH];
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    WordFrequency freq[MAX_WORDS];

    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    read_file(fp, text);
    fclose(fp);

    tokenize(text, words, MAX_WORDS);
    count_words(words, MAX_WORDS, freq);
    print_word_frequencies(freq, MAX_WORDS);

    return 0;
}
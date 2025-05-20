//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

typedef struct {
    char word[MAX_WORD_LEN];
    int freq;
} WordFreq;

void readWords(FILE* input, WordFreq* words) {
    char word[MAX_WORD_LEN];
    int i = 0;
    while (fscanf(input, "%s", word)!= EOF) {
        if (i >= MAX_WORDS) {
            printf("Error: Too many words in input file.\n");
            exit(1);
        }
        strcpy(words[i].word, word);
        words[i].freq = 1;
        i++;
    }
}

void sortWords(WordFreq* words, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (words[j].freq > words[i].freq) {
                WordFreq temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }
}

void translate(char* input, WordFreq* words, int n) {
    char word[MAX_WORD_LEN];
    int i = 0;
    while (fscanf(input, "%s", word)!= EOF) {
        int found = 0;
        for (int j = 0; j < n; j++) {
            if (strcmp(word, words[j].word) == 0) {
                printf("%s ", words[j].word);
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("%s ", word);
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        exit(1);
    }
    FILE* input = fopen(argv[1], "r");
    if (input == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }
    FILE* output = fopen(argv[2], "w");
    if (output == NULL) {
        printf("Error: Could not open output file.\n");
        exit(1);
    }
    WordFreq words[MAX_WORDS];
    readWords(input, words);
    sortWords(words, MAX_WORDS);
    translate(input, words, MAX_WORDS);
    fclose(input);
    fclose(output);
    return 0;
}
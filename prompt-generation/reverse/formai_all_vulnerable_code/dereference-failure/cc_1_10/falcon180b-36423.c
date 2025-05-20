//Falcon-180B DATASET v1.0 Category: Text processing ; Style: Cyberpunk
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

void read_file(FILE* fp, char* text) {
    fseek(fp, 0, SEEK_END);
    int size = ftell(fp);
    rewind(fp);

    if (size >= MAX_WORDS * MAX_WORD_LEN) {
        printf("Error: File too large.\n");
        exit(1);
    }

    fread(text, size, 1, fp);
    text[size] = '\0';
}

void count_words(char* text, WordCount* word_counts, int num_words) {
    char* token = strtok(text, ",.?!;:");
    while (token!= NULL && num_words > 0) {
        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(token, word_counts[i].word) == 0) {
                word_counts[i].count++;
                break;
            }
        }
        if (i == num_words) {
            if (num_words >= MAX_WORDS) {
                printf("Error: Too many unique words.\n");
                exit(1);
            }
            strcpy(word_counts[num_words].word, token);
            word_counts[num_words].count = 1;
            num_words++;
        }
        token = strtok(NULL, ",.?!;:");
    }
}

void print_word_counts(WordCount* word_counts, int num_words) {
    printf("Word Counts:\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }
}

int main() {
    FILE* fp;
    char* text = malloc(MAX_WORDS * MAX_WORD_LEN);
    WordCount word_counts[MAX_WORDS];
    int num_words = 0;

    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    read_file(fp, text);
    count_words(text, word_counts, num_words);

    print_word_counts(word_counts, num_words);

    free(text);
    return 0;
}
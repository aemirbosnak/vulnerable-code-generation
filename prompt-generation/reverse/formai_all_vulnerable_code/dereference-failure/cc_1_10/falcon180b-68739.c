//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORDS 10000
#define MAX_WORD_LEN 20

typedef struct {
    char word[MAX_WORD_LEN+1];
    int count;
} WordCount;

void read_file(const char* filename, char* buffer) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(1);
    }

    char ch;
    while ((ch = fgetc(fp))!= EOF) {
        buffer[fputc(tolower(ch), stdout)] = ch;
    }

    fclose(fp);
}

void count_words(char* buffer, WordCount* word_counts) {
    char word[MAX_WORD_LEN+1];
    int word_len = 0;

    for (int i = 0; i < strlen(buffer); i++) {
        if (isalpha(buffer[i])) {
            word[word_len++] = buffer[i];
        } else {
            if (word_len > 0) {
                word[word_len] = '\0';
                int word_index = hash(word);
                word_counts[word_index].count++;
                word_len = 0;
            }
        }
    }

    if (word_len > 0) {
        word[word_len] = '\0';
        int word_index = hash(word);
        word_counts[word_index].count++;
    }
}

int hash(char* word) {
    int sum = 0;
    for (int i = 0; i < strlen(word); i++) {
        sum += word[i];
    }
    return sum % MAX_WORDS;
}

void print_word_counts(WordCount* word_counts) {
    for (int i = 0; i < MAX_WORDS; i++) {
        if (word_counts[i].count > 0) {
            printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char buffer[MAX_WORD_LEN+1];
    read_file(argv[1], buffer);

    WordCount word_counts[MAX_WORDS];
    memset(word_counts, 0, sizeof(word_counts));

    count_words(buffer, word_counts);

    print_word_counts(word_counts);

    return 0;
}
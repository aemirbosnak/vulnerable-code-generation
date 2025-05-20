//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: minimalist
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LEN 1000
#define MAX_WORD_LEN 50

typedef struct {
    char *word;
    int len;
    int count;
} Word;

void read_file(const char *filename, char *buffer) {
    FILE *file;
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }
    fread(buffer, 1, MAX_LEN, file);
    fclose(file);
}

bool is_word(char *str, int start, int end) {
    int i;
    for (i = start; i <= end; i++) {
        if (!isalpha(str[i])) {
            return false;
        }
    }
    return true;
}

bool is_valid_word(char *str, int len) {
    int i;
    for (i = 0; i < len; i++) {
        if (!isalpha(str[i])) {
            return false;
        }
    }
    return true;
}

void search_words(char *buffer, int word_count, Word *words) {
    int i, j, k, len;
    char *p;
    for (i = 0; i < word_count; i++) {
        p = strtok(buffer, " \n\r\t\f\v");
        while (p!= NULL) {
            len = strlen(p);
            if (len > MAX_WORD_LEN) {
                len = MAX_WORD_LEN;
            }
            for (j = 0; j < len; j++) {
                p[j] = tolower(p[j]);
            }
            for (k = 0; k < i; k++) {
                if (strcmp(p, words[k].word) == 0) {
                    words[k].count++;
                    break;
                }
            }
            if (k == i) {
                words[i].word = malloc(len + 1);
                strncpy(words[i].word, p, len);
                words[i].word[len] = '\0';
                words[i].len = len;
                words[i].count = 1;
                i++;
            }
            p = strtok(NULL, " \n\r\t\f\v");
        }
    }
}

void print_words(Word *words, int word_count) {
    int i;
    for (i = 0; i < word_count; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main(int argc, char *argv[]) {
    char *buffer;
    Word *words;
    int word_count;

    if (argc < 2) {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }

    buffer = malloc(MAX_LEN);
    read_file(argv[1], buffer);
    search_words(buffer, 0, NULL);
    word_count = 0;
    words = malloc(sizeof(Word) * word_count);
    search_words(buffer, word_count, words);
    print_words(words, word_count);
    free(buffer);
    return 0;
}
//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORD_LEN 100
#define MAX_LINE_LEN 1000

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

bool is_alpha(char c) {
    return isalpha(c);
}

bool is_space(char c) {
    return isspace(c);
}

void trim(char* str) {
    char* end = str + strlen(str) - 1;
    while (end > str && isspace(*end)) {
        *end-- = '\0';
    }
    while (*str && isspace(*str)) {
        str++;
    }
}

void word_count(char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    WordCount words[MAX_WORD_LEN];
    int num_words = 0;

    char line[MAX_LINE_LEN];
    while (fgets(line, MAX_LINE_LEN, file)) {
        trim(line);
        if (strlen(line) == 0) {
            continue;
        }

        char* word_start = line;
        while (is_alpha(*word_start)) {
            word_start++;
        }
        char* word_end = word_start;
        while (is_alpha(*word_end)) {
            word_end++;
        }
        if (word_start == word_end) {
            continue;
        }

        strncpy(words[num_words].word, word_start, MAX_WORD_LEN);
        words[num_words].word[MAX_WORD_LEN - 1] = '\0';
        words[num_words].count = 1;
        num_words++;
    }

    fclose(file);

    printf("Word Count:\n");
    for (int i = 0; i < num_words; i++) {
        if (words[i].count > 1) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }
}

int main(int argc, char** argv) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    word_count(argv[1]);

    return 0;
}
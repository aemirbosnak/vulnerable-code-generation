//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: portable
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 10000

int is_word_char(char c) {
    return isalpha(c) || c == '-';
}

int get_word(FILE* fp, char* buf) {
    int c;
    int i = 0;
    
    while ((c = fgetc(fp)) != EOF && !is_word_char(c));
    if (c == EOF) {
        return 0;
    }

    do {
        buf[i++] = c;
        c = fgetc(fp);
    } while (is_word_char(c) && i < MAX_WORD_LENGTH - 1);

    buf[i] = '\0';
    return i;
}

int cmp_str(const void* a, const void* b) {
    const char** sa = (const char**)a;
    const char** sb = (const char**)b;
    return strcmp(*sa, *sb);
}

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "usage: %s FILE\n", argv[0]);
        return -1;
    }

    char buf[MAX_WORD_LENGTH];
    int words_count = 0;
    char* words[MAX_WORDS];

    FILE* fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("fopen");
        return -1;
    }

    while (get_word(fp, buf)) {
        words[words_count++] = strdup(buf);
    }

    fclose(fp);

    qsort(words, words_count, sizeof(char*), cmp_str);

    for (int i = 0; i < words_count; ++i) {
        int count = 1;
        while (i < words_count - 1 && strcmp(words[i], words[i+1]) == 0) {
            ++count;
            ++i;
        }
        printf("%s: %d\n", words[i], count);
        free(words[i]);
    }

    return 0;
}
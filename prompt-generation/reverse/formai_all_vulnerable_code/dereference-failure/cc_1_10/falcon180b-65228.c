//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 30

struct word_freq {
    char word[MAX_WORD_LENGTH];
    int freq;
};

int word_compare(const void *a, const void *b) {
    return strcmp(*(char * const *)a, *(char * const *)b);
}

int main(int argc, char *argv[]) {
    FILE *fp;
    char line[1000];
    char word[MAX_WORD_LENGTH];
    struct word_freq *word_freq_table = calloc(MAX_WORDS, sizeof(struct word_freq));
    int num_words = 0;

    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", argv[1]);
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        int len = strlen(line);
        char *p = line;
        while (isspace(*p)) p++;
        while (len > 0 &&!isspace(*(p + len - 1))) len--;
        strncpy(word, p, len);
        word[len] = '\0';

        struct word_freq *entry = bsearch(word, word_freq_table, num_words, sizeof(struct word_freq), word_compare);
        if (entry == NULL) {
            if (num_words >= MAX_WORDS) {
                printf("Error: too many words\n");
                exit(1);
            }
            strcpy(entry->word, word);
            entry->freq = 1;
            num_words++;
        } else {
            entry->freq++;
        }
    }

    fclose(fp);

    qsort(word_freq_table, num_words, sizeof(struct word_freq), word_compare);

    printf("Word\tFrequency\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s\t%d\n", word_freq_table[i].word, word_freq_table[i].freq);
    }

    return 0;
}
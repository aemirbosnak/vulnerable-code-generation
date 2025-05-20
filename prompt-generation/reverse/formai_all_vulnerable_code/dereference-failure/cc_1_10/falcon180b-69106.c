//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LEN 100

struct word_freq {
    char word[MAX_WORD_LEN];
    int freq;
};

int compare_words(const void *a, const void *b) {
    struct word_freq *w1 = (struct word_freq *)a;
    struct word_freq *w2 = (struct word_freq *)b;
    return strcmp(w1->word, w2->word);
}

int main() {
    FILE *file;
    char line[1024];
    char word[MAX_WORD_LEN];
    int i = 0;
    struct word_freq freq_table[MAX_WORDS];

    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), file)!= NULL) {
        char *p = line;
        while ((word[i] = tolower(*p))!= '\0') {
            p++;
            i++;
            if (i >= MAX_WORD_LEN) {
                break;
            }
        }
        word[i] = '\0';

        for (int j = 0; j < i; j++) {
            if (!isalpha(word[j])) {
                word[j] = '\0';
                break;
            }
        }

        if (i > 0) {
            struct word_freq *found = bsearch(&word, freq_table, i, sizeof(struct word_freq), compare_words);
            if (found == NULL) {
                if (i >= MAX_WORDS) {
                    printf("Maximum number of words reached\n");
                    exit(1);
                }
                strncpy(freq_table[i].word, word, MAX_WORD_LEN);
                freq_table[i].freq = 1;
                i++;
            } else {
                found->freq++;
            }
        }
    }

    qsort(freq_table, i, sizeof(struct word_freq), compare_words);

    printf("Word\tFrequency\n");
    for (int j = 0; j < i; j++) {
        printf("%s\t%d\n", freq_table[j].word, freq_table[j].freq);
    }

    fclose(file);
    return 0;
}
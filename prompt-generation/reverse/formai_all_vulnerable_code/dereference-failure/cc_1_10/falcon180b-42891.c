//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LEN 50

struct word_freq {
    char word[MAX_WORD_LEN];
    int freq;
};

int compare_words(const void *a, const void *b) {
    struct word_freq *w1 = (struct word_freq *)a;
    struct word_freq *w2 = (struct word_freq *)b;

    return strcmp(w1->word, w2->word);
}

int main(int argc, char *argv[]) {
    FILE *input_file;
    char line[1024];
    char word[MAX_WORD_LEN];
    int word_len;
    struct word_freq *word_freq_table;
    int num_words = 0;

    if (argc!= 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    // Read input file
    while (fgets(line, sizeof(line), input_file)!= NULL) {
        int i = 0;
        while (isspace(line[i])) {
            i++;
        }
        while (i < strlen(line)) {
            if (num_words >= MAX_WORDS) {
                printf("Maximum number of words reached.\n");
                break;
            }

            word_len = 0;
            while (!isspace(line[i]) && i < strlen(line)) {
                word[word_len] = tolower(line[i]);
                i++;
                word_len++;
            }

            if (word_len > 0) {
                strcpy(word_freq_table[num_words].word, word);
                word_freq_table[num_words].freq = 1;
                num_words++;
            }
        }
    }

    // Sort word frequency table
    qsort(word_freq_table, num_words, sizeof(struct word_freq), compare_words);

    // Print word frequency table
    printf("Word\tFrequency\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s\t%d\n", word_freq_table[i].word, word_freq_table[i].freq);
    }

    fclose(input_file);
    return 0;
}
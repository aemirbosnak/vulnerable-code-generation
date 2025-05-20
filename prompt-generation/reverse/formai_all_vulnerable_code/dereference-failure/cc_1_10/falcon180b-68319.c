//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 20

struct word_freq {
    char word[MAX_WORD_LEN];
    int freq;
};

int compare_freq(const void *a, const void *b) {
    const struct word_freq *w1 = a;
    const struct word_freq *w2 = b;

    if (w1->freq > w2->freq) {
        return -1;
    } else if (w1->freq < w2->freq) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char input_string[1000];
    FILE *input_file = fopen("input.txt", "r");
    char word[MAX_WORD_LEN];
    int word_count = 0;
    struct word_freq *word_freq_array;

    if (input_file == NULL) {
        printf("Error opening input file\n");
        exit(1);
    }

    while (fscanf(input_file, "%s", word)!= EOF) {
        if (word_count >= MAX_WORDS) {
            printf("Error: maximum number of words exceeded\n");
            exit(1);
        }

        strcpy(word_freq_array[word_count].word, word);
        word_freq_array[word_count].freq++;
        word_count++;
    }

    fclose(input_file);

    qsort(word_freq_array, word_count, sizeof(struct word_freq), compare_freq);

    printf("Word\tFrequency\n");

    for (int i = 0; i < word_count; i++) {
        printf("%s\t%d\n", word_freq_array[i].word, word_freq_array[i].freq);
    }

    return 0;
}
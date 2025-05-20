//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000000
#define MAX_WORD_LEN 100

typedef struct {
    char word[MAX_WORD_LEN];
    int freq;
} WordFreq;

void init_word_freq(WordFreq *wf) {
    wf->freq = 0;
    wf->word[0] = '\0';
}

int compare_word_freq(const void *a, const void *b) {
    const WordFreq *wfa = a;
    const WordFreq *wfb = b;
    if (wfa->freq > wfb->freq) {
        return -1;
    } else if (wfa->freq < wfb->freq) {
        return 1;
    } else {
        return 0;
    }
}

void add_word(WordFreq *wf, const char *word) {
    if (strlen(word) > MAX_WORD_LEN - 1) {
        return;
    }
    strcpy(wf->word, word);
    wf->freq++;
}

void print_word_freq(const WordFreq *wf) {
    printf("%s: %d\n", wf->word, wf->freq);
}

void word_freq_counter(FILE *fp, WordFreq *wf_array, int num_words) {
    char word[MAX_WORD_LEN];
    int i = 0;
    while (fscanf(fp, "%s", word)!= EOF) {
        if (i >= num_words) {
            break;
        }
        if (isalpha(word[0])) {
            add_word(wf_array + i, word);
            i++;
        }
    }
    qsort(wf_array, num_words, sizeof(WordFreq), compare_word_freq);
    for (i = 0; i < num_words; i++) {
        print_word_freq(wf_array + i);
    }
}

int main() {
    FILE *fp;
    char filename[100];
    printf("Enter the filename: ");
    scanf("%s", filename);
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    int num_words;
    printf("Enter the number of words to count: ");
    scanf("%d", &num_words);
    WordFreq wf_array[num_words];
    for (int i = 0; i < num_words; i++) {
        init_word_freq(wf_array + i);
    }
    word_freq_counter(fp, wf_array, num_words);
    fclose(fp);
    return 0;
}
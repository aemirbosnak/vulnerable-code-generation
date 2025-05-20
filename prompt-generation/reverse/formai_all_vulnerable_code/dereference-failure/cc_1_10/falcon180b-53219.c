//Falcon-180B DATASET v1.0 Category: Text processing ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>

#define MAX_LINE 1024
#define MAX_WORD 64

typedef struct {
    char *word;
    int count;
} WordCount;

int compare(const void *a, const void *b) {
    WordCount *wc1 = (WordCount *)a;
    WordCount *wc2 = (WordCount *)b;

    return strcmp(wc1->word, wc2->word);
}

int main(int argc, char *argv[]) {
    FILE *fp;
    char line[MAX_LINE];
    char word[MAX_WORD];
    char *token;
    WordCount *word_counts = NULL;
    int num_words = 0;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        return 1;
    }

    while (fgets(line, MAX_LINE, fp)!= NULL) {
        token = strtok(line, ",.?!;:-_\"'");
        while (token!= NULL) {
            if (strlen(token) > 0 && token[0]!= '\0') {
                if (num_words >= MAX_WORD) {
                    fprintf(stderr, "Error: Too many words\n");
                    fclose(fp);
                    return 1;
                }
                strcpy(word_counts[num_words].word, token);
                word_counts[num_words].count = 1;
                num_words++;
            }
            token = strtok(NULL, ",.?!;:-_\"'");
        }
    }

    fclose(fp);

    qsort(word_counts, num_words, sizeof(WordCount), compare);

    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
    }

    free(word_counts);

    return 0;
}
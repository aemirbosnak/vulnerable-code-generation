//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 1000
#define MAX_LINE_LEN 10000
#define MAX_WORDS 10000

struct word {
    char *word;
    int freq;
};

int compare(const void *a, const void *b) {
    struct word *w1 = (struct word *) a;
    struct word *w2 = (struct word *) b;

    if (w1->freq > w2->freq) {
        return -1;
    } else if (w1->freq < w2->freq) {
        return 1;
    } else {
        return 0;
    }
}

int main(int argc, char *argv[]) {
    FILE *fp;
    char line[MAX_LINE_LEN];
    char word[MAX_WORD_LEN];
    struct word words[MAX_WORDS];
    int num_words = 0;

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", argv[1]);
        exit(1);
    }

    while (fgets(line, MAX_LINE_LEN, fp)!= NULL) {
        char *p = line;
        while ((word[0] = *p)!= '\0') {
            int len = strlen(word);
            if (len > 0 && isalpha(word[0])) {
                word[len - 1] = '\0';
                for (int i = 0; i < num_words; i++) {
                    if (strcmp(words[i].word, word) == 0) {
                        words[i].freq++;
                        break;
                    }
                }
                if (num_words >= MAX_WORDS) {
                    printf("Error: too many words\n");
                    exit(1);
                }
                strcpy(words[num_words].word, word);
                words[num_words].freq = 1;
                num_words++;
            }
            p++;
        }
    }

    qsort(words, num_words, sizeof(struct word), compare);

    printf("Word\tFrequency\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s\t%d\n", words[i].word, words[i].freq);
    }

    fclose(fp);
    return 0;
}
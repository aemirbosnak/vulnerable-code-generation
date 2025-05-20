//MISTRAL-7B DATASET v1.0 Category: Text Summarizer ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_LENGTH 50

typedef struct Word {
    char word[MAX_LENGTH];
    int freq;
} Word;

void tokenize(char *text, Word words[MAX_WORDS]) {
    char token[MAX_LENGTH];
    int i = 0, j = 0;
    int num_words = 0;

    for (i = 0; text[i]; i++) {
        if (isalpha(text[i])) {
            token[j] = tolower(text[i]);
            j++;
        } else if (j) {
            token[j] = '\0';
            if (num_words < MAX_WORDS) {
                strcpy(words[num_words++].word, token);
                words[num_words - 1].freq = 0;
            }
            j = 0;
        }
    }

    if (j && num_words < MAX_WORDS) {
        strcpy(words[num_words++].word, token);
        words[num_words - 1].freq = 0;
    }
}

void summarize(Word words[MAX_WORDS], int num_words) {
    int i, j, k;
    Word summary[5];
    int summary_size = 0;

    for (i = 0; i < num_words; i++) {
        for (j = 0; j < summary_size; j++) {
            if (strcmp(words[i].word, summary[j].word) == 0) {
                words[i].freq += words[j].freq;
                free(summary + j);
                summary_size--;
                break;
            }
        }

        if (summary_size < 5 && words[i].freq > 0) {
            if (summary_size < 5) {
                memmove(summary + summary_size, summary + summary_size + 1,
                        (5 - summary_size) * sizeof(Word));
            }
            strcpy(summary[summary_size++].word, words[i].word);
            summary[summary_size - 1].freq = words[i].freq;
        }
    }

    printf("Summary:\n");
    for (i = 0; i < summary_size; i++) {
        printf("%s: %d\n", summary[i].word, summary[i].freq);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <text>\n", argv[0]);
        return 1;
    }

    Word text[MAX_WORDS];
    int num_words = 0;

    tokenize(argv[1], text);
    summarize(text, num_words);

    return 0;
}
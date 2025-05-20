//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 512
#define MAX_WORD 64

typedef struct {
    char *word;
    int count;
} WordCount;

void init_word_count(WordCount *word_count) {
    word_count->word = (char *)malloc(MAX_WORD);
    word_count->count = 0;
}

void free_word_count(WordCount *word_count) {
    free(word_count->word);
    word_count->word = NULL;
    word_count->count = 0;
}

void print_word_count(const WordCount *word_count) {
    if (word_count->count > 0) {
        printf("%s: %d\n", word_count->word, word_count->count);
    }
}

int main() {
    FILE *fp;
    char line[MAX_LINE];
    WordCount word_count;
    char *word;
    int i, j;

    init_word_count(&word_count);

    if ((fp = fopen("input.txt", "r")) == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE, fp)!= NULL) {
        for (i = 0, j = 0; i < strlen(line); i++) {
            if (isalpha(line[i])) {
                if (j >= MAX_WORD) {
                    printf("Error: Word exceeds maximum length.\n");
                    exit(1);
                }
                word[j++] = tolower(line[i]);
            } else if (j > 0) {
                word[j] = '\0';
                if (strlen(word) > 0) {
                    word_count.word = strdup(word);
                    word_count.count++;
                }
                j = 0;
            }
        }
        if (j > 0) {
            word[j] = '\0';
            if (strlen(word) > 0) {
                word_count.word = strdup(word);
                word_count.count++;
            }
        }
    }

    fclose(fp);

    for (i = 0; i < word_count.count; i++) {
        print_word_count(&word_count);
    }

    free_word_count(&word_count);

    return 0;
}
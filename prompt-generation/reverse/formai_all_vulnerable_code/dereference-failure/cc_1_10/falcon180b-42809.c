//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000000
#define MAX_WORD_LENGTH 100

struct Word {
    char word[MAX_WORD_LENGTH];
    int count;
};

int compareWords(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

int main() {
    FILE *file;
    char line[1024];
    char *word;
    struct Word *words = malloc(MAX_WORDS * sizeof(struct Word));
    int numWords = 0;
    int i;

    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), file)!= NULL) {
        word = strtok(line, " \t\r\n\f\v.,?!;:");
        while (word!= NULL) {
            if (numWords >= MAX_WORDS) {
                printf("Error: maximum number of words exceeded\n");
                exit(1);
            }

            if (strlen(word) >= MAX_WORD_LENGTH) {
                printf("Error: word too long\n");
                exit(1);
            }

            strcpy(words[numWords].word, word);
            words[numWords].count = 1;

            numWords++;

            word = strtok(NULL, " \t\r\n\f\v.,?!;:");
        }
    }

    qsort(words, numWords, sizeof(struct Word), compareWords);

    for (i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    free(words);
    fclose(file);

    return 0;
}
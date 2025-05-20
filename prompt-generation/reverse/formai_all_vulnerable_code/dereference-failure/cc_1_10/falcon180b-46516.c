//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

struct Word {
    char word[MAX_WORD_LENGTH];
    int count;
};

int compareWords(const void *a, const void *b) {
    const struct Word *wordA = a;
    const struct Word *wordB = b;
    return strcmp(wordA->word, wordB->word);
}

void printWords(struct Word *words, int numWords) {
    qsort(words, numWords, sizeof(struct Word), compareWords);
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main(int argc, char **argv) {
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    struct Word words[MAX_WORDS];
    int numWords = 0;

    char ch;
    while ((ch = fgetc(file))!= EOF) {
        if (isspace(ch)) {
            if (numWords >= MAX_WORDS) {
                printf("Error: Too many words.\n");
                fclose(file);
                return 1;
            }
            words[numWords].word[0] = '\0';
            words[numWords].count = 1;
            numWords++;
        } else {
            int len = strlen(words[numWords - 1].word);
            if (len >= MAX_WORD_LENGTH) {
                printf("Error: Word too long.\n");
                fclose(file);
                return 1;
            }
            strncat(words[numWords - 1].word, &ch, 1);
        }
    }

    if (numWords == 0) {
        printf("Error: No words found.\n");
        fclose(file);
        return 1;
    }

    fclose(file);

    printWords(words, numWords);

    return 0;
}
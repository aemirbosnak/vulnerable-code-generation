//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

int compareWords(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

int main(int argc, char *argv[]) {
    FILE *file;
    char *text = NULL;
    size_t textLength = 0;
    char word[MAX_WORD_LENGTH];
    Word words[MAX_WORDS];
    int numWords = 0;
    int i, j, k, l, m;
    char *line = NULL;
    size_t lineLength = 0;

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    while ((getline(&line, &lineLength, file))!= -1) {
        textLength += strlen(line);
        text = realloc(text, textLength + 1);
        strcat(text, line);
        strcat(text, " ");
    }

    free(line);
    fclose(file);

    for (i = 0; i < textLength; i++) {
        if (isalpha(text[i])) {
            for (j = 0; j < MAX_WORD_LENGTH - 1 && isalpha(text[i + j]); j++) {
                word[j] = tolower(text[i + j]);
            }
            word[j] = '\0';
            for (k = 0; k < numWords; k++) {
                if (strcmp(word, words[k].word) == 0) {
                    words[k].count++;
                    break;
                }
            }
            if (k == numWords) {
                words[numWords].word[0] = word[0];
                strcpy(words[numWords].word + 1, &word[1]);
                words[numWords].count = 1;
                numWords++;
            }
        }
    }

    qsort(words, numWords, sizeof(Word), compareWords);

    for (i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    WordCount *wc1 = (WordCount *)a;
    WordCount *wc2 = (WordCount *)b;

    return strcmp(wc1->word, wc2->word);
}

int main() {
    FILE *file;
    char line[1000];
    char *text = NULL;
    size_t len = 0;
    WordCount words[MAX_WORDS];
    int numWords = 0;

    file = fopen("romeo_and_juliet.txt", "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), file)!= NULL) {
        len += strlen(line);
        text = realloc(text, len + 1);
        strcat(text, line);
    }

    fclose(file);

    text[len - 1] = '\0';

    for (char *p = text; *p!= '\0'; p++) {
        if (isalpha(*p)) {
            char word[MAX_WORD_LEN];
            int i = 0;

            while (isalpha(*p) && i < MAX_WORD_LEN - 1) {
                word[i++] = tolower(*p);
                p++;
            }

            word[i] = '\0';

            for (int j = 0; j < numWords; j++) {
                if (strcmp(words[j].word, word) == 0) {
                    words[j].count++;
                    break;
                }
            }

            if (numWords == MAX_WORDS) {
                printf("Maximum number of words reached.\n");
                break;
            }

            strcpy(words[numWords].word, word);
            words[numWords].count = 1;
            numWords++;
        }
    }

    qsort(words, numWords, sizeof(WordCount), compareWords);

    printf("Word count summary:\n");

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    free(text);

    return 0;
}
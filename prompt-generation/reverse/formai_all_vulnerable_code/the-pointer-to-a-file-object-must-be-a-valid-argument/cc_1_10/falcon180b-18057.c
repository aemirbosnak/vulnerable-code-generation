//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MIN_WORD_LENGTH 3
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    WordFrequency *word1 = (WordFrequency *)a;
    WordFrequency *word2 = (WordFrequency *)b;

    return strcmp(word1->word, word2->word);
}

void readWords(char *filename, WordFrequency *words, int *numWords) {
    FILE *file = fopen(filename, "r");
    char line[1000];
    char *word;

    while (fgets(line, sizeof(line), file)!= NULL) {
        word = strtok(line, ",.?!;:");

        while (word!= NULL) {
            int length = strlen(word);

            if (length >= MIN_WORD_LENGTH && length <= MAX_WORD_LENGTH) {
                int i;
                for (i = 0; i < *numWords; i++) {
                    if (strcmp(word, words[i].word) == 0) {
                        words[i].frequency++;
                        break;
                    }
                }

                if (i == *numWords) {
                    strcpy(words[*numWords].word, word);
                    words[*numWords].frequency = 1;
                    (*numWords)++;
                }
            }

            word = strtok(NULL, ",.?!;:");
        }
    }

    fclose(file);
}

void calculateFrequencies(WordFrequency *words, int numWords) {
    qsort(words, numWords, sizeof(WordFrequency), compareWords);

    int i;
    for (i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    WordFrequency words[MAX_WORDS];
    int numWords = 0;

    readWords(argv[1], words, &numWords);
    calculateFrequencies(words, numWords);

    return 0;
}
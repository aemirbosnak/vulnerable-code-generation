//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 100
#define MAX_FILE_NAME_LEN 1000

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

void initWordCount(WordCount *wordCount) {
    strcpy(wordCount->word, "");
    wordCount->count = 0;
}

void updateWordCount(WordCount *wordCount, char *word) {
    if (strcmp(wordCount->word, word) == 0) {
        wordCount->count++;
    } else {
        strcpy(wordCount->word, word);
        wordCount->count = 1;
    }
}

void printWordCount(WordCount *wordCount) {
    printf("%s: %d\n", wordCount->word, wordCount->count);
}

int isWord(char *word) {
    int len = strlen(word);
    return (len > 0 && isalnum(word[0]) && isalnum(word[len - 1]));
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char filename[MAX_FILE_NAME_LEN];
    strcpy(filename, argv[1]);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file '%s'.\n", filename);
        return 1;
    }

    WordCount wordCounts[MAX_WORD_LEN];
    int numWordCounts = 0;

    char word[MAX_WORD_LEN];
    while (fscanf(file, "%s", word)!= EOF) {
        if (isWord(word)) {
            int i;
            for (i = 0; i < numWordCounts; i++) {
                if (strcmp(word, wordCounts[i].word) == 0) {
                    updateWordCount(&wordCounts[i], word);
                    break;
                }
            }
            if (i == numWordCounts) {
                initWordCount(&wordCounts[i]);
                strcpy(wordCounts[i].word, word);
                numWordCounts++;
            }
        }
    }

    fclose(file);

    int totalWords = 0;
    for (int i = 0; i < numWordCounts; i++) {
        printWordCount(&wordCounts[i]);
        totalWords += wordCounts[i].count;
    }

    printf("Total words: %d\n", totalWords);

    return 0;
}
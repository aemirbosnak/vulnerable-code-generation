//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_NUM_WORDS 100000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    WordCount *wordA = (WordCount*)a;
    WordCount *wordB = (WordCount*)b;

    if (wordA->count > wordB->count) {
        return -1;
    } else if (wordA->count < wordB->count) {
        return 1;
    } else {
        return 0;
    }
}

void countWords(char* text, int numWords, WordCount words[]) {
    char* word = strtok(text, ",.?!;:\"'");
    while (word!= NULL && numWords > 0) {
        int i;
        for (i = 0; i < numWords; i++) {
            if (strcmp(word, words[i].word) == 0) {
                words[i].count++;
                break;
            }
        }
        if (i == numWords) {
            if (numWords >= MAX_NUM_WORDS) {
                printf("Error: Maximum number of words exceeded.\n");
                exit(1);
            }
            strcpy(words[numWords].word, word);
            words[numWords].count = 1;
            numWords++;
        }
        word = strtok(NULL, ",.?!;:\"'");
    }
}

void printWords(WordCount words[], int numWords) {
    qsort(words, numWords, sizeof(WordCount), compareWords);

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    char* text = NULL;
    size_t textSize = 0;
    if (fseek(file, 0, SEEK_END)!= 0) {
        printf("Error: Could not determine file size.\n");
        fclose(file);
        return 1;
    }
    textSize = ftell(file);
    if (textSize == 0) {
        printf("Error: File is empty.\n");
        fclose(file);
        return 1;
    }
    rewind(file);

    text = malloc(textSize + 1);
    if (text == NULL) {
        printf("Error: Could not allocate memory.\n");
        fclose(file);
        return 1;
    }

    size_t numCharsRead = fread(text, 1, textSize, file);
    if (numCharsRead!= textSize) {
        printf("Error: Could not read entire file.\n");
        free(text);
        fclose(file);
        return 1;
    }

    char* newline = strrchr(text, '\n');
    if (newline!= NULL) {
        *newline = '\0';
    }

    int numWords = 0;
    WordCount words[MAX_NUM_WORDS];
    countWords(text, numWords, words);

    printWords(words, numWords);

    free(text);
    fclose(file);

    return 0;
}
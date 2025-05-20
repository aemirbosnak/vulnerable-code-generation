//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000
#define MAX_WORDS 1000

typedef struct {
    char *word;
    int length;
} Word;

int compare(const void *a, const void *b) {
    Word *wordA = (Word *) a;
    Word *wordB = (Word *) b;
    return strcmp(wordA->word, wordB->word);
}

int main() {
    FILE *file;
    char line[MAX_LEN];
    char *input = (char *) malloc(MAX_LEN * sizeof(char));
    int inputSize = 0;
    int wordCount = 0;
    Word words[MAX_WORDS];

    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LEN, file)!= NULL) {
        strcat(input, line);
        inputSize += strlen(line);
    }

    fclose(file);

    char *word = strtok(input, " ");
    while (word!= NULL) {
        if (wordCount >= MAX_WORDS) {
            printf("Maximum word count exceeded.\n");
            exit(1);
        }
        words[wordCount].word = strdup(word);
        words[wordCount].length = strlen(word);
        wordCount++;
        word = strtok(NULL, " ");
    }

    qsort(words, wordCount, sizeof(Word), compare);

    for (int i = 0; i < wordCount; i++) {
        printf("%s (%d)\n", words[i].word, words[i].length);
    }

    for (int i = 0; i < wordCount; i++) {
        free(words[i].word);
    }
    free(input);

    return 0;
}
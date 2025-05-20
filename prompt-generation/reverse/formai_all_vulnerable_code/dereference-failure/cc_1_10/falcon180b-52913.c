//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

int compareWords(const void *a, const void *b) {
    return strcmp(((Word*)a)->word, ((Word*)b)->word);
}

int main() {
    FILE *file;
    char line[1024];
    char word[MAX_WORD_LENGTH];
    int wordCount = 0;
    Word *wordArray = malloc(MAX_WORDS * sizeof(Word));
    int i;

    srand(time(NULL));
    for (i = 0; i < MAX_WORDS; i++) {
        wordArray[i].word[0] = '\0';
        wordArray[i].count = 0;
    }

    file = fopen("spam.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), file)!= NULL) {
        char *token = strtok(line, " ");
        while (token!= NULL) {
            strcpy(word, token);
            tolower(word);
            if (strlen(word) > 0) {
                int index = rand() % MAX_WORDS;
                while (wordArray[index].word[0]!= '\0') {
                    index = (index + 1) % MAX_WORDS;
                }
                strcpy(wordArray[index].word, word);
                wordArray[index].count++;
            }
            token = strtok(NULL, " ");
        }
        wordCount++;
    }

    fclose(file);

    qsort(wordArray, MAX_WORDS, sizeof(Word), compareWords);

    for (i = 0; i < MAX_WORDS; i++) {
        if (wordArray[i].word[0]!= '\0') {
            printf("%s - %d\n", wordArray[i].word, wordArray[i].count);
        }
    }

    free(wordArray);

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: immersive
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 20
#define MAX_WORD_COUNT 1000
#define TRUE 1
#define FALSE 0

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

Word dictionary[MAX_WORD_COUNT];
int dictionaryCount = 0;

void loadDictionary() {
    FILE *file;
    char line[MAX_WORD_LENGTH];
    char *word;
    int count = 0;

    file = fopen("dictionary.txt", "r");

    if (file == NULL) {
        printf("Error: cannot open dictionary file.\n");
        exit(1);
    }

    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL && count < MAX_WORD_COUNT) {
        word = strtok(line, " ");
        strcpy(dictionary[count].word, word);
        dictionary[count].count = 1;
        count++;
    }

    fclose(file);
}

int compareWords(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

void checkSpelling(char *text) {
    int i, j, k;
    char *word;
    Word *foundWord;

    loadDictionary();

    for (i = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            word = malloc(MAX_WORD_LENGTH);
            strncpy(word, &text[i], MAX_WORD_LENGTH);
            word[strcspn(word, " ")] = '\0';

            foundWord = bsearch(word, dictionary, dictionaryCount, sizeof(Word), compareWords);

            if (foundWord == NULL) {
                printf("Possible spelling error: %s\n", word);
            } else {
                foundWord->count++;
            }

            free(word);
        }
    }

    qsort(dictionary, dictionaryCount, sizeof(Word), compareWords);

    for (i = 0; i < dictionaryCount; i++) {
        printf("%s: %d\n", dictionary[i].word, dictionary[i].count);
    }
}

int main() {
    char text[1000];

    printf("Enter text to check spelling:\n");
    fgets(text, 1000, stdin);

    checkSpelling(text);

    return 0;
}
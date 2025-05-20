//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 100
#define MAX_LINE_LEN 1000

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

int compareWords(const void* a, const void* b) {
    const char* str1 = *(const char**)a;
    const char* str2 = *(const char**)b;
    return strcmp(str1, str2);
}

int main() {
    char line[MAX_LINE_LEN];
    WordCount* words = NULL;
    int numWords = 0;
    int maxWords = 1000;

    printf("Enter a filename: ");
    fgets(line, MAX_LINE_LEN, stdin);
    line[strcspn(line, "\n")] = '\0';

    FILE* file = fopen(line, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    char word[MAX_WORD_LEN];
    while (fscanf(file, "%s", word)!= EOF) {
        if (numWords >= maxWords) {
            printf("Maximum number of words reached.\n");
            break;
        }
        WordCount* newWord = malloc(sizeof(WordCount));
        strcpy(newWord->word, word);
        newWord->count = 1;
        words = realloc(words, sizeof(WordCount) * ++numWords);
        qsort(words, numWords, sizeof(WordCount), compareWords);
        for (int i = 0; i < numWords - 1; i++) {
            if (strcmp(words[i].word, word) == 0) {
                words[i].count++;
                break;
            }
        }
    }

    fclose(file);

    printf("Enter a word to count: ");
    fgets(word, MAX_WORD_LEN, stdin);
    word[strcspn(word, "\n")] = '\0';

    WordCount* targetWord = bsearch(word, words, numWords, sizeof(WordCount), compareWords);
    if (targetWord == NULL) {
        printf("Word not found.\n");
    } else {
        printf("Occurrences of '%s': %d\n", targetWord->word, targetWord->count);
    }

    free(words);
    return 0;
}
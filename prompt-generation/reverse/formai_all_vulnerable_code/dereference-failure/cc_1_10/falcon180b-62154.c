//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int main(int argc, char *argv[]) {
    FILE *file;
    char line[1024];
    char *token;
    int numWords = 0;
    WordCount *wordCounts = malloc(MAX_WORDS * sizeof(WordCount));

    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");

    if (file == NULL) {
        printf("Error opening file '%s'.\n", argv[1]);
        return 1;
    }

    while (fgets(line, sizeof(line), file)!= NULL) {
        token = strtok(line, ",.?!;:\"'");
        while (token!= NULL) {
            numWords++;
            if (numWords >= MAX_WORDS) {
                printf("Too many words in file.\n");
                fclose(file);
                return 1;
            }
            if (strlen(token) >= MAX_WORD_LENGTH) {
                printf("Word '%s' is too long.\n", token);
                fclose(file);
                return 1;
            }
            strcpy(wordCounts[numWords - 1].word, token);
            wordCounts[numWords - 1].count = 1;
            token = strtok(NULL, ",.?!;:\"'");
        }
    }

    fclose(file);

    printf("Word count:\n");
    for (int i = 0; i < numWords; i++) {
        if (wordCounts[i].count > 1) {
            printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
        }
    }

    free(wordCounts);

    return 0;
}
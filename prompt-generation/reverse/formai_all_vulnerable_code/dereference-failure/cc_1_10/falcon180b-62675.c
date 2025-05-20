//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: ephemeral
// This is a Word Count Tool program in C

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORD_LENGTH 100
#define MAX_FILE_SIZE 1000000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int main(int argc, char *argv[]) {
    FILE *file;
    char line[MAX_FILE_SIZE];
    char *word;
    int wordCount = 0;
    WordCount *wordCounts = malloc(sizeof(WordCount) * 100000); // allocate memory for 100000 words
    memset(wordCounts, 0, sizeof(WordCount) * 100000); // initialize all word counts to 0

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    while (fgets(line, MAX_FILE_SIZE, file)!= NULL) {
        word = strtok(line, ",.?!;:\"'-");
        while (word!= NULL) {
            if (strlen(word) > 0) {
                wordCount++;
                if (wordCount < MAX_WORD_LENGTH) {
                    strcpy(wordCounts[wordCount].word, word);
                    wordCounts[wordCount].count++;
                }
            }
            word = strtok(NULL, ",.?!;:\"'-");
        }
    }

    fclose(file);

    printf("Total words: %d\n", wordCount);
    printf("Word count:\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }

    free(wordCounts);
    return 0;
}
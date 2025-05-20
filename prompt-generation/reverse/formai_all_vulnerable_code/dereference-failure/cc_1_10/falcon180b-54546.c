//Falcon-180B DATASET v1.0 Category: Text processing ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LEN 100

typedef struct {
    char *word;
    int count;
} WordCount;

int main() {
    FILE *file;
    char line[MAX_WORD_LEN];
    WordCount words[MAX_WORDS];
    int numWords = 0;
    int i;

    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(line, MAX_WORD_LEN, file)!= NULL) {
        char *word = strtok(line, " ");
        while (word!= NULL) {
            for (i = 0; i < numWords; i++) {
                if (strcmp(word, words[i].word) == 0) {
                    words[i].count++;
                    break;
                }
            }
            if (i == numWords) {
                if (numWords >= MAX_WORDS) {
                    printf("Too many words.\n");
                    exit(1);
                }
                words[numWords].word = strdup(word);
                words[numWords].count = 1;
                numWords++;
            }
            word = strtok(NULL, " ");
        }
    }

    fclose(file);

    for (i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}
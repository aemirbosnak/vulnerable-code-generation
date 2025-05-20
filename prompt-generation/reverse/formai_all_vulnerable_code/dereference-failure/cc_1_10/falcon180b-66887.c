//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

typedef struct {
    char* word;
    int count;
} WordCount;

int main(int argc, char** argv) {
    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    char line[MAX_WORD_LEN];
    WordCount words[MAX_WORDS];
    int numWords = 0;

    while (fgets(line, MAX_WORD_LEN, file)!= NULL) {
        char* token = strtok(line, " ");
        while (token!= NULL) {
            int i;
            for (i = 0; i < numWords; i++) {
                if (strcmp(token, words[i].word) == 0) {
                    words[i].count++;
                    break;
                }
            }
            if (i == numWords) {
                if (numWords >= MAX_WORDS) {
                    printf("Error: too many words.\n");
                    exit(1);
                }
                words[numWords].word = strdup(token);
                words[numWords].count = 1;
                numWords++;
            }
            token = strtok(NULL, " ");
        }
    }

    fclose(file);

    printf("Word count:\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}
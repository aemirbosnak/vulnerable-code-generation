//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct wordFreq {
    char *word;
    int freq;
};

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        exit(1);
    }

    char buffer[1024];
    struct wordFreq wordList[1024];
    int numWords = 0;

    while (fgets(buffer, 1024, fp) != NULL) {
        char *token = strtok(buffer, " ");
        while (token != NULL) {
            int found = 0;
            for (int i = 0; i < numWords; i++) {
                if (strcmp(token, wordList[i].word) == 0) {
                    wordList[i].freq++;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                wordList[numWords].word = strdup(token);
                wordList[numWords].freq = 1;
                numWords++;
            }
            token = strtok(NULL, " ");
        }
    }

    fclose(fp);

    printf("Word frequency count in %s:\n", argv[1]);
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordList[i].word, wordList[i].freq);
    }

    return 0;
}
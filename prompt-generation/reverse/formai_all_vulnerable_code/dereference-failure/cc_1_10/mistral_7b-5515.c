//MISTRAL-7B DATASET v1.0 Category: Word Frequency Counter ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_WORDS 1000
#define WORD_LENGTH 50

typedef struct Word {
    char word[WORD_LENGTH];
    int count;
} Word;

void toLower(char *str) {
    int i;
    for (i = 0; str[i]; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
    }
}

int main(int argc, char *argv[]) {
    Word words[MAX_WORDS];
    int numWords = 0;
    int i, j;
    char *line = NULL;
    size_t len = 0;

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        perror("Error opening file");
        return 1;
    }

    while (getline(&line, &len, fp) != -1) {
        toLower(line);
        char *token = strtok(line, " \t\n\r.,;:!?");
        while (token) {
            for (i = 0; i < numWords; i++) {
                if (strcmp(words[i].word, token) == 0) {
                    words[i].count++;
                    break;
                }
            }
            if (i == numWords) {
                if (numWords == MAX_WORDS) {
                    printf("Too many words in file\n");
                    return 1;
                }
                strcpy(words[numWords++].word, token);
                words[numWords - 1].count = 1;
            }
            token = strtok(NULL, " \t\n\r.,;:!?");
        }
    }

    for (i = 0; i < numWords; i++) {
        printf("%s : %d\n", words[i].word, words[i].count);
    }

    fclose(fp);
    free(line);
    return 0;
}
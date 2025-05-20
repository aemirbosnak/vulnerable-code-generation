//Falcon2-11B DATASET v1.0 Category: Spam Detection System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

typedef struct {
    char word[MAX_LENGTH];
    int count;
} word_t;

int main() {
    FILE *fp;
    char line[MAX_LENGTH];
    word_t *words;

    fp = fopen("spam.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }

    words = (word_t*)malloc(MAX_LENGTH * sizeof(word_t));
    if (words == NULL) {
        perror("Memory allocation failed");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        char *word = strtok(line, " ");
        while (word!= NULL) {
            int is_spam = 1;
            for (int i = 0; i < strlen(word); i++) {
                if (!isalpha(word[i])) {
                    is_spam = 0;
                    break;
                }
            }
            if (is_spam) {
                strcpy(words[words->count].word, word);
                words[words->count].count++;
            }
            word = strtok(NULL, " ");
        }
    }

    fclose(fp);
    fp = fopen("spam.txt", "w");
    for (int i = 0; i < words->count; i++) {
        if (words[i].count > 1) {
            fprintf(fp, "%s: %d\n", words[i].word, words[i].count);
        }
    }
    fclose(fp);

    free(words);

    return 0;
}
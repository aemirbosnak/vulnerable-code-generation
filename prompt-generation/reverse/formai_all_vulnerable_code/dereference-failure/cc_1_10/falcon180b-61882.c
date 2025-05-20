//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int is_spam;
} Word;

int main() {
    FILE *fp;
    char line[1000];
    char *token;
    Word words[MAX_WORDS];
    int num_words = 0;
    int i;

    // Load spam words
    fp = fopen("spam_words.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open spam_words.txt\n");
        return 1;
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        token = strtok(line, "\n");
        strcpy(words[num_words].word, token);
        words[num_words].is_spam = 1;
        num_words++;
    }

    fclose(fp);

    // Load email text
    fp = fopen("email.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open email.txt\n");
        return 1;
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        token = strtok(line, ",.!?;:");
        while (token!= NULL) {
            for (i = 0; i < num_words; i++) {
                if (strcmp(token, words[i].word) == 0) {
                    printf("%s (spam)\n", token);
                    break;
                }
            }

            if (i == num_words) {
                printf("%s\n", token);
            }

            token = strtok(NULL, ",.!?;:");
        }
    }

    fclose(fp);

    return 0;
}
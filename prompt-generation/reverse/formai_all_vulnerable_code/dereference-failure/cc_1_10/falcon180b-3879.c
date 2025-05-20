//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: complete
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 1000

struct Word {
    char *word;
    int count;
};

int isSpam(char *message, struct Word words[], int numWords) {
    int i, j;
    int spamCount = 0;
    char *word;
    char *tokens[MAX_WORDS];

    word = strtok(message, " \t\n\r\f\v.,!?;:");
    while (word!= NULL) {
        for (i = 0; i < numWords; i++) {
            if (strcmp(word, words[i].word) == 0) {
                words[i].count++;
                spamCount++;
                break;
            }
        }
        if (i == numWords) {
            if (numWords >= MAX_WORDS) {
                printf("Warning: Maximum number of words reached.\n");
                break;
            }
            strcpy(words[numWords].word, word);
            words[numWords].count = 1;
            numWords++;
        }
        word = strtok(NULL, " \t\n\r\f\v.,!?;:");
    }

    for (i = 0; i < numWords; i++) {
        if (words[i].count > 1) {
            spamCount++;
        }
    }

    if (spamCount >= 3) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    FILE *fp;
    char line[1024];
    char *message;
    struct Word words[MAX_WORDS];
    int numWords = 0;
    int i;

    fp = fopen("spam_words.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open spam_words.txt.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        message = strdup(line);
        for (i = 0; i < strlen(message); i++) {
            if (message[i] == '\n') {
                message[i] = '\0';
                break;
            }
        }
        words[numWords].word = message;
        words[numWords].count = 0;
        numWords++;
    }

    fclose(fp);

    while (1) {
        printf("Enter message (or type 'exit' to quit):\n");
        fgets(message, sizeof(message), stdin);

        if (strcmp(message, "exit") == 0) {
            break;
        }

        if (isSpam(message, words, numWords)) {
            printf("Message is spam.\n");
        } else {
            printf("Message is not spam.\n");
        }
    }

    return 0;
}
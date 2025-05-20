//MISTRAL-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: automated
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_WORDS 10000
#define WORD_LEN 50
#define DICTIONARY_FILE "dictionary.txt"

typedef struct {
    char word[WORD_LEN];
    int score;
} Word;

Word dictionary[MAX_WORDS];
int dictSize = 0;

void loadDictionary() {
    int fd = open(DICTIONARY_FILE, O_RDONLY);
    char line[1024];
    char *token;

    if (fd < 0) {
        perror("Error opening dictionary file");
        exit(EXIT_FAILURE);
    }

    while (fgets(line, sizeof(line), fd) != NULL) {
        token = strtok(line, " \t\n\r\f,\";:!?.");
        strcpy(dictionary[dictSize].word, token);
        dictSize++;

        token = strtok(NULL, " \t\n\r\f,\";:!?.");
        if (token != NULL) {
            dictionary[dictSize - 1].score = atoi(token);
        } else {
            dictionary[dictSize - 1].score = 0;
        }
    }

    close(fd);
}

int main() {
    int fd;
    char input[1024];
    char *token;
    bool isPositive = true;
    int totalScore = 0;

    loadDictionary();

    printf("Sentiment Analysis Tool\n");
    printf("Enter text to analyze (type 'quit' to exit):\n");

    while (true) {
        fgets(input, sizeof(input), stdin);
        token = strtok(input, " \t\n\r\f,\";:!?.");

        if (strcmp(token, "quit") == 0) {
            break;
        }

        for (int i = 0; i < dictSize; i++) {
            if (strncmp(dictionary[i].word, token, strlen(token)) == 0) {
                totalScore += dictionary[i].score;
                if (dictionary[i].score < 0) {
                    isPositive = false;
                }
                break;
            }
        }
    }

    printf("\nTotal score: %d\n", totalScore);

    if (isPositive) {
        printf("Sentiment: Positive\n");
    } else {
        printf("Sentiment: Negative\n");
    }

    return 0;
}
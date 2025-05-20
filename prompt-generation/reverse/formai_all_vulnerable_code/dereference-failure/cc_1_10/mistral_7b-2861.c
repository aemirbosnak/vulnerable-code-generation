//MISTRAL-7B DATASET v1.0 Category: Word Frequency Counter ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define BUFFER_SIZE 1024
#define WORD_COUNT 256

char word[MAX_WORD_LENGTH];
char fileName[100];
FILE *file;
int wordFrequency[WORD_COUNT];
int i, j, count;

void toLower(char *str) {
    for (i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }
}

void processLine(char line[]) {
    char *token;
    toLower(line);

    token = strtok(line, " ");
    count = 0;

    while (token != NULL) {
        strcpy(word, token);
        for (j = 0; j < strlen(word); j++) {
            if (isalnum(word[j]) == 0) {
                word[j] = '\0';
                break;
            }
        }
        if (strlen(word) > 0) {
            int index = hash(word);
            wordFrequency[index]++;
        }
        token = strtok(NULL, " ");
    }
}

int hash(char *str) {
    int hash = 0;
    int i;

    for (i = 0; str[i] != '\0'; i++) {
        hash = ((hash << 5) + hash) + str[i]; /* hash * 31 + c */
    }

    return hash % WORD_COUNT;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    strcpy(fileName, argv[1]);

    file = fopen(fileName, "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    char buffer[BUFFER_SIZE];

    while (fgets(buffer, BUFFER_SIZE, file) != NULL) {
        processLine(buffer);
    }

    fclose(file);

    printf("Word Frequency Counter - Post Apocalypse\n");

    for (i = 0; i < WORD_COUNT; i++) {
        if (wordFrequency[i] > 0) {
            printf("%s : %d\n", &word[hash(word)], wordFrequency[i]);
        }
    }

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: invasive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50
#define THRESHOLD 0.7

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

void loadWords(char* filename, WordCount words[]) {
    FILE* fp = fopen(filename, "r");
    char line[MAX_WORD_LEN];
    while (fgets(line, MAX_WORD_LEN, fp)!= NULL) {
        char* token = strtok(line, " \t\n\r\f\v.,?!;:");
        while (token!= NULL) {
            if (strlen(token) > 0) {
                strcpy(words[hash(token) % MAX_WORDS].word, token);
                words[hash(token) % MAX_WORDS].count++;
            }
            token = strtok(NULL, " \t\n\r\f\v.,?!;:");
        }
    }
    fclose(fp);
}

int hash(char* str) {
    int hash = 0;
    while (*str!= '\0') {
        hash = (hash * 31) ^ tolower(*str++);
    }
    return hash;
}

int isSpam(char* message, WordCount words[]) {
    int spamCount = 0;
    char* token = strtok(message, " \t\n\r\f\v.,?!;:");
    while (token!= NULL) {
        if (strlen(token) > 0) {
            int index = hash(token) % MAX_WORDS;
            if (strcmp(words[index].word, token) == 0) {
                spamCount += words[index].count;
            }
        }
        token = strtok(NULL, " \t\n\r\f\v.,?!;:");
    }
    return (double)spamCount / strlen(message) >= THRESHOLD;
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: %s <spam_words_file> <message_file>\n", argv[0]);
        return 1;
    }
    WordCount words[MAX_WORDS];
    loadWords(argv[1], words);
    char message[MAX_WORD_LEN];
    FILE* fp = fopen(argv[2], "r");
    if (fp == NULL) {
        printf("Error opening message file.\n");
        return 1;
    }
    fgets(message, MAX_WORD_LEN, fp);
    fclose(fp);
    if (isSpam(message, words)) {
        printf("Spam detected.\n");
    } else {
        printf("No spam detected.\n");
    }
    return 0;
}
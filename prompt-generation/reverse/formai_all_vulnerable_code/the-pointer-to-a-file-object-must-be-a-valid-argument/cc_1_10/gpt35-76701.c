//FormAI DATASET v1.0 Category: Spam Detection System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SPAM_WORDS 50
#define MAX_SPAM_MESSAGES 100

typedef struct WordCount {
    char *word;
    int count;
} WordCount;

typedef struct SpamMessage {
    int id;
    char *content;
    int wordCount[MAX_SPAM_WORDS];
} SpamMessage;

WordCount spamWords[MAX_SPAM_WORDS];
SpamMessage spamMessages[MAX_SPAM_MESSAGES];

int countWords(char *content, char *word) {
    int count = 0;
    char *temp = strstr(content, word);
    while (temp) {
        count++;
        temp = strstr(temp + 1, word);
    }
    return count;
}

void addWord(char *word) {
    for (int i = 0; i < MAX_SPAM_WORDS; i++) {
        if (spamWords[i].word == NULL) {
            spamWords[i].word = word;
            spamWords[i].count = 1;
            return;
        } else if (strcmp(spamWords[i].word, word) == 0) {
            spamWords[i].count++;
            return;
        }
    }
}

int checkSpam(char *message) {
    int totalWords = 0;
    int spamCount = 0;

    // Count words in message
    char *copy = strdup(message);
    char *word = strtok(copy, " ");
    while (word) {
        for (int i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }
        for (int i = 0; i < MAX_SPAM_WORDS; i++) {
            if (spamWords[i].word != NULL && strcmp(spamWords[i].word, word) == 0) {
                spamCount += countWords(message, word);
            }
        }
        totalWords++;
        word = strtok(NULL, " ");
    }

    // Check for spam
    double spamRatio = (double) spamCount / (double) totalWords;
    if (spamRatio >= 0.1) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    // Load spam words from file
    FILE *file = fopen("spam_words.txt", "r");
    char line[100];
    int i = 0;
    while (fgets(line, sizeof(line), file)) {
        strtok(line, "\n");
        spamWords[i].word = strdup(line);
        spamWords[i].count = 0;
        i++;
    }

    // Load messages from file
    file = fopen("messages.txt", "r");
    i = 0;
    while (fgets(line, sizeof(line), file)) {
        strtok(line, "\n");
        spamMessages[i].id = i;
        spamMessages[i].content = strdup(line);

        // Count occurrences of each spam word in message
        for (int j = 0; j < MAX_SPAM_WORDS && spamWords[j].word != NULL; j++) {
            spamMessages[i].wordCount[j] = countWords(line, spamWords[j].word);
        }

        i++;
    }

    // Check for spam in each message
    printf("SPAM MESSAGES:\n");
    for (int j = 0; j < MAX_SPAM_MESSAGES && spamMessages[j].content != NULL; j++) {
        if (checkSpam(spamMessages[j].content)) {
            printf("Message ID: %d\nContent: %s\n\n", spamMessages[j].id, spamMessages[j].content);
        }
    }

    // Print statistics of spam words
    printf("SPAM WORDS STATISTICS:\n");
    for (int j = 0; j < MAX_SPAM_WORDS && spamWords[j].word != NULL; j++) {
        printf("Word: %s\nCount: %d\n\n", spamWords[j].word, spamWords[j].count);
    }

    return 0;
}
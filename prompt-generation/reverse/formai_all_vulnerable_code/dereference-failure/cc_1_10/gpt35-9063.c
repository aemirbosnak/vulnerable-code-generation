//FormAI DATASET v1.0 Category: Spam Detection System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SPAM_WORDS 100
#define MAX_SPAM_LENGTH 100

int count_words(char *message) {
    int count = 0;
    char *ptr = strtok(message, " ");
    while (ptr != NULL) {
        count++;
        ptr = strtok(NULL, " ");
    }
    return count;
}

void remove_newline(char *str) {
    int len = strlen(str);
    if (str[len-1] == '\n') {
        str[len-1] = '\0';
    }
}

void to_lower(char *str) {
    int i = 0;
    while (str[i]) {
        str[i] = tolower(str[i]);
        i++;
    }
}

int check_spam_word(char *word, char spam_words[MAX_SPAM_WORDS][MAX_SPAM_LENGTH], int spam_count) {
    int i;
    for (i = 0; i < spam_count; i++) {
        if (strcmp(word, spam_words[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int check_spam(char *message, char spam_words[MAX_SPAM_WORDS][MAX_SPAM_LENGTH], int spam_count) {
    int count = count_words(message);
    char *ptr = strtok(message, " ");
    while (ptr != NULL) {
        to_lower(ptr);
        if (check_spam_word(ptr, spam_words, spam_count) == 1) {
            return 1;
        }
        ptr = strtok(NULL, " ");
    }
    return 0;
}

int main() {
    char message[500];
    char spam_words[MAX_SPAM_WORDS][MAX_SPAM_LENGTH];
    int spam_count = 0;

    // Read spam words from file
    FILE *fp;
    fp = fopen("spam_words.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open spam words file.\n");
        return 1;
    }
    while (fgets(spam_words[spam_count], MAX_SPAM_LENGTH, fp)) {
        remove_newline(spam_words[spam_count]);
        spam_count++;
    }
    fclose(fp);

    // Get user message
    printf("Enter your message: ");
    fgets(message, 500, stdin);
    remove_newline(message);

    // Check for spam
    if (check_spam(message, spam_words, spam_count) == 1) {
        printf("SPAM DETECTED!\n");
    } else {
        printf("Message is okay.\n");
    }

    return 0;
}
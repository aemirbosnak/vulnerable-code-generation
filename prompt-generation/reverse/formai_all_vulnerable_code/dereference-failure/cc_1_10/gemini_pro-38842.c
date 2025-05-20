//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 20

char* stop_words[] = {"the", "and", "of", "to", "in", "is", "a"};
int stop_words_count = sizeof(stop_words) / sizeof(char*);

char* spam_words[] = {"free", "money", "offer", "win", "click"};
int spam_words_count = sizeof(spam_words) / sizeof(char*);

int is_spam(char* message) {
    char words[MAX_WORDS][MAX_WORD_LEN];
    int word_count = 0;

    char* word = strtok(message, " ");
    while (word != NULL) {
        if (word_count < MAX_WORDS) {
            strcpy(words[word_count], word);
            word_count++;
        }
        word = strtok(NULL, " ");
    }

    int spam_count = 0;
    for (int i = 0; i < word_count; i++) {
        int is_stop_word = 0;
        for (int j = 0; j < stop_words_count; j++) {
            if (strcmp(words[i], stop_words[j]) == 0) {
                is_stop_word = 1;
                break;
            }
        }

        if (is_stop_word == 0) {
            for (int j = 0; j < spam_words_count; j++) {
                if (strcmp(words[i], spam_words[j]) == 0) {
                    spam_count++;
                    break;
                }
            }
        }
    }

    if (spam_count > 0) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char* message = "Hello, I have a free offer for you. Click here to win money!";

    if (is_spam(message)) {
        printf("The message is spam.\n");
    } else {
        printf("The message is not spam.\n");
    }

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_WORDS 1000000
#define MIN_WORD_LENGTH 3
#define MAX_WORD_LENGTH 30

int spam_count = 0;
char **spam_words = NULL;
int num_spam_words = 0;

int is_spam(char *message) {
    int i;
    int word_count = 0;
    char *word = NULL;
    int word_length = 0;
    int is_spam = 0;

    for (i = 0; i < strlen(message); i++) {
        if (isspace(message[i])) {
            if (word_length >= MIN_WORD_LENGTH && word_length <= MAX_WORD_LENGTH) {
                word_count++;
            }
            word_length = 0;
        } else {
            word_length++;
        }
    }

    if (word_length >= MIN_WORD_LENGTH && word_length <= MAX_WORD_LENGTH) {
        word_count++;
    }

    for (i = 0; i < num_spam_words; i++) {
        if (strstr(message, spam_words[i])!= NULL) {
            is_spam = 1;
            break;
        }
    }

    if (is_spam == 1) {
        spam_count++;
    }

    return is_spam;
}

int main() {
    char message[1000000];
    int i;

    spam_words = malloc(sizeof(char *) * MAX_WORDS);

    spam_words[0] = strdup("viagra");
    num_spam_words = 1;

    printf("Enter message: ");
    fgets(message, sizeof(message), stdin);

    if (is_spam(message)) {
        printf("Spam detected!\n");
    } else {
        printf("No spam detected.\n");
    }

    return 0;
}
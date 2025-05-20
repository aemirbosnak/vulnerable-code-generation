//FormAI DATASET v1.0 Category: Spam Detection System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1000
#define MAX_SPAM_WORDS 10

const char *SPAM_WORDS[MAX_SPAM_WORDS] = {"offer", "free", "money", "click", "win", "lottery", "credit", "card", "sex"};

int is_spam(char *input) {
    int i, j, input_len, word_len;
    char lowercase_input[MAX_INPUT_SIZE];

    input_len = strlen(input);

    // Convert input to lowercase
    for (i = 0; i < input_len; i++) {
        if (input[i] >= 'A' && input[i] <= 'Z') {
            lowercase_input[i] = input[i] - ('A' - 'a');
        } else {
            lowercase_input[i] = input[i];
        }
    }

    // Check if any of the spam words are present in the input string
    for (i = 0; i < MAX_SPAM_WORDS; i++) {
        word_len = strlen(SPAM_WORDS[i]);
        for (j = 0; j <= input_len - word_len; j++) {
            if (strncasecmp(lowercase_input + j, SPAM_WORDS[i], word_len) == 0) {
                return 1;
            }
        }
    }

    return 0;
}

int main() {
    char input[MAX_INPUT_SIZE];
    int is_spam_flag;

    printf("Enter your message: ");
    fgets(input, MAX_INPUT_SIZE, stdin);

    is_spam_flag = is_spam(input);

    if (is_spam_flag) {
        printf("The message is spam.\n");
    } else {
        printf("The message is not spam.\n");
    }

    return 0;
}
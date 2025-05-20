//GPT-4o-mini DATASET v1.0 Category: Spam Detection System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 1024
#define SPAM_KEYWORDS_SIZE 5
#define SPAM_THRESHOLD 3

const char *spam_keywords[SPAM_KEYWORDS_SIZE] = {
    "win", "free", "winner", "click", "offer"
};

void to_lowercase(char *str) {
    while (*str) {
        *str = tolower((unsigned char)*str);
        str++;
    }
}

int count_spam_keywords(const char *input) {
    int count = 0;
    char *temp = strdup(input);  // Make a mutable copy of the input
    if (temp == NULL) {
        fprintf(stderr, "Memory allocation error!\n");
        exit(EXIT_FAILURE);
    }

    to_lowercase(temp);

    for (int i = 0; i < SPAM_KEYWORDS_SIZE; i++) {
        if (strstr(temp, spam_keywords[i]) != NULL) {
            count++;
        }
    }

    free(temp);
    return count;
}

char *read_input() {
    char *input = malloc(MAX_INPUT_SIZE);
    if (input == NULL) {
        fprintf(stderr, "Memory allocation error!\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter your message (Type 'exit' to quit): ");
    if (fgets(input, MAX_INPUT_SIZE, stdin) == NULL) {
        free(input);
        return NULL;
    }

    // Remove newline character at the end
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    return input;
}

void spam_detector() {
    char *input;

    while (1) {
        input = read_input();
        if (input == NULL) {
            break;  // Exit on error
        }
        if (strcmp(input, "exit") == 0) {
            free(input);
            break;  // Exit command
        }

        int spam_count = count_spam_keywords(input);
        printf("Your message contains %d spam triggers.\n", spam_count);

        if (spam_count >= SPAM_THRESHOLD) {
            printf("Warning: Your message is marked as spam!\n");
        } else {
            printf("Your message seems fine.\n");
        }

        free(input);
    }
}

int main() {
    printf("Welcome to the Spam Detection System!\n");
    printf("This system will analyze your messages for spam content.\n");

    spam_detector();

    printf("Thank you for using the Spam Detection System. Goodbye!\n");
    return 0;
}
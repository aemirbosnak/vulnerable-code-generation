//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *text;
    int len;
} spam_pattern;

int compare_patterns(spam_pattern *a, spam_pattern *b) {
    if (a->len != b->len) {
        return 0;
    }
    for (int i = 0; i < a->len; i++) {
        if (a->text[i] != b->text[i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    // Initialize the spam patterns
    spam_pattern patterns[] = {
        { .text = "FREE", .len = 4 },
        { .text = "WIN", .len = 3 },
        { .text = "URGENT", .len = 6 },
        { .text = "ACT NOW", .len = 7 },
        { .text = "100% FREE", .len = 8 },
    };

    // Get the input text from the user
    char *input_text = malloc(1024);
    printf("Enter the text to check for spam: ");
    fgets(input_text, 1024, stdin);

    // Check the input text against the spam patterns
    int is_spam = 0;
    for (int i = 0; i < sizeof(patterns) / sizeof(patterns[0]); i++) {
        if (strstr(input_text, patterns[i].text) != NULL) {
            is_spam = 1;
            break;
        }
    }

    // Print the result
    if (is_spam) {
        printf("The text is spam.\n");
    } else {
        printf("The text is not spam.\n");
    }

    // Free the allocated memory
    free(input_text);

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 1000
#define MAX_TOKEN_LEN 100

typedef struct {
    char *word;
    int count;
} token_t;

int spam_detection(char *email_content) {
    int spam_count = 0;
    token_t tokens[MAX_TOKENS];
    int num_tokens = 0;

    // Tokenize the email content
    char *token = strtok(email_content, " ");
    while (token!= NULL) {
        if (num_tokens >= MAX_TOKENS) {
            break;
        }
        if (strlen(token) > MAX_TOKEN_LEN) {
            break;
        }
        tokens[num_tokens].word = strdup(token);
        tokens[num_tokens++].count = 0;
        token = strtok(NULL, " ");
    }

    // Count the frequency of each token
    char *word;
    while ((word = strtok(email_content, " "))!= NULL) {
        for (int i = 0; i < num_tokens; i++) {
            if (strcmp(word, tokens[i].word) == 0) {
                tokens[i].count++;
                break;
            }
        }
    }

    // Check for spammy words
    for (int i = 0; i < num_tokens; i++) {
        if (tokens[i].count > 1) {
            spam_count++;
        }
    }

    return spam_count;
}

int main() {
    char email_content[10000];
    printf("Enter email content: ");
    fgets(email_content, 10000, stdin);
    int spam_count = spam_detection(email_content);
    if (spam_count > 0) {
        printf("Spam detected!\n");
    } else {
        printf("No spam detected.\n");
    }
    return 0;
}
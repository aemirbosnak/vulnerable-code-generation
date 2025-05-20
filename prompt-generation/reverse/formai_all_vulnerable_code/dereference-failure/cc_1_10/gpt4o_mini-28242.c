//GPT-4o-mini DATASET v1.0 Category: Spam Detection System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MESSAGES 100
#define MAX_MESSAGE_LENGTH 256
#define MAX_KEYWORDS 10
#define MAX_KEYWORD_LENGTH 50

typedef struct {
    char **keywords;
    int count;
} SpamKeywords;

void initializeKeywords(SpamKeywords *spamKeywords) {
    spamKeywords->keywords = malloc(MAX_KEYWORDS * sizeof(char *));
    for (int i = 0; i < MAX_KEYWORDS; i++) {
        spamKeywords->keywords[i] = malloc(MAX_KEYWORD_LENGTH * sizeof(char));
    }
    spamKeywords->count = 0;
}

void addKeyword(SpamKeywords *spamKeywords, const char *keyword) {
    if (spamKeywords->count < MAX_KEYWORDS) {
        strncpy(spamKeywords->keywords[spamKeywords->count], keyword, MAX_KEYWORD_LENGTH);
        spamKeywords->count++;
    }
}

int isSpamMessage(const char *message, SpamKeywords *spamKeywords) {
    for (int i = 0; i < spamKeywords->count; i++) {
        if (strstr(message, spamKeywords->keywords[i]) != NULL) {
            return 1; // Message contains spam keyword
        }
    }
    return 0; // No spam keywords found
}

void freeKeywords(SpamKeywords *spamKeywords) {
    for (int i = 0; i < spamKeywords->count; i++) {
        free(spamKeywords->keywords[i]);
    }
    free(spamKeywords->keywords);
}

int main() {
    SpamKeywords spamKeywords;
    initializeKeywords(&spamKeywords);

    // Define some keywords for spam detection
    addKeyword(&spamKeywords, "win a free");
    addKeyword(&spamKeywords, "click here");
    addKeyword(&spamKeywords, "money back");
    addKeyword(&spamKeywords, "limited time offer");
    addKeyword(&spamKeywords, "act now");
    addKeyword(&spamKeywords, "urgent");
    addKeyword(&spamKeywords, "subscribe");
    addKeyword(&spamKeywords, "100% guaranteed");
    addKeyword(&spamKeywords, "free gift");
    addKeyword(&spamKeywords, "risk-free");

    char *messages[MAX_MESSAGES];
    int messageCount = 0;

    printf("Enter messages (type 'exit' to stop):\n");
    while (messageCount < MAX_MESSAGES) {
        messages[messageCount] = (char *)malloc(MAX_MESSAGE_LENGTH * sizeof(char));
        fgets(messages[messageCount], MAX_MESSAGE_LENGTH, stdin);
        
        // Remove trailing newline character
        messages[messageCount][strcspn(messages[messageCount], "\n")] = 0;

        if (strcmp(messages[messageCount], "exit") == 0) {
            free(messages[messageCount]);
            break;
        }
        messageCount++;
    }

    printf("\nSpam Detection Results:\n");
    for (int i = 0; i < messageCount; i++) {
        if (isSpamMessage(messages[i], &spamKeywords)) {
            printf("Spam: \"%s\"\n", messages[i]);
        } else {
            printf("Not Spam: \"%s\"\n", messages[i]);
        }
        free(messages[i]); // Clean up each message after processing
    }

    // Free allocated memory for keywords
    freeKeywords(&spamKeywords);

    return 0;
}
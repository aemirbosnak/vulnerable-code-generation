//GPT-4o-mini DATASET v1.0 Category: Spam Detection System ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_MESSAGES 100
#define MAX_LENGTH 256

typedef struct {
    char *content;
    int spamScore;
} Message;

void initializeMessage(Message *msg, const char *content) {
    msg->content = (char *)malloc(strlen(content) + 1);
    strcpy(msg->content, content);
    msg->spamScore = 0;
}

void freeMessage(Message *msg) {
    free(msg->content);
}

int calculateSpamScore(const char *message) {
    const char *spamWords[] = { "win", "free", "winner", "money", "click", "buy", "urgent", "act now", "limited", "offer" };
    int score = 0;

    for (int i = 0; i < sizeof(spamWords) / sizeof(spamWords[0]); i++) {
        if (strstr(message, spamWords[i]) != NULL) {
            score += 1;
        }
    }

    return score;
}

void analyzeMessages(Message messages[], int count) {
    printf("Analyzing messages for spam...\n");
    for (int i = 0; i < count; i++) {
        messages[i].spamScore = calculateSpamScore(messages[i].content);
        printf("Message %d: \"%s\" - Spam Score: %d\n", i + 1, messages[i].content, messages[i].spamScore);
    }
}

void sortMessagesBySpamScore(Message messages[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (messages[j].spamScore < messages[j + 1].spamScore) {
                Message temp = messages[j];
                messages[j] = messages[j + 1];
                messages[j + 1] = temp;
            }
        }
    }
}

void displayMostSpammyMessages(Message messages[], int count) {
    printf("\nMost Spammy Messages:\n");
    for (int i = 0; i < count; i++) {
        if (messages[i].spamScore > 0) {
            printf("Message %d: \"%s\" with a score of %d\n", i + 1, messages[i].content, messages[i].spamScore);
        }
    }
}

int main() {
    Message messages[MAX_MESSAGES];
    int msgCount = 0;

    printf("Welcome to the Sherlock Holmes Spam Detection System!\n");
    printf("Please enter messages (type 'END' to finish):\n");

    while (msgCount < MAX_MESSAGES) {
        char input[MAX_LENGTH];
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0; // Remove trailing newline
        
        if (strcmp(input, "END") == 0) {
            break;
        }

        initializeMessage(&messages[msgCount], input);
        msgCount++;
    }

    analyzeMessages(messages, msgCount);
    sortMessagesBySpamScore(messages, msgCount);
    displayMostSpammyMessages(messages, msgCount);

    for (int i = 0; i < msgCount; i++) {
        freeMessage(&messages[i]);
    }

    return 0;
}
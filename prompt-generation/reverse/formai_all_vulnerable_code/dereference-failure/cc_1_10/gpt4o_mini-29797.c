//GPT-4o-mini DATASET v1.0 Category: Spam Detection System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_MESSAGE_LENGTH 1024
#define SPAM_KEYWORDS_COUNT 5

const char *spam_keywords[SPAM_KEYWORDS_COUNT] = {
    "buy now",
    "subscribe",
    "limited time offer",
    "click here",
    "free gift"
};

typedef struct {
    char message[MAX_MESSAGE_LENGTH];
    bool is_spam;
} Message;

void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

bool contains_spam_keyword(const char *message) {
    for (int i = 0; i < SPAM_KEYWORDS_COUNT; i++) {
        if (strstr(message, spam_keywords[i]) != NULL) {
            return true;
        }
    }
    return false;
}

void analyze_message(Message *msg) {
    char temp_message[MAX_MESSAGE_LENGTH];
    
    strncpy(temp_message, msg->message, MAX_MESSAGE_LENGTH);
    to_lowercase(temp_message);
    
    msg->is_spam = contains_spam_keyword(temp_message);
}

void display_analysis_result(Message *msg) {
    printf("Analyzing Message: \"%s\"\n", msg->message);
    if (msg->is_spam) {
        printf("Result: SPAM detected!\n");
    } else {
        printf("Result: Not spam.\n");
    }
}

void load_messages(Message **messages, int *count) {
    *count = 0;
    *messages = malloc(sizeof(Message) * 10); // Initial capacity

    while (true) {
        printf("Enter a message (or 'quit' to stop): ");
        fgets((*messages)[*count].message, MAX_MESSAGE_LENGTH, stdin);
        (*messages)[*count].message[strcspn((*messages)[*count].message, "\n")] = '\0'; // Remove newline

        if (strcmp((*messages)[*count].message, "quit") == 0) {
            break;
        }

        analyze_message(&((*messages)[*count]));
        (*count)++;

        // Resize if necessary
        if (*count % 10 == 0) {
            *messages = realloc(*messages, sizeof(Message) * (*count + 10));
        }
    }
}

void free_messages(Message *messages) {
    free(messages);
}

int main() {
    Message *messages = NULL;
    int message_count = 0;

    load_messages(&messages, &message_count);

    printf("\nAnalyzed Messages Summary:\n");
    for (int i = 0; i < message_count; i++) {
        display_analysis_result(&messages[i]);
    }

    free_messages(messages);
    return 0;
}
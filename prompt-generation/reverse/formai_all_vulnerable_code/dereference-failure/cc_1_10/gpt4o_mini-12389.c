//GPT-4o-mini DATASET v1.0 Category: Spam Detection System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1024
#define SPAM_THRESHOLD 5

typedef struct {
    char **messages;
    int count;
    int capacity;
} MessageBuffer;

void init_buffer(MessageBuffer *buffer) {
    buffer->capacity = 10;
    buffer->count = 0;
    buffer->messages = malloc(buffer->capacity * sizeof(char *));
    for (int i = 0; i < buffer->capacity; i++) {
        buffer->messages[i] = malloc(MAX_LENGTH * sizeof(char));
    }
}

void add_message(MessageBuffer *buffer, const char *msg) {
    if (buffer->count >= buffer->capacity) {
        buffer->capacity *= 2;
        buffer->messages = realloc(buffer->messages, buffer->capacity * sizeof(char *));
        for (int i = buffer->count; i < buffer->capacity; i++) {
            buffer->messages[i] = malloc(MAX_LENGTH * sizeof(char));
        }
    }
    strcpy(buffer->messages[buffer->count++], msg);
}

void free_buffer(MessageBuffer *buffer) {
    for (int i = 0; i < buffer->capacity; i++) {
        free(buffer->messages[i]);
    }
    free(buffer->messages);
}

/// This function analyzes a message for spam keywords
int analyze_spam(const char *msg) {
    const char *spam_keywords[] = {
        "free", "winner", "cash", "urgent", 
        "limited", "guarantee", "offer", "click"
    };
    int spam_count = 0;
    
    // Case insensitive search for spam keywords
    for (int i = 0; i < sizeof(spam_keywords) / sizeof(spam_keywords[0]); i++) {
        if (strstr(msg, spam_keywords[i]) != NULL) {
            spam_count++;
        }
    }
    
    return spam_count;
}

/// Function to check if a message exceeds spam threshold
int is_spam(const char *msg) {
    int count = analyze_spam(msg);
    return (count >= SPAM_THRESHOLD);
}

void print_spam_report(MessageBuffer *buffer) {
    int spam_messages = 0;

    printf("Spam Report:\n");
    for (int i = 0; i < buffer->count; i++) {
        if (is_spam(buffer->messages[i])) {
            printf("Spam Message %d: %s\n", i + 1, buffer->messages[i]);
            spam_messages++;
        }
    }
    if (spam_messages == 0) {
        printf("No spam detected.\n");
    }
}

int main() {
    MessageBuffer buffer;
    init_buffer(&buffer);
    
    char input[MAX_LENGTH];

    printf("=== Spam Detection System ===\n");
    printf("Enter messages (Type 'exit' to stop):\n");

    while (1) {
        printf("Message: ");
        fgets(input, MAX_LENGTH, stdin);
        input[strcspn(input, "\n")] = 0; // Remove newline character

        if (strcmp(input, "exit") == 0) {
            break;
        }
        
        add_message(&buffer, input);
    }

    print_spam_report(&buffer);
    free_buffer(&buffer);
    return 0;
}
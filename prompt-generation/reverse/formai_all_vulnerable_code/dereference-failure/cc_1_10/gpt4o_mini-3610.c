//GPT-4o-mini DATASET v1.0 Category: Spam Detection System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

#define MAX_MESSAGES 100
#define MAX_LENGTH 500

typedef struct {
    char** messages;
    int count;
} MessageBuffer;

void initializeBuffer(MessageBuffer* buffer) {
    buffer->messages = (char**)malloc(MAX_MESSAGES * sizeof(char*));
    for (int i = 0; i < MAX_MESSAGES; i++) {
        buffer->messages[i] = (char*)malloc(MAX_LENGTH * sizeof(char));
    }
    buffer->count = 0;
}

void freeBuffer(MessageBuffer* buffer) {
    for (int i = 0; i < buffer->count; i++) {
        free(buffer->messages[i]);
    }
    free(buffer->messages);
}

void addMessage(MessageBuffer* buffer, const char* message) {
    if (buffer->count < MAX_MESSAGES) {
        strncpy(buffer->messages[buffer->count], message, MAX_LENGTH - 1);
        buffer->messages[buffer->count][MAX_LENGTH - 1] = '\0';
        buffer->count++;
    } else {
        printf("Message buffer is full. Cannot add more messages.\n");
    }
}

int containsSpam(const char* message) {
    const char* spamWords[] = {"win", "free", "prize", "call", "click here", "free gift", NULL};
    for (int i = 0; spamWords[i] != NULL; i++) {
        if (strstr(message, spamWords[i]) != NULL) {
            return 1;
        }
    }
    return 0;
}

void detectSpamMessages(MessageBuffer* buffer) {
    printf("Spam detection results:\n");
    for (int i = 0; i < buffer->count; i++) {
        if (containsSpam(buffer->messages[i])) {
            printf("Spam detected: %s\n", buffer->messages[i]);
        }
    }
}

void loadMessagesFromFile(MessageBuffer* buffer, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    while (fgets(buffer->messages[buffer->count], MAX_LENGTH, file) != NULL) {
        buffer->messages[buffer->count][strcspn(buffer->messages[buffer->count], "\n")] = 0; // Remove newline
        buffer->count++;
        if (buffer->count >= MAX_MESSAGES) {
            break;
        }
    }

    fclose(file);
}

void printMessages(MessageBuffer* buffer) {
    printf("Messages:\n");
    for (int i = 0; i < buffer->count; i++) {
        printf("%d: %s\n", i + 1, buffer->messages[i]);
    }
}

int main() {
    MessageBuffer buffer;
    initializeBuffer(&buffer);

    const char* filename = "messages.txt";
    loadMessagesFromFile(&buffer, filename);
    printMessages(&buffer);
    detectSpamMessages(&buffer);

    freeBuffer(&buffer);
    return 0;
}
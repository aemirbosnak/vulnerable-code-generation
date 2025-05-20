//GPT-4o-mini DATASET v1.0 Category: Spam Detection System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MESSAGE_LENGTH 256
#define SPAM_KEYWORDS_SIZE 5

const char *spam_keywords[SPAM_KEYWORDS_SIZE] = {
    "free", "winner", "win", "prize", "guarantee"
};

// Function to determine if a message contains spam keywords
int is_spam(const char *message) {
    for (int i = 0; i < SPAM_KEYWORDS_SIZE; i++) {
        if (strstr(message, spam_keywords[i]) != NULL) {
            return 1; // found a spam keyword
        }
    }
    return 0; // no spam keyword found
}

// Function to read messages from a file
char **read_messages(const char *filename, int *message_count) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    char **messages = NULL;
    char line[MAX_MESSAGE_LENGTH];
    *message_count = 0;

    while (fgets(line, sizeof(line), file)) {
        messages = realloc(messages, sizeof(char*) * (*message_count + 1));
        messages[*message_count] = strdup(line);
        (*message_count)++;
    }
    fclose(file);
    return messages;
}

// Function to free the messages array
void free_messages(char **messages, int message_count) {
    for (int i = 0; i < message_count; i++) {
        free(messages[i]);
    }
    free(messages);
}

// Function to classify and print the messages
void classify_messages(char **messages, int message_count) {
    for (int i = 0; i < message_count; i++) {
        printf("Message: %s", messages[i]);
        if (is_spam(messages[i])) {
            printf("Classification: SPAM\n\n");
        } else {
            printf("Classification: NOT SPAM\n\n");
        }
    }
}

// Main function to orchestrate the spam detection
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int message_count;
    char **messages = read_messages(argv[1], &message_count);
    classify_messages(messages, message_count);
    free_messages(messages, message_count);

    return EXIT_SUCCESS;
}
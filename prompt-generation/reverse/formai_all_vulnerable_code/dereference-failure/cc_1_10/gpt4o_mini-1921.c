//GPT-4o-mini DATASET v1.0 Category: Spam Detection System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 256
#define SPAM_KEYWORDS_COUNT 5
#define INPUT_FILE "messages.txt"
#define OUTPUT_FILE "spam_results.txt"

// List of spam keywords
const char *spam_keywords[SPAM_KEYWORDS_COUNT] = {
    "free",
    "win",
    "click here",
    "winner",
    "limited time offer"
};

// Function to check if a message contains any spam keywords
bool contains_spam(const char *message) {
    for (int i = 0; i < SPAM_KEYWORDS_COUNT; i++) {
        if (strstr(message, spam_keywords[i]) != NULL) {
            return true;
        }
    }
    return false;
}

// Function to write results to an output file
void log_result(const char *message, bool is_spam) {
    FILE *output_file = fopen(OUTPUT_FILE, "a");
    if (output_file == NULL) {
        perror("Error opening output file");
        exit(EXIT_FAILURE);
    }
    if (is_spam) {
        fprintf(output_file, "SPAM: %s\n", message);
    } else {
        fprintf(output_file, "NOT SPAM: %s\n", message);
    }
    fclose(output_file);
}

// Function to process the input messages file
void process_messages(const char *input_file) {
    FILE *file = fopen(input_file, "r");
    if (file == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        // Remove newline character from the message
        line[strcspn(line, "\n")] = 0;
        bool is_spam = contains_spam(line);
        log_result(line, is_spam);
    }

    fclose(file);
}

int main() {
    // Clear previous results
    FILE *output_file = fopen(OUTPUT_FILE, "w");
    if (output_file != NULL) {
        fclose(output_file);
    } else {
        perror("Error resetting output file");
    }

    // Process messages from the input file
    process_messages(INPUT_FILE);

    printf("Spam detection completed. Results are saved in %s\n", OUTPUT_FILE);
    return 0;
}
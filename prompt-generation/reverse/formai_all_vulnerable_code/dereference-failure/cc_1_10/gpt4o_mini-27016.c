//GPT-4o-mini DATASET v1.0 Category: Browser Plugin ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

#define LOG_FILE "user_input.log"
#define MAX_INPUT_LENGTH 256

// Function prototypes
void initialize_logger();
void log_input(const char *input);
void capture_input();
void sanitize_input(char *buffer);
void cleanup();

FILE *log_file;

int main() {
    initialize_logger();
    capture_input();
    cleanup();
    return 0;
}

// Initializes the logger by opening the log file
void initialize_logger() {
    log_file = fopen(LOG_FILE, "a");
    if (log_file == NULL) {
        perror("Failed to open log file");
        exit(EXIT_FAILURE);
    }
    printf("Logger initialized. Logging to %s\n", LOG_FILE);
}

// Captures user input and logs it
void capture_input() {
    char user_input[MAX_INPUT_LENGTH];

    printf("Enter some text (type 'exit' to quit):\n");

    while (1) {
        printf("> ");
        if (fgets(user_input, sizeof(user_input), stdin) != NULL) {
            // Remove the newline character from the input
            user_input[strcspn(user_input, "\n")] = 0;

            if (strcasecmp(user_input, "exit") == 0) {
                printf("Exiting input capture.\n");
                break;
            }

            sanitize_input(user_input);
            log_input(user_input);
        } else {
            perror("Error reading input");
            break;
        }
    }
}

// Logs the user input to the log file
void log_input(const char *input) {
    if (fprintf(log_file, "%s\n", input) < 0) {
        perror("Failed to log input");
    } else {
        printf("Logged: %s\n", input);
    }
}

// Sanitizes the input by trimming excess whitespace and enforcing input limits
void sanitize_input(char *buffer) {
    // Trim leading whitespace
    while (isspace((unsigned char)*buffer)) {
        buffer++;
    }

    // Trim trailing whitespace
    char *end = buffer + strlen(buffer) - 1;
    while (end > buffer && isspace((unsigned char)*end)) {
        end--;
    }
    *(end + 1) = '\0'; // Null terminate the string
}

// Clean up by closing the log file
void cleanup() {
    if (log_file != NULL) {
        fclose(log_file);
        printf("Logger closed.\n");
    }
}
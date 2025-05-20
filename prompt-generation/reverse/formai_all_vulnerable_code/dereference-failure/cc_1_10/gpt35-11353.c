//FormAI DATASET v1.0 Category: Log analysis ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of log messages
#define MAX_MESSAGE_LEN 1024

// Define the maximum number of log messages
#define MAX_NUM_MESSAGES 1000

/*
 * A struct to represent a log message
 */
typedef struct {
    char message[MAX_MESSAGE_LEN];
    int level;
} LogMessage;

/*
 * Parses a log message into its level and message content
 */
void parse_log_message(char *input, int *level, char *message) {
    char *token = strtok(input, ":");
    *level = atoi(token);
    token = strtok(NULL, "");
    strcpy(message, token);
}

int main() {
    // Define the log file name
    char *log_file = "application.log";

    // Open the log file for reading
    FILE *file = fopen(log_file, "r");

    // Check if the file was successfully opened
    if (file == NULL) {
        printf("Failed to open log file %s", log_file);
        return 1;
    }

    // Define an array to store all the log messages
    LogMessage log_messages[MAX_NUM_MESSAGES];

    // Initialize the number of log messages to 0
    int num_messages = 0;

    // Read the log file line by line
    char line[MAX_MESSAGE_LEN];
    while (fgets(line, MAX_MESSAGE_LEN, file)) {
        // Parse the log message
        int level;
        char message[MAX_MESSAGE_LEN];
        parse_log_message(line, &level, message);

        // Store the log message in the array
        LogMessage log_message;
        strcpy(log_message.message, message);
        log_message.level = level;
        log_messages[num_messages] = log_message;
        num_messages++;
    }

    // Close the log file
    fclose(file);

    // Calculate the Shannon entropy for the log messages
    double level_entropy[10] = {0};
    double message_entropy[MAX_MESSAGE_LEN] = {0};
    double total_entropy = 0;
    for (int i = 0; i < num_messages; i++) {
        // Calculate the entropy for the level
        level_entropy[log_messages[i].level]++;
        double level_prob = level_entropy[log_messages[i].level] / num_messages;
        double level_log_prob = log2(level_prob);
        total_entropy -= level_prob * level_log_prob;

        // Calculate the entropy for the message
        for (int j = 0; j < strlen(log_messages[i].message); j++) {
            char c = log_messages[i].message[j];
            message_entropy[(int) c]++;
            double message_prob = message_entropy[(int) c] / num_messages;
            double message_log_prob = log2(message_prob);
            total_entropy -= message_prob * message_log_prob;
        }
    }

    // Print the entropy results
    printf("Level entropy:\n");
    for (int i = 0; i < 10; i++) {
        double prob = level_entropy[i] / num_messages;
        printf("%d: %f\n", i, prob);
    }
    printf("\nMessage entropy:\n");
    for (int i = 0; i < MAX_MESSAGE_LEN; i++) {
        double prob = message_entropy[i] / num_messages;
        if (prob > 0) {
            printf("%c: %f\n", (char) i, prob);
        }
    }
    printf("\nTotal entropy: %f bits/message\n", total_entropy);

    return 0;
}
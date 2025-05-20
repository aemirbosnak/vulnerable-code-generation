//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

// Define the maximum line length for the log file
#define MAX_LINE_LENGTH 1024

// Define the regular expression pattern for extracting log messages
#define LOG_MESSAGE_PATTERN "^\[(.*?)\] (.*?): (.*?)$"

// Define the regular expression pattern for extracting log timestamps
#define LOG_TIMESTAMP_PATTERN "^\[(.*?)\]"

// Define the regular expression pattern for extracting log levels
#define LOG_LEVEL_PATTERN ".*?: (.*?): .*"

// Define the regular expression pattern for extracting log messages
#define LOG_MESSAGE_PATTERN ".*?: .*?: (.*)$"

// Define the regular expression pattern for extracting log tags
#define LOG_TAG_PATTERN "\[(.*?)\]"

// Define the maximum number of log messages to store
#define MAX_LOG_MESSAGES 100

// Define the structure of a log message
typedef struct {
    char *timestamp;
    char *level;
    char *tag;
    char *message;
} LogMessage;

// Define the structure of a log file
typedef struct {
    FILE *file;
    LogMessage messages[MAX_LOG_MESSAGES];
    int num_messages;
} LogFile;

// Create a new log file
LogFile *create_log_file(char *filename) {
    LogFile *log_file = malloc(sizeof(LogFile));
    log_file->file = fopen(filename, "r");
    log_file->num_messages = 0;
    return log_file;
}

// Close a log file
void close_log_file(LogFile *log_file) {
    fclose(log_file->file);
    free(log_file);
}

// Read the next line from a log file
char *read_line_from_log_file(LogFile *log_file) {
    char *line = NULL;
    size_t len = 0;
    if (getline(&line, &len, log_file->file) != -1) {
        return line;
    } else {
        return NULL;
    }
}

// Parse a log line using a regular expression
int parse_log_line(char *line, char *pattern, char **result) {
    int status;
    regex_t regex;
    regmatch_t matches[4];

    // Compile the regular expression
    status = regcomp(&regex, pattern, REG_EXTENDED);
    if (status != 0) {
        return -1;
    }

    // Execute the regular expression on the line
    status = regexec(&regex, line, 4, matches, 0);
    if (status != 0) {
        return -1;
    }

    // Extract the result from the regular expression match
    *result = strndup(line + matches[3].rm_so, matches[3].rm_eo - matches[3].rm_so);

    // Free the regular expression
    regfree(&regex);

    return 0;
}

// Add a log message to a log file
void add_log_message_to_log_file(LogFile *log_file, LogMessage *log_message) {
    log_file->messages[log_file->num_messages] = *log_message;
    log_file->num_messages++;
}

// Print the log messages from a log file
void print_log_messages(LogFile *log_file) {
    for (int i = 0; i < log_file->num_messages; i++) {
        printf("%s %s %s %s\n",
            log_file->messages[i].timestamp,
            log_file->messages[i].level,
            log_file->messages[i].tag,
            log_file->messages[i].message);
    }
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the user specified a log file
    if (argc < 2) {
        printf("Usage: %s <log file>\n", argv[0]);
        return -1;
    }

    // Create a log file
    LogFile *log_file = create_log_file(argv[1]);
    if (log_file == NULL) {
        perror("Error opening log file");
        return -1;
    }

    // Read the log lines from the file
    char *line;
    while ((line = read_line_from_log_file(log_file)) != NULL) {
        // Parse the log timestamp
        char *timestamp;
        if (parse_log_line(line, LOG_TIMESTAMP_PATTERN, &timestamp) != 0) {
            perror("Error parsing log timestamp");
            return -1;
        }

        // Parse the log level
        char *level;
        if (parse_log_line(line, LOG_LEVEL_PATTERN, &level) != 0) {
            perror("Error parsing log level");
            return -1;
        }

        // Parse the log tag
        char *tag;
        if (parse_log_line(line, LOG_TAG_PATTERN, &tag) != 0) {
            perror("Error parsing log tag");
            return -1;
        }

        // Parse the log message
        char *message;
        if (parse_log_line(line, LOG_MESSAGE_PATTERN, &message) != 0) {
            perror("Error parsing log message");
            return -1;
        }

        // Create a log message
        LogMessage log_message;
        log_message.timestamp = timestamp;
        log_message.level = level;
        log_message.tag = tag;
        log_message.message = message;

        // Add the log message to the log file
        add_log_message_to_log_file(log_file, &log_message);
    }

    // Print the log messages
    print_log_messages(log_file);

    // Close the log file
    close_log_file(log_file);

    return 0;
}
//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define constants for log formats
#define FORMAT_TEXT 1
#define FORMAT_JSON 2
#define FORMAT_XML 3

// Function prototypes
void log_event(int format, const char *message);
void get_current_time(char *buffer, size_t size);

// Main function
int main(int argc, char *argv[]) {
    int log_format = FORMAT_TEXT; // Default format
    char log_message[256];

    // Check for command-line argument to set log format
    if (argc > 1) {
        if (strcmp(argv[1], "json") == 0) {
            log_format = FORMAT_JSON;
        } else if (strcmp(argv[1], "xml") == 0) {
            log_format = FORMAT_XML;
        }
    }

    printf("Enter log messages (Type 'exit' to quit):\n");

    while (1) {
        printf("> ");
        fgets(log_message, sizeof(log_message), stdin);
        log_message[strcspn(log_message, "\n")] = 0; // Remove newline

        if (strcmp(log_message, "exit") == 0) {
            break;
        }

        log_event(log_format, log_message);
    }

    return 0;
}

// Function to log events based on the selected format
void log_event(int format, const char *message) {
    // Get the current time as a string
    char time_buffer[20];
    get_current_time(time_buffer, sizeof(time_buffer));

    // Open log file
    FILE *log_file = fopen("event_log.txt", "a");
    if (!log_file) {
        perror("Unable to open log file");
        return;
    }

    // Switch to determine logging format
    switch (format) {
        case FORMAT_JSON:
            fprintf(log_file, "{\"timestamp\": \"%s\", \"event\": \"%s\"}\n", time_buffer, message);
            break;
        case FORMAT_XML:
            fprintf(log_file, "<event>\n\t<timestamp>%s</timestamp>\n\t<message>%s</message>\n</event>\n", time_buffer, message);
            break;
        case FORMAT_TEXT:
        default:
            fprintf(log_file, "[%s] %s\n", time_buffer, message);
            break;
    }

    fclose(log_file);
}

// Function to get the current time as a string
void get_current_time(char *buffer, size_t size) {
    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);
    strftime(buffer, size, "%Y-%m-%d %H:%M:%S", tm_info);
}
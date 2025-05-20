//GPT-4o-mini DATASET v1.0 Category: Browser Plugin ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

#define LOG_FILE "traffic_log.txt"
#define BUFFER_SIZE 1024

FILE *log_file;

// Function to handle logging requests and responses
void log_traffic(const char *message) {
    time_t now;
    time(&now);
    char *time_str = ctime(&now);
    time_str[strlen(time_str) - 1] = '\0';  // removing newline character
    fprintf(log_file, "[%s] %s\n", time_str, message);
    fflush(log_file);
}

// Signal handler to gracefully close the log file on exit
void signal_handler(int signum) {
    if (log_file != NULL) {
        fclose(log_file);
    }
    exit(signum);
}

int main() {
    char input_buffer[BUFFER_SIZE];
    
    // Open the log file for appending
    log_file = fopen(LOG_FILE, "a");
    if (log_file == NULL) {
        perror("Error opening log file");
        return EXIT_FAILURE;
    }
    
    // Setting up signal handling for cleanup on termination
    signal(SIGINT, signal_handler);
    signal(SIGTERM, signal_handler);

    // Simulated HTTP traffic logging
    printf("Starting Traffic Logger Plugin. Press Ctrl+C to exit.\n");

    while (1) {
        printf("Enter HTTP Request/Response (or type 'exit' to quit): ");
        if (fgets(input_buffer, BUFFER_SIZE, stdin) != NULL) {
            // Remove newline character from input
            input_buffer[strcspn(input_buffer, "\n")] = 0;

            if (strcmp(input_buffer, "exit") == 0) {
                break;
            }

            // Log the traffic
            log_traffic(input_buffer);
            printf("Logged: %s\n", input_buffer);
        }
    }

    // Cleanup
    if (log_file != NULL) {
        fclose(log_file);
    }
    
    printf("Traffic Logger stopped.\n");
    return EXIT_SUCCESS;
}
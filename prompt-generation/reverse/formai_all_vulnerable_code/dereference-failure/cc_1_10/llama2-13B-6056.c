//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_LOG_LEN 1024
#define MAX_LOG_FILES 10

struct log_entry {
    char timestamp[20];
    char client_ip[15];
    char request_method[10];
    char request_uri[100];
    char response_code[3];
    char response_reason[100];
};

int main(int argc, char *argv[]) {
    // Initialize log file names
    char *log_files[MAX_LOG_FILES];
    for (int i = 0; i < MAX_LOG_FILES; i++) {
        log_files[i] = malloc(20 * sizeof(char));
        snprintf(log_files[i], 20, "access.log.%d", i);
    }

    // Initialize log entry struct
    struct log_entry current_entry;

    // Set up log file descriptors
    int log_fd[MAX_LOG_FILES];
    for (int i = 0; i < MAX_LOG_FILES; i++) {
        log_fd[i] = open(log_files[i], O_WRONLY | O_APPEND | O_CREAT, 0644);
        if (log_fd[i] == -1) {
            perror("Error opening log file");
            exit(EXIT_FAILURE);
        }
    }

    // Set up log parsing loop
    while (1) {
        // Read log entry from current log file
        char buffer[1024];
        ssize_t read_size = read(log_fd[0], buffer, sizeof(buffer));
        if (read_size == -1) {
            perror("Error reading from log file");
            exit(EXIT_FAILURE);
        }

        // Parse log entry
        char *token;
        char *timestamp = strtok(buffer, " ");
        char *client_ip = strtok(NULL, " ");
        char *request_method = strtok(NULL, " ");
        char *request_uri = strtok(NULL, " ");
        char *response_code = strtok(NULL, " ");
        char *response_reason = strtok(NULL, "\n");

        // Update current entry with parsed log entry
        strcpy(current_entry.timestamp, timestamp);
        strcpy(current_entry.client_ip, client_ip);
        strcpy(current_entry.request_method, request_method);
        strcpy(current_entry.request_uri, request_uri);
        strcpy(current_entry.response_code, response_code);
        strcpy(current_entry.response_reason, response_reason);

        // Check if next log file is empty
        if (feof(log_fd[0]) == 0) {
            // No, not empty, move to next file
            int next_file = (log_fd[0] + 1) % MAX_LOG_FILES;
            if (next_file == 0) {
                // Wrap around to first file
                next_file = MAX_LOG_FILES - 1;
            }
            close(log_fd[0]);
            log_fd[0] = open(log_files[next_file], O_WRONLY | O_APPEND | O_CREAT, 0644);
            if (log_fd[0] == -1) {
                perror("Error opening log file");
                exit(EXIT_FAILURE);
            }
        } else {
            // Yes, empty, exit
            break;
        }
    }

    // Clean up
    for (int i = 0; i < MAX_LOG_FILES; i++) {
        close(log_fd[i]);
    }

    return 0;
}
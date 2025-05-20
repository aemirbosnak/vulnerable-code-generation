//GPT-4o-mini DATASET v1.0 Category: Intrusion detection system ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

#define LOG_FILE "intrusion_log.txt"
#define BUFFER_SIZE 1024
#define ALLOWED_COMMANDS_SIZE 5

// Function prototypes
void log_intrusion(const char *message);
int is_command_allowed(const char *command);
void monitor_commands();

const char *allowed_commands[ALLOWED_COMMANDS_SIZE] = {
    "ls", "pwd", "whoami", "echo", "cat"
};

int main() {
    printf("Starting Intrusion Detection System...\n");

    // Monitoring commands in an infinite loop
    monitor_commands();

    return 0;
}

void log_intrusion(const char *message) {
    FILE *file = fopen(LOG_FILE, "a");
    if (file == NULL) {
        perror("Could not open log file");
        return;
    }

    // Get current time
    time_t now = time(NULL);
    char *time_str = ctime(&now);
    // Remove newline character from ctime result
    time_str[strlen(time_str) - 1] = '\0';

    // Log the intrusion message with timestamp
    fprintf(file, "[%s] %s\n", time_str, message);
    fclose(file);
}

int is_command_allowed(const char *command) {
    for (int i = 0; i < ALLOWED_COMMANDS_SIZE; i++) {
        if (strcmp(command, allowed_commands[i]) == 0) {
            return 1; // Command is allowed
        }
    }
    return 0; // Command is not allowed
}

void monitor_commands() {
    char command[BUFFER_SIZE];
    
    printf("Please enter the command to execute (type 'exit' to quit):\n");

    while (1) {
        printf("> ");
        if (fgets(command, sizeof(command), stdin) == NULL) {
            printf("Error reading command.\n");
            continue;
        }

        // Remove newline character from command input
        command[strcspn(command, "\n")] = 0;

        // Exit condition
        if (strcmp(command, "exit") == 0) {
            printf("Exiting Intrusion Detection System.\n");
            break;
        }

        // Check if the command is allowed
        if (!is_command_allowed(command)) {
            printf("Alert: Attempted to execute non-allowed command: %s\n", command);
            log_intrusion(command);
        } else {
            printf("Executing allowed command: %s\n", command);
            int result = system(command);
            if (result == -1) {
                perror("Command execution failed");
            }
        }
    }
}
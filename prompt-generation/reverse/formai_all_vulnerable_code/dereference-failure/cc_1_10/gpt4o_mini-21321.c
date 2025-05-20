//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MAX_BUFFER 256
#define PORT 8080

typedef enum {
    CONSOLE_LOG,
    FILE_LOG,
    NETWORK_LOG
} LogMode;

typedef struct {
    LogMode mode;
    FILE *file;
    int sock;
    struct sockaddr_in server_addr;
} EventLogger;

// Function to initialize the event logger
void init_logger(EventLogger *logger, LogMode mode, const char *filename) {
    logger->mode = mode;

    if (mode == FILE_LOG) {
        logger->file = fopen(filename, "a");
        if (logger->file == NULL) {
            perror("Failed to open log file");
            exit(EXIT_FAILURE);
        }
    } else if (mode == NETWORK_LOG) {
        logger->sock = socket(AF_INET, SOCK_DGRAM, 0);
        if (logger->sock < 0) {
            perror("Socket creation failed");
            exit(EXIT_FAILURE);
        }

        logger->server_addr.sin_family = AF_INET;
        logger->server_addr.sin_port = htons(PORT);
        logger->server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    }
}

// Function to log an event
void log_event(EventLogger *logger, const char *event) {
    time_t now = time(NULL);
    char *time_str = ctime(&now);
    time_str[strlen(time_str) - 1] = '\0'; // Remove newline

    char log_entry[MAX_BUFFER];
    snprintf(log_entry, sizeof(log_entry), "[%s] %s\n", time_str, event);

    switch (logger->mode) {
        case CONSOLE_LOG:
            printf("%s", log_entry);
            break;
        case FILE_LOG:
            fprintf(logger->file, "%s", log_entry);
            fflush(logger->file);
            break;
        case NETWORK_LOG:
            sendto(logger->sock, log_entry, strlen(log_entry), 0,
                   (struct sockaddr*)&logger->server_addr, sizeof(logger->server_addr));
            break;
        default:
            fprintf(stderr, "Unknown log mode\n");
            exit(EXIT_FAILURE);
    }
}

// Clean up the logger resources
void cleanup_logger(EventLogger *logger) {
    if (logger->mode == FILE_LOG) {
        fclose(logger->file);
    } else if (logger->mode == NETWORK_LOG) {
        close(logger->sock);
    }
}

// Function to switch logging modes
void switch_mode(EventLogger *logger, LogMode new_mode, const char *filename) {
    cleanup_logger(logger);
    init_logger(logger, new_mode, filename);
}

int main() {
    EventLogger logger;
    char command[MAX_BUFFER];

    // Initialize logger in console mode
    init_logger(&logger, CONSOLE_LOG, NULL);
    
    while (1) {
        printf("Enter a log event (or type 'exit' to quit, 'switch' to change mode): ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0; // Remove newline

        if (strcmp(command, "exit") == 0) {
            break;
        } else if (strcmp(command, "switch") == 0) {
            int mode;
            printf("Select log mode (0: Console, 1: File, 2: Network): ");
            scanf("%d", &mode);
            getchar(); // To consume the newline
            if (mode == 1) {
                switch_mode(&logger, FILE_LOG, "events.log");
            } else if (mode == 2) {
                switch_mode(&logger, NETWORK_LOG, NULL);
            } else {
                switch_mode(&logger, CONSOLE_LOG, NULL);
            }
        } else {
            log_event(&logger, command);
        }
    }

    cleanup_logger(&logger);
    return 0;
}
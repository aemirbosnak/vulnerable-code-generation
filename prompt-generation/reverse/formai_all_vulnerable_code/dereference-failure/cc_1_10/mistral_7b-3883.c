//MISTRAL-7B DATASET v1.0 Category: System event logger ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LOG_ENTRIES 100
#define LOG_FILE "event_logger.log"

typedef struct {
    time_t timestamp;
    char message[1024];
} LogEntry;

void log_message(const char *message) {
    FILE *log_file = fopen(LOG_FILE, "a");
    LogEntry entry;
    time_t current_time;

    if (log_file == NULL) {
        perror("Error opening log file");
        return;
    }

    time(&current_time);
    entry.timestamp = current_time;

    strcpy(entry.message, message);
    strcat(entry.message, " [");
    strcat(entry.message, ctime(&current_time));
    strcat(entry.message, "]");

    fwrite(&entry, sizeof(LogEntry), 1, log_file);
    fclose(log_file);

    printf("%s\n", entry.message);
}

int main(int argc, char *argv[]) {
    int i;

    if (argc > 1) {
        for (i = 1; i < argc; i++) {
            log_message(argv[i]);
        }
    } else {
        log_message("No arguments provided");
    }

    return EXIT_SUCCESS;
}
//Falcon-180B DATASET v1.0 Category: System event logger ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define LOG_FILE "event_log.txt"
#define MAX_LOG_SIZE (1024 * 1024 * 10) // 10 MB
#define EVENT_TIMESTAMP_FORMAT "%Y-%m-%d %H:%M:%S"
#define EVENT_LOG_FORMAT "%s %s\n"

typedef struct {
    char event[256];
    time_t timestamp;
} Event;

static FILE *logFile = NULL;
static size_t logSize = 0;

static void initLogFile() {
    logFile = fopen(LOG_FILE, "a");
    if (!logFile) {
        fprintf(stderr, "Error: Failed to open log file.\n");
        exit(EXIT_FAILURE);
    }
    logSize = 0;
}

static void logEvent(const char *event) {
    if (logSize >= MAX_LOG_SIZE) {
        fprintf(stderr, "Warning: Log file reached maximum size. Truncating...\n");
        fclose(logFile);
        initLogFile();
    }

    time_t now = time(NULL);
    struct tm tm = *localtime(&now);
    strftime(event + strlen(event), 32, EVENT_TIMESTAMP_FORMAT, &tm);

    fprintf(logFile, EVENT_LOG_FORMAT, event, event + strlen(event));
    logSize += strlen(event) + 1;
}

int main(int argc, char *argv[]) {
    initLogFile();

    while (true) {
        char input[256];
        printf("Enter an event to log: ");
        fgets(input, sizeof(input), stdin);

        if (strlen(input) > 0 && input[strlen(input) - 1] == '\n') {
            input[strlen(input) - 1] = '\0';
        }

        logEvent(input);
    }

    return 0;
}
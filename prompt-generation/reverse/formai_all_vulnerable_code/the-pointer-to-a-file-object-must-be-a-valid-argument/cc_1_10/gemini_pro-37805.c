//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define MAX_LOG_LINE_LENGTH 1024
#define MAX_LOG_LINES 1000

typedef struct {
    time_t timestamp;
    char *message;
} LogEntry;

static LogEntry *log_entries[MAX_LOG_LINES];
static int num_log_entries = 0;

static const char *log_filename = "log.txt";

static void add_log_entry(time_t timestamp, const char *message);
static void print_log_entries(void);
static void clear_log_entries(void);
static int compare_log_entries(const void *a, const void *b);

int main(int argc, char **argv) {
    int fd;
    char buffer[MAX_LOG_LINE_LENGTH];
    char *line;
    time_t timestamp;
    char *message;

    fd = open(log_filename, O_RDONLY);
    if (fd == -1) {
        perror("open");
        return EXIT_FAILURE;
    }

    while (fgets(buffer, MAX_LOG_LINE_LENGTH, fd) != NULL) {
        line = strtok(buffer, "\n");
        if (line == NULL) {
            continue;
        }

        timestamp = strtol(line, &line, 10);
        if (timestamp == 0) {
            continue;
        }

        message = line;
        if (message == NULL) {
            continue;
        }

        add_log_entry(timestamp, message);
    }

    close(fd);

    qsort(log_entries, num_log_entries, sizeof(LogEntry *), compare_log_entries);

    print_log_entries();

    clear_log_entries();

    return EXIT_SUCCESS;
}

static void add_log_entry(time_t timestamp, const char *message) {
    LogEntry *log_entry;

    if (num_log_entries >= MAX_LOG_LINES) {
        return;
    }

    log_entry = malloc(sizeof(LogEntry));
    if (log_entry == NULL) {
        return;
    }

    log_entry->timestamp = timestamp;
    log_entry->message = strdup(message);
    if (log_entry->message == NULL) {
        free(log_entry);
        return;
    }

    log_entries[num_log_entries++] = log_entry;
}

static void print_log_entries(void) {
    int i;

    for (i = 0; i < num_log_entries; i++) {
        printf("%ld %s", log_entries[i]->timestamp, log_entries[i]->message);
    }
}

static void clear_log_entries(void) {
    int i;

    for (i = 0; i < num_log_entries; i++) {
        free(log_entries[i]->message);
        free(log_entries[i]);
    }

    num_log_entries = 0;
}

static int compare_log_entries(const void *a, const void *b) {
    LogEntry *log_entry_a = *(LogEntry **)a;
    LogEntry *log_entry_b = *(LogEntry **)b;

    return log_entry_a->timestamp - log_entry_b->timestamp;
}
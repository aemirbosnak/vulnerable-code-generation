//GEMINI-pro DATASET v1.0 Category: System event logger ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <time.h>
#include <string.h>
#include <errno.h>

typedef struct {
    uint32_t code;
    uint32_t size;
    uint64_t timestamp;
    uint8_t  data[];
} log_entry_t;

typedef struct {
    FILE *file;
    uint32_t index;
    uint64_t timestamp;
} log_t;

static int log_open(log_t *log, const char *path)
{
    log->file = fopen(path, "w");
    if (log->file == NULL)
        return -1;
    log->index = 0;
    log->timestamp = time(NULL);
    return 0;
}

static void log_close(log_t *log)
{
    fclose(log->file);
}

static int log_write(log_t *log, log_entry_t *entry)
{
    size_t size = sizeof(*entry) + entry->size;
    if (fwrite(entry, size, 1, log->file) != 1)
        return -1;
    log->index++;
    log->timestamp = time(NULL);
    return 0;
}

int main(int argc, char **argv)
{
    log_t log;
    log_entry_t entry;

    if (argc < 2) {
        printf("Usage: %s <log file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (log_open(&log, argv[1]) == -1) {
        perror("log_open");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < 100; i++) {
        entry.code = i;
        entry.size = strlen("Hello world!");
        entry.timestamp = time(NULL);
        strcpy((char *)entry.data, "Hello world!");
        if (log_write(&log, &entry) == -1) {
            perror("log_write");
            return EXIT_FAILURE;
        }
    }

    log_close(&log);

    return EXIT_SUCCESS;
}
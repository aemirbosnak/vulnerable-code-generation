//GEMINI-pro DATASET v1.0 Category: System event logger ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <time.h>
#include <errno.h>
#include <string.h>
#include <syslog.h>

#define MAX_EVENT_SIZE 1024

struct event_log {
    time_t timestamp;
    int level;
    const char *message;
};

static FILE *log_file = NULL;

void open_log(const char *filename)
{
    log_file = fopen(filename, "a");
    if (log_file == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }
}

void close_log(void)
{
    if (log_file != NULL) {
        fclose(log_file);
        log_file = NULL;
    }
}

void log_event(int level, const char *format, ...)
{
    struct event_log event;

    va_list args;
    va_start(args, format);
    vasprintf(&event.message, format, args);
    va_end(args);

    event.timestamp = time(NULL);
    event.level = level;

    if (log_file != NULL) {
        fprintf(log_file, "%ld %d %s\n", event.timestamp, event.level, event.message);
    } else {
        syslog(level, "%s", event.message);
    }

    free((void *)event.message);
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <log file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    open_log(argv[1]);

    log_event(LOG_INFO, "Program started");

    log_event(LOG_WARNING, "Error occurred: %s", strerror(errno));

    log_event(LOG_ERR, "Critical error: %s", strerror(errno));

    log_event(LOG_NOTICE, "Program ended");

    close_log();

    return EXIT_SUCCESS;
}
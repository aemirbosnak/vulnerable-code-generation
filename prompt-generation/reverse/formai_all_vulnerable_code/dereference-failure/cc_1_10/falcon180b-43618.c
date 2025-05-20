//Falcon-180B DATASET v1.0 Category: System event logger ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <syslog.h>
#include <errno.h>

#define LOG_FILE "/var/log/syslog"
#define LOG_PRIORITY LOG_ERR
#define LOG_TAG "EVENT_LOGGER"

#define MAX_EVENT_LENGTH 4096

typedef struct {
    char event_type[64];
    char event_message[MAX_EVENT_LENGTH];
    time_t event_time;
} Event;

void log_event(Event* event) {
    syslog(LOG_PRIORITY, "[%s] %s", event->event_type, event->event_message);
}

void write_to_log(Event* event) {
    FILE* log_file = fopen(LOG_FILE, "a");
    if (log_file == NULL) {
        fprintf(stderr, "Error opening log file: %s\n", strerror(errno));
        exit(1);
    }

    fprintf(log_file, "[%s] %s\n", event->event_type, event->event_message);
    fclose(log_file);
}

int main() {
    openlog(LOG_TAG, LOG_PRIORITY, LOG_USER);

    Event event = {
       .event_type = "SYSTEM_EVENT",
       .event_message = "System started",
       .event_time = time(NULL)
    };

    log_event(&event);
    write_to_log(&event);

    closelog();

    return 0;
}
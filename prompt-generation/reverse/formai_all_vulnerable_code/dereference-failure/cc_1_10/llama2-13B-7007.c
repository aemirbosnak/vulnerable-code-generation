//LLAMA2-13B DATASET v1.0 Category: System event logger ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define EVENT_LOG_MAX_LENGTH 1024
#define EVENT_LOG_FILE "event_log.txt"

typedef struct {
    char *message;
    int timestamp;
} event_t;

event_t *event_log = NULL;
int event_log_size = 0;

void event_log_init() {
    event_log = (event_t *)calloc(1, sizeof(event_t));
    event_log_size = 1;
}

void event_log_add(const char *message) {
    event_t *new_event = (event_t *)calloc(1, sizeof(event_t));
    new_event->message = message;
    new_event->timestamp = time(NULL);
    if (event_log_size == 0) {
        event_log = new_event;
    } else {
        event_log = realloc(event_log, (event_log_size + 1) * sizeof(event_t));
        event_log[event_log_size - 1] = *new_event;
    }
    event_log_size++;
}

void event_log_clear() {
    free(event_log);
    event_log = NULL;
    event_log_size = 0;
}

void event_log_print() {
    if (event_log_size == 0) {
        printf("Event log is empty.\n");
        return;
    }
    printf("Event log contents (most recent first):\n");
    for (int i = 0; i < event_log_size; i++) {
        printf("%d: %s\n", event_log[i].timestamp, event_log[i].message);
    }
}

int main() {
    event_log_init();
    char *messages[] = {"Hello, world!", "This is a test message.", "This is another test message."};
    int i;
    for (i = 0; i < sizeof(messages) / sizeof(char *); i++) {
        event_log_add(messages[i]);
    }
    event_log_print();
    event_log_clear();
    return 0;
}
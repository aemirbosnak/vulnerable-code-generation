//LLAMA2-13B DATASET v1.0 Category: System event logger ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <syslog.h>

#define MAX_LOG_LEN 1024
#define MAX_EVENTS 100

typedef struct {
    char *name;
    char *message;
    time_t timestamp;
} event_t;

static int event_queue[MAX_EVENTS];
static int event_head = 0;
static int event_tail = 0;

void enqueue_event(char *name, char *message) {
    event_t *event = malloc(sizeof(event_t));
    event->name = name;
    event->message = message;
    event->timestamp = time(NULL);
    if (event_head == MAX_EVENTS) {
        printf("Event queue is full, dropping old event\n");
        // drop the oldest event
        event_queue[0] = event;
        event_head = 1;
    } else {
        event_queue[event_head] = event;
        event_head++;
    }
}

void dequeue_event(void) {
    if (event_tail == event_head) {
        printf("Event queue is empty\n");
        return;
    }
    event_t *event = event_queue[event_tail];
    event_tail++;
    if (event_tail == MAX_EVENTS) {
        event_tail = 0;
    }
    printf("Event: %s %s\n", event->name, event->message);
}

int main(void) {
    setvbuf(stdout, NULL, _IONBF, 0);

    char *event_names[] = {"Event 1", "Event 2", "Event 3"};
    char *event_messages[] = {"This is the first event", "This is the second event", "This is the third event"};
    int i;

    for (i = 0; i < sizeof(event_names) / sizeof(char *); i++) {
        enqueue_event(event_names[i], event_messages[i]);
    }

    while (1) {
        dequeue_event();
    }

    return 0;
}
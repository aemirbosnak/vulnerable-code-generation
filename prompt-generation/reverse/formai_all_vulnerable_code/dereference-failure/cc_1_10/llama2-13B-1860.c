//LLAMA2-13B DATASET v1.0 Category: System event logger ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/syscall.h>
#include <unistd.h>

#define MAX_EVENTS 1000
#define MAX_LENGTH 256

struct event {
    int type;
    char name[MAX_LENGTH];
    char description[MAX_LENGTH];
    int timestamp;
};

static int events[MAX_EVENTS];
static int head = 0;
static int tail = 0;

void log_event(int type, char *name, char *description) {
    struct event *e = (struct event *) malloc(sizeof(struct event));
    e->type = type;
    strcpy(e->name, name);
    strcpy(e->description, description);
    e->timestamp = time(NULL);
    if (head == MAX_EVENTS) {
        tail++;
        if (tail == MAX_EVENTS) {
            tail = 0;
        }
    }
    events[head] = e;
    head++;
}

void print_events() {
    int i;
    for (i = tail; i != head; i++) {
        struct event *e = events[i];
        printf("[%d] %s (%s) at %d\n", e->timestamp, e->name, e->description, e->type);
    }
}

int main() {
    log_event(1, "login", "User logged in");
    log_event(2, "logout", "User logged out");
    log_event(3, "error", "Error occurred");
    log_event(4, "warning", "Warning message");
    log_event(5, "info", "Informational message");
    print_events();
    return 0;
}
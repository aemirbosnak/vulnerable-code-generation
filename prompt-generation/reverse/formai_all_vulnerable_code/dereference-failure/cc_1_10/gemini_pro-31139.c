//GEMINI-pro DATASET v1.0 Category: System event logger ; Style: Donald Knuth
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define EVENTLOGGER_MAX_SIZE 256
#define EVENTLOGGER_MAX_ENTRIES 100

typedef struct event {
    char *message;
    unsigned int timestamp;
} event_t;

typedef struct eventlogger {
    event_t events[EVENTLOGGER_MAX_ENTRIES];
    unsigned int head;
    unsigned int tail;
    unsigned int size;
} eventlogger_t;

eventlogger_t *eventlogger_create() {
    eventlogger_t *logger = malloc(sizeof(eventlogger_t));
    if (logger == NULL) {
        return NULL;
    }

    logger->head = 0;
    logger->tail = 0;
    logger->size = 0;

    return logger;
}

void eventlogger_destroy(eventlogger_t *logger) {
    for (unsigned int i = 0; i < logger->size; i++) {
        free(logger->events[i].message);
    }

    free(logger);
}

bool eventlogger_add(eventlogger_t *logger, char *message) {
    if (logger->size == EVENTLOGGER_MAX_ENTRIES) {
        return false;
    }

    logger->events[logger->head].message = malloc(strlen(message) + 1);
    if (logger->events[logger->head].message == NULL) {
        return false;
    }

    strcpy(logger->events[logger->head].message, message);
    logger->events[logger->head].timestamp = time(NULL);

    logger->head = (logger->head + 1) % EVENTLOGGER_MAX_ENTRIES;
    logger->size++;

    return true;
}

char *eventlogger_get(eventlogger_t *logger, unsigned int index) {
    if (index >= logger->size) {
        return NULL;
    }

    unsigned int i = (logger->tail + index) % EVENTLOGGER_MAX_ENTRIES;

    return logger->events[i].message;
}

unsigned int eventlogger_size(eventlogger_t *logger) {
    return logger->size;
}

void eventlogger_print(eventlogger_t *logger) {
    for (unsigned int i = 0; i < logger->size; i++) {
        printf("%s\n", logger->events[i].message);
    }
}

int main() {
    eventlogger_t *logger = eventlogger_create();

    eventlogger_add(logger, "Event 1");
    eventlogger_add(logger, "Event 2");
    eventlogger_add(logger, "Event 3");

    eventlogger_print(logger);

    eventlogger_destroy(logger);

    return 0;
}
//Falcon-180B DATASET v1.0 Category: System event logger ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024
#define MAX_EVENTS 10000

typedef struct {
    char *event;
    time_t timestamp;
} Event;

int main(int argc, char *argv[]) {
    int fd;
    char buffer[BUFFER_SIZE];
    Event *events = (Event *)malloc(MAX_EVENTS * sizeof(Event));
    int num_events = 0;
    int i;

    if (argc!= 2) {
        printf("Usage: %s <log_file>\n", argv[0]);
        exit(1);
    }

    if ((fd = open(argv[1], O_RDONLY)) == -1) {
        printf("Error: Could not open log file.\n");
        exit(1);
    }

    while ((num_events < MAX_EVENTS) && (fgets(buffer, BUFFER_SIZE, fd)!= NULL)) {
        Event *new_event = (Event *)malloc(sizeof(Event));
        strcpy(new_event->event, buffer);
        new_event->timestamp = time(NULL);
        events[num_events++] = *new_event;
    }

    close(fd);

    printf("Log file events:\n");
    for (i = 0; i < num_events; i++) {
        printf("%s - %s\n", events[i].event, ctime(&events[i].timestamp));
    }

    free(events);
    return 0;
}
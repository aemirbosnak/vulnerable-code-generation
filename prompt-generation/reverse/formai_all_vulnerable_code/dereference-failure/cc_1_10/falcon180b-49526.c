//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_EVENTS 1000

typedef struct {
    char ip[16];
    char date[32];
    char time[8];
    char request[MAX_LINE_LENGTH];
    char status[10];
    char bytes[20];
} log_event;

int num_events = 0;
log_event events[MAX_NUM_EVENTS];

void add_event(const char* line) {
    if (num_events >= MAX_NUM_EVENTS) {
        fprintf(stderr, "Error: Maximum number of events reached.\n");
        exit(1);
    }

    char* token = strtok(line, " ");
    strcpy(events[num_events].ip, token);

    token = strtok(NULL, " ");
    strcpy(events[num_events].date, token);

    token = strtok(NULL, " ");
    strcpy(events[num_events].time, token);

    token = strtok(NULL, " ");
    strcpy(events[num_events].request, token);

    token = strtok(NULL, " ");
    strcpy(events[num_events].status, token);

    token = strtok(NULL, " ");
    strcpy(events[num_events].bytes, token);

    num_events++;
}

void print_events() {
    printf("IP\tDate\tTime\tRequest\tStatus\tBytes\n");

    for (int i = 0; i < num_events; i++) {
        printf("%s\t%s\t%s\t%s\t%s\t%s\n", events[i].ip, events[i].date, events[i].time, events[i].request, events[i].status, events[i].bytes);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Error: No log file specified.\n");
        exit(1);
    }

    FILE* log_file = fopen(argv[1], "r");

    if (log_file == NULL) {
        fprintf(stderr, "Error: Could not open log file.\n");
        exit(1);
    }

    char line[MAX_LINE_LENGTH];

    while (fgets(line, MAX_LINE_LENGTH, log_file)!= NULL) {
        add_event(line);
    }

    fclose(log_file);

    print_events();

    return 0;
}
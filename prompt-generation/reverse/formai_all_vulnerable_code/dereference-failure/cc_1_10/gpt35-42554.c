//FormAI DATASET v1.0 Category: System event logger ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Event {
    char* time;
    char* source;
    char* message;
};

void logEvent(struct Event e) {
    FILE* fp = fopen("event_log.txt", "a");
    fprintf(fp, "%s - [%s] %s\n", e.time, e.source, e.message);
    fclose(fp);
}

int main() {

    printf("Event Logger System\n\n");

    // get source
    printf("Enter event source: ");
    char source[100];
    scanf("%s", source);

    // loop through events
    int num_events;
    printf("How many events do you want to log? ");
    scanf("%d", &num_events);

    for (int i = 0; i < num_events; i++) {

        // get message
        printf("Enter event message: ");
        char message[100];
        scanf("%s", message);

        // get current time
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        char time[20];
        sprintf(time, "%d-%02d-%02d %02d:%02d:%02d",
                tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,
                tm.tm_hour, tm.tm_min, tm.tm_sec);

        // create event object
        struct Event e;
        e.time = time;
        e.source = source;
        e.message = message;

        // log event
        logEvent(e);

        printf("Event logged!\n");
    }

    return 0;
}
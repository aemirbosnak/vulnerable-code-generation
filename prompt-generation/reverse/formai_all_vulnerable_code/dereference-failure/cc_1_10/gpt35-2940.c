//FormAI DATASET v1.0 Category: System event logger ; Style: paranoid
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct {
    char event_name[20];
    char date[20];
    char time[20];
} Event;

Event *event_list = NULL; // Global pointer

void log_event(char *event_name) {
    Event event;
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    sprintf(event.event_name, "%s", event_name);
    sprintf(event.date, "%d-%d-%d", tm->tm_year+1900, tm->tm_mon+1, tm->tm_mday);
    sprintf(event.time, "%d:%d:%d", tm->tm_hour, tm->tm_min, tm->tm_sec);

    if (event_list == NULL) {
        event_list = (Event*)malloc(sizeof(Event)); // Allocate memory for first event
        *event_list = event;
        printf("Event logged: %s\n", event_list->event_name);
    } else {
        int i = 0;
        while(event_list[i].event_name != NULL) { // Find the end of the event list
            i++;
        }
        event_list = (Event*)realloc(event_list, sizeof(Event)*(i+1)); // Allocate memory for the next event
        event_list[i] = event;
        printf("Event logged: %s\n", event_list[i].event_name);
    }
}

void print_event_log() {
    if (event_list == NULL) {
        printf("No events logged!\n");
    } else {
        printf("Event log:\n");
        int i = 0;
        while(event_list[i].event_name != NULL) {
            printf("%s - Date: %s, Time: %s\n", event_list[i].event_name, event_list[i].date, event_list[i].time);
            i++;
        }
    }
}

int main() {
    char event1[] = "System startup";
    char event2[] = "User logged in as Admin";
    char event3[] = "Access denied for user 'hacker'";
    char event4[] = "Administrator privileges revoked";

    log_event(event1);
    log_event(event2);
    log_event(event3);
    log_event(event4);
    print_event_log();

    return 0;
}
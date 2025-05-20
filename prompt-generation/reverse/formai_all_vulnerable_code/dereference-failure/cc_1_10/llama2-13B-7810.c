//LLAMA2-13B DATASET v1.0 Category: System event logger ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <syslog.h>
#include <unistd.h>
#include <time.h>

#define MAX_EVENT_LEN 1024
#define MAX_SURPRISE_LEN 256

struct event {
    char *message;
    int severity;
};

void surprise(const char *message) {
    char *surprise = "OH MY GOSH!";
    if (strcmp(message, "LOGGED") == 0) {
        surprise = "YOU GOT ME!";
    } else if (strcmp(message, "LOGGED AGAIN") == 0) {
        surprise = "WOW, TWICE IN A ROW!";
    } else {
        surprise = "HOLY COW, THIS IS UNEXPECTED!";
    }
    printf("%s\n", surprise);
}

int main() {
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);

    while (1) {
        struct event event;
        char message[MAX_EVENT_LEN];

        // Read input from standard input
        fgets(message, MAX_EVENT_LEN, stdin);

        // Parse input and extract message and severity
        char *token = strtok(message, " ");
        int severity = atoi(token);
        token = strtok(NULL, " ");
        char *message_ptr = message;

        // Create event structure and log event to system log
        event.message = message_ptr;
        event.severity = severity;
        syslog(severity, "%s", message_ptr);

        // Surprise the user with a fun and unexpected message
        surprise(message_ptr);
    }

    return 0;
}
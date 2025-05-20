//Falcon2-11B DATASET v1.0 Category: System event logger ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>

#define BUF_SIZE 1024
#define LOG_FILE "/var/log/syslog"

typedef struct {
    int pid;
    char *event_type;
    char *event_message;
    char *hostname;
} Event;

Event events[10];
int num_events = 0;

void log_event(const char *event_type, const char *event_message, const char *hostname) {
    Event *event = &events[num_events];
    event->pid = getpid();
    strcpy(event->event_type, event_type);
    strcpy(event->event_message, event_message);
    strcpy(event->hostname, hostname);
    num_events++;
}

void write_log() {
    int fd = open(LOG_FILE, O_CREAT | O_TRUNC | O_WRONLY, S_IRUSR | S_IWUSR);
    if (fd < 0) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < num_events; i++) {
        printf("%d: %s %s %s\n", events[i].pid, events[i].event_type, events[i].event_message, events[i].hostname);
        write(fd, events[i].event_message, strlen(events[i].event_message));
        write(fd, "\n", 1);
    }

    close(fd);
}

void *log_thread(void *arg) {
    while (1) {
        sleep(1);
        log_event("SYSLOG", "System event occurred", "localhost");
    }
}

int main() {
    pthread_t log_thread_id;

    pthread_create(&log_thread_id, NULL, log_thread, NULL);
    write_log();
    pthread_join(log_thread_id, NULL);

    return 0;
}
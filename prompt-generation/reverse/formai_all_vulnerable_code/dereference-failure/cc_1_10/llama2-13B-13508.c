//LLAMA2-13B DATASET v1.0 Category: System event logger ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>

#define EVENT_LOG_FILE "event_log.txt"
#define MAX_EVENT_LENGTH 1024
#define MAX_EVENT_COUNT 1000

typedef struct {
    char *message;
    time_t timestamp;
} event_t;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

int event_log_fd = -1;

void event_log_init(void) {
    event_log_fd = open(EVENT_LOG_FILE, O_RDWR | O_CREAT, 0644);
    if (event_log_fd == -1) {
        perror("Error opening event log file");
        exit(1);
    }
}

void event_log_write(const char *message) {
    pthread_mutex_lock(&mutex);
    event_t *event = malloc(sizeof(event_t));
    event->message = message;
    event->timestamp = time(NULL);
    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&mutex);
}

void *event_log_thread(void *arg) {
    while (1) {
        pthread_mutex_lock(&mutex);
        while (event_log_fd == -1) {
            pthread_cond_wait(&cond, &mutex);
        }
        pthread_mutex_unlock(&mutex);

        char buffer[MAX_EVENT_LENGTH];
        ssize_t bytes_written = write(event_log_fd, buffer, strlen(buffer));
        if (bytes_written == -1) {
            perror("Error writing to event log");
            exit(1);
        }

        close(event_log_fd);
        event_log_fd = -1;
    }
    return NULL;
}

int main(int argc, char **argv) {
    event_log_init();

    pthread_t log_thread;
    pthread_create(&log_thread, NULL, event_log_thread, NULL);

    sleep(1);

    char message[] = "Hello, world!";
    event_log_write(message);

    sleep(2);

    char message2[] = "This is the second event";
    event_log_write(message2);

    pthread_join(log_thread, NULL);

    return 0;
}
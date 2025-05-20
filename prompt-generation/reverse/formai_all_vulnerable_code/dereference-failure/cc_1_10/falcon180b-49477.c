//Falcon-180B DATASET v1.0 Category: System event logger ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <errno.h>
#include <syslog.h>
#include <pthread.h>

typedef struct {
    int id;
    char *name;
    FILE *file;
} Logger;

void *log_thread(void *arg) {
    Logger *logger = (Logger *) arg;
    char buffer[1024];
    while (1) {
        if (fgets(buffer, sizeof(buffer), logger->file) == NULL) {
            if (ferror(logger->file)) {
                syslog(LOG_ERR, "Error reading log file: %s", strerror(errno));
            }
            break;
        }
        syslog(LOG_INFO, "Log message: %s", buffer);
    }
    return NULL;
}

int main() {
    int i;
    Logger loggers[10];
    pthread_t threads[10];
    for (i = 0; i < 10; i++) {
        loggers[i].id = i;
        loggers[i].name = (char *) malloc(16);
        sprintf(loggers[i].name, "Logger %d", i);
        loggers[i].file = fopen(loggers[i].name, "w");
        if (loggers[i].file == NULL) {
            syslog(LOG_ERR, "Error opening log file: %s", strerror(errno));
            exit(1);
        }
        pthread_create(&threads[i], NULL, log_thread, &loggers[i]);
    }
    while (1) {
        sleep(1);
        time_t now = time(NULL);
        struct tm tm = *localtime(&now);
        char datetime[32];
        strftime(datetime, sizeof(datetime), "%Y-%m-%d %H:%M:%S", &tm);
        syslog(LOG_INFO, "Current date and time: %s", datetime);
    }
    return 0;
}
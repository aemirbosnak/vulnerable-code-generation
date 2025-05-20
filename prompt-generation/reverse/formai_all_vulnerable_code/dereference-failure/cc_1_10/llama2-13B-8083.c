//LLAMA2-13B DATASET v1.0 Category: System event logger ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <syslog.h>

#define MAX_MESSAGE_LENGTH 1024
#define MAX_LOG_FILES 10

typedef struct {
    char date[20];
    char time[20];
    char level[10];
    char message[MAX_MESSAGE_LENGTH];
} log_entry_t;

log_entry_t current_log[MAX_LOG_FILES];
int current_log_index = 0;

void log_init(void) {
    int i;
    for (i = 0; i < MAX_LOG_FILES; i++) {
        current_log[i].date[0] = '\0';
        current_log[i].time[0] = '\0';
        current_log[i].level[0] = '\0';
        current_log[i].message[0] = '\0';
    }
}

void log_write(int level, const char *message) {
    time_t now;
    struct tm *tm;
    char buffer[20];

    now = time(NULL);
    tm = localtime(&now);
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", tm);

    if (level > 0) {
        char *level_string = "DEBUG";
        if (level == 1) {
            level_string = "INFO";
        } else if (level == 2) {
            level_string = "WARNING";
        } else if (level == 3) {
            level_string = "ERROR";
        } else {
            level_string = "FATAL";
        }
        current_log[current_log_index].level[0] = level_string[0];
    } else {
        current_log[current_log_index].level[0] = '0';
    }

    strcpy(current_log[current_log_index].date, buffer);
    strcpy(current_log[current_log_index].time, buffer);
    strcpy(current_log[current_log_index].message, message);

    current_log_index++;

    if (current_log_index >= MAX_LOG_FILES) {
        current_log_index = 0;
    }
}

void log_read(void) {
    int i;
    for (i = 0; i < MAX_LOG_FILES; i++) {
        printf("%s - %s - %s - %s\n", current_log[i].date, current_log[i].time, current_log[i].level, current_log[i].message);
    }
}

int main(void) {
    log_init();

    log_write(1, "Hello, world!");
    log_write(2, "This is a test message");
    log_write(3, "This is an error message");
    log_write(1, "Goodbye, world!");

    log_read();

    return 0;
}
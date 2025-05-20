//Falcon2-11B DATASET v1.0 Category: System event logger ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUF_SIZE 256

typedef struct {
    char log_time[BUF_SIZE];
    char log_message[BUF_SIZE];
} event_log;

void write_to_file(event_log* log, FILE* file) {
    if (fwrite(log->log_time, sizeof(char), strlen(log->log_time), file)!= strlen(log->log_time)) {
        fprintf(stderr, "Error writing to file\n");
        exit(1);
    }
    if (fwrite(log->log_message, sizeof(char), strlen(log->log_message), file)!= strlen(log->log_message)) {
        fprintf(stderr, "Error writing to file\n");
        exit(1);
    }
    fflush(file);
}

void create_event_log(event_log* log) {
    time_t rawtime;
    struct tm* timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(log->log_time, BUF_SIZE, "%Y-%m-%d %H:%M:%S", timeinfo);
    log->log_message[0] = '\0';
}

int main() {
    event_log log;
    FILE* file;

    file = fopen("event_log.txt", "w");
    if (!file) {
        fprintf(stderr, "Error opening file\n");
        exit(1);
    }

    create_event_log(&log);
    write_to_file(&log, file);

    fclose(file);

    return 0;
}
//LLAMA2-13B DATASET v1.0 Category: System event logger ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>

#define MAX_EVENT_LEN 1024
#define MAX_LOG_LEN 10240

typedef struct {
    char quest_name[50];
    char quest_description[100];
    time_t timestamp;
} event_t;

typedef struct {
    char log_file[50];
    FILE *log_fp;
} log_t;

log_t *log_init(const char *log_file_name) {
    log_t *log = malloc(sizeof(log_t));
    log->log_file[0] = '\0';
    strcpy(log->log_file, log_file_name);
    log->log_fp = fopen(log->log_file, "a");
    if (log->log_fp == NULL) {
        printf("Failed to open log file: %s\n", log_file_name);
        exit(EXIT_FAILURE);
    }
    return log;
}

void log_add_event(log_t *log, const char *quest_name, const char *quest_description) {
    event_t event;
    strcpy(event.quest_name, quest_name);
    strcpy(event.quest_description, quest_description);
    event.timestamp = time(NULL);
    fprintf(log->log_fp, "%s: %s\n", event.quest_name, event.quest_description);
}

void log_close(log_t *log) {
    fclose(log->log_fp);
    free(log);
}

int main(void) {
    log_t *log = log_init("log.txt");
    log_add_event(log, "Slay the Dragon", "Killed the fierce dragon that terrorized the kingdom");
    log_add_event(log, "Rescue the Princess", "Freed the beautiful princess from the castle tower");
    log_add_event(log, "Recover the Treasure", "Found the hidden treasure and brought it back to the kingdom");
    log_close(log);
    return 0;
}
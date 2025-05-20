//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_IP_LENGTH 16
#define MAX_TIME_LENGTH 9

typedef struct{
    char ip[MAX_IP_LENGTH];
    char time[MAX_TIME_LENGTH];
} LogEntry;

typedef struct{
    LogEntry *entries;
    int size;
    int capacity;
} Log;

void log_append(Log *log, LogEntry new_entry){
    if(log->size >= log->capacity){
        log->capacity *= 2;
        log->entries = realloc(log->entries, log->capacity * sizeof(LogEntry));
    }
    log->entries[log->size++] = new_entry;
}

void parse_line(char *line, LogEntry *entry){
    int i, j;

    // parse IP address
    for(i = 0; i < MAX_IP_LENGTH - 1 && line[i] != ' '; i++){
        entry->ip[i] = line[i];
    }
    entry->ip[i] = '\0';

    // parse time
    for(i++; i < MAX_LINE_LENGTH - 1 && line[i] != '\n' && line[i] != '\r'; i++){
        entry->time[j++] = line[i];
    }
    entry->time[j] = '\0';
}

int is_suspect(const Log *log, const char *ip){
    int i, count = 0;

    for(i = log->size - 1; i >= 0 && count < 10; i--){
        if(strcmp(log->entries[i].ip, ip) == 0){
            count++;
            if(count == 10){
                return 1;
            }
        }
    }

    return 0;
}

int main(){
    Log log = {.entries = malloc(16 * sizeof(LogEntry)), .size = 0, .capacity = 16};
    char line[MAX_LINE_LENGTH];

    while(fgets(line, MAX_LINE_LENGTH, stdin)){
        LogEntry entry;
        parse_line(line, &entry);

        if(is_suspect(&log, entry.ip)){
            printf("Intruder detected: %s\n", entry.ip);
        }

        log_append(&log, entry);
    }

    free(log.entries);

    return 0;
}
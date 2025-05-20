//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ALERT_THRESHOLD 5
#define MAX_LOG_SIZE 1000

typedef struct {
    char *ip_address;
    char *timestamp;
    char *message;
} Log;

int get_log_count(Log *logs) {
    int count = 0;

    while(logs[count].message != NULL) {
        count++;
    }

    return count;
}

Log * get_logs_from_file(char *filepath) {
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int i = 0;

    Log *logs = (Log *) malloc(sizeof(Log) * MAX_LOG_SIZE);

    fp = fopen(filepath, "r");
    if(fp == NULL) {
        printf("Unable to open file %s\n", filepath);
        exit(EXIT_FAILURE);
    }

    while((read = getline(&line, &len, fp)) != -1) {
        char *ip_address = strtok(line, ",");
        char *timestamp = strtok(NULL, ",");
        char *message = strtok(NULL, "\n");

        logs[i].ip_address = (char *) malloc(strlen(ip_address) + 1);
        logs[i].timestamp = (char *) malloc(strlen(timestamp) + 1);
        logs[i].message = (char *) malloc(strlen(message) + 1);

        strcpy(logs[i].ip_address, ip_address);
        strcpy(logs[i].timestamp, timestamp);
        strcpy(logs[i].message, message);

        i++;
    }

    fclose(fp);

    return logs;
}

bool is_ip_blacklisted(char *ip_address, char **blacklist, int blacklist_size) {
    for(int i = 0; i < blacklist_size; i++) {
        if(strcmp(ip_address, blacklist[i]) == 0) {
            return true;
        }
    }

    return false;
}

void add_ip_to_blacklist(char *ip_address, char ***blacklist, int *blacklist_size) {
    *blacklist_size += 1;
    *blacklist = (char **) realloc(*blacklist, sizeof(char *) * (*blacklist_size));

    (*blacklist)[(*blacklist_size) - 1] = (char *) malloc(strlen(ip_address) + 1);
    strcpy((*blacklist)[(*blacklist_size) - 1], ip_address);
}

int main() {
    Log *logs = get_logs_from_file("logs.csv");
    int log_count = get_log_count(logs);

    char **blacklist = (char **) malloc(sizeof(char *) * 1);
    int blacklist_size = 0;

    for(int i = 0; i < log_count; i++) {
        int alert_count = 0;

        for(int j = i + 1; j < log_count; j++) {
            if(strcmp(logs[i].ip_address, logs[j].ip_address) == 0 &&
                    strcmp(logs[i].message, logs[j].message) == 0) {
                alert_count++;

                if(alert_count >= ALERT_THRESHOLD && 
                        !is_ip_blacklisted(logs[i].ip_address, blacklist, blacklist_size)) {
                    printf("ALERT: IP address %s has triggered the same intrusion %d times.\n", logs[i].ip_address, alert_count);
                    add_ip_to_blacklist(logs[i].ip_address, &blacklist, &blacklist_size);
                    break;
                }
            }
        }
    }

    return 0;
}
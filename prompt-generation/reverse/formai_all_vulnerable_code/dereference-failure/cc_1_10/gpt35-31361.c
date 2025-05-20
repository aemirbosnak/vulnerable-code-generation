//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_SIZE 100000 // maximum size of log data
#define MAX_ATTEMPTS 5 // maximum login attempts allowed
#define MAX_WRONG_PASSWORDS 3 // maximum wrong passwords before triggering alert
#define ALERT_THRESHOLD 10 // number of alerts before triggering email notification

typedef struct {
    char timestamp[20];
    char source_ip[16];
    char destination_ip[16];
    char action[10];
} Log;

int log_count = 0;
int attempts = 0;
int wrong_passwords = 0;
int alerts = 0;

void parse_log(char* log_line, Log* log_data) {
    char* token = strtok(log_line, ",");
    strcpy(log_data->timestamp, token);

    token = strtok(NULL, ",");
    strcpy(log_data->source_ip, token);

    token = strtok(NULL, ",");
    strcpy(log_data->destination_ip, token);

    token = strtok(NULL, ",");
    strcpy(log_data->action, token);
}

void log_alert(char* message) {
    alerts++;
    if(alerts >= ALERT_THRESHOLD) {
        printf("Sending email notification: %s\n", message);
        alerts = 0;
    }
}

int main() {
    FILE* fp = fopen("log.txt", "r");
    if(fp == NULL) {
        printf("Error opening log file.\n");
        return 1;
    }

    char log_data[MAX_LOG_SIZE];
    while(fgets(log_data, MAX_LOG_SIZE, fp) != NULL) {
        Log log_entry;
        parse_log(log_data, &log_entry);
        log_count++;

        if(strcmp(log_entry.source_ip, "192.168.0.1") == 0) {
            attempts++;
            if(attempts >= MAX_ATTEMPTS) {
                printf("Too many login attempts from %s. Blocking IP.\n", log_entry.source_ip);
                log_alert("Possible Brute-force attack detected.");
                attempts = 0;
            }
        }

        if(strcmp(log_entry.action, "login_failed") == 0) {
            wrong_passwords++;
            if(wrong_passwords >= MAX_WRONG_PASSWORDS) {
                printf("Multiple failed login attempts from %s. Alerting security team.\n", log_entry.source_ip);
                log_alert("Possible Password-guessing attack detected.");
                wrong_passwords = 0;
            }
        }

        if(strcmp(log_entry.action, "root_access") == 0) {
            printf("Root access granted to %s from %s. Alerting security team.\n", log_entry.destination_ip, log_entry.source_ip);
            log_alert("Possible unauthorized access detected.");
        }
    }

    fclose(fp);
    printf("Finished analyzing %d log entries.\n", log_count);

    return 0;
}
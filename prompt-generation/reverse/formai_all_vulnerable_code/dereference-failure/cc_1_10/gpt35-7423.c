//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_URL_LENGTH 100
#define SLEEP_TIME 10
#define LOG_FILE "uptime.log"

int ping_url(char url[]);
void log_event(char message[]);

int main(int argc, char *argv[]) {
    char url[MAX_URL_LENGTH];
    int status;

    if (argc < 2) {
        printf("Usage: website-uptime url\n");
        exit(EXIT_FAILURE);
    }
    strcpy(url, argv[1]);

    printf("Monitoring %s...\n", url);

    while(1) {
        status = ping_url(url);
        if (status == 0) {
            log_event("Connection successful\n");
        } else {
            log_event("Connection failed\n");
        }
        sleep(SLEEP_TIME);
    }
}

int ping_url(char url[]) {
    char command[MAX_URL_LENGTH + 20];
    snprintf(command, sizeof(command), "ping -c 1 %s >/dev/null 2>&1", url);
    return system(command);
}

void log_event(char message[]) {
    FILE *logfile;
    time_t current_time;
    char formatted_time[20];

    current_time = time(NULL);
    strftime(formatted_time, sizeof(formatted_time), "%Y-%m-%d %H:%M:%S", localtime(&current_time));

    logfile = fopen(LOG_FILE, "a");
    if (logfile == NULL) {
        printf("Error opening log file.\n");
        exit(EXIT_FAILURE);
    }

    fprintf(logfile, "[%s] %s", formatted_time, message);

    fclose(logfile);
}
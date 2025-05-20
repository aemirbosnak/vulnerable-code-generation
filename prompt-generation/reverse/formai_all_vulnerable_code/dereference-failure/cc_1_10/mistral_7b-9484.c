//MISTRAL-7B DATASET v1.0 Category: System event logger ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EVENTS 100
#define MAX_LEN 256
#define LOG_FILE "event.log"

typedef struct event_tag {
    char timestamp[20];
    char message[MAX_LEN];
} event_t;

void create_timestamp(char *buf) {
    time_t rawtime;
    struct tm *timeinfo;
    char *token;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", timeinfo);
    token = strtok(buf, " ");
    strcat(token, ".");
    strcat(token, (timeinfo->tm_sec < 10) ? "0" : "");
    strcat(token, itoa(timeinfo->tm_sec));

    strcpy(buf, token);
}

void log_event(const char *msg) {
    event_t *event;
    FILE *fp;

    if ((fp = fopen(LOG_FILE, "a")) == NULL) {
        perror("Unable to open file");
        return;
    }

    if ((event = (event_t *)calloc(sizeof(event_t), 1)) == NULL) {
        perror("Unable to allocate memory");
        fclose(fp);
        return;
    }

    create_timestamp(event->timestamp);
    strncpy(event->message, msg, sizeof(event->message) - 1);

    fwrite(event, sizeof(event_t), 1, fp);
    fflush(fp);

    free(event);
    fclose(fp);
}

void print_log() {
    FILE *fp;
    event_t event;
    int i = 0;

    if ((fp = fopen(LOG_FILE, "r")) == NULL) {
        perror("Unable to open file");
        return;
    }

    printf("\nLog Entries:\n");
    printf("------------------------------------------------------------------------------------------\n");

    while (fread(&event, sizeof(event_t), 1, fp) > 0) {
        printf("%s - %s\n", event.timestamp, event.message);
        i++;
        if (i >= MAX_EVENTS) {
            break;
        }
    }

    fclose(fp);
}

int main(void) {
    char *msg = "A safe style C system event logger was started.";
    log_event(msg);
    log_event("Creating 10 events in a row...");

    for (int i = 0; i < 10; i++) {
        char str[MAX_LEN];
        sprintf(str, "Event %d: Safe event logger is working fine.", i + 1);
        log_event(str);
    }

    printf("Log entries have been written to %s\n", LOG_FILE);
    printf("Let's print the last 10 log entries:\n");
    print_log();

    return EXIT_SUCCESS;
}

int itoa(int num) {
    char buf[10];
    int i = 0, sign = 1;

    if (num < 0) {
        sign = -1;
        num = -num;
    }

    do {
        buf[i++] = num % 10 + '0';
        num /= 10;
    } while (num > 0);

    if (sign < 0) {
        buf[i++] = '-';
    }

    buf[i] = '\0';

    return i;
}
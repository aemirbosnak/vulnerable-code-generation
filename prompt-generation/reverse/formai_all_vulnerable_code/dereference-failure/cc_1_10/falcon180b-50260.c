//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

typedef struct log_entry {
    char ip[16];
    char method[8];
    char url[1024];
    char status[3];
    int bytes_sent;
    char agent[256];
    char referer[1024];
    char user_agent[256];
} LogEntry;

int main(int argc, char **argv) {
    FILE *fp;
    char line[MAX_SIZE];
    char *token;
    LogEntry log_entry;
    int count = 0;
    int i;

    if (argc!= 2) {
        printf("Usage: %s <log_file>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Unable to open %s\n", argv[1]);
        return 1;
    }

    while (fgets(line, MAX_SIZE, fp)!= NULL) {
        count++;

        token = strtok(line, " ");
        strcpy(log_entry.ip, token);

        token = strtok(NULL, " ");
        strcpy(log_entry.method, token);

        token = strtok(NULL, " ");
        strcpy(log_entry.url, token);

        token = strtok(NULL, " ");
        strcpy(log_entry.status, token);

        token = strtok(NULL, " ");
        log_entry.bytes_sent = atoi(token);

        token = strtok(NULL, " ");
        strcpy(log_entry.agent, token);

        token = strtok(NULL, " ");
        strcpy(log_entry.referer, token);

        token = strtok(NULL, " ");
        strcpy(log_entry.user_agent, token);

        printf("Entry %d:\n", count);
        printf("IP: %s\n", log_entry.ip);
        printf("Method: %s\n", log_entry.method);
        printf("URL: %s\n", log_entry.url);
        printf("Status: %s\n", log_entry.status);
        printf("Bytes sent: %d\n", log_entry.bytes_sent);
        printf("Agent: %s\n", log_entry.agent);
        printf("Referer: %s\n", log_entry.referer);
        printf("User agent: %s\n", log_entry.user_agent);
        printf("\n");
    }

    fclose(fp);
    return 0;
}
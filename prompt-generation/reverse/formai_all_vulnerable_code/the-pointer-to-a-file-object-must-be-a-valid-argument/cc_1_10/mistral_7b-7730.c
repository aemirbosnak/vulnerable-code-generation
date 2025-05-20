//MISTRAL-7B DATASET v1.0 Category: Log analysis ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LEN 8192
#define LOG_FILE "server.log"

typedef struct {
    int year, month, day, hour, minute, second;
    char method[10], path[256], protocol[10];
    int status_code, content_length;
    char user_agent[256];
} log_entry;

void parse_log(FILE *fp, log_entry *entry) {
    char line[MAX_LINE_LEN], *token;
    int i;

    fgets(line, MAX_LINE_LEN, fp);

    sscanf(line, "%d %d %d %d:%d:%d %s %s %d %d %s",
           &entry->year, &entry->month, &entry->day,
           &entry->hour, &entry->minute, &entry->second,
           entry->method, entry->path, &entry->status_code,
           &entry->content_length, entry->protocol);

    for (i = 0; i < strlen(line); i++) {
        if (isdigit(line[i])) line[i] = ' ';
    }

    strcpy(entry->user_agent, strchr(line, ' ')+1);
    entry->user_agent[strcspn(entry->user_agent, "\n")] = '\0';
}

int main(void) {
    FILE *fp;
    log_entry entry;
    int total_requests = 0, total_bytes = 0;
    double avg_request_size;

    fp = fopen(LOG_FILE, "r");

    while (fscanf(fp, "%s", entry.method) != EOF) {
        parse_log(fp, &entry);

        total_requests++;
        total_bytes += entry.content_length;
    }

    avg_request_size = (double)total_bytes / total_requests;

    printf("Total requests: %d\n", total_requests);
    printf("Total bytes: %d\n", total_bytes);
    printf("Average request size: %.2f bytes\n", avg_request_size);

    fclose(fp);

    return 0;
}
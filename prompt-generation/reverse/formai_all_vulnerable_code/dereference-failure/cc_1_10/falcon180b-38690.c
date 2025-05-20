//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

struct log_entry {
    char ip_address[16];
    char method[8];
    char url[256];
    char status_code[4];
    char user_agent[256];
};

void process_log(struct log_entry *entry, char *line) {
    char *ip_start = strstr(line, " ") + 1;
    strncpy(entry->ip_address, ip_start, 15);
    entry->ip_address[15] = '\0';

    char *method_start = strstr(line, " ") + 1;
    strncpy(entry->method, method_start, 7);
    entry->method[7] = '\0';

    char *url_start = strstr(line, " ") + 1;
    strncpy(entry->url, url_start, 255);
    entry->url[255] = '\0';

    char *status_code_start = strstr(line, " ") + 1;
    strncpy(entry->status_code, status_code_start, 3);
    entry->status_code[3] = '\0';

    char *user_agent_start = strstr(line, " ") + 1;
    strncpy(entry->user_agent, user_agent_start, 255);
    entry->user_agent[255] = '\0';
}

void print_entry(struct log_entry *entry) {
    printf("IP Address: %s\n", entry->ip_address);
    printf("Method: %s\n", entry->method);
    printf("URL: %s\n", entry->url);
    printf("Status Code: %s\n", entry->status_code);
    printf("User Agent: %s\n\n", entry->user_agent);
}

int main() {
    FILE *log_file = fopen("logfile.txt", "r");
    if (log_file == NULL) {
        printf("Error opening log file.\n");
        return 1;
    }

    struct log_entry entry;
    char line[MAX_LINE_SIZE];

    while (fgets(line, MAX_LINE_SIZE, log_file)!= NULL) {
        process_log(&entry, line);
        print_entry(&entry);
    }

    fclose(log_file);
    return 0;
}
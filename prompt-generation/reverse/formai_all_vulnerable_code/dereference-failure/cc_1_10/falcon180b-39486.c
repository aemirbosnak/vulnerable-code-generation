//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_ENTRIES 1000
#define MAX_LOG_ENTRY_SIZE 1024

typedef struct {
    char *ip_address;
    char *date_time;
    char *request_type;
    char *request_url;
    int response_code;
} LogEntry;

void add_log_entry(LogEntry *log_entries, int num_entries, char *ip_address, char *date_time, char *request_type, char *request_url, int response_code) {
    if (num_entries >= MAX_LOG_ENTRIES) {
        printf("Error: Log is full.\n");
        return;
    }

    LogEntry *entry = &log_entries[num_entries];

    entry->ip_address = strdup(ip_address);
    entry->date_time = strdup(date_time);
    entry->request_type = strdup(request_type);
    entry->request_url = strdup(request_url);
    entry->response_code = response_code;

    num_entries++;
}

void print_log_entries(LogEntry *log_entries, int num_entries) {
    for (int i = 0; i < num_entries; i++) {
        printf("IP Address: %s\n", log_entries[i].ip_address);
        printf("Date and Time: %s\n", log_entries[i].date_time);
        printf("Request Type: %s\n", log_entries[i].request_type);
        printf("Request URL: %s\n", log_entries[i].request_url);
        printf("Response Code: %d\n\n", log_entries[i].response_code);
    }
}

int main() {
    LogEntry log_entries[MAX_LOG_ENTRIES];
    int num_entries = 0;

    add_log_entry(log_entries, num_entries, "192.168.0.1", "2022-02-22 12:34:56", "GET", "/index.html", 200);
    add_log_entry(log_entries, num_entries, "192.168.0.2", "2022-02-22 12:35:01", "POST", "/login.php", 401);
    add_log_entry(log_entries, num_entries, "192.168.0.3", "2022-02-22 12:35:16", "PUT", "/settings.php", 403);

    print_log_entries(log_entries, num_entries);

    return 0;
}
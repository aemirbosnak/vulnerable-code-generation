//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_SIZE 1000
#define MAX_WORD_SIZE 50

struct log_entry {
    char ip_address[50];
    char request_method[50];
    char requested_file[50];
    int response_code;
    int bytes_sent;
};

void parse_log_entry(char* log_line, struct log_entry* entry) {
    char* token = strtok(log_line, " ");
    strcpy(entry->ip_address, token);

    token = strtok(NULL, " ");
    strcpy(entry->request_method, token);

    token = strtok(NULL, " ");
    strcpy(entry->requested_file, token);

    entry->response_code = atoi(strtok(NULL, " "));
    entry->bytes_sent = atoi(strtok(NULL, " "));
}

int compare_log_entries(const void* a, const void* b) {
    const struct log_entry* entry1 = (const struct log_entry*)a;
    const struct log_entry* entry2 = (const struct log_entry*)b;

    if (entry1->response_code > entry2->response_code) {
        return -1;
    } else if (entry1->response_code < entry2->response_code) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    FILE* log_file = fopen("logfile.txt", "r");

    if (log_file == NULL) {
        printf("Error: Unable to open log file.\n");
        exit(1);
    }

    char log_buffer[MAX_LOG_SIZE];
    struct log_entry log_entries[MAX_LOG_SIZE];
    int num_entries = 0;

    while (fgets(log_buffer, MAX_LOG_SIZE, log_file)!= NULL) {
        parse_log_entry(log_buffer, &log_entries[num_entries]);
        num_entries++;
    }

    qsort(log_entries, num_entries, sizeof(struct log_entry), compare_log_entries);

    printf("Log entries sorted by response code:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("IP Address: %s\nRequest Method: %s\nRequested File: %s\nResponse Code: %d\nBytes Sent: %d\n\n",
               log_entries[i].ip_address,
               log_entries[i].request_method,
               log_entries[i].requested_file,
               log_entries[i].response_code,
               log_entries[i].bytes_sent);
    }

    fclose(log_file);
    return 0;
}
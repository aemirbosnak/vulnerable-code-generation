//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This is a decentralized Intrusion Detection System that detects unauthorized access to a network */

struct log {
    char* date;
    char* time;
    char* ip_address;
    char* message;
};

void print_log(struct log* log_entry) {
    printf("%s %s %s %s\n", log_entry->date, log_entry->time, log_entry->ip_address, log_entry->message);
}

int main() {
    struct log log_entries[100];
    int num_entries = 0;
    int i;

    char input[256];
    char *token;

    while (strcmp(input, "exit") != 0) {
        printf("Enter log entry (date time ip_address message): ");
        fgets(input, 256, stdin);

        // tokenize input
        token = strtok(input, " ");
        log_entries[num_entries].date = strdup(token);

        token = strtok(NULL, " ");
        log_entries[num_entries].time = strdup(token);

        token = strtok(NULL, " ");
        log_entries[num_entries].ip_address = strdup(token);

        token = strtok(NULL, "\n");
        log_entries[num_entries].message = strdup(token);

        num_entries++;
    }

    printf("\n\n\n");

    // print all log entries
    for (i = 0; i < num_entries; i++) {
        print_log(&log_entries[i]);
    }

    return 0;
}
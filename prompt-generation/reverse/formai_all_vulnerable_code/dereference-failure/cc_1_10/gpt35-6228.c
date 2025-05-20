//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 100

typedef struct log_record log_record;

struct log_record {
    char *ip_address;
    char *timestamp;
    char *request;
    log_record *next;
};

typedef struct {
    int warn_threshold;
    int block_threshold;
    log_record *log_list;
} IDS;

void print_help() {
    printf("Usage: ids [warn-threshold] [block-threshold]\n");
    exit(1);
}

void add_log_record(IDS *ids, char *ip_address, char *timestamp, char *request) {
    log_record *new_record = (log_record *)malloc(sizeof(log_record));
    new_record->ip_address = strdup(ip_address);
    new_record->timestamp = strdup(timestamp);
    new_record->request = strdup(request);
    new_record->next = ids->log_list;
    ids->log_list = new_record;
}

int count_log_records(IDS *ids) {
    int count = 0;
    for (log_record *current = ids->log_list; current != NULL; current = current->next) {
        count++;
    }
    return count;
}

void print_log_records(IDS *ids) {
    printf("IP Address\tTimestamp\tRequest\n");
    for (log_record *current = ids->log_list; current != NULL; current = current->next) {
        printf("%s\t%s\t%s\n", current->ip_address, current->timestamp, current->request);
    }
}

void check_intrusion(IDS *ids) {
    int num_logs = count_log_records(ids);
    if (num_logs >= ids->block_threshold) {
        printf("Intrusion detected. Blocking IP addresses.\n");
        exit(0);
    } else if (num_logs >= ids->warn_threshold) {
        printf("Warning: Possible intrusion detected.\n");
    }
}

int main(int argc, char *argv[]) {
    IDS ids;
    int warn_threshold = 10;
    int block_threshold = 20;
    if (argc == 2 || argc > 3) {
        print_help();
    } else if (argc == 3) {
        warn_threshold = atoi(argv[1]);
        block_threshold = atoi(argv[2]);
    }
    ids.warn_threshold = warn_threshold;
    ids.block_threshold = block_threshold;
    char line[MAX_LINE];
    while (fgets(line, MAX_LINE, stdin)) {
        char *ip_address = strtok(line, " ");
        char *timestamp = strtok(NULL, " ");
        char *request = strtok(NULL, "\n");
        add_log_record(&ids, ip_address, timestamp, request);
        check_intrusion(&ids);
    }
    print_log_records(&ids);
    return 0;
}
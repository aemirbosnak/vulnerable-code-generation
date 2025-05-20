//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LOG_ENTRIES 1000

struct log_entry {
    char *source_ip;
    char *destination_ip;
    char *date_time;
    bool is_malicious;
};

struct intrusion_detection_system {
    struct log_entry *log_entries;
    int num_entries;
};

void log_entry_init(struct log_entry *entry, char *source_ip, char *destination_ip, char *date_time, bool is_malicious) {
    entry->source_ip = source_ip;
    entry->destination_ip = destination_ip;
    entry->date_time = date_time;
    entry->is_malicious = is_malicious;
}

void intrusion_detection_system_init(struct intrusion_detection_system *ids) {
    ids->log_entries = (struct log_entry *) malloc(MAX_LOG_ENTRIES * sizeof(struct log_entry));
    ids->num_entries = 0;
}

void add_log_entry(struct intrusion_detection_system *ids, char *source_ip, char *destination_ip, char *date_time, bool is_malicious) {
    if (ids->num_entries >= MAX_LOG_ENTRIES) {
        printf("Max log entries reached. Cannot add new entry.\n");
        return;
    }
    struct log_entry *entry = &ids->log_entries[ids->num_entries];
    log_entry_init(entry, source_ip, destination_ip, date_time, is_malicious);
    ids->num_entries++;
}

void print_log_entries(struct intrusion_detection_system *ids) {
    for (int i = 0; i < ids->num_entries; i++) {
        struct log_entry *entry = &ids->log_entries[i];
        printf("Log entry %d:\n", i + 1);
        printf("\tSource IP: %s\n", entry->source_ip);
        printf("\tDestination IP: %s\n", entry->destination_ip);
        printf("\tDate & Time: %s\n", entry->date_time);
        printf("\tIs Malicious: %s\n", entry->is_malicious ? "true" : "false");
    }
}

int main() {
    struct intrusion_detection_system ids;
    intrusion_detection_system_init(&ids);
    add_log_entry(&ids, "192.168.1.101", "173.194.33.129", "2021-05-01 12:00:00", false);
    add_log_entry(&ids, "192.168.1.102", "8.8.8.8", "2021-05-02 13:00:00", true);
    add_log_entry(&ids, "192.168.1.103", "173.194.33.129", "2021-05-03 14:00:00", false);
    add_log_entry(&ids, "192.168.1.104", "173.194.33.129", "2021-05-04 15:00:00", true);
    print_log_entries(&ids);
    return 0;
}
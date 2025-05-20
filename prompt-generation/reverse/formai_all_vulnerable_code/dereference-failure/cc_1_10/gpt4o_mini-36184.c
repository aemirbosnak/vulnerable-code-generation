//GPT-4o-mini DATASET v1.0 Category: Log analysis ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IP_LENGTH 16
#define MAX_LOG_LINE 256
#define MAX_ENTRIES 1024

typedef struct {
    char ip[MAX_IP_LENGTH];
    int request_count;
} IPRequest;

void log_analyzer(const char *filename, int threshold);
void increment_request_count(IPRequest *entries, int *entry_count, const char *ip);
void print_summary(IPRequest *entries, int entry_count, int threshold);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <logfile> <threshold>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    const char *filename = argv[1];
    int threshold = atoi(argv[2]);

    if (threshold <= 0) {
        fprintf(stderr, "Threshold should be a positive number.\n");
        return EXIT_FAILURE;
    }

    log_analyzer(filename, threshold);
    return EXIT_SUCCESS;
}

void log_analyzer(const char *filename, int threshold) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    IPRequest entries[MAX_ENTRIES];
    int entry_count = 0;
    char log_line[MAX_LOG_LINE];

    while (fgets(log_line, sizeof(log_line), file)) {
        char ip[MAX_IP_LENGTH];
        sscanf(log_line, "%15s", ip);  // Assuming IP is the first element in the log line
        increment_request_count(entries, &entry_count, ip);
    }

    fclose(file);
    
    print_summary(entries, entry_count, threshold);
}

void increment_request_count(IPRequest *entries, int *entry_count, const char *ip) {
    for (int i = 0; i < *entry_count; i++) {
        if (strcmp(entries[i].ip, ip) == 0) {
            entries[i].request_count++;
            return;
        }
    }

    // New IP address
    if (*entry_count < MAX_ENTRIES) {
        strcpy(entries[*entry_count].ip, ip);
        entries[*entry_count].request_count = 1;
        (*entry_count)++;
    } else {
        fprintf(stderr, "Maximum number of IP entries reached.\n");
    }
}

void print_summary(IPRequest *entries, int entry_count, int threshold) {
    printf("IP Address Request Summary:\n");
    printf("%-15s %s\n", "IP Address", "Request Count");
    printf("-------------------------\n");
    
    for (int i = 0; i < entry_count; i++) {
        printf("%-15s %d\n", entries[i].ip, entries[i].request_count);
    }
    
    printf("\nIP Addresses exceeding the threshold of %d requests:\n", threshold);
    for (int i = 0; i < entry_count; i++) {
        if (entries[i].request_count > threshold) {
            printf("- %s: %d requests\n", entries[i].ip, entries[i].request_count);
        }
    }
}
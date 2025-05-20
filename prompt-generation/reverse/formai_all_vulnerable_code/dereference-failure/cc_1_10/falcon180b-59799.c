//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_SIZE 1024

typedef struct {
    char *ip_address;
    int num_requests;
} RequestStats;

typedef struct {
    RequestStats *stats;
    int num_stats;
} LogAnalysis;

void add_request_stats(LogAnalysis *analysis, char *ip_address) {
    RequestStats *stats = malloc(sizeof(RequestStats));
    stats->ip_address = strdup(ip_address);
    stats->num_requests = 1;
    analysis->stats = realloc(analysis->stats, sizeof(RequestStats) * (analysis->num_stats + 1));
    analysis->stats[analysis->num_stats] = *stats;
    analysis->num_stats++;
}

void print_request_stats(RequestStats *stats) {
    printf("IP Address: %s\n", stats->ip_address);
    printf("Number of Requests: %d\n", stats->num_requests);
}

void print_log_analysis(LogAnalysis *analysis) {
    for (int i = 0; i < analysis->num_stats; i++) {
        print_request_stats(&analysis->stats[i]);
    }
}

int main() {
    FILE *log_file = fopen("logfile.txt", "r");
    if (log_file == NULL) {
        printf("Error opening log file.\n");
        exit(1);
    }

    LogAnalysis analysis = {0};

    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, log_file)!= NULL) {
        char *ip_address = strstr(line, " ");
        if (ip_address!= NULL) {
            ip_address += 1;
            add_request_stats(&analysis, ip_address);
        }
    }

    print_log_analysis(&analysis);

    fclose(log_file);
    return 0;
}
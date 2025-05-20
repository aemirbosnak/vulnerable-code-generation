//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *ip;
    int count;
} IPCount;

void add_ip_count(IPCount *ip_counts, int size, char *ip) {
    for (int i = 0; i < size; i++) {
        if (strcmp(ip_counts[i].ip, ip) == 0) {
            ip_counts[i].count++;
            return;
        }
    }
    IPCount *new_ip_count = (IPCount *) realloc(ip_counts, sizeof(IPCount) * (size + 1));
    if (new_ip_count == NULL) {
        fprintf(stderr, "Error: Out of memory\n");
        exit(1);
    }
    ip_counts = new_ip_count;
    ip_counts[size].ip = strdup(ip);
    ip_counts[size].count = 1;
}

void print_ip_counts(IPCount *ip_counts, int size) {
    for (int i = 0; i < size; i++) {
        printf("%s %d\n", ip_counts[i].ip, ip_counts[i].count);
    }
}

void process_line(char *line, IPCount *ip_counts, int size) {
    char *token = strtok(line, " ");
    while (token!= NULL) {
        if (strncmp(token, "GET", 3) == 0) {
            char *ip = strtok(NULL, " ");
            add_ip_count(ip_counts, size, ip);
        }
        token = strtok(NULL, " ");
    }
}

int main() {
    FILE *log_file = fopen("access.log", "r");
    if (log_file == NULL) {
        fprintf(stderr, "Error: Unable to open log file\n");
        exit(1);
    }

    IPCount *ip_counts = (IPCount *) malloc(sizeof(IPCount));
    ip_counts[0].ip = strdup("");
    ip_counts[0].count = 0;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, log_file)!= NULL) {
        process_line(line, ip_counts, 1);
    }

    print_ip_counts(ip_counts, 1);

    free(ip_counts[0].ip);
    free(ip_counts);
    fclose(log_file);

    return 0;
}
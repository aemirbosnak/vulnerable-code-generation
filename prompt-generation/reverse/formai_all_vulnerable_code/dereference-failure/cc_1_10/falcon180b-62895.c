//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LOG_LINES 1000
#define MAX_LINE_LENGTH 256

struct LogLine {
    char ip[16];
    char date[32];
    char time[32];
    char request[256];
    char status[32];
};

void read_log_file(FILE *fp, struct LogLine *lines, int *num_lines) {
    char line[MAX_LINE_LENGTH];
    int i = 0;

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        if (i >= MAX_LOG_LINES) {
            printf("Error: Maximum number of log lines exceeded.\n");
            exit(1);
        }

        char *ptr = strtok(line, " ");
        strcpy(lines[i].ip, ptr);
        ptr = strtok(NULL, " ");
        strcpy(lines[i].date, ptr);
        ptr = strtok(NULL, " ");
        strcpy(lines[i].time, ptr);
        ptr = strtok(NULL, " ");
        strcpy(lines[i].request, ptr);
        ptr = strtok(NULL, " ");
        strcpy(lines[i].status, ptr);

        i++;
    }

    *num_lines = i;
}

void print_log_line(struct LogLine line) {
    printf("%-15s %-30s %-30s %-80s %s\n", line.ip, line.date, line.time, line.request, line.status);
}

void print_log_lines(struct LogLine *lines, int num_lines) {
    for (int i = 0; i < num_lines; i++) {
        print_log_line(lines[i]);
    }
}

int main(int argc, char **argv) {
    if (argc!= 2) {
        printf("Usage: %s <log_file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Could not open log file.\n");
        return 1;
    }

    struct LogLine lines[MAX_LOG_LINES];
    int num_lines = 0;

    read_log_file(fp, lines, &num_lines);
    fclose(fp);

    printf("Log lines:\n");
    print_log_lines(lines, num_lines);

    return 0;
}
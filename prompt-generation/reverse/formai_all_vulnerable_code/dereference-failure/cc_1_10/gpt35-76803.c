//FormAI DATASET v1.0 Category: Log analysis ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1024

struct Log {
    char date[11];
    char time[9];
    char ip[16];
    char message[256];
};

struct LogList {
    struct Log log;
    struct LogList *next;
};

struct LogList *parse_log_file(char *log_file) {
    FILE *fp = fopen(log_file, "r");
    if (!fp) {
        perror("Failed to open log file");
        exit(1);
    }

    struct LogList *head = NULL;
    struct LogList **tail = &head;
    char line[MAX_LINE];
    while (fgets(line, MAX_LINE, fp)) {
        struct LogList *ll = malloc(sizeof(struct LogList));
        if (sscanf(line, "%10s %8s %15s %[^\n]", ll->log.date, ll->log.time, ll->log.ip, ll->log.message) == 4) {
            ll->next = NULL;
            *tail = ll;
            tail = &ll->next;
        } else {
            free(ll);
        }
    }

    fclose(fp);
    return head;
}

void print_logs(struct LogList *ll) {
    for (; ll; ll = ll->next) {
        printf("%s %s %s %s\n", ll->log.date, ll->log.time, ll->log.ip, ll->log.message);
    }
}

void count_by_ip(struct LogList *ll) {
    struct {
        char ip[16];
        int count;
    } ips[1024];

    int num_ips = 0;
    for (; ll; ll = ll->next) {
        int i;
        for (i = 0; i < num_ips; ++i) {
            if (strcmp(ips[i].ip, ll->log.ip) == 0) {
                ++ips[i].count;
                break;
            }
        }

        if (i == num_ips) {
            strcpy(ips[i].ip, ll->log.ip);
            ips[i].count = 1;
            ++num_ips;
        }
    }

    printf("IP address\tCount\n");
    for (int i = 0; i < num_ips; ++i) {
        printf("%s\t\t%d\n", ips[i].ip, ips[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <log_file> <command>\n", argv[0]);
        return 1;
    }

    struct LogList *ll = parse_log_file(argv[1]);

    if (strcmp(argv[2], "all") == 0) {
        print_logs(ll);
    } else if (strcmp(argv[2], "count") == 0) {
        count_by_ip(ll);
    } else {
        fprintf(stderr, "Invalid command: %s\n", argv[2]);
        return 1;
    }

    return 0;
}
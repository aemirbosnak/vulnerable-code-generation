//MISTRAL-7B DATASET v1.0 Category: Log analysis ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_LINE_LEN 1024
#define LOG_FILE_PREFIX "access_log."
#define DATE_FORMAT "%d/%b/%Y:%H:%M:%S %z"

struct log_entry {
    char ip[16];
    int status_code;
    char request[256];
    char user_agent[256];
    time_t timestamp;
};

bool parse_log_line(const char *line, struct log_entry *entry) {
    sscanf(line, "%[^ ] %*s %[^ ] %d %s %s %lld",
           entry->ip,
           entry->request,
           &entry->status_code,
           entry->user_agent,
           &entry->timestamp);

    return !strchr(entry->ip, ':') &&
           !strchr(entry->request, '\n') &&
           !strchr(entry->user_agent, '\n');
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <logfile>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char logfile[MAX_LINE_LEN];
    strcpy(logfile, argv[1]);

    int log_file_num = 0;
    char *token = strtok(logfile, '.');
    while (token != NULL) {
        if (strcmp(token, "log") == 0) {
            log_file_num++;
        }
        token = strtok(NULL, ".");
    }

    if (log_file_num < 1) {
        fprintf(stderr, "Invalid logfile name: %s\n", logfile);
        exit(EXIT_FAILURE);
    }

    int log_fd = open(logfile, O_RDONLY);
    if (log_fd < 0) {
        perror("Error opening logfile");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LEN];
    struct log_entry entry;
    int total_status_code_404 = 0;

    while (fgets(line, sizeof(line), log_fd) != NULL) {
        if (parse_log_line(line, &entry)) {
            printf("%s [%ld] %s %s %s\n",
                   ctime(&entry.timestamp),
                   (int)entry.timestamp,
                   entry.ip,
                   entry.request,
                   entry.user_agent);

            if (strstr(entry.request, "/404.html") != NULL) {
                total_status_code_404++;
            }
        }
    }

    close(log_fd);

    printf("\nTotal 404 errors: %d\n", total_status_code_404);

    return EXIT_SUCCESS;
}
//FormAI DATASET v1.0 Category: System process viewer ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#define BUF_SIZE 1024

int is_number(const char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i]))
            return 0;
    }
    return 1;
}

void print_header() {
    printf("\n\t%-6s %-15s %-15s %-10s\n", "PID", "USER", "COMMAND", "STATUS");
    printf("\t-------------------------------------------------\n");
}

void print_process(char *pid, char *user, char *command, char *status) {
    printf("\t%-6s %-15s %-15s %-10s\n", pid, user, command, status);
}

int main() {
    DIR *dir = opendir("/proc");
    struct dirent *entry;

    if (!dir) {
        perror("Unable to open /proc directory");
        exit(EXIT_FAILURE);
    }

    printf("Displaying system process information...\n\n");
    print_header();

    while ((entry = readdir(dir)) != NULL) {
        if (is_number(entry->d_name)) {
            char buffer[BUF_SIZE], *pid, *status;

            pid = entry->d_name;

            // Read command line for process
            snprintf(buffer, BUF_SIZE, "/proc/%s/cmdline", pid);
            FILE *fp = fopen(buffer, "r");
            if (!fp) {
                perror("Unable to open command line file");
                exit(EXIT_FAILURE);
            }
            fgets(buffer, sizeof(buffer), fp);
            fclose(fp);

            // Read user id for process
            snprintf(buffer, BUF_SIZE, "/proc/%s/status", pid);
            fp = fopen(buffer, "r");
            if (!fp) {
                perror("Unable to open status file");
                exit(EXIT_FAILURE);
            }
            char line[BUF_SIZE], *token, *user;
            while (fgets(line, sizeof(line), fp)) {
                if (strncmp(line, "Uid:", 4) == 0) {
                    token = strtok(line, "\t");
                    token = strtok(NULL, "\t");
                    user = token;
                    break;
                }
            }
            fclose(fp);

            // Read process status
            snprintf(buffer, BUF_SIZE, "/proc/%s/status", pid);
            fp = fopen(buffer, "r");
            if (!fp) {
                perror("Unable to open status file");
                exit(EXIT_FAILURE);
            }
            while (fgets(line, sizeof(line), fp)) {
                if (strncmp(line, "State:", 6) == 0) {
                    token = strtok(line, "\t");
                    token = strtok(NULL, "\t");
                    status = token;
                    break;
                }
            }
            fclose(fp);

            print_process(pid, user, buffer, status);
        }
    }

    closedir(dir);

    return 0;
}
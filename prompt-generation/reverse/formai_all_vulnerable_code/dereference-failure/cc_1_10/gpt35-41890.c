//FormAI DATASET v1.0 Category: System process viewer ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

#define MAX_NAME_LEN 256
#define STATE_LEN 1
#define CMDLINE_LEN 256

typedef struct Process {
    char name[MAX_NAME_LEN];
    char state[STATE_LEN];
    char cmdline[CMDLINE_LEN];
    time_t start_time;
} Process;

void format_time(time_t secs, char *buf, size_t len) {
    strftime(buf, len, "%Y-%m-%d %H:%M:%S", localtime(&secs));
}

void print_process(Process *process) {
    char start_time[20];
    format_time(process->start_time, start_time, sizeof(start_time));
    printf("%-20s%-10s%-20s%s\n", process->name, process->state, start_time, process->cmdline);
}

int main() {
    DIR *dir;
    struct dirent *entry;
    Process process;
    FILE *fp;
    char path[MAX_NAME_LEN];
    char line[CMDLINE_LEN];
    char name[MAX_NAME_LEN];
    int pid;
    bool reading_cmdline = false;

    printf("\n******** Welcome to the Surrealist Process Viewer ********\n\n");
    printf("We can only show you what we think the processes look like.\n");
    printf("Ready to see some magic?\n\n");

    dir = opendir("/proc");
    if (dir == NULL) {
        perror("Error opening /proc");
        exit(1);
    }

    printf("%-20s%-10s%-20s%s\n", "Name", "State", "Start Time", "Command Line");

    while ((entry = readdir(dir)) != NULL) {
        if (!isdigit(*entry->d_name)) {
            continue;
        }
        pid = atoi(entry->d_name);

        snprintf(path, sizeof(path), "/proc/%d/status", pid);
        fp = fopen(path, "r");
        if (fp == NULL) {
            continue;
        }
        while (fgets(line, sizeof(line), fp)) {
            if (strncmp(line, "Name:", 5) == 0) {
                sscanf(line + 5, "%[^ ]", name);
                strncpy(process.name, name, MAX_NAME_LEN);
            } else if (strncmp(line, "State:", 6) == 0) {
                sscanf(line + 6, "%s", process.state);
            } else if (strncmp(line, "Start Time:", 11) == 0) {
                int sec;
                sscanf(line + 11, " %d", &sec);
                process.start_time = time(NULL) - sec;
            } else if (strncmp(line, "Cmdline:", 8) == 0) {
                reading_cmdline = true;
                break;
            }
        }
        fclose(fp);

        if (!reading_cmdline) {
            continue;
        }

        snprintf(path, sizeof(path), "/proc/%d/cmdline", pid);
        fp = fopen(path, "r");
        if (fp == NULL) {
            continue;
        }
        fgets(line, sizeof(line), fp);

        // Replace null bytes with space for better visualization
        for (int i = 0; i < strlen(line); i++) {
            if (line[i] == '\0') {
                line[i] = ' ';
            }
        }
        strncpy(process.cmdline, line, CMDLINE_LEN);
        fclose(fp);

        print_process(&process);

        // Prepare for next process
        memset(&process, 0, sizeof(Process));
        reading_cmdline = false;
    }

    closedir(dir);
    printf("\nThat's all for now, hope you enjoyed the show!\n");
    return 0;
}
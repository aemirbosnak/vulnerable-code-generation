//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/types.h>
#include <pwd.h>

#define MAX_PROCESSES 1024
#define BUFFER_SIZE 256

typedef struct {
    pid_t pid;
    char user[32];
    long unsigned int memory;
    char command[BUFFER_SIZE];
} ProcessInfo;

void get_process_info(ProcessInfo *processes, int *count) {
    struct dirent *entry;
    DIR *dp = opendir("/proc");
    
    if (!dp) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    *count = 0;
    while ((entry = readdir(dp)) != NULL) {
        if (entry->d_type == DT_DIR) {
            if (isdigit(entry->d_name[0])) {
                ProcessInfo proc;
                proc.pid = atoi(entry->d_name);

                // Get user information
                char commfile[BUFFER_SIZE];
                snprintf(commfile, sizeof(commfile), "/proc/%s/comm", entry->d_name);
                FILE *commfp = fopen(commfile, "r");
                if (commfp) {
                    fgets(proc.command, sizeof(proc.command), commfp);
                    strtok(proc.command, "\n"); // Strip newline
                    fclose(commfp);
                }

                // Get memory usage
                char statfile[BUFFER_SIZE];
                snprintf(statfile, sizeof(statfile), "/proc/%s/statm", entry->d_name);
                FILE *statfp = fopen(statfile, "r");
                if (statfp) {
                    fscanf(statfp, "%*s %lu", &proc.memory); // Total memory used
                    fclose(statfp);
                }

                // Get user name from UID
                struct passwd *pw;
                char statinfo[BUFFER_SIZE];
                snprintf(statinfo, sizeof(statinfo), "/proc/%s/stat", entry->d_name);
                FILE *statfp2 = fopen(statinfo, "r");
                if (statfp2) {
                    int uid;
                    fscanf(statfp2, "%*d %*s %*s %*s %d", &uid);
                    pw = getpwuid(uid);
                    if (pw) {
                        strncpy(proc.user, pw->pw_name, sizeof(proc.user));
                    } else {
                        strncpy(proc.user, "unknown", sizeof(proc.user));
                    }
                    fclose(statfp2);
                }

                processes[*count] = proc;
                (*count)++;
            }
        }
    }
    
    closedir(dp);
}

void display_processes(ProcessInfo *processes, int count) {
    printf("%-10s %-15s %-10s %-50s\n", "PID", "USER", "MEMORY", "COMMAND");
    printf("------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-10d %-15s %-10lu %-50s\n", processes[i].pid, processes[i].user, processes[i].memory, processes[i].command);
    }
}

int main() {
    ProcessInfo processes[MAX_PROCESSES];
    int process_count = 0;

    get_process_info(processes, &process_count);
    display_processes(processes, process_count);

    return 0;
}
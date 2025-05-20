//FormAI DATASET v1.0 Category: System process viewer ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#define MAX_PATH 1024
#define MAX_CMDLINE_LEN 100
#define MAX_NAME_LEN 256
#define MAX_STATUS_LEN 256

typedef struct proc_info {
    int pid;
    char name[MAX_NAME_LEN];
    char state;
    char status[MAX_STATUS_LEN];
    char cmdline[MAX_CMDLINE_LEN];
} proc_info_t;

int get_proc_info(int pid, proc_info_t *proc_info) {
    // read /proc/{pid}/status file
    char path[MAX_PATH];
    snprintf(path, MAX_PATH, "/proc/%d/status", pid);
    FILE *fp = fopen(path, "r");
    if (!fp) {
        return 0;
    }
    char line[MAX_PATH];
    while (fgets(line, MAX_PATH, fp)) {
        if (strncmp(line, "Name:", 5) == 0) {
            sscanf(line + 5, "%s", proc_info->name);
        } else if (strncmp(line, "State:", 6) == 0) {
            sscanf(line + 6, " %c", &proc_info->state);
        } else if (strncmp(line, "Status:", 7) == 0) {
            sscanf(line + 7, " %[^\n]", proc_info->status);
        }
    }
    fclose(fp);

    // read /proc/{pid}/cmdline file
    snprintf(path, MAX_PATH, "/proc/%d/cmdline", pid);
    fp = fopen(path, "r");
    if (!fp) {
        return 0;
    }
    char cmdline[MAX_PATH];
    fgets(cmdline, MAX_PATH, fp);
    fclose(fp);

    // clean up cmdline
    int len = strlen(cmdline);
    for (int i = 0; i < len; i++) {
        if (cmdline[i] == '\0') {
            cmdline[i] = ' ';
        }
    }
    ssize_t end = len - 1;
    while (end >= 0 && isspace(cmdline[end])) {
        cmdline[end] = '\0';
        end--;
    }
    strncpy(proc_info->cmdline, cmdline, MAX_CMDLINE_LEN);

    return 1;
}

void print_proc_info(const proc_info_t *proc_info) {
    printf("%-10d %-20.20s %-10c %-60.60s %-s\n",
           proc_info->pid, proc_info->name, proc_info->state, proc_info->status, proc_info->cmdline);
}

int main(void) {
    printf("PID       NAME                 STATE      STATUS                                                         CMDLINE\n");

    DIR *dirp = opendir("/proc");
    if (!dirp) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    struct dirent *direntp;
    while ((direntp = readdir(dirp))) {
        if (!isdigit(*(direntp->d_name))) {
            continue;
        }
        int pid = atoi(direntp->d_name);
        proc_info_t proc_info;
        if (get_proc_info(pid, &proc_info)) {
            print_proc_info(&proc_info);
        }
    }
    closedir(dirp);

    return EXIT_SUCCESS;
}
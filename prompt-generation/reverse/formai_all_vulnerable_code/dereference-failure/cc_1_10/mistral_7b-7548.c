//MISTRAL-7B DATASET v1.0 Category: System process viewer ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <fcntl.h>

#define MAX_PROCS 100
#define PROC_NAME_LEN 32
#define STAT_SIZE 8
#define PID_LEN 5
#define COMMAND_LEN 128

typedef struct {
    pid_t pid;
    char name[PROC_NAME_LEN];
    char cmdline[COMMAND_LEN];
    long int state;
} proc_info_t;

void read_proc_stat(proc_info_t *proc_info, pid_t pid) {
    char filename[PID_LEN + 5];
    int fd;
    int i;

    snprintf(filename, sizeof(filename), "/proc/%d/status", pid);
    fd = open(filename, O_RDONLY);
    if (fd < 0) {
        perror("Error opening process status file");
        return;
    }

    read(fd, &proc_info->state, STAT_SIZE);
    close(fd);

    snprintf(filename, sizeof(filename), "/proc/%d/cmdline", pid);
    fd = open(filename, O_RDONLY);
    if (fd >= 0) {
        read(fd, proc_info->cmdline, COMMAND_LEN - 1);
        close(fd);
        proc_info->cmdline[COMMAND_LEN - 1] = '\0';
    }

    strncpy(proc_info->name, basename(filename), PROC_NAME_LEN);
}

int main() {
    proc_info_t proc_info[MAX_PROCS];
    DIR *dir;
    struct dirent *entry;
    pid_t pids[MAX_PROCS];
    int num_procs = 0;

    if (!(dir = opendir("/proc"))) {
        perror("Error opening /proc directory");
        return 1;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (isdigit(*entry->d_name)) {
            pids[num_procs] = atoi(entry->d_name);
            num_procs++;
            if (num_procs >= MAX_PROCS) {
                break;
            }
        }
    }

    for (int i = 0; i < num_procs; i++) {
        read_proc_stat(&proc_info[i], pids[i]);
        printf("Process ID: %d, Name: %s, State: %s, Command Line: %s\n",
                proc_info[i].pid, proc_info[i].name,
                (proc_info[i].state & 0x0000FF00) >> 8,
                proc_info[i].cmdline);
    }

    closedir(dir);
    return 0;
}
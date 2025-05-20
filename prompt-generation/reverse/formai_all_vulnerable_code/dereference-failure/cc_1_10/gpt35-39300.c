//FormAI DATASET v1.0 Category: System process viewer ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

#define MAX_PROCESSES 1024

struct process_info {
    char name[256];
    int pid;
    char state[20];
    char cmdline[1024];
};

int read_proc_stat(char *path, int *pid, char *name, char *state);
int read_proc_cmdline(char *path, char *cmdline);

int main(int argc, char **argv) {
    int i, count;
    char path[256], cmdline[1024];
    struct process_info processes[MAX_PROCESSES];

    // Read all process information into array
    count = 0;
    DIR *dirp = opendir("/proc");
    struct dirent *dp;
    while ((dp = readdir(dirp)) != NULL && count < MAX_PROCESSES) {
        // Skip directories that aren't PIDs
        if (!isdigit(dp->d_name[0])) continue;

        int pid;
        strcpy(path, "/proc/");
        strcat(path, dp->d_name);

        if (read_proc_stat(path, &pid, processes[count].name, processes[count].state) == 0) {
            processes[count].pid = pid;
            read_proc_cmdline(path, processes[count].cmdline);
            count++;
        }
    }
    closedir(dirp);

    // Print process information
    printf("%5s %20s %20s %s\n", "PID", "NAME", "STATE", "CMDLINE");
    for (i = 0; i < count; i++) {
        printf("%5d %20s %20s %s\n", processes[i].pid, processes[i].name, processes[i].state, processes[i].cmdline);
    }

    return 0;
}

// Read /proc/[pid]/stat file to get process name and state
// Returns 0 on success, -1 on error
int read_proc_stat(char *path, int *pid, char *name, char *state) {
    char buf[1024];
    FILE *fp;

    strcpy(buf, path);
    strcat(buf, "/stat");
    fp = fopen(buf, "r");
    if (fp == NULL) {
        perror("fopen");
        return -1;
    }

    if (fscanf(fp, "%d %s %s\n", pid, name, state) != 3) {
        perror("fscanf");
        fclose(fp);
        return -1;
    }

    fclose(fp);
    return 0;
}

// Read /proc/[pid]/cmdline file to get process command line
// Returns 0 on success, -1 on error
int read_proc_cmdline(char *path, char *cmdline) {
    char buf[1024];
    FILE *fp;

    strcpy(buf, path);
    strcat(buf, "/cmdline");
    fp = fopen(buf, "r");
    if (fp == NULL) {
        perror("fopen");
        return -1;
    }

    if (fgets(cmdline, 1024, fp) == NULL) {
        perror("fgets");
        fclose(fp);
        return -1;
    }

    fclose(fp);
    return 0;
}
//FormAI DATASET v1.0 Category: System process viewer ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

#define MAX_STAT_PATH_LEN 1024
#define MAX_COMM_LEN 1024

typedef struct process_info {
    int pid;
    int ppid;
    char state;
    char comm[MAX_COMM_LEN];
} process_info;

void get_process_info(char *stat_path, process_info *info) {
    FILE *fp;
    char buf[MAX_COMM_LEN];
    int ppid;

    fp = fopen(stat_path, "r");

    // Read pid, and ignore the rest.
    fscanf(fp, "%d ", &info->pid);
    fgets(buf, MAX_COMM_LEN, fp);

    // Read ppid.
    fgets(buf, MAX_COMM_LEN, fp);
    sscanf(buf, "PPid: %d", &ppid);
    info->ppid = ppid;

    // Read state.
    fscanf(fp, "%c ", &info->state);

    // Read comm.
    fgets(buf, MAX_COMM_LEN, fp);
    sscanf(buf, "%*d %*d %*d %*d %*d %*u %*lu %*lu %*lu %*lu "
                "%*lu %*lu %*lu %*ld %*ld %*ld %*ld %*ld %*ld "
                "%*ld %*llu %*lu %*ld %*lu %*lu %*lu %s",
                info->comm);

    fclose(fp);
}

void print_process_info(process_info *info) {
    printf("%5d %5d %5c %s\n", info->pid, info->ppid, info->state, info->comm);
}

void list_processes() {
    DIR *dir;
    struct dirent *ent;

    printf("%5s %5s %5s %s\n", "PID", "PPID", "STAT", "COMMAND");

    dir = opendir("/proc");

    if (dir == NULL) {
        perror("opendir failed");
        exit(EXIT_FAILURE);
    }

    while ((ent = readdir(dir)) != NULL) {
        int pid;

        // Check if it's a directory.
        if (!isdigit(ent->d_name[0])) {
            continue;
        }

        pid = atoi(ent->d_name);

        char stat_path[MAX_STAT_PATH_LEN];
        snprintf(stat_path, MAX_STAT_PATH_LEN, "/proc/%d/stat", pid);

        process_info info;
        get_process_info(stat_path, &info);

        print_process_info(&info);
    }

    closedir(dir);
}

int main() {
    list_processes();
    return 0;
}
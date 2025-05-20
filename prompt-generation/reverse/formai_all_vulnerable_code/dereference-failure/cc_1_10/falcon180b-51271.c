//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: imaginative
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>

#define MAX_PROCESS_NAME 64

struct process {
    pid_t pid;
    char name[MAX_PROCESS_NAME];
};

int main(int argc, char *argv[]) {
    DIR *dp;
    struct dirent *dirp;
    int nprocs = 0;
    struct process *procs = NULL;

    if ((dp = opendir("/proc")) == NULL) {
        perror("opendir");
        exit(1);
    }

    while ((dirp = readdir(dp))!= NULL) {
        if (dirp->d_type == DT_DIR) {
            pid_t pid = atoi(dirp->d_name);
            char path[64];
            snprintf(path, sizeof(path), "/proc/%d/cmdline", pid);

            int fd = open(path, O_RDONLY);
            char cmdline[1024];
            read(fd, cmdline, sizeof(cmdline));
            close(fd);

            // Extract process name from cmdline
            char *token = strtok(cmdline, " ");
            if (token!= NULL) {
                strncpy(procs[nprocs].name, token, MAX_PROCESS_NAME);
            }

            procs[nprocs].pid = pid;
            nprocs++;
            procs = realloc(procs, sizeof(struct process) * nprocs);
        }
    }

    closedir(dp);

    printf("PID\tName\n");
    for (int i = 0; i < nprocs; i++) {
        printf("%d\t%s\n", procs[i].pid, procs[i].name);
    }

    free(procs);

    return 0;
}
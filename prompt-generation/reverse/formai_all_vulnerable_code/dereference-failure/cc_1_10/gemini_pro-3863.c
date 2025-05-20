//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>

#define MAX_FILES 256

void print_proc_info(pid_t pid) {
    char buf[256];
    int fd;

    snprintf(buf, sizeof(buf), "/proc/%d/stat", pid);
    fd = open(buf, O_RDONLY);
    if (fd < 0) {
        perror("open");
        return;
    }

    read(fd, buf, sizeof(buf));
    close(fd);

    char *state = strtok(buf, " ");
    char *ppid = strtok(NULL, " ");
    char *utime = strtok(NULL, " ");
    char *stime = strtok(NULL, " ");
    char *cutime = strtok(NULL, " ");
    char *cstime = strtok(NULL, " ");

    printf("%d: %s %s %s %s %s %s\n", pid, state, ppid, utime, stime, cutime, cstime);
}

int main() {
    DIR *proc = opendir("/proc");
    if (proc == NULL) {
        perror("opendir");
        return 1;
    }

    struct dirent *entry;
    pid_t pids[MAX_FILES];
    int num_pids = 0;

    while ((entry = readdir(proc)) != NULL) {
        if (entry->d_type != DT_DIR) {
            continue;
        }

        pid_t pid = atoi(entry->d_name);
        if (pid > 0) {
            pids[num_pids++] = pid;
        }
    }

    closedir(proc);

    for (int i = 0; i < num_pids; i++) {
        print_proc_info(pids[i]);
    }

    return 0;
}
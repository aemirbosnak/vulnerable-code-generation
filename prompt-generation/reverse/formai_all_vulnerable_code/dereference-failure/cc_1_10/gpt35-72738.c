//FormAI DATASET v1.0 Category: System process viewer ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <ctype.h>

#define BUF_SIZE 1024

int main(){

    DIR *dir;
    struct dirent *entry;

    char path[BUF_SIZE], buff[BUF_SIZE];
    char name[BUF_SIZE], state;
    int pid, ppid, pgrp, session, tty_nr, tpgid;
    unsigned int flags;
    unsigned long int minflt, cminflt, majflt, cmajflt, utime, stime, starttime;
    long int cutime, cstime, priority, nice, num_threads, itrealvalue, rss;

    FILE* fd;

    printf("%5s %5s %5s %5s %5s %5s %5s %5s %5s %5s %5s %5s %5s %5s %20s\n",
            "UID", "PID", "PPID", "PGRP", "SESSION", "TTY_NR", "TPGID",
            "FLAGS", "MINFLT", "CMINFLT", "MAJFLT", "CMAJFLT", "UTIME", "STIME", "COMMAND");

    dir = opendir("/proc/");
    if (!dir) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dir)) != NULL) {

        if (!isdigit(*entry->d_name))
            continue;

        pid = atoi(entry->d_name);

        sprintf(path, "/proc/%d/stat", pid);
        fd = fopen(path, "r");

        if (!fd) {
            perror("fopen");
            exit(EXIT_FAILURE);
        }

        fscanf(fd, "%d %s %c %d %d %d %d %d %u %lu %lu %lu %lu %ld %ld %ld %ld %ld %ld %ld %ld %lu %lu %ld",
                &pid, buff, &state, &ppid, &pgrp, &session, &tty_nr, &tpgid,
                &flags, &minflt, &cminflt, &majflt, &cmajflt, &utime, &stime,
                &cutime, &cstime, &priority, &nice, &num_threads, &itrealvalue, &starttime,
                &rss);

        fclose(fd);

        sprintf(path, "/proc/%d/cmdline", pid);
        fd = fopen(path, "r");

        if (!fd) {
            perror("fopen");
            exit(EXIT_FAILURE);
        }

        fgets(name, BUF_SIZE, fd);
        fclose(fd);

        printf("%5d %5d %5d %5d %5d %5d %5d %5u %5lu %5lu %5lu %5lu %5lu %5ld %5ld %5ld %5ld %5ld %5ld %5ld %5ld %5lu %5lu %5ld %20s\n",
                getuid(), pid, ppid, pgrp, session, tty_nr, tpgid,
                flags, minflt, cminflt, majflt, cmajflt, utime, stime, cutime+cstime, priority, nice, num_threads, itrealvalue, starttime,
                rss, name);
    }

    closedir(dir);
    return 0;
}
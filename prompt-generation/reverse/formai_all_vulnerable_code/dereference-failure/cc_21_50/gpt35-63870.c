//FormAI DATASET v1.0 Category: System process viewer ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define BUF_SIZE 1024

int main(void) {
    DIR *dir_ptr;
    struct dirent *entry_ptr;
    FILE *stat_fp;
    char stat_path[BUF_SIZE];
    char line[BUF_SIZE];
    char *pch;
    int pid;
    char comm[BUF_SIZE];
    char state;
    int ppid;
    int pgrp;
    int session;
    int tty_nr;
    int tpgid;
    unsigned long flags;
    unsigned long minflt;
    unsigned long cminflt;
    unsigned long majflt;
    unsigned long cmajflt;
    unsigned long utime;
    unsigned long stime;
    long cutime;
    long cstime;
    long int priority;
    long int nice;
    long int time;
    unsigned long int starttime;
    unsigned long int vsize;
    long int rss;

    printf("%-20s %-6s %-6s %-6s %-6s %-8s %-8s %-6s %-8s %-8s %-12s %-12s\n", "COMMAND", "PID", "PPID", "PGRP", "SESSION", "STATE", "UTIME", "STIME", "RSS", "VSZ", "STARTTIME", "TIME");

    dir_ptr = opendir("/proc");

    if (dir_ptr == NULL) {
        printf("Error: could not open directory /proc\n");
        exit(EXIT_FAILURE);
    }

    while ((entry_ptr = readdir(dir_ptr))) {
        if (entry_ptr->d_type != DT_DIR) {
            continue;
        }

        pid = atoi(entry_ptr->d_name);

        if (pid == 0) {
            continue;
        }

        sprintf(stat_path, "/proc/%d/stat", pid);

        stat_fp = fopen(stat_path, "r");

        if (stat_fp == NULL) {
            continue;
        }

        fgets(line, BUF_SIZE, stat_fp);

        pch = strtok(line, " ");

        if (pch == NULL) {
            continue;
        }

        strcpy(comm, pch);

        pch = strtok(NULL, " ");

        if (pch == NULL) {
            continue;
        }

        state = *(pch + 0);

        pch = strtok(NULL, " ");

        if (pch == NULL) {
            continue;
        }

        ppid = atoi(pch);

        pch = strtok(NULL, " ");

        if (pch == NULL) {
            continue;
        }

        pgrp = atoi(pch);

        pch = strtok(NULL, " ");

        if (pch == NULL) {
            continue;
        }

        session = atoi(pch);

        pch = strtok(NULL, " ");

        if (pch == NULL) {
            continue;
        }

        tty_nr = atoi(pch);

        pch = strtok(NULL, " ");

        if (pch == NULL) {
            continue;
        }

        tpgid = atoi(pch);

        pch = strtok(NULL, " ");

        if (pch == NULL) {
            continue;
        }

        flags = atol(pch);

        pch = strtok(NULL, " ");

        if (pch == NULL) {
            continue;
        }

        minflt = atol(pch);

        pch = strtok(NULL, " ");

        if (pch == NULL) {
            continue;
        }

        cminflt = atol(pch);

        pch = strtok(NULL, " ");

        if (pch == NULL) {
            continue;
        }

        majflt = atol(pch);

        pch = strtok(NULL, " ");

        if (pch == NULL) {
            continue;
        }

        cmajflt = atol(pch);

        pch = strtok(NULL, " ");

        if (pch == NULL) {
            continue;
        }

        utime = atol(pch);

        pch = strtok(NULL, " ");

        if (pch == NULL) {
            continue;
        }

        stime = atol(pch);

        pch = strtok(NULL, " ");

        if (pch == NULL) {
            continue;
        }

        cutime = atol(pch);

        pch = strtok(NULL, " ");

        if (pch == NULL) {
            continue;
        }

        cstime = atol(pch);

        pch = strtok(NULL, " ");

        if (pch == NULL) {
            continue;
        }

        priority = atol(pch);

        pch = strtok(NULL, " ");

        if (pch == NULL) {
            continue;
        }

        nice = atol(pch);

        pch = strtok(NULL, " ");

        if (pch == NULL) {
            continue;
        }

        time = atol(pch);

        pch = strtok(NULL, " ");

        if (pch == NULL) {
            continue;
        }

        starttime = atol(pch);

        pch = strtok(NULL, " ");

        if (pch == NULL) {
            continue;
        }

        vsize = atol(pch);

        pch = strtok(NULL, " ");

        if (pch == NULL) {
            continue;
        }

        rss = atol(pch);

        fclose(stat_fp);

        printf("%-20s %-6d %-6d %-6d %-6d %-8c %-8lu %-6lu %-8ld %-8lu %-12lu %-12ld\n", comm, pid, ppid, pgrp, session, state, utime, stime, rss, vsize, starttime, time);
    }

    closedir(dir_ptr);

    return 0;
}
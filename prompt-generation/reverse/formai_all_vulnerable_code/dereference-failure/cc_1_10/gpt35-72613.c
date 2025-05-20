//FormAI DATASET v1.0 Category: System process viewer ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#define PROCESS_PATH "/proc"

// function to extract process id from directory names
int get_pid_from_dirname(const char *dirname) {
    int pid = 0;
    int len = strlen(dirname);
    for(int i = 0; i < len; i++) {
        if(isdigit(dirname[i])) {
            pid = pid * 10 + (dirname[i] - '0');
        } else {
            return -1;
        }
    }
    return pid;
}

// function to read and output process information
void read_proc_stats(const char *pname) {
    char stat_path[512];
    char line[512];
    int pid, ppid, pgrp, threads;
    long unsigned int utime, stime, vsize;

    // prepare path to stat file
    sprintf(stat_path, "/proc/%s/stat", pname);

    // open file and read data
    FILE *fp = fopen(stat_path, "r");
    if(fp != NULL) {
        fgets(line, sizeof(line), fp);
        sscanf(line, "%d %*s %*c %d %d %*s %*s %*s %*s %lu %lu %*s %*s %*s %*s %ld %ld %*s %*s %d",
               &pid, &ppid, &pgrp, &utime, &stime, &vsize, &threads);
        fclose(fp);

        // output process information
        printf("| %5d | %5d | %5d | %5lu | %5lu | %10lu | %-15s |\n",
               pid, ppid, pgrp, utime, stime, vsize, pname);
    }
}

int main(void) {
    DIR *dirp;
    struct dirent *de;

    printf("+-------+-------+-------+-------+-------+------------+-----------------+\n");
    printf("| PID   | PPID  |  PGRP | UTIME | STIME |    VSIZE   | NAME            |\n");
    printf("+-------+-------+-------+-------+-------+------------+-----------------+\n");

    // read all directories in the process path
    dirp = opendir(PROCESS_PATH);
    if(dirp == NULL) {
        perror("Cannot open directory");
        exit(EXIT_FAILURE);
    }
    while((de = readdir(dirp)) != NULL) {
        if(isdigit(de->d_name[0])) {
            // this is a process directory, extract process id and read information
            int pid = get_pid_from_dirname(de->d_name);
            if(pid > 0) {
                read_proc_stats(de->d_name);
            }
        }
    }
    closedir(dirp);
    printf("+-------+-------+-------+-------+-------+------------+-----------------+\n");

    return EXIT_SUCCESS;
}
//FormAI DATASET v1.0 Category: System process viewer ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

void printProcessInfo(char *pid) {
    char statPath[50], statusPath[50];
    FILE *statFile, *statusFile;

    // Construct paths for stat and status files
    sprintf(statPath, "/proc/%s/stat", pid);
    sprintf(statusPath, "/proc/%s/status", pid);

    // Open stat file
    statFile = fopen(statPath, "r");
    if (statFile == NULL) {
        printf("Unable to open stat file for process %s\n", pid);
        return;
    }

    // Open status file
    statusFile = fopen(statusPath, "r");
    if (statusFile == NULL) {
        printf("Unable to open status file for process %s\n", pid);
        return;
    }

    // Parse and print process info from stat file
    char name[50], state, comm[50];
    int ppid, pgrp, session, tty_nr, tpgid;
    unsigned int flags;
    long int utime, stime, cutime, cstime, start_time;
    fscanf(statFile, "%s %s %c %d %d %d %d %d %u %lu %lu %ld %ld %ld %ld %ld",
           pid, comm, &state, &ppid, &pgrp, &session, &tty_nr, &tpgid, &flags, &utime, &stime,
           &cutime, &cstime, &start_time);
    printf("%-7s%-20s%-7c%-7d%-7d%-7u%-7ld%-7ld", pid, comm, state, ppid, pgrp, session,
           tty_nr, tpgid);

    // Parse and print NICE value from status file
    char line[100], nice[10];
    while (fgets(line, sizeof(line), statusFile) != NULL) {
        if (strncmp(line, "Nice:", 5) == 0) {
            sscanf(line + 5, "%s", nice);
            printf("%-7s", nice);
            break;
        }
    }

    printf("\n");

    // Close stat and status files
    fclose(statFile);
    fclose(statusFile);
}

int main() {
    DIR *dir;
    struct dirent *dirEntry;

    printf("%-7s%-20s%-7s%-7s%-7s%-7s%-7s%-7s\n", "PID", "COMM", "STAT", "PPID", "PGRP",
           "SESSION", "TTY_NR", "TPGID");
    printf("%s\n", "--------------------------------------------------------");

    // Open the /proc directory
    dir = opendir("/proc");
    if (dir == NULL) {
        printf("Unable to open /proc directory\n");
        exit(EXIT_FAILURE);
    }

    // Iterate through the /proc directory and print process info for each PID subdirectory
    while ((dirEntry = readdir(dir)) != NULL) {
        if (isdigit(dirEntry->d_name[0])) {
            printProcessInfo(dirEntry->d_name);
        }
    }

    // Close the /proc directory and exit
    closedir(dir);
    return 0;
}
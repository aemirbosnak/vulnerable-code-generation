//FormAI DATASET v1.0 Category: System process viewer ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

// function to check if string is a number
int isNumber(char* str) {
    int i;
    for (i = 0; i < strlen(str); i++) {
        if (!isdigit(str[i]))
            return 0; // not a number
    }
    return 1; // is a number
}

// main function
int main() {
    DIR* dir;
    struct dirent* entry;
    char path[50], line[100], name[100], user[100], state[10], command[100];
    int pid, ppid, priority, numThreads, numFd;

    // open '/proc' directory
    dir = opendir("/proc");

    // iterate through each directory in '/proc'
    while ((entry = readdir(dir)) != NULL) {
        // check if directory name is a number (process id)
        if (isNumber(entry->d_name)) {
            // generate path to process information files
            strcpy(path, "/proc/");
            strcat(path, entry->d_name);
            strcat(path, "/stat");

            // open process information file
            FILE* fp = fopen(path, "r");
            if (fp == NULL) {
                perror("Error opening file");
                return 1;
            }

            // read process information file
            fgets(line, 100, fp);

            // parse process information into variables
            sscanf(line, "%d (%[^)]s %c %d %d %d %d %*s %*s %*s %*s %*s %d %d %d %d %d %d %d %*s %d %*s %*s %*s %lu %lu %*s %lu %*s %*s %ld %ld %ld %ld %*s %llu %lu",
                &pid, name, &state[0], &ppid, &priority, &numThreads, &numFd, &user[0], &user[1],
                &user[2], &user[3], &user[4], &user[5], &user[6], &user[7], &user[8], &user[9]);

            // generate path to command information file
            strcpy(path, "/proc/");
            strcat(path, entry->d_name);
            strcat(path, "/cmdline");

            // open command information file
            fp = fopen(path, "r");
            if (fp == NULL) {
                perror("Error opening file");
                return 1;
            }

            // read command information file
            fgets(command, 100, fp);

            // print process information
            printf("PID: %d\n", pid);
            printf("Name: %s\n", name);
            printf("State: %c\n", state[0]);
            printf("PPID: %d\n", ppid);
            printf("Priority: %d\n", priority);
            printf("Number of Threads: %d\n", numThreads);
            printf("Number of File Descriptors: %d\n", numFd);
            printf("Command: %s\n", command);

            // close files
            fclose(fp);
        }
    }

    // close directory
    closedir(dir);

    return 0;
}
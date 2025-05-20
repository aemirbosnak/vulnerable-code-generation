//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_SIZE 1024 // max size of buffer to read

int main() {
    char buffer[MAX_SIZE];
    int pid;
    FILE *fp;

    // get pid of current process
    pid = getpid();

    // open /proc/self/statm file for reading
    sprintf(buffer, "/proc/%d/statm", pid);
    fp = fopen(buffer, "r");

    if (fp == NULL) {
        printf("Error opening /proc/%d/statm\n", pid);
        exit(1);
    }

    // read contents of /proc/self/statm
    if (fread(buffer, 1, MAX_SIZE, fp) <= 0) {
        printf("Error reading /proc/%d/statm\n", pid);
        exit(2);
    }

    // close /proc/self/statm file
    fclose(fp);

    // parse contents of /proc/self/statm to get RAM usage
    int ram_usage = 0;
    char *token = strtok(buffer, " ");
    while (token!= NULL) {
        if (strcmp(token, "size") == 0) {
            token = strtok(NULL, " ");
            ram_usage = atoi(token);
            break;
        }
        token = strtok(NULL, " ");
    }

    // print RAM usage in KB
    printf("RAM usage: %d KB\n", ram_usage);

    return 0;
}
//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[]) {
    char pid[MAX_LINE_LENGTH];
    char command[MAX_LINE_LENGTH];

    // check if process ID argument is provided
    if (argc == 1) {
        printf("Please provide the process ID as an argument.\n");
        return 0;
    }

    // get process ID from argument provided
    strcpy(pid, argv[1]);

    // create command to get RAM usage from /proc/{PID}/status
    sprintf(command, "grep '^VmRSS:' /proc/%s/status | awk '{print $2}'", pid);

    // loop to constantly monitor RAM usage
    while (1) {
        FILE* fp = popen(command, "r");
        if (fp == NULL) {
            printf("Failed to get RAM usage.\n");
            return 0;
        }

        char output[MAX_LINE_LENGTH];
        if (fgets(output, MAX_LINE_LENGTH, fp) == NULL) {
            printf("Failed to read RAM usage.\n");
            pclose(fp);
            return 0;
        }
        pclose(fp);

        // remove newline character from output
        strtok(output, "\n");

        // convert RAM usage to integer
        int ram_usage = atoi(output);

        // print RAM usage
        printf("RAM usage: %d kB\n", ram_usage);

        // sleep for one second before repeating loop
        sleep(1);
    }

    return 0;
}
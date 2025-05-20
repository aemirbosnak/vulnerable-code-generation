//FormAI DATASET v1.0 Category: System process viewer ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <ctype.h>
#include <string.h>

#define MAX_PID_LENGTH 16
#define MAX_PROCESS_NAME_LENGTH 256

/* Struct for holding process information */
typedef struct {
    char pid[MAX_PID_LENGTH];
    char name[MAX_PROCESS_NAME_LENGTH];
    char state;
    unsigned long int memory;
} ProcessInfo;

int main() {
    DIR *dir;
    struct dirent *dent;
    ProcessInfo processInfo;

    printf("The following processes are currently running on this system:\n");

    /* Open the /proc directory */
    dir = opendir("/proc");
    if (dir == NULL) {
        perror("Failed to open /proc directory");
        exit(1);
    }

    /* Iterate over the directories in /proc */
    while ((dent = readdir(dir)) != NULL) {
        /* Check if the directory name is a number */
        if (isdigit(dent->d_name[0])) {
            /* Extract the process ID */
            strcpy(processInfo.pid, dent->d_name);

            /* Open the cmdline file for the process */
            char filePath[MAX_PID_LENGTH + 10];
            sprintf(filePath, "/proc/%s/cmdline", dent->d_name);
            FILE *cmdlineFile = fopen(filePath, "r");
            if (cmdlineFile == NULL) {
                fprintf(stderr, "Failed to open %s\n", filePath);
                continue;
            }

            /* Read the process name from the cmdline file */
            fgets(processInfo.name, MAX_PROCESS_NAME_LENGTH, cmdlineFile);
            fclose(cmdlineFile);

            /* Remove newline characters from the process name */
            size_t length = strlen(processInfo.name);
            while (length > 0 && (processInfo.name[length - 1] == '\n' || processInfo.name[length - 1] == '\0')) {
                processInfo.name[length - 1] = '\0';
                length--;
            }

            /* Open the stat file for the process */
            sprintf(filePath, "/proc/%s/stat", dent->d_name);
            FILE *statFile = fopen(filePath, "r");
            if (statFile == NULL) {
                fprintf(stderr, "Failed to open %s\n", filePath);
                continue;
            }

            /* Read the state and memory usage from the stat file */
            fscanf(statFile, "%*s %*s %c %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %lu", &processInfo.state, &processInfo.memory);
            fclose(statFile);

            /* Print the process information */
            printf("PID: %s  Name: %s  State: %c  Memory: %lu\n", processInfo.pid, processInfo.name, processInfo.state, processInfo.memory);
        }
    }

    closedir(dir);

    return 0;
}
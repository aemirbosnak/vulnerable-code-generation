//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>
#include <time.h>

// Custom data structure to store process information
typedef struct {
    pid_t pid;
    char *name;
    char *username;
    char *state;
    time_t time;
} Process;

// Function to compare two processes by their time
int compareProcesses(const void *a, const void *b) {
    const Process *p1 = (const Process *)a;
    const Process *p2 = (const Process *)b;

    return difftime(p2->time, p1->time);
}

// Function to get the username of the process owner
char * getUsername(uid_t uid) {
    struct passwd *pw = getpwuid(uid);
    if (pw) {
        return pw->pw_name;
    } else {
        return "Unknown";
    }
}

// Function to get the process state
char * getProcessState(char state) {
    switch (state) {
        case 'R':
            return "Running";
        case 'S':
            return "Sleeping";
        case 'D':
            return "Disk sleep";
        case 'T':
            return "Stopped";
        case 't':
            return "Tracing stop";
        case 'W':
            return "Paging";
        case 'X':
            return "Dead";
        case 'Z':
            return "Zombie";
        default:
            return "Unknown";
    }
}

// Function to print process information
void printProcess(Process process) {
    printf("%5d %10s %10s %10s %20s\n", process.pid, process.name, process.username, process.state, ctime(&process.time));
}

// Function to scan the /proc directory and get process information
void scanProcDirectory() {
    DIR *procDir = opendir("/proc");
    if (!procDir) {
        perror("opendir");
        return;
    }

    struct dirent *entry;
    Process processes[100];
    int numProcesses = 0;

    while ((entry = readdir(procDir))) {
        if (!strcmp(entry->d_name, ".") || !strcmp(entry->d_name, "..")) {
            continue;
        }

        // Check if the directory is a process directory
        char *statFilePath = malloc(strlen("/proc/") + strlen(entry->d_name) + strlen("/stat") + 1);
        sprintf(statFilePath, "/proc/%s/stat", entry->d_name);
        if (access(statFilePath, F_OK) != 0) {
            free(statFilePath);
            continue;
        }

        // Read the process stat file
        FILE *statFile = fopen(statFilePath, "r");
        if (!statFile) {
            perror("fopen");
            free(statFilePath);
            continue;
        }

        // Parse the process stat file
        char buf[1024];
        fgets(buf, sizeof(buf), statFile);

        // Get the process name
        char *nameStart = strchr(buf, '(');
        char *nameEnd = strchr(buf, ')');
        char *name = malloc(nameEnd - nameStart + 1);
        strncpy(name, nameStart + 1, nameEnd - nameStart - 1);

        // Get the process username
        char *uidStr = strchr(buf, ')');
        uidStr += 2;
        uid_t uid = atoi(uidStr);
        char *username = getUsername(uid);

        // Get the process state
        char state = buf[2];
        char *processState = getProcessState(state);

        // Get the process time
        char *timeStr = strchr(buf, ')');
        timeStr += 19;
        time_t time = atoi(timeStr);

        // Store the process information
        processes[numProcesses].pid = atoi(entry->d_name);
        processes[numProcesses].name = name;
        processes[numProcesses].username = username;
        processes[numProcesses].state = processState;
        processes[numProcesses].time = time;

        numProcesses++;

        fclose(statFile);
        free(statFilePath);
    }

    closedir(procDir);

    // Sort the processes by their time
    qsort(processes, numProcesses, sizeof(Process), compareProcesses);

    // Print the process information
    printf("%5s %10s %10s %10s %20s\n", "PID", "NAME", "USER", "STATE", "TIME");
    for (int i = 0; i < numProcesses; i++) {
        printProcess(processes[i]);
        free(processes[i].name);
    }
}

int main() {
    scanProcDirectory();

    return 0;
}
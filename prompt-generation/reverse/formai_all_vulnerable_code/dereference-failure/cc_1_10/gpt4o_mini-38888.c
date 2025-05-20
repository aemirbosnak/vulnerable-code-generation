//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

#define MAX_BUFF 256
#define MAX_PROCESSES 1024

void displayHeader() {
    printf("\033[1;32m");
    printf("===============================================\n");
    printf("       Cyberpunk Process Viewer v1.0 !       \n");
    printf("===============================================\n");
    printf("\033[0m");
}

void displayProcess(int pid, const char *name, const char *user, const char *state, long int mem) {
    printf("\033[1;34mPID: %d | Name: %s | User: %s | State: %s | Memory: %ld KB\033[0m\n", pid, name, user, state, mem);
}

char* getProcessName(int pid) {
    char path[MAX_BUFF];
    snprintf(path, sizeof(path), "/proc/%d/comm", pid);
    FILE *file = fopen(path, "r");
    char *comm = malloc(MAX_BUFF);
    if (file) {
        fgets(comm, MAX_BUFF, file);
        comm[strcspn(comm, "\n")] = 0; // Remove newline
        fclose(file);
    } else {
        strcpy(comm, "Unknown");
    }
    return comm;
}

char* getUserById(uid_t uid) {
    struct passwd *pw = getpwuid(uid);
    return pw ? pw->pw_name : "Unknown";
}

char* getState(int pid) {
    char path[MAX_BUFF];
    snprintf(path, sizeof(path), "/proc/%d/stat", pid);
    FILE *file = fopen(path, "r");
    if (file) {
        int stateIndex;
        fscanf(file, "%*d %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %d", &stateIndex);
        fclose(file);
        switch (stateIndex) {
            case 0: return "Running";
            case 1: return "Sleeping";
            case 2: return "Waiting";
            case 3: return "Zombie";
            case 4: return "Stopped";
            default: return "Unknown";
        }
    }
    return "Unknown";
}

long int getMemoryUsage(int pid) {
    char path[MAX_BUFF];
    snprintf(path, sizeof(path), "/proc/%d/status", pid);
    FILE *file = fopen(path, "r");
    char line[MAX_BUFF];
    long int vmSize = 0;
    if (file) {
        while(fgets(line, sizeof(line), file)) {
            if (strncmp(line, "VmSize:", 7) == 0) {
                sscanf(line + 7, "%ld", &vmSize);
                break;
            }
        }
        fclose(file);
    }
    return vmSize;
}

void listProcesses() {
    DIR *dir = opendir("/proc");
    struct dirent *entry;
    displayHeader();
    while ((entry = readdir(dir)) != NULL) {
        if (isdigit(entry->d_name[0])) {
            int pid = atoi(entry->d_name);
            char *name = getProcessName(pid);
            char *user = getUserById(getuid());
            char *state = getState(pid);
            long int mem = getMemoryUsage(pid);
            displayProcess(pid, name, user, state, mem);
            free(name);
        }
    }
    closedir(dir);
}

int main() {
    while (1) {
        listProcesses();
        printf("\n\033[1;33mRefreshing... Press Ctrl+C to exit.\033[0m\n");
        sleep(3);
        printf("\033[H\033[J"); // Clear the screen
    }
    return 0;
}
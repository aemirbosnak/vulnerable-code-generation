//FormAI DATASET v1.0 Category: System process viewer ; Style: portable
#include <stdio.h>
#include <dirent.h>
#include <string.h>

// function to check if a string is a number
int isNumber(const char* str) {
    for (int i=0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

// function to get CPU usage
void getCPUUsage(int pid, float* cpuUsage) {
    char cmd[100];
    sprintf(cmd, "ps -p %d -o pcpu | tail -n +2", pid);
    FILE* file = popen(cmd, "r");
    if (file) {
        char buffer[10];
        fgets(buffer, 10, file);
        pclose(file);
        *cpuUsage = strtof(buffer, NULL);
    }
}

// function to get process details and print
void printProcessDetails(const char* pid) {
    char path[50];
    sprintf(path, "/proc/%s/", pid);

    DIR* dir = opendir(path);
    if (!dir) {
        return;
    }
    closedir(dir);

    char cmd[100];
    sprintf(cmd, "cat /proc/%s/status", pid);
    FILE* file = popen(cmd, "r");
    if (file) {
        printf("%-10s", pid);

        char buffer[100];
        while (fgets(buffer, 100, file)) {
            if (strncmp(buffer, "Name:", 5) == 0) {
                printf("%-20s", buffer + 6);
            } else if (strncmp(buffer, "State:", 6) == 0) {
                printf("%-10s", buffer + 7);
            } else if (strncmp(buffer, "PPid:", 5) == 0) {
                printf("%-10s", buffer + 6);
            } else if (strncmp(buffer, "Threads:", 8) == 0) {
                printf("%-10s", buffer + 9);
            }
        }
    }

    float cpuUsage = 0.0;
    getCPUUsage(atoi(pid), &cpuUsage);
    printf("%.2f%%\n", cpuUsage);
    pclose(file);
}

// main function
int main() {
    printf("%-10s%-20s%-10s%-10s%-10s%-10s\n", "PID", "NAME", "STATE", "PPID", "THREADS", "CPU");
    DIR* dir = opendir("/proc");
    if (dir) {
        struct dirent* p;
        while ((p=readdir(dir)) != NULL) {
            if (isNumber(p->d_name)) {
                printProcessDetails(p->d_name);
            }
        }
    }
    return 0;
}
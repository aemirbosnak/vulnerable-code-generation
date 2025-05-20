//FormAI DATASET v1.0 Category: System process viewer ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

void printProcessInfo(char *pid, char *prop) {
    char filename[100];
    char buffer[1024];
    FILE *f;

    sprintf(filename, "/proc/%s/%s", pid, prop);
    f = fopen(filename, "r");
    if (f != NULL) {
        fgets(buffer, sizeof(buffer), f);
        printf("%-20s: %s", prop, buffer);
        fclose(f);
    }
}

void printProcess(char *pid) {
    DIR *d;
    struct dirent *dir;
    d = opendir("/proc");
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            if (strcmp(dir->d_name, pid) == 0) {
                printProcessInfo(pid, "Name");
                printProcessInfo(pid, "State");
                printProcessInfo(pid, "PPid");
                printProcessInfo(pid, "Threads");
                printProcessInfo(pid, "VmSize");
                printProcessInfo(pid, "VmRSS");
                break;
            }
        }
        closedir(d);
    }
}

void printAllProcesses() {
    DIR *d;
    struct dirent *dir;
    char filename[100];
    FILE *f;
    char buffer[1024];

    d = opendir("/proc");
    if (d) {
        printf("%-10s %-20s %-20s %-10s %-15s %-10s\n", "PID", "Name", "State", "PPID", "Threads", "Memory");
        while ((dir = readdir(d)) != NULL) {
            if (dir->d_type == DT_DIR) {
                if (atoi(dir->d_name) != 0) {
                    printProcess(dir->d_name);
                }
            }
        }
        closedir(d);
    }
}

int main() {
    printAllProcesses();
    return 0;
}
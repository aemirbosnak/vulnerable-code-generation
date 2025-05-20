//FormAI DATASET v1.0 Category: System process viewer ; Style: grateful
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>

#define MAX_LEN 1024

struct Process {
    int pid;
    char name[MAX_LEN];
    char state[MAX_LEN];
    char user[MAX_LEN];
    int mem;
    char cmd[MAX_LEN];
};

void printHeader() {
    printf("%8s %-25s %-10s %-10s %12s %s\n", "PID", "NAME", "STATE", "USER", "MEM", "COMMAND");
}

char* getProcessState(char state) {
    static char str[MAX_LEN];
    switch(state) {
        case 'R':
            strcpy(str, "Running");
            break;
        case 'S':
            strcpy(str, "Sleeping");
            break;
        case 'D':
            strcpy(str, "Disk sleep");
            break;
        case 'Z':
            strcpy(str, "Zombie");
            break;
        case 'T':
            strcpy(str, "Stopped");
            break;
        case 't':
            strcpy(str, "Tracing stop");
            break;
        case 'X':
        case 'x':
            strcpy(str, "Dead");
            break;
        case 'K':
            strcpy(str, "Wakekill");
            break;
        case 'W':
            strcpy(str, "Waking");
            break;
        case 'P':
            strcpy(str, "Parked");
            break;
        default:
            strcpy(str, "Unknown");
    }
    return str;
}

void printProcess(struct Process p) {
    printf("%8d %-25s %-10s %-10s %12d %s\n", p.pid, p.name, p.state, p.user, p.mem, p.cmd);
}

void listProcesses() {
    struct dirent* dirEntry;
    DIR* dir = opendir("/proc");
    if (dir == NULL) {
        printf("Unable to open /proc directory");
        return;
    }

    printf("Listing processes...\n");
    printHeader();

    while ((dirEntry = readdir(dir)) != NULL) {
        if (isdigit(dirEntry->d_name[0])) {
            char path[MAX_LEN];
            memset(path, 0, sizeof(path));
            sprintf(path, "/proc/%s/stat", dirEntry->d_name);
            FILE* file = fopen(path, "r");
            if (file == NULL) {
                continue;
            }

            struct Process p;
            memset(&p, 0, sizeof(p));

            fscanf(file, "%d", &p.pid);
            char* name = strstr(dirEntry->d_name, "/");
            if (name == NULL) {
                strcpy(p.name, dirEntry->d_name);
            } else {
                strcpy(p.name, name + 1);
            }
            fscanf(file, " %s", p.cmd);
            fscanf(file, " %c", &p.state[0]);

            fclose(file);

            char* pMem;
            memset(path, 0, sizeof(path));
            sprintf(path, "/proc/%d/status", p.pid);
            file = fopen(path, "r");
            while (fgets(path, sizeof(path), file)) {
                if (strncmp(path, "VmSize:", 7) == 0) {
                    pMem = strtok(path + 7, " \t\n");
                    p.mem = atoi(pMem);
                    break;
                }
            }
            fclose(file);

            memset(path, 0, sizeof(path));
            sprintf(path, "/proc/%d/loginuid", p.pid);
            file = fopen(path, "r");
            if (file == NULL) {
                continue;
            }
            char loginUID[MAX_LEN];
            memset(loginUID, 0, sizeof(loginUID));
            fgets(loginUID, sizeof(loginUID), file);
            fclose(file);

            memset(path, 0, sizeof(path));
            sprintf(path, "/proc/%d/status", p.pid);
            file = fopen(path, "r");
            while (fgets(path, sizeof(path), file)) {
                if (strncmp(path, "Uid:", 4) == 0) {
                    char* uid = strtok(path + 4, " \t\n");
                    if (strcmp(uid, loginUID) == 0) {
                        strncpy(p.user, "CURRENT_USER", MAX_LEN);
                    } else {
                        strncpy(p.user, "OTHER_USER", MAX_LEN);
                    }
                    break;
                }
            }
            fclose(file);

            strncpy(p.state, getProcessState(p.state[0]), MAX_LEN);
            printProcess(p);
        }
    }
    closedir(dir);
}

int main() {
    listProcesses();
    return 0;
}
//FormAI DATASET v1.0 Category: System process viewer ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define MAX_PATH_SIZE 1024

struct ProcessInfo {
    int pid;
    char name[MAX_PATH_SIZE];
    char state[2];
    char ppid[10];
};

void printProcessInfo(struct ProcessInfo *pi) {
    printf("%-10d%-25s%-10s%-10s\n", pi->pid, pi->name, pi->state, pi->ppid);
}

int getProcInfo(char *path, struct ProcessInfo *pi) {
    FILE *fp;
    char buf[MAX_PATH_SIZE];
    char state;

    sprintf(buf, "%s/status", path);

    fp = fopen(buf, "r");
    if (!fp) {
        return 0;
    }

    while (fscanf(fp, "%s", buf) > 0) {
        if (strcmp(buf, "Name:") == 0) {
            fscanf(fp, "%s", pi->name);
        }
        else if (strcmp(buf, "State:") == 0) {
            fscanf(fp, "%c", &state);
            pi->state[0] = state;
            pi->state[1] = '\0';
        }
        else if (strcmp(buf, "PPid:") == 0) {
            fscanf(fp, "%s", pi->ppid);
        }
    }

    fclose(fp);

    return 1;
}

void printHeader() {
    printf("%-10s%-25s%-10s%-10s\n", "PID", "Name", "State", "PPID");
    printf("------------------------------------------\n");
}

int main(int argc, char **argv) {
    DIR *dir;
    struct dirent *ent;
    char path[MAX_PATH_SIZE];
    struct ProcessInfo pi;
  
    printHeader();

    dir = opendir("/proc");
    while ((ent = readdir(dir)) != NULL) {
        if (atoi(ent->d_name) > 0) {
            sprintf(path, "/proc/%s", ent->d_name);
            if (getProcInfo(path, &pi)) {
                pi.pid = atoi(ent->d_name);
                printProcessInfo(&pi);
            }
        }
    }

    closedir(dir);

    return 0;
}
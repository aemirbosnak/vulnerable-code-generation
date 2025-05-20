//FormAI DATASET v1.0 Category: System process viewer ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<unistd.h>
#include<string.h>
#include<dirent.h>
#include<sys/types.h>

int isProcessDir(char *dname) {
    int pid = 0, k = 0;
    int len = strlen(dname);
    if ((len <= 0) || !isdigit(dname[0])) {
        return 0;
    }
    for (int i = 0; i < len ; i++) {
        if (isdigit(dname[i])) {
            pid = pid * 10 + (int)dname[i] - 48;
        } else {
            k = 1; // non numeric
            break;
        }
    }
    if (k) {
        return 0;
    }
    char cmd[64] = {0};
    sprintf(cmd, "/proc/%d/status", pid);
    FILE *fp = fopen(cmd, "r");
    if (fp != NULL) {
        fclose(fp);
        return 1;
    }
    return 0;
}

void showStatusForProcess(char *dname) {
    char cmd[256] = {0};
    char path[64] = {0};
    sprintf(path, "/proc/%s", dname);
    chdir(path);
    sprintf(cmd, "cat status");
    system(cmd);
}

void listProcesses() {
    DIR *dirp;
    struct dirent *entry;
    dirp = opendir("/proc");
    if (dirp == NULL) {
        printf("\n Unable to open directory /proc");
        return;
    }
    while ((entry = readdir(dirp)) != NULL) {
        if (entry->d_type == DT_DIR && isProcessDir(entry->d_name)) {
            printf("\nProcessInfo(pid=%s):\n",entry->d_name);
            showStatusForProcess(entry->d_name);
        }
    }
    closedir(dirp);
}

int main() {
    printf("\nList of Running Processes on System\n");
    listProcesses();
    return 0;
}
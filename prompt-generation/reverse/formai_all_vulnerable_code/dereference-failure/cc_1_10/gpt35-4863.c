//FormAI DATASET v1.0 Category: System process viewer ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

#define MAX_PID_LENGTH 32
#define MAX_PROCESS_NAME_LENGTH 256
#define MAX_CMDLINE_LENGTH 1024

typedef struct proc_info {
    char pid[MAX_PID_LENGTH];
    char name[MAX_PROCESS_NAME_LENGTH];
    char cmdline[MAX_CMDLINE_LENGTH];
} proc_info_t;

void get_pid_name(char *dir_name, proc_info_t *p_info) {
    DIR *dp;
    struct dirent *dirp;
    char path[256];
    char pid[32];
    FILE *fp;
    char line[256];
    int line_num = 0;

    if ((dp = opendir(dir_name)) == NULL) {
        perror("Error opening /proc");
        return;
    }
    while ((dirp = readdir(dp)) != NULL) {
        if (isdigit(dirp->d_name[0])) {
            strcpy(pid, dirp->d_name);
            sprintf(path, "%s/%s/status", dir_name, pid);
            fp = fopen(path, "r");
            if (fp == NULL) {
                perror("Error opening file");
                return;
            }
            line_num = 0;
            while (fgets(line, sizeof(line), fp)) {
                line_num++;
                if (line_num == 1) {
                    strncpy(p_info->pid, line + 6, MAX_PID_LENGTH - 1);
                }
                else if (line_num == 2) {
                    strncpy(p_info->name, line + 6, MAX_PROCESS_NAME_LENGTH - 1);
                }
                if (line[0] == 'S' && line[1] == 't' && line[2] == 'a' && line[3] == 't' && line[4] == 'e') {
                    p_info->name[strlen(p_info->name) - 1] = '\0';
                    sprintf(path, "%s/%s/cmdline", dir_name, pid);
                    fp = fopen(path, "r");
                    if (fp == NULL) {
                        perror("Error opening file");
                        return;
                    }
                    fgets(line, sizeof(line), fp);
                    strncpy(p_info->cmdline, line, MAX_CMDLINE_LENGTH - 1);
                    break;
                }
            }
            fclose(fp);
        }
    }
    closedir(dp);
}

int main() {
    proc_info_t p_info;
    char dir_name[] = "/proc";
    get_pid_name(dir_name, &p_info);
    printf("PID: %s\nProcess Name: %s\nCommand Line: %s\n", p_info.pid, p_info.name, p_info.cmdline);
    return 0;
}
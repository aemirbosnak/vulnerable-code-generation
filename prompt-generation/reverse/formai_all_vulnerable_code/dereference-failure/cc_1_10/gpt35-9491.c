//FormAI DATASET v1.0 Category: System process viewer ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

#define MAX_DIR_PATH_LEN 1000
#define MAX_CMD_LINE_LEN 10000

typedef struct pid_info {
    int pid;
    char name[100];
    char state[100];
} pid_info;

void parse_cmd_line(pid_info *info, char *cmd_line) {
    char temp[100];
    char *tok = strtok(cmd_line, " ");
    int i = 0;
    while (tok != NULL) {
        if (i == 0) {
            info->pid = atoi(tok);
        }
        if (i == 1) {
            strncpy(info->name, tok, 99);
            info->name[99] = '\0';
        }
        if (i == 2) {
            strncpy(info->state, tok, 99);
            info->state[99] = '\0';
        }
        i++;
        tok = strtok(NULL, " ");
    }
    return;
}

void get_process_info(pid_info *pid_arr, int *num_pids) {
    DIR* dir;
    struct dirent* ent;
    char dir_path[MAX_DIR_PATH_LEN];
    int pid;
    char cmd_line[MAX_CMD_LINE_LEN];
    sprintf(dir_path, "/proc");
    if ((dir = opendir(dir_path)) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            pid = atoi(ent->d_name);
            if (!pid) {
                continue;
            }
            sprintf(dir_path, "/proc/%d/stat", pid);
            FILE *f = fopen(dir_path, "r");
            if (f == NULL) {
                continue;
            }
            fgets(cmd_line, MAX_CMD_LINE_LEN, f);
            fclose(f);
            parse_cmd_line(&pid_arr[*num_pids], cmd_line);
            (*num_pids)++;
        }
        closedir(dir);
    } else {
        perror("");
    }
}

void print_process_info(pid_info *pid_arr, int num_pids) {
    printf("Total Processes: %d\n", num_pids);
    printf("PID\t\tName\t\tStat\n");
    for (int i=0; i<num_pids; i++) {
        printf("%d\t\t%s\t\t%s\n",
               pid_arr[i].pid, pid_arr[i].name, pid_arr[i].state);
    }
}

int main(void) {
    pid_info pid_arr[10000];
    int num_pids = 0;
    get_process_info(pid_arr, &num_pids);
    print_process_info(pid_arr, num_pids);
    return 0;
}
//FormAI DATASET v1.0 Category: System process viewer ; Style: mind-bending
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <dirent.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_PID_LEN 10
#define MAX_COMM_LEN 32
#define MAX_STATE_LEN 32
#define MAX_COMMAND_LEN 1024

typedef struct process_info {
    char pid[MAX_PID_LEN];
    char comm[MAX_COMM_LEN];
    char state[MAX_STATE_LEN];
    char command[MAX_COMMAND_LEN];
} process_info;

void print_header() {
    printf("%-10s %-32s %-32s %-1024s\n", "PID", "COMM", "STATE", "COMMAND");
}

void print_process_info(process_info *info) {
    printf("%-10s %-32s %-32s %-1024s\n", info->pid, info->comm, info->state, info->command);
}

bool is_number(char *str) {
    for (int i = 0; i < strlen(str); i++) {
        if (!isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

bool is_valid_pid(char *pid) {
    if (!is_number(pid)) {
        return false;
    }
    int pid_int = atoi(pid);
    if (pid_int <= 0 || pid_int >= 65535) {
        return false;
    }
    return true;
}

void read_process_info(char *pid_str, process_info *info) {
    char path[1024];
    sprintf(path, "/proc/%s/stat", pid_str);
    FILE *fp = fopen(path, "r");
    if (fp == NULL) {
        return;
    }
    fscanf(fp, "%s %s %s", info->pid, info->comm, info->state);
    fclose(fp);
    sprintf(path, "/proc/%s/cmdline", pid_str);
    fp = fopen(path, "r");
    if (fp == NULL) {
        return;
    }
    fgets(info->command, MAX_COMMAND_LEN, fp);
    fclose(fp);
}

void print_all_processes() {
    DIR *dir;
    struct dirent *ent;
    dir = opendir("/proc");
    if (dir == NULL) {
        return;
    }
    while ((ent = readdir(dir)) != NULL) {
        process_info info;
        if (is_valid_pid(ent->d_name)) {
            read_process_info(ent->d_name, &info);
            print_process_info(&info);
        }
    }
    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        print_header();
        print_all_processes();
    } else if (argc == 2) {
        if (strcmp(argv[1], "--help") == 0) {
            printf("Usage: %s [PID]\n", argv[0]);
        } else if (is_valid_pid(argv[1])) {
            process_info info;
            read_process_info(argv[1], &info);
            print_header();
            print_process_info(&info);
        } else {
            printf("Invalid PID: %s\n", argv[1]);
        }
    } else {
        printf("Invalid arguments\n");
    }
    return 0;
}
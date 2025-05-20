//FormAI DATASET v1.0 Category: System process viewer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 256
#define MAX_PID_LEN 10

void print_sys_info(char* cmd) {
    char sys_cmd[MAX_CMD_LEN];
    snprintf(sys_cmd, sizeof(sys_cmd), "%s", cmd);
    system(sys_cmd);
}

void print_process_info(char pid[MAX_PID_LEN]) {
    char stat_cmd[MAX_CMD_LEN];
    char mem_cmd[MAX_CMD_LEN];
    char cwd_cmd[MAX_CMD_LEN];
    char exe_cmd[MAX_CMD_LEN];

    snprintf(stat_cmd, sizeof(stat_cmd), "cat /proc/%s/stat", pid);
    snprintf(mem_cmd, sizeof(mem_cmd), "cat /proc/%s/status | grep VmSize", pid);
    snprintf(cwd_cmd, sizeof(cwd_cmd), "readlink /proc/%s/cwd", pid);
    snprintf(exe_cmd, sizeof(exe_cmd), "readlink /proc/%s/exe", pid);

    printf("Process Stat:\n");
    print_sys_info(stat_cmd);

    printf("Process Memory Info:\n");
    print_sys_info(mem_cmd);

    printf("Process Working Directory:\n");
    print_sys_info(cwd_cmd);

    printf("Process Executable Path:\n");
    print_sys_info(exe_cmd);
}

int main(int argc, char* argv[]) {
    char pid[MAX_PID_LEN];

    if (argc != 2) {
        printf("Usage: %s PID\n", argv[0]);
        return -1;
    }

    strncpy(pid, argv[1], MAX_PID_LEN);

    printf("System and Proces Info:\n\n");

    print_sys_info("uname -a\n");
    print_process_info(pid);

    return 0;
}
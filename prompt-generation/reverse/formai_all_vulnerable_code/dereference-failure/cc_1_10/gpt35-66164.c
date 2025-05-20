//FormAI DATASET v1.0 Category: System process viewer ; Style: Dennis Ritchie
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PROC_DIR 2048
#define MAX_PROC_COUNT 200
#define MAX_CMD_LENGTH 256

struct Process {
    int pid;
    char cmd[MAX_CMD_LENGTH];
};

struct Process proc_array[MAX_PROC_COUNT]; 

int process_count = 0;

void clear_process_array() {
    for(int i=0; i<process_count; i++) {
        proc_array[i].pid = 0;
        memset(proc_array[i].cmd, 0, MAX_CMD_LENGTH);
    }
    process_count = 0;
}

void parse_process_cmd(char *cmdline, char processed_cmd[MAX_CMD_LENGTH]) {
    int startIndex = 0;
    int endIndex = 0;
    int idx = 0;
    int cmdFound = 0;
    while(cmdline[endIndex] != '\0') {
        if(cmdline[endIndex] == ' ') {
            if(cmdFound) {
                break;
            } else {
                startIndex = endIndex+1;
            }
        } else {
            if(!cmdFound) {
                cmdFound = 1;
            }
        }
        endIndex++;
    }

    idx = 0;
    for(int i=startIndex; i<endIndex; i++) {
        processed_cmd[idx++] = cmdline[i];
    }
}

int is_process_dir(const struct dirent *entry) {
    if(isdigit(entry->d_name[0])) {
        return 1;
    } else {
        return 0;
    }
}

void get_process_cmd(int pid, char process_cmd[MAX_CMD_LENGTH]) {
    char cmdline_path[MAX_PROC_DIR];
    FILE *cmdline_file;
    char cmdline_buff[MAX_CMD_LENGTH];

    snprintf(cmdline_path, MAX_PROC_DIR, "/proc/%d/cmdline", pid);
    cmdline_file = fopen(cmdline_path, "r");
    if(cmdline_file == NULL) {
        snprintf(process_cmd, MAX_CMD_LENGTH, "Unknown");
        return;
    }

    fgets(cmdline_buff, MAX_CMD_LENGTH, cmdline_file);
    fclose(cmdline_file);

    parse_process_cmd(cmdline_buff, process_cmd);
}

void populate_process_list() {
    struct dirent **namelist;
    int n;

    n = scandir("/proc", &namelist, is_process_dir, alphasort);
    if (n < 0) {
        perror("scandir");
    } else {
        clear_process_array();
        for(int i=0; i<n && i<MAX_PROC_COUNT; i++) {
            char proc_dir[MAX_PROC_DIR];
            snprintf(proc_dir, MAX_PROC_DIR, "/proc/%s", namelist[i]->d_name);
            FILE *status_file;
            char status_buff[MAX_CMD_LENGTH];

            snprintf(proc_array[i].cmd, MAX_CMD_LENGTH, "Unknown");

            // check if we can read /proc/[pid]/status file
            snprintf(proc_dir, MAX_PROC_DIR, "/proc/%s/status", namelist[i]->d_name);
            status_file = fopen(proc_dir, "r");

            if(!status_file) {
                continue;
            }

            while(fgets(status_buff, MAX_CMD_LENGTH, status_file)) {
                int found_pid = 0;
                int cmd_found = 0;
                char key[MAX_CMD_LENGTH];
                char value[MAX_CMD_LENGTH];
                int len = strlen(status_buff);

                if(status_buff[0] == 'P' && status_buff[1] == 'i' && status_buff[2] == 'd') {
                    sscanf(status_buff, "%s %s", key, value);
                    proc_array[i].pid = atoi(value);
                    found_pid = 1;
                } else if(status_buff[0] == 'N' && status_buff[1] == 'a' && status_buff[2] == 'm' && status_buff[3] == 'e') {
                    sscanf(status_buff, "%s %[^\n]s", key, value);
                    parse_process_cmd(value, proc_array[i].cmd);
                    cmd_found = 1;
                }

                if(found_pid && cmd_found) {
                    break;
                }
            }

            fclose(status_file);
            process_count++;
        }

        for(int i=0; i<n; i++) {
            free(namelist[i]);
        }
        free(namelist);
    }
}

void print_process_info() {
    populate_process_list();

    printf("%-10s %-10s\n", "PID", "CMD");

    for(int i=0; i<process_count; i++) {
        printf("%-10d %-10s\n", proc_array[i].pid, proc_array[i].cmd);
    }
}

int main() {
    print_process_info();
    return 0;
}
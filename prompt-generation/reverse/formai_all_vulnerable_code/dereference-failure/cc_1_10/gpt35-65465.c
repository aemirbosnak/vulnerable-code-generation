//FormAI DATASET v1.0 Category: System process viewer ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <dirent.h>
#include <unistd.h>
#include <pwd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define CMDLINE_LENGTH 1024
#define MAX_NAME_SIZE 256

typedef struct process_info {
    char name[MAX_NAME_SIZE];
    pid_t pid;
    uid_t uid;
} ProcessInfo;

void print_header() {
    printf("%-10s %-20s %-20s\n", "PID", "USER", "COMMAND");
}

void print_item(ProcessInfo *info) {
    printf("%-10d %-20s %-20s\n", info->pid, getpwuid(info->uid)->pw_name, info->name);
}

void print_processes() {
    DIR *dir = opendir("/proc");
    struct dirent *entry;
    ProcessInfo pinfo;
    char cmdline[CMDLINE_LENGTH];
    size_t cmdline_len;
    struct stat sbuf;
    
    if (dir == NULL) {
        perror("Failed to open /proc");
        exit(EXIT_FAILURE);
    }
    
    print_header();
    
    while ((entry = readdir(dir)) != NULL) {
        if (!isdigit(entry->d_name[0])) {
            continue;
        }
        
        pinfo.pid = atoi(entry->d_name);

        // check if /proc/PID exists
        if (stat(entry->d_name, &sbuf) != 0) {
            continue;
        }

        // check if /proc/PID/cmdline exists
        snprintf(cmdline, CMDLINE_LENGTH, "/proc/%d/cmdline", pinfo.pid);
        if (access(cmdline, R_OK) != 0) {
            continue;
        }
        
        // read the cmdline file
        FILE *cmdline_file = fopen(cmdline, "r");
        if (cmdline_file == NULL) {
            continue;
        }
        cmdline_len = fread(cmdline, 1, CMDLINE_LENGTH, cmdline_file);
        fclose(cmdline_file);

        // extract the executable name
        char *name = cmdline;
        for (size_t i = 0; i < cmdline_len; i++) {
            if (cmdline[i] == '\0') {
                if (i != cmdline_len-1) {
                    name = cmdline+i+1;
                } else {
                    name = "";
                }
                break;
            }
        }
        strncpy(pinfo.name, name, MAX_NAME_SIZE);

        // check UID
        char status_path[CMDLINE_LENGTH];
        snprintf(status_path, CMDLINE_LENGTH, "/proc/%d/status", pinfo.pid);
        FILE *status_file = fopen(status_path, "r");
        if (status_file != NULL) {
            char line[CMDLINE_LENGTH];
            while (fgets(line, CMDLINE_LENGTH, status_file) != NULL) {
                if (strncmp(line, "Uid:", 4) == 0) {
                    char *str_uid = strtok(line+4, " \t\n");
                    pinfo.uid = atoi(str_uid);
                    break;
                }
            }
            fclose(status_file);
        }
        
        print_item(&pinfo);
    }
    
    closedir(dir);
}

int main() {
    print_processes();
    return 0;
}
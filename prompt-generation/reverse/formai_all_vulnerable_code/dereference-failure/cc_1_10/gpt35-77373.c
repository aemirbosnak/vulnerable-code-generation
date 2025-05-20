//FormAI DATASET v1.0 Category: System process viewer ; Style: expert-level
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

// Function to check if the provided string is a numeric value
int is_numeric(const char *s) {
    while (*s) {
        if (!isdigit(*s))
            return 0;
        else
            s++;
    }
    return 1;
}

// Function to extract the process name from the provided process ID
void get_process_name(char *pid, char *process_name) {
    FILE *fp;
    char path[1024];

    sprintf(path, "/proc/%s/cmdline", pid);
    fp = fopen(path, "r");
    if (fp) {
        fgets(process_name, 1024, fp);
        fclose(fp);
    }
}

// Function to extract the memory usage details of the provided process ID
void get_memory_usage(char *pid, char *mem_usage) {
    FILE *fp;
    char path[1024];

    sprintf(path, "/proc/%s/status", pid);
    fp = fopen(path, "r");
    if (fp) {
        char line[512];

        while (fgets(line, 512, fp) != NULL) {
            if (strstr(line, "VmRSS")) {
                char *token = strtok(line, " ");
                token = strtok(NULL, " ");

                sprintf(mem_usage, "%s KB", token);
                fclose(fp);
                return;
            }
        }
        fclose(fp);
    }
}

// Function to get the list of all running processes
void get_processes() {
    DIR *d;
    struct dirent *dir;
    char path[1024], pid[10];
    char process_name[1024], mem_usage[1024];

    d = opendir("/proc");
    if (d) {
        printf("%-10s%-40s%-20s\n", "PID", "Process Name", "Memory Usage");
        printf("-------------------------------------------------------------\n");

        while ((dir = readdir(d)) != NULL) {
            if (is_numeric(dir->d_name)) {
                strcpy(pid, dir->d_name);

                get_process_name(pid, process_name);
                if (strlen(process_name) > 0) {
                    get_memory_usage(pid, mem_usage);
                    sprintf(path, "/proc/%s/exe", pid);

                    printf("%-10s%-40s%-20s\n", pid, process_name, mem_usage);
                }
            }
        }
        closedir(d);
    }
}

int main() {
    get_processes();
    return 0;
}
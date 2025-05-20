//FormAI DATASET v1.0 Category: System process viewer ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>

// get system process list
int get_process_list(struct dirent ***namelist) {
    return scandir("/proc", namelist, NULL, alphasort);
}

// check if given string is numeric
int is_numeric(char *str) {
    for (int i = 0; i < strlen(str); i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

// get the name of the process given its pid
char *get_process_name(char *pid) {
    char *path = malloc(sizeof(char) * 50);
    sprintf(path, "/proc/%s/cmdline", pid);

    int fd = open(path, O_RDONLY);
    if (fd < 0) {
        return NULL;    // unable to open the file
    }

    char cmd[100];
    read(fd, cmd, sizeof(cmd));
    close(fd);

    char *name = malloc(sizeof(char) * 20);
    sscanf(cmd, "%s", name);

    return name;
}

// get the total memory used by process given its pid
long int get_process_memory(char *pid) {
    char *path = malloc(sizeof(char) * 50);
    sprintf(path, "/proc/%s/status", pid);

    FILE *fp = fopen(path, "r");
    if (fp == NULL) {
        return 0;   // unable to open the file
    }

    char line[512];
    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, "VmSize:") != NULL) { // search for VmSize keyword
            char *p = strtok(line, " \t");
            p = strtok(NULL, " \t\n");
            long int memory_kb = atol(p);
            fclose(fp);
            return memory_kb * 1024;    // Return memory in bytes
        }
    }

    fclose(fp);
    return 0;   // VmSize keyword not found
}

int main() {
    struct dirent** namelist;
    int num_processes = get_process_list(&namelist);
    printf("%-8s %-20s %s\n", "PID", "Process Name", "Memory Used");

    for (int i = 0; i < num_processes; i++) {
        if (is_numeric(namelist[i]->d_name)) {
            char *pid = namelist[i]->d_name;
            char *process_name = get_process_name(pid);
            if (process_name != NULL) {
                long int memory = get_process_memory(pid);
                printf("%-8s %-20s %ld bytes\n", pid, process_name, memory);
                free(process_name);
            }
        }
    }

    for (int i = 0; i < num_processes; i++) {
        free(namelist[i]);
    }
    free(namelist);

    return 0;
}
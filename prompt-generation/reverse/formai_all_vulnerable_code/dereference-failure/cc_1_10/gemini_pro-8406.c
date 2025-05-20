//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/sysmacros.h>
#include <dirent.h>

#define MAX_PATH 256

typedef struct {
    pid_t pid;
    char name[32];
    char path[MAX_PATH];
    char state;
    int ppid;
} process_t;

typedef struct {
    int num_processes;
    process_t processes[1024];
} process_list_t;

process_list_t get_process_list() {
    process_list_t list = {0};

    DIR *dir = opendir("/proc");
    if (dir == NULL) {
        return list;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char path[MAX_PATH];
        snprintf(path, MAX_PATH, "/proc/%s/stat", entry->d_name);

        FILE *file = fopen(path, "r");
        if (file == NULL) {
            continue;
        }

        process_t process = {0};
        process.pid = atoi(entry->d_name);

        fscanf(file, "%*s %s %c %*s %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*s %*s %*d %*d %ld %*d %*d %*d %*d %*d\n", process.name, &process.state, &process.ppid);

        fscanf(file, "%*s %s\n", process.path);

        list.processes[list.num_processes++] = process;

        fclose(file);
    }

    closedir(dir);

    return list;
}

void print_process_list(process_list_t list) {
    printf("%-6s %-16s %-4s %-6s %-s\n", "PID", "NAME", "STATE", "PPID", "PATH");
    for (int i = 0; i < list.num_processes; i++) {
        printf("%-6d %-16s %-4c %-6d %s\n", list.processes[i].pid, list.processes[i].name, list.processes[i].state, list.processes[i].ppid, list.processes[i].path);
    }
}

int main() {
    process_list_t list = get_process_list();
    print_process_list(list);

    return 0;
}
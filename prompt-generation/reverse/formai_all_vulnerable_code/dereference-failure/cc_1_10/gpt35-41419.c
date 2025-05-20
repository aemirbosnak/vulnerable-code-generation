//FormAI DATASET v1.0 Category: System process viewer ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

// Function to check if a pid represents a running process
int is_running(char* pid_str) {
    char path[100];
    sprintf(path, "/proc/%s/stat", pid_str);
    struct stat sb;
    if(stat(path, &sb) == -1) {
        if(errno == ENOENT) {
            return 0;
        }
        perror("stat()");
        exit(EXIT_FAILURE);
    }
    return 1;
}

// Function to print process info given a pid
void print_process_info(char* pid_str) {
    char path[100], pid[20], comm[20], state;
    int ppid;
    unsigned long int rss;
    sprintf(path, "/proc/%s/stat", pid_str);
    FILE* fp = fopen(path, "r");
    if(fp == NULL) {
        perror("fopen()");
        exit(EXIT_FAILURE);
    }
    fscanf(fp, "%s %s %c %d", pid, comm, &state, &ppid);
    fclose(fp);
    sprintf(path, "/proc/%s/statm", pid_str);
    fp = fopen(path, "r");
    if(fp == NULL) {
        perror("fopen()");
        exit(EXIT_FAILURE);
    }
    fscanf(fp, "%*d %lu", &rss);
    fclose(fp);
    printf("%s %c %d %lu\n", comm, state, ppid, rss * sysconf(_SC_PAGESIZE));
}

int main() {
    DIR* proc_dir = opendir("/proc");
    if(proc_dir == NULL) {
        perror("opendir()");
        exit(EXIT_FAILURE);
    }
    struct dirent* entry;
    while((entry = readdir(proc_dir)) != NULL) {
        char* name = entry->d_name;
        if(strspn(name, "0123456789") == strlen(name) && is_running(name)) {
            print_process_info(name);
        }
    }
    return 0;
}
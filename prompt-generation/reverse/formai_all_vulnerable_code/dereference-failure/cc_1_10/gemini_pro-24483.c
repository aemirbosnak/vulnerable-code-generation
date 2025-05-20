//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>

// Custom data structure to store process information
typedef struct ProcessInfo {
    pid_t pid;
    char *name;
    char *state;
    int ppid;
    long unsigned int vsize;
    long unsigned int rss;
    char *exe;
} ProcessInfo;

// Function to get process information
ProcessInfo* getProcessInfo(pid_t pid) {
    char proc_path[256];
    sprintf(proc_path, "/proc/%d", pid);

    ProcessInfo *info = malloc(sizeof(ProcessInfo));
    info->pid = pid;

    // Get process name
    char name_path[256];
    sprintf(name_path, "%s/comm", proc_path);
    FILE *name_file = fopen(name_path, "r");
    if (name_file != NULL) {
        char name[256];
        fgets(name, 256, name_file);
        info->name = strdup(strtok(name, "\n"));
        fclose(name_file);
    }

    // Get process state
    char state_path[256];
    sprintf(state_path, "%s/stat", proc_path);
    FILE *state_file = fopen(state_path, "r");
    if (state_file != NULL) {
        char state[2];
        fscanf(state_file, "%*d %s %*c", state);
        info->state = strdup(state);
        fclose(state_file);
    }

    // Get process parent pid
    char ppid_path[256];
    sprintf(ppid_path, "%s/stat", proc_path);
    FILE *ppid_file = fopen(ppid_path, "r");
    if (ppid_file != NULL) {
        int ppid;
        fscanf(ppid_file, "%*d %*s %*c %d", &ppid);
        info->ppid = ppid;
        fclose(ppid_file);
    }

    // Get process virtual memory size
    char vsize_path[256];
    sprintf(vsize_path, "%s/statm", proc_path);
    FILE *vsize_file = fopen(vsize_path, "r");
    if (vsize_file != NULL) {
        long unsigned int vsize;
        fscanf(vsize_file, "%lu", &vsize);
        info->vsize = vsize;
        fclose(vsize_file);
    }

    // Get process resident set size
    char rss_path[256];
    sprintf(rss_path, "%s/statm", proc_path);
    FILE *rss_file = fopen(rss_path, "r");
    if (rss_file != NULL) {
        long unsigned int rss;
        fscanf(rss_file, "%*lu %lu", &rss);
        info->rss = rss;
        fclose(rss_file);
    }

    // Get process executable path
    char exe_path[256];
    sprintf(exe_path, "/proc/%d/exe", pid);
    info->exe = realpath(exe_path, NULL);

    return info;
}

// Function to print process information
void printProcessInfo(ProcessInfo *info) {
    printf("%-5d %-15s %-3s %-4d %-8lu %-8lu %-s\n",
        info->pid, info->name, info->state, info->ppid, info->vsize, info->rss, info->exe);
}

// Function to recursively list all processes
void listProcesses(const char *dir) {
    DIR *d = opendir(dir);
    if (d == NULL) {
        perror("opendir");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(d)) != NULL) {
        if (entry->d_type == DT_DIR && strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            // Recursively list processes in subdirectory
            char subdir[256];
            sprintf(subdir, "%s/%s", dir, entry->d_name);
            listProcesses(subdir);
        } else if (entry->d_type == DT_REG) {
            // Get process information
            int pid = atoi(entry->d_name);
            ProcessInfo *info = getProcessInfo(pid);

            // Print process information
            printProcessInfo(info);

            // Free process information
            free(info->name);
            free(info->state);
            free(info->exe);
            free(info);
        }
    }

    closedir(d);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // List all processes in the specified directory
    listProcesses(argv[1]);

    return EXIT_SUCCESS;
}
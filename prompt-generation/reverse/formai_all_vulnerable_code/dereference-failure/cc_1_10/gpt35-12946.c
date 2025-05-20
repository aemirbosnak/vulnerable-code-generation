//FormAI DATASET v1.0 Category: System process viewer ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>

#define PROC_DIRECTORY "/proc"

typedef struct process_info {
    char name[256];
    int pid;
    char state[16];
    int threads;
    long int vm_size;
} ProcessInfo;

void format_bytes(char *buf, unsigned long int size) {
    const char *prefixes[] = {"B", "KB", "MB", "GB"};
    int i = 0;
    while (size > 1024) {
        size /= 1024;
        i++;
    }
    sprintf(buf, "%ld %s", size, prefixes[i]);
}

void print_process_info(const ProcessInfo *pinfo) {
    char vm_size_str[32];
    format_bytes(vm_size_str, pinfo->vm_size);
    printf("%-8d %-20s %-4s %-4d %-10s\n", pinfo->pid, pinfo->name, pinfo->state, pinfo->threads, vm_size_str);
}

int main() {
    DIR *dir = opendir(PROC_DIRECTORY);
    if (dir == NULL) {
        perror(PROC_DIRECTORY);
        return EXIT_FAILURE;
    }

    printf("%-8s %-20s %-4s %-4s %-10s\n", "PID", "NAME", "STAT", "TH", "VM SIZE");

    struct dirent *entry;
    while ((entry = readdir(dir))) {
        if (isdigit(entry->d_name[0])) {
            char filename[512];
            sprintf(filename, PROC_DIRECTORY "/%s/stat", entry->d_name);
            FILE *f = fopen(filename, "r");
            if (f == NULL) {
                continue;
            }
            ProcessInfo pinfo;
            fscanf(f, "%d %s %s %*d %*d %*d %*d %*d %*u %*lu %*lu %*lu %*lu %*lu %*ld %*ld %*ld %*ld %*ld %*ld %*llu %ld", 
                   &pinfo.pid, pinfo.name, pinfo.state, &pinfo.threads, &pinfo.vm_size);
            fclose(f);
            print_process_info(&pinfo);
        }
    }

    closedir(dir);
    return EXIT_SUCCESS;
}
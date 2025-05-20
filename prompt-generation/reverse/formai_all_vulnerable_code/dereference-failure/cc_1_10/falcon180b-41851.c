//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>

typedef struct {
    char name[100];
    int pid;
    long rss;
    long vsz;
    float cpu;
    float mem;
} process;

void read_proc_dir(char* path, process* processes, int* count) {
    DIR* dir = opendir(path);
    struct dirent* entry;
    while ((entry = readdir(dir))!= NULL) {
        if (entry->d_type == DT_DIR) {
            char* new_path = malloc(strlen(path) + strlen(entry->d_name) + 2);
            strcpy(new_path, path);
            strcat(new_path, "/");
            strcat(new_path, entry->d_name);
            read_proc_dir(new_path, processes, count);
            free(new_path);
        } else {
            process* proc = malloc(sizeof(process));
            strcpy(proc->name, entry->d_name);
            sscanf(entry->d_name, "%d", &proc->pid);
            proc->rss = 0;
            proc->vsz = 0;
            proc->cpu = 0;
            proc->mem = 0;
            *count += 1;
            processes[*count-1] = *proc;
            free(proc);
        }
    }
    closedir(dir);
}

void read_proc_info(int pid, process* proc) {
    char path[100];
    sprintf(path, "/proc/%d/stat", pid);
    FILE* file = fopen(path, "r");
    if (file!= NULL) {
        fscanf(file, "%*s %*s %*s %*s %*s %ld %ld %ld %ld %ld %ld", &proc->rss, &proc->vsz, &proc->rss, &proc->vsz, &proc->cpu, &proc->mem);
        fclose(file);
    }
}

int main() {
    int count = 0;
    process* processes = malloc(100 * sizeof(process));
    read_proc_dir("/proc", processes, &count);
    for (int i = 0; i < count; i++) {
        read_proc_info(processes[i].pid, &processes[i]);
    }
    printf("Name\tPID\tRSS\tVSZ\tCPU\tMEM\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t%d\t%ld\t%ld\t%.2f%%\t%.2f%%\n", processes[i].name, processes[i].pid, processes[i].rss, processes[i].vsz, processes[i].cpu, processes[i].mem);
    }
    free(processes);
    return 0;
}
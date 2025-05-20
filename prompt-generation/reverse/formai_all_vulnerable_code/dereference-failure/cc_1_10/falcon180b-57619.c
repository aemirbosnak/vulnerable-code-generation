//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/statvfs.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>
#include <sys/time.h>
#include <time.h>

#define MAX_PROCESSES 1024
#define MAX_PROCESS_NAME_LENGTH 16

typedef struct {
    int pid;
    char name[MAX_PROCESS_NAME_LENGTH];
    float cpu_usage;
} Process;

void get_processes(Process *processes) {
    DIR *dir;
    struct dirent *ent;
    char path[50];
    sprintf(path, "/proc");
    dir = opendir(path);
    if (dir == NULL) {
        printf("Error opening /proc directory.\n");
        exit(1);
    }
    int count = 0;
    while ((ent = readdir(dir))!= NULL) {
        if (ent->d_type == DT_DIR && count < MAX_PROCESSES) {
            int pid = atoi(ent->d_name);
            sprintf(processes[count].name, "%d", pid);
            processes[count].pid = pid;
            count++;
        }
    }
    closedir(dir);
}

float get_cpu_usage(int pid) {
    char path[50];
    sprintf(path, "/proc/%d/stat", pid);
    FILE *file = fopen(path, "r");
    if (file == NULL) {
        printf("Error opening /proc/%d/stat file.\n", pid);
        exit(1);
    }
    char line[1024];
    fgets(line, 1024, file);
    fclose(file);
    int utime, stime;
    sscanf(line, "%*d %*s %*s %*s %*s %*s %*s %*s %d %d", &utime, &stime);
    float total_time = utime + stime;
    struct statvfs buf;
    if (statvfs("/proc", &buf) == -1) {
        printf("Error getting /proc file system information.\n");
        exit(1);
    }
    float system_time = ((float) buf.f_files - 3) * 100.0;
    return (total_time - system_time) / system_time * 100.0;
}

void print_processes(Process *processes, int num_processes) {
    printf("PID\tName\tCPU Usage\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\t%.2f%%\n", processes[i].pid, processes[i].name, processes[i].cpu_usage);
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    get_processes(processes);
    int num_processes = 0;
    while (num_processes < MAX_PROCESSES) {
        for (int i = 0; i < num_processes; i++) {
            processes[i].cpu_usage = get_cpu_usage(processes[i].pid);
        }
        usleep(100000);
        num_processes++;
    }
    print_processes(processes, num_processes);
    return 0;
}
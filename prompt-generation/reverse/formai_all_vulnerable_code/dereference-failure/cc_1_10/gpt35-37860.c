//FormAI DATASET v1.0 Category: System process viewer ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <dirent.h>
#include <errno.h>
#include <time.h>
#include <unistd.h>
#include <sys/sysinfo.h>

#define MAX_PID 32768
#define MAX_CMDLINE_LENGTH 512
#define MAX_BUFFER_LENGTH 1024
#define HERTZ 100

typedef struct {
    char *name;
    int pid;
    char state;
    unsigned long utime;
    unsigned long stime;
    unsigned long vsize;
    unsigned long rss;
    unsigned long starttime;
} process;

/* Get system uptime */
long int get_uptime() {
    struct sysinfo info;
    sysinfo(&info);
    return info.uptime;
}

/* Convert process starttime to seconds */
unsigned long int get_proc_starttime(process proc, long int uptime) {
    return uptime - (proc.starttime / HERTZ);
}

/* Print process info */
void print_process_info(process proc, long int uptime) {
    unsigned long int starttime = get_proc_starttime(proc, uptime);
    time_t stime = starttime;
    printf("%-15s \t %d \t %c \t %lu \t %lu \t %lu \t %lu \t %ld:%02ld:%02ld\n",
        proc.name, proc.pid, proc.state, proc.utime, proc.stime,
        proc.vsize / 1024, proc.rss * getpagesize() / 1024, 
        (long int)(stime / 3600) % 24, (long int)(stime / 60) % 60, (long int)stime % 60);
}

/* Return list of processes */
void get_processes(process *proc_list) {
    int i = 0;
    DIR *dir = opendir("/proc");
    if (dir == NULL) {
        printf("Error: Could not open /proc directory.");
        exit(EXIT_FAILURE);
    }
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (!isdigit(entry->d_name[0]))
            continue;
        int pid = atoi(entry->d_name);
        char stat_file[MAX_BUFFER_LENGTH];
        snprintf(stat_file, MAX_BUFFER_LENGTH, "/proc/%d/stat", pid);
        FILE *file = fopen(stat_file, "r");
        if (file == NULL)
            continue;
        process proc;
        proc.name = malloc(MAX_CMDLINE_LENGTH * sizeof(char));
        if (proc.name == NULL) {
            printf("Error: Could not allocate memory. \n");
            exit(EXIT_FAILURE);
        }
        memset(proc.name, 0, MAX_CMDLINE_LENGTH);
        char cmd[MAX_CMDLINE_LENGTH];
        fscanf(file, "%d (%[^)])%c", &proc.pid, cmd, &proc.state);
        sprintf(proc.name, "%s", cmd);
        for (int i = 0; i < 14; i++)
            fscanf(file, "%*s");
        fscanf(file, "%lu %lu %*u %*u %*u %*u %lu %lu", 
            &proc.utime, &proc.stime, &proc.vsize, &proc.rss);
        char stat_file2[MAX_BUFFER_LENGTH];
        snprintf(stat_file2, MAX_BUFFER_LENGTH, "/proc/%d/starttime", pid);
        FILE *file2 = fopen(stat_file2, "r");
        if (file2 == NULL)
            continue;
        fscanf(file2, "%lu", &proc.starttime);
        fclose(file);
        fclose(file2);
        proc_list[i++] = proc;
    }
    proc_list[i].pid = -1;
    closedir(dir);
}

int main() {
    process processes[MAX_PID];
    get_processes(processes);
    long int uptime = get_uptime();
    printf("%-15s \t %s \t %s \t %s \t %s \t %s \t %s \t %s \n"
            "----------------------------------------------------------------------------------------------\n",
           "Name", "PID", "State", "UTime", "STime", "VSize", "RSS", "StartTime");
    for (process *p = processes; p->pid != -1; p++) {
        print_process_info(*p, uptime);
    }
    return 0;
}
//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <time.h>

#define MAX_PATH_LEN 256
#define MAX_PROC_NUM 1024

typedef struct proc_info {
    pid_t pid;
    char name[MAX_PATH_LEN];
    char state;
    int ppid;
    int uid;
    long int mem_usage;
    time_t start_time;
} proc_info;

int compare_procs(const void *a, const void *b) {
    const proc_info *proc1 = (const proc_info *)a;
    const proc_info *proc2 = (const proc_info *)b;
    return proc1->pid - proc2->pid;
}

int main() {
    proc_info procs[MAX_PROC_NUM];
    int num_procs = 0;
    DIR *proc_dir = opendir("/proc");
    if (proc_dir == NULL) {
        perror("Error opening /proc");
        return EXIT_FAILURE;
    }
    struct dirent *proc_dirent;
    while ((proc_dirent = readdir(proc_dir)) != NULL) {
        if (strcmp(proc_dirent->d_name, ".") == 0 || strcmp(proc_dirent->d_name, "..") == 0) {
            continue;
        }
        if (!isdigit(proc_dirent->d_name[0])) {
            continue;
        }
        char proc_path[MAX_PATH_LEN];
        snprintf(proc_path, MAX_PATH_LEN, "/proc/%s/status", proc_dirent->d_name);
        FILE *proc_status_file = fopen(proc_path, "r");
        if (proc_status_file == NULL) {
            perror("Error opening proc status file");
            continue;
        }
        proc_info *proc = &procs[num_procs];
        proc->pid = atoi(proc_dirent->d_name);
        char line[MAX_PATH_LEN];
        while (fgets(line, MAX_PATH_LEN, proc_status_file) != NULL) {
            if (strncmp(line, "Name:", 5) == 0) {
                sscanf(line, "Name:\t%s", proc->name);
            } else if (strncmp(line, "State:", 6) == 0) {
                sscanf(line, "State:\t%c", &proc->state);
            } else if (strncmp(line, "PPid:\t", 6) == 0) {
                sscanf(line, "PPid:\t%d", &proc->ppid);
            } else if (strncmp(line, "Uid:\t", 5) == 0) {
                sscanf(line, "Uid:\t%d", &proc->uid);
            } else if (strncmp(line, "VmSize:", 7) == 0) {
                long int mem_usage;
                sscanf(line, "VmSize:\t%ld", &mem_usage);
                proc->mem_usage = mem_usage / 1024;
            } else if (strncmp(line, "Start time:", 11) == 0) {
                char start_time_str[MAX_PATH_LEN];
                sscanf(line, "Start time:\t%s", start_time_str);
                struct tm start_time_tm;
                strptime(start_time_str, "%s %b %e %H:%M:%S %Y", &start_time_tm);
                proc->start_time = mktime(&start_time_tm);
            }
        }
        fclose(proc_status_file);
        num_procs++;
    }
    closedir(proc_dir);
    qsort(procs, num_procs, sizeof(proc_info), compare_procs);
    printf("PID\tName\t\tState\tPPID\tUID\tMemUsage\tStartTime\n");
    for (int i = 0; i < num_procs; i++) {
        proc_info *proc = &procs[i];
        printf("%d\t%-16s\t%c\t%d\t%d\t%ldKB\t%s",
               proc->pid, proc->name, proc->state, proc->ppid, proc->uid, proc->mem_usage,
               ctime(&proc->start_time));
    }
    return EXIT_SUCCESS;
}
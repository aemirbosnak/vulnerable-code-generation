//FormAI DATASET v1.0 Category: System process viewer ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>
#include <fcntl.h>
#include <errno.h>

#define PATH_TO_PROC_DIR "/proc"

struct Process {
    int pid;
    char pname[50];
    char state;
    float cpu_usage;
};

struct ProcessList {
    struct Process* processes;
    size_t size;
};

float calculate_cpu_usage(int pid);
char get_process_state(int pid);
void format_pname(char* pname);

int main() {
    struct ProcessList p_list;
    p_list.size = 0;
    p_list.processes = NULL;
    
    DIR* proc_dir = opendir(PATH_TO_PROC_DIR);
    if (proc_dir == NULL) {
        fprintf(stderr, "Could not open %s: %s\n", PATH_TO_PROC_DIR, strerror(errno));
        exit(EXIT_FAILURE);
    }
    
    struct dirent* entry;
    while ((entry = readdir(proc_dir))) {
        int pid = atoi(entry->d_name);
        if (pid > 0) {
            struct Process p;
            p.pid = pid;
            char stat_file_path[50];
            sprintf(stat_file_path, "%s/%d/stat", PATH_TO_PROC_DIR, pid);
            FILE* stat_file = fopen(stat_file_path, "r");
            if (stat_file) {
                fscanf(stat_file, "%*d %s %c", p.pname, &p.state);
                fclose(stat_file);
            } else {
                strcpy(p.pname, "N/A");
                p.state = 'N';
            }
            format_pname(p.pname);
            p.cpu_usage = calculate_cpu_usage(p.pid);
            p_list.size++;
            p_list.processes = realloc(p_list.processes, p_list.size * sizeof(struct Process));
            p_list.processes[p_list.size - 1] = p;
        }
    }
    closedir(proc_dir);
    
    printf("%-10s %-25s %-10s %-10s\n", "PID", "PROCESS NAME", "STATE", "CPU USAGE");
    for (int i = 0; i < p_list.size; i++) {
        printf("%-10d %-25s %-10c %-10.2f\n", p_list.processes[i].pid, p_list.processes[i].pname, p_list.processes[i].state, p_list.processes[i].cpu_usage);
    }
    
    free(p_list.processes);
    return 0;
}

float calculate_cpu_usage(int pid) {
    char stat_file_path[50];
    sprintf(stat_file_path, "%s/%d/stat", PATH_TO_PROC_DIR, pid);
    FILE* stat_file = fopen(stat_file_path, "r");
    if (stat_file) {
        int utime, stime;
        fscanf(stat_file, "%*d %*s %c %*d %*d %*d %*d %*d %*u %*u %*u %*u %*u %*u %*u %*d %*d %*d %d %d", &stime, &utime);
        fclose(stat_file);
        float cpu_usage = (float)(utime + stime) / sysconf(_SC_CLK_TCK);
        return cpu_usage;
    } else {
        fprintf(stderr, "Could not open %s: %s\n", stat_file_path, strerror(errno));
        return 0.0;
    }
}

char get_process_state(int pid) {
    char stat_file_path[50];
    sprintf(stat_file_path, "%s/%d/stat", PATH_TO_PROC_DIR, pid);
    FILE* stat_file = fopen(stat_file_path, "r");
    if (stat_file) {
        char state;
        fscanf(stat_file, "%*d %*s %c", &state);
        fclose(stat_file);
        return state;
    } else {
        fprintf(stderr, "Could not open %s: %s\n", stat_file_path, strerror(errno));
        return 'N';
    }
}

void format_pname(char* pname) {
    int len = strlen(pname);
    if (pname[0] == '(' && pname[len-1] == ')') {
        for (int i = 0; i < len - 2; i++) {
            pname[i] = pname[i+1];
        }
        pname[len - 2] = '\0';
    }
}
//FormAI DATASET v1.0 Category: System process viewer ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>

#define PROC_DIR "/proc"
#define FIELD_SIZE 64
#define MAX_ARGS 128

// Struct to hold process information
typedef struct {
    pid_t pid;
    char cmd[FIELD_SIZE];
    char state;
    unsigned long int utime;
    unsigned long int stime;
} ProcessInfo;

// Extracts the process command from the cmdline file in the proc directory
void get_cmdline(char *cmdline_path, char *cmd) {
    FILE *cmdline_file = fopen(cmdline_path, "r");
    if (cmdline_file == NULL) {
        perror("Error opening cmdline file");
        exit(EXIT_FAILURE);
    }
    fgets(cmd, FIELD_SIZE, cmdline_file);
    fclose(cmdline_file);
}

// Extracts the process state from the stat file in the proc directory
char get_state(char *stat_path) {
    FILE *stat_file = fopen(stat_path, "r");
    if (stat_file == NULL) {
        perror("Error opening stat file");
        exit(EXIT_FAILURE);
    }
    char state;
    fscanf(stat_file, "%*d %*s %c", &state);
    fclose(stat_file);
    return state;
}

// Extracts the process utime and stime (in clock ticks) from the stat file in the proc directory
void get_cpu_time(char *stat_path, unsigned long int *utime, unsigned long int *stime) {
    FILE *stat_file = fopen(stat_path, "r");
    if (stat_file == NULL) {
        perror("Error opening stat file");
        exit(EXIT_FAILURE);
    }
    fscanf(stat_file, "%*d %*s %*c %*d %*d %*d %*d %*d %*u %*lu %*lu %*lu %*lu %lu %lu", utime, stime);
    fclose(stat_file);
}

// Filters process arguments by removing brackets and trimming whitespace
void filter_args(char *arg) {
    char *p = arg;
    while (*p) {
        if (*p == '[' || *p == ']') {
            *p = ' ';
        }
        p++;
    }
    p = arg + strlen(arg) - 1;
    while (isspace(*p)) {
        *p = '\0';
        p--;
    }
    p = arg;
    while (isspace(*p)) {
        p++;
    }
    strcpy(arg, p);
}

// Extracts process information from the proc directory and populates a ProcessInfo struct
ProcessInfo *get_process_info(pid_t pid) {
    ProcessInfo *info = malloc(sizeof(ProcessInfo));
    char stat_path[FIELD_SIZE];
    char cmdline_path[FIELD_SIZE];
    sprintf(stat_path, "%s/%d/stat", PROC_DIR, pid);
    sprintf(cmdline_path, "%s/%d/cmdline", PROC_DIR, pid);
    get_cmdline(cmdline_path, info->cmd);
    info->state = get_state(stat_path);
    get_cpu_time(stat_path, &(info->utime), &(info->stime));
    info->pid = pid;
    return info;
}

int main() {
    DIR *proc_dir = opendir(PROC_DIR);
    struct dirent *entry = readdir(proc_dir);
    ProcessInfo **procs = malloc(sizeof(ProcessInfo*) * MAX_ARGS);
    int num_procs = 0;
    while (entry != NULL) {
        if (isdigit(entry->d_name[0])) {
            pid_t pid = atoi(entry->d_name);
            ProcessInfo *info = get_process_info(pid);
            procs[num_procs] = info;
            num_procs++;
        }
        entry = readdir(proc_dir);
    }
    closedir(proc_dir);
    printf("%-10s %-20s %-10s %-10s\n", "PID", "CMD", "STATE", "CPU TIME");
    for (int i = 0; i < num_procs; i++) {
        ProcessInfo *info = procs[i];
        char filtered_cmd[FIELD_SIZE];
        strcpy(filtered_cmd, info->cmd);
        filter_args(filtered_cmd);
        printf("%-10d %-20s %-10c %-10lu\n", info->pid, filtered_cmd, info->state, info->utime+info->stime);
        free(info);
    }
    free(procs);
    return 0;
}
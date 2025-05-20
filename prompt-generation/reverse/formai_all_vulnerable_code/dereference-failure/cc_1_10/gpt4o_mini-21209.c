//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <ctype.h>

#define BUFFER_SIZE 256
#define PROC_PATH "/proc/"
#define STAT_FILE "status"
#define CMDLINE_FILE "cmdline"
#define CMD_LENGTH 1024

typedef struct {
    int pid;
    char name[BUFFER_SIZE];
    char state[BUFFER_SIZE];
    double cpu_usage;
} Process;

void strip_newline(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

void read_process_info(int pid, Process *proc) {
    char path[BUFFER_SIZE];
    snprintf(path, sizeof(path), "%s%d/%s", PROC_PATH, pid, STAT_FILE);
    FILE *stat_file = fopen(path, "r");
    if (stat_file) {
        char line[BUFFER_SIZE];
        fgets(line, sizeof(line), stat_file);
        sscanf(line, "%d %s %s", &proc->pid, proc->name, proc->state);
        fclose(stat_file);
    }
  
    // For CPU usage statistics, we’ll require fetching from /proc/stat and process it
    // This part simply sets a default value for demonstration purposes
    proc->cpu_usage = (double)(rand() % 100) / 100.0;  // Random CPU usage for the sake of this demo
}

void display_process(Process *proc) {
    printf("Process ID: %d\n", proc->pid);
    printf("Process Name: %s\n", proc->name);
    printf("Current State: %s\n", proc->state);
    printf("CPU Usage: %.2f%%\n", proc->cpu_usage * 100);
    printf("-----------------------------\n");
}

int compare_processes(const void *a, const void *b) {
    return ((Process *)b)->cpu_usage > ((Process *)a)->cpu_usage ? 1 : -1;
}

void list_processes() {
    struct dirent *entry;
    DIR *dp = opendir(PROC_PATH);
    if (dp == NULL) {
        perror("opendir failed");
        exit(EXIT_FAILURE);
    }

    Process processes[BUFFER_SIZE];
    int count = 0;

    while ((entry = readdir(dp))) {
        if (isdigit(entry->d_name[0])) {
            int pid = atoi(entry->d_name);
            Process proc;
            read_process_info(pid, &proc);
            processes[count++] = proc;
        }
    }
    closedir(dp);

    qsort(processes, count, sizeof(Process), compare_processes);

    printf("Top CPU consuming processes:\n");
    printf("-----------------------------\n");
    for (int i = 0; i < count && i < 10; i++) {
        display_process(&processes[i]);
    }
}

void show_help() {
    printf("Usage: process_viewer [option]\n");
    printf("Options:\n");
    printf("  -h          Show this help message\n");
    printf("  -l          List top CPU consuming processes\n");
    printf("  -p [PID]    Show details for a specific PID\n");
}

void view_specific_process(int pid) {
    Process proc;
    read_process_info(pid, &proc);
    display_process(&proc);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        show_help();
        return EXIT_FAILURE;
    }
    
    if (strcmp(argv[1], "-h") == 0) {
        show_help();
        return EXIT_SUCCESS;
    } 
    else if (strcmp(argv[1], "-l") == 0) {
        list_processes();
        return EXIT_SUCCESS;
    } 
    else if (strcmp(argv[1], "-p") == 0 && argc == 3) {
        int pid = atoi(argv[2]);
        view_specific_process(pid);
        return EXIT_SUCCESS;
    } 
    
    show_help();
    return EXIT_FAILURE;
}
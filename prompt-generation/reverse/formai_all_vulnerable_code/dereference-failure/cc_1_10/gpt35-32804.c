//FormAI DATASET v1.0 Category: System process viewer ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

#define MAX_PID_LENGTH 10
#define MAX_LINE_SIZE 1024
#define PROCESS_NAME_SIZE 256

typedef struct {
    char name[PROCESS_NAME_SIZE];
    char pid[MAX_PID_LENGTH];
    char status;
    char memory[10];
    char cpu[10];
} Process;

void print_processes(Process *processes, int num_processes) {
    printf("===================================================\n");
    printf("| %-45s | %9s | %6s%% | %6s%% |\n", "Process Name", "PID", "Memory", "CPU");
    printf("===================================================\n");
    for (int i = 0; i < num_processes; i++) {
        printf("| %-45s | %9s | %6s | %6s |\n", processes[i].name, processes[i].pid, processes[i].memory, processes[i].cpu);
    }
    printf("===================================================\n");
}

int is_digit(char c) {
    return isdigit((unsigned char)c);
}

void get_process_info(char *pid, Process *process) {
    FILE *stat_file;
    char stat_file_path[MAX_LINE_SIZE];
    char line[MAX_LINE_SIZE];
    char *tokens;
    int token_count = 0;
    sprintf(stat_file_path, "/proc/%s/stat", pid);
    stat_file = fopen(stat_file_path, "r");
    if (stat_file == NULL) {
        fprintf(stderr, "Failed to open file %s\n", stat_file_path);
        exit(EXIT_FAILURE);
    }
    char *name = process->name;
    while (fgets(line, sizeof(line), stat_file)) {
        tokens = strtok(line, " ");
        token_count = 0;
        while (tokens != NULL) {
            token_count++;
            if (token_count == 2) {
                strncpy(name, tokens, PROCESS_NAME_SIZE-1);
                name[strlen(tokens)-1] = '\0';
            } else if (token_count == 14) {
                strncpy(process->cpu, tokens, sizeof(process->cpu)-1);
                process->cpu[strlen(tokens)-1] = '\0';
            } else if (token_count == 24) {
                strncpy(process->memory, tokens, sizeof(process->memory)-1);
                process->memory[strlen(tokens)-1] = '\0';
            }
            tokens = strtok(NULL, " ");
        }
    }
    fclose(stat_file);
}

void get_processes(Process *processes, int *num_processes) {
    DIR *proc;
    struct dirent *ent;
    int count = 0;
    *num_processes = 0;

    if ((proc = opendir("/proc")) == NULL) {
        fprintf(stderr, "Failed to open /proc directory\n");
        exit(EXIT_FAILURE);
    }
    while ((ent = readdir(proc)) != NULL) {
        if (is_digit(ent->d_name[0])) {
            strncpy(processes[count].pid, ent->d_name, MAX_PID_LENGTH-1);
            processes[count].pid[MAX_PID_LENGTH-1] = '\0';
            get_process_info(processes[count].pid, &processes[count]);
            count++;
            if (count >= *num_processes) {
                processes = realloc(processes, ((*num_processes)+50)*sizeof(Process));
                *num_processes += 50;
            }
        }
    }
    closedir(proc);
}

int main() {
    int num_processes = 50;

    Process *processes = malloc(num_processes * sizeof(Process));

    get_processes(processes, &num_processes);

    print_processes(processes, num_processes);

    free(processes);

    return 0;
}
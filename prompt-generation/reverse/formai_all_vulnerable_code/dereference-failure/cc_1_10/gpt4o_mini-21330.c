//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <signal.h>

#define MAX_PROCESSES 256
#define BUFFER_SIZE 256

typedef struct {
    int pid;
    char comm[BUFFER_SIZE];
    char state[BUFFER_SIZE];
} Process;

void get_process_info(Process *proc) {
    char filepath[BUFFER_SIZE];
    snprintf(filepath, sizeof(filepath), "/proc/%d/stat", proc->pid);
    
    FILE *file = fopen(filepath, "r");
    if (file != NULL) {
        fscanf(file, "%d %s %s", &proc->pid, proc->comm, proc->state);
        fclose(file);
    } else {
        perror("Error opening stat file");
        exit(EXIT_FAILURE);
    }
}

void list_processes(Process processes[], int *count) {
    struct dirent *entry;
    DIR *dp = opendir("/proc");
    
    if (dp == NULL) {
        perror("Error opening /proc directory");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dp))) {
        if (entry->d_type == DT_DIR) {
            int pid = atoi(entry->d_name);
            if (pid > 0) {
                processes[*count].pid = pid;
                get_process_info(&processes[*count]);
                (*count)++;
                if (*count >= MAX_PROCESSES) {
                    break;
                }
            }
        }
    }
    
    closedir(dp);
}

void print_processes(Process processes[], int count) {
    printf("\n=================== Shocked Process Viewer ===================\n");
    printf("PID\tCOMM\t\tSTATE\n");
    
    for (int i = 0; i < count; i++) {
        printf("%d\t%-15s\t%s\n", processes[i].pid, processes[i].comm, processes[i].state);
    }
    
    printf("==============================================================\n");
}

void show_process_details(Process *proc) {
    char filepath[BUFFER_SIZE];
    snprintf(filepath, sizeof(filepath), "/proc/%d/status", proc->pid);
    
    FILE *file = fopen(filepath, "r");
    if (file == NULL) {
        perror("Error opening status file");
        return;
    }
    
    printf("\n===== Detailed Info for PID %d - %s =====\n", proc->pid, proc->comm);
    char line[BUFFER_SIZE];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
    printf("=============================================\n");
}

void kill_process(int pid) {
    printf("Are you sure you want to kill process %d? (Y/N): ", pid);
    char response = getchar();
    
    if (response == 'Y' || response == 'y') {
        if (kill(pid, SIGKILL) == 0) {
            printf("Process %d terminated successfully!\n", pid);
        } else {
            perror("Failed to terminate process");
        }
    } else {
        printf("Aborted process termination.\n");
    }
    while (getchar() != '\n'); // Clear the buffer
}

int main() {
    Process processes[MAX_PROCESSES];
    int count = 0;
    
    list_processes(processes, &count);
    
    print_processes(processes, count);
    
    int choice = 0;
    while (1) {
        printf("Choose a PID to see details (or 0 to quit): ");
        scanf("%d", &choice);
        
        if (choice == 0) {
            break;
        }
        
        int found = 0;
        for (int i = 0; i < count; i++) {
            if (processes[i].pid == choice) {
                show_process_details(&processes[i]);
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("PID %d not found!\n", choice);
        }
        
        printf("Would you like to kill this process? (1 for YES, 0 for NO): ");
        int kill_choice;
        scanf("%d", &kill_choice);
        
        if (kill_choice == 1) {
            kill_process(choice);
        }
    }
    
    return 0;
}
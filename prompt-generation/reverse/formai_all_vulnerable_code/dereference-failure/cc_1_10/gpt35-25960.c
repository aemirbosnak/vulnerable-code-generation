//FormAI DATASET v1.0 Category: System process viewer ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

// Struct to hold process information
typedef struct process {
    int pid;
    char name[100];
    char state;
    int memory;
} Process;

// Function to check if string is a number
int is_number(char* str) {
    for(int i=0; i<strlen(str); i++) {
        if(!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

// Function to get process information
Process* get_process_info(int pid) {
    // Open process status file
    char filename[100];
    sprintf(filename, "/proc/%d/status", pid);
    FILE* file = fopen(filename, "r");
    if(!file) {
        printf("Error: cannot open file %s\n", filename);
        return NULL;
    }

    // Read process status file
    Process* process = malloc(sizeof(Process));
    process->pid = pid;
    while(!feof(file)) {
        char line[100];
        fgets(line, 100, file);
        char* key = strtok(line, ":\t");
        char* value = strtok(NULL, ":\t");
        if(key && value) {
            if(strcmp(key, "Name") == 0) {
                strcpy(process->name, value);
            }
            else if(strcmp(key, "State") == 0) {
                process->state = value[0];
            }
            else if(strcmp(key, "VmSize") == 0) {
                sscanf(value, "%d", &process->memory);
            }
        }
    }
    fclose(file);
    return process;
}

// Function to print a process
void print_process(Process* process) {
    printf("%5d %20s %c %10d KB\n", process->pid, process->name, process->state, process->memory);
}

int main() {
    // Print header
    printf("%5s %20s %4s %10s\n", "PID", "NAME", "STAT", "MEMORY");

    // Read /proc directory to get list of processes
    DIR* proc_dir = opendir("/proc");
    if(!proc_dir) {
        printf("Error: cannot open /proc directory\n");
        return 1;
    }

    struct dirent* entry;
    while((entry = readdir(proc_dir)) != NULL) {
        // Check if entry is a directory and its name is a number
        if(entry->d_type == DT_DIR && is_number(entry->d_name)) {
            // Get process information and print it
            Process* process = get_process_info(atoi(entry->d_name));
            if(process) {
                print_process(process);
                free(process);
            }
        }
    }
    closedir(proc_dir);
    return 0;
}
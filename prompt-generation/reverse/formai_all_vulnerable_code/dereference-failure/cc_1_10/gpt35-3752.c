//FormAI DATASET v1.0 Category: System process viewer ; Style: accurate
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_PID_LEN 6
#define MAX_CMDLINE_LEN 256

// Struct for storing process information
typedef struct {
    char pid[MAX_PID_LEN + 1];
    char cmdline[MAX_CMDLINE_LEN + 1];
} Process;

// Function to check if a given string is an integer
int is_integer(const char* str) {
    while (*str) {
        if (!isdigit(*str)) {
            return 0;
        }
        str++;
    }
    return 1;
}

// Function to parse the process cmdline from proc/[pid]/cmdline file
void parse_cmdline(const char* path, char* cmdline) {
    FILE* fp = fopen(path, "r");
    if (fp) {
        fgets(cmdline, MAX_CMDLINE_LEN, fp);
        fclose(fp);
    } else {
        strcpy(cmdline, "Unknown process");
    }
}

// Function to get the list of all running processes
void get_processes(Process** processes, int* num_processes) {
    DIR* dir = opendir("/proc");
    struct dirent* entry;

    *num_processes = 0;

    if (dir == NULL) {
        perror("Error opening /proc");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dir)) != NULL) {
        // Check if the entry is a directory and its name is a number (PID)
        if (entry->d_type == DT_DIR && is_integer(entry->d_name)) {
            // Construct the path to the cmdline file
            char path[MAX_CMDLINE_LEN + 1];
            snprintf(path, MAX_CMDLINE_LEN, "/proc/%s/cmdline", entry->d_name);

            // Parse the cmdline and store the process information
            char cmdline[MAX_CMDLINE_LEN + 1];
            parse_cmdline(path, cmdline);
            Process* process = (Process*) malloc(sizeof(Process));
            strncpy(process->pid, entry->d_name, MAX_PID_LEN);
            strncpy(process->cmdline, cmdline, MAX_CMDLINE_LEN);
            (*processes)[(*num_processes)++] = *process;
        }
    }

    closedir(dir);
}

// Function to print the list of all running processes
void print_processes(Process* processes, const int num_processes) {
    printf("PID\tCMDLINE\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%s\t%s\n", processes[i].pid, processes[i].cmdline);
    }
}

int main() {
    Process* processes = (Process*) malloc(sizeof(Process) * 1024);
    int num_processes;
    get_processes(&processes, &num_processes);
    print_processes(processes, num_processes);
    free(processes);
    return 0;
}
//FormAI DATASET v1.0 Category: System process viewer ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>
#include <unistd.h>

/* Define constants */
#define PROC_DIR "/proc"

/* Define macros */
#define STR_EQ(str1, str2) strncmp(str1, str2, sizeof(str2)-1)

/* Define struct for a process */
typedef struct {
    int pid;
    char name[256];
    char state;
    int parent_pid;
    unsigned long utime;
    unsigned long stime;
    unsigned long vsize;
} Process;

/* Function declarations */
void print_processes(Process* processes, int num_processes);
int is_number(char* str);
Process parse_stat_file(char* filename);

int main() {
    /* Open the proc directory */
    DIR* proc_dir = opendir(PROC_DIR);
    if(proc_dir == NULL) {
        perror("Error opening proc directory");
        return 1;
    }
    
    /* Count the number of processes */
    int num_processes = 0;
    struct dirent* file;
    while((file = readdir(proc_dir)) != NULL) {
        if(is_number(file->d_name)) {
            num_processes++;
        }
    }
    
    /* Allocate memory for the processes */
    Process* processes = (Process*) malloc(num_processes * sizeof(Process));
    if(processes == NULL) {
        perror("Error allocating memory for processes");
        return 1;
    }
    
    /* Reset the proc directory stream to the beginning */
    rewinddir(proc_dir);
    
    /* Parse the stat files for each process */
    int i = 0;
    while((file = readdir(proc_dir)) != NULL) {
        if(is_number(file->d_name)) {
            char filename[256];
            snprintf(filename, sizeof(filename), "%s/%s/stat", PROC_DIR, file->d_name);
            processes[i] = parse_stat_file(filename);
            i++;
        }
    }
    
    /* Close the proc directory */
    closedir(proc_dir);
    
    /* Print the list of processes */
    print_processes(processes, num_processes);
    
    /* Free the memory used by the processes */
    free(processes);
    
    return 0;
}

/* Function to print the list of processes */
void print_processes(Process* processes, int num_processes) {
    printf("%-8s %-20s %-10s %-10s %-10s %-10s %-10s\n", "PID", "NAME", "STATE", "PPID", "UTIME", "STIME", "VSIZE");
    for(int i = 0; i < num_processes; i++) {
        printf("%-8d %-20s %-10c %-10d %-10lu %-10lu %-10lu\n", processes[i].pid, processes[i].name, processes[i].state, processes[i].parent_pid, processes[i].utime, processes[i].stime, processes[i].vsize);
    }
}

/* Function to check if a string is a number */
int is_number(char* str) {
    for(int i = 0; str[i] != '\0'; i++) {
        if(!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

/* Function to parse a stat file and return the process information */
Process parse_stat_file(char* filename) {
    Process process;
    FILE* file = fopen(filename, "r");
    if(file == NULL) {
        perror("Error opening stat file");
        exit(1);
    }
    fscanf(file, "%d %s %c %d %*d %*d %*d %*d %*u %*u %*u %*u %lu %lu %*d %ld %ld %*d %*d %*u %lu", &process.pid, process.name, &process.state, &process.parent_pid, &process.utime, &process.stime, &process.vsize);
    fclose(file);
    return process;
}
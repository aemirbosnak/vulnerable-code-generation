//FormAI DATASET v1.0 Category: System process viewer ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>

// Struct to store process information
typedef struct {
    char name[255];
    int pid;
    char status;
    int mem_size;
} ProcessInfo;

// Function to get all running processes
void getAllProcesses(ProcessInfo **proc_list, int *num_procs) {
    DIR *dir;
    struct dirent *entry;
    char path[256];
    char name[256];
    char status[2];
    int pid, mem_size;
    FILE *fp;

    // Count number of processes
    *num_procs = 0;
    dir = opendir("/proc/");
    while ((entry = readdir(dir)) != NULL) {
        if (isdigit(entry->d_name[0])) {
            (*num_procs)++;
        }
    }
    closedir(dir);

    // Allocate memory for process list
    *proc_list = (ProcessInfo*)malloc(*num_procs*sizeof(ProcessInfo));

    // Get process information
    int i = 0;
    dir = opendir("/proc/");
    while ((entry = readdir(dir)) != NULL) {
        if (isdigit(entry->d_name[0])) {
            pid = atoi(entry->d_name);
            sprintf(path, "/proc/%d/status", pid);
            fp = fopen(path, "r");
            fgets(name, 256, fp);
            fgets(status, 2, fp);
            fgets(name, 256, fp);
            fgets(name, 256, fp);
            fgets(name, 256, fp);
            fgets(name, 256, fp);
            fgets(name, 256, fp);
            fgets(name, 256, fp);
            fscanf(fp, "VmSize:\t%d", &mem_size);
            fclose(fp);
            (*proc_list)[i].pid = pid;
            strcpy((*proc_list)[i].name, name);
            (*proc_list)[i].status = status[0];
            (*proc_list)[i].mem_size = mem_size;
            i++;
        }
    }
    closedir(dir);
}

int main(void) {
    ProcessInfo *proc_list;
    int num_procs;
    int i;

    // Get all running processes
    getAllProcesses(&proc_list, &num_procs);

    // Display process information
    printf("Number of running processes: %d\n", num_procs);
    printf("Name\tPID\tStatus\tMemory Size\n");
    for (i = 0; i < num_procs; i++) {
        printf("%s\t%d\t%c\t%d\n", proc_list[i].name, proc_list[i].pid, proc_list[i].status, proc_list[i].mem_size);
    }

    // Free memory allocated for process list
    free(proc_list);

    return 0;
}
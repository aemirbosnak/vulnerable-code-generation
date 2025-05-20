//FormAI DATASET v1.0 Category: System process viewer ; Style: distributed
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

// Structure to hold the process info
typedef struct process_info {
    int pid;
    char process_name[50];
    int memory_usage;
    int cpu_usage;
    char status[20];
} process_info;

// Function to get the process list from local machine
process_info* get_process_list() {
    FILE *file;
    char buffer[1024], *ptr;
    process_info *list = malloc(sizeof(process_info) * 100);
    int i = 0;

    // Open the process list file
    file = fopen("/proc/stat", "r");

    while(fgets(buffer, sizeof(buffer), file)) {
        if(strncmp(buffer, "processes", strlen("processes"))==0) {
            ptr = strtok(buffer, " ");
            ptr = strtok(NULL, " ");
            list[i].pid = atoi(ptr);
        }
        else if(strncmp(buffer, "procs_running", strlen("procs_running"))==0) {
            ptr = strtok(buffer, " ");
            ptr = strtok(NULL, " ");
            list[i].cpu_usage = atoi(ptr);
            i++;
        }
    }

    // Close the file and return the process list
    fclose(file);
    return list;
}

// Function to display the process list
void display_process_list(process_info *list) {
    printf("--------------------------------------------------------\n");
    printf("| %-10s | %-20s | %-15s | %-15s |\n", "PID", "Process Name", "Memory Usage", "CPU Usage");
    printf("--------------------------------------------------------\n");

    for(int i=0; list[i].pid!=0; i++) {
        printf("| %-10d | %-20s | %-15d | %-15d |\n", list[i].pid, 
        list[i].process_name, list[i].memory_usage, list[i].cpu_usage);
    }

    printf("--------------------------------------------------------\n");
}

int main() {
    process_info *list;
    list = get_process_list();
    display_process_list(list);
    return 0;
}
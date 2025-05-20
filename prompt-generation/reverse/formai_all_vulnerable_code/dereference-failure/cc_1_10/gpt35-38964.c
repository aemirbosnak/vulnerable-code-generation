//FormAI DATASET v1.0 Category: System process viewer ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include<fcntl.h>
#include<ctype.h>
#include<unistd.h>

// Define a struct to store the process information
typedef struct {
    char pid[10];
    char name[100];
    char status[10];
    char memory[20];
} Process;

// Function to check whether the given character is a digit or not
int is_digit(char c) {
    if(c >= '0' && c <= '9') {
        return 1;
    }
    return 0;
}

// Function to get the total memory usage of a process
void get_memory_usage(char* pid, char* memory) {
    // Open the file "status" inside the process directory
    char path[50];
    sprintf(path, "/proc/%s/status", pid);
    FILE* file = fopen(path, "r");
    if(file == NULL) {
        sprintf(memory, "N/A");
        return;
    }
    char line[1000];
    while(fgets(line, 1000, file)) {
        // If the line starts with "VmSize", then extract the memory usage
        if(strncmp(line, "VmSize:", 7) == 0) {
            char* token = strtok(line, " ");
            token = strtok(NULL, " ");
            if(token != NULL) {
                strcpy(memory, token);
                strcat(memory, " kB");
                break;
            }
        }
    }
    fclose(file);
}

// Function to get the process information
void get_process_info(Process* process, char* pid) {
    // Open the file "status" inside the process directory
    char path[50];
    sprintf(path, "/proc/%s/status", pid);
    FILE* file = fopen(path, "r");
    if(file == NULL) {
        strcpy(process->name, "N/A");
        strcpy(process->status, "N/A");
        strcpy(process->memory, "N/A");
        return;
    }
    char line[1000];
    while(fgets(line, 1000, file)) {
        // If the line starts with "Name", then extract the process name
        if(strncmp(line, "Name:", 5) == 0) {
            char* token = strtok(line, "\t");
            token = strtok(NULL, "\t");
            if(token != NULL) {
                strcpy(process->name, token);
            }
        }
        // If the line starts with "State", then extract the process status
        else if(strncmp(line, "State:", 6) == 0) {
            char* token = strtok(line, "\t");
            token = strtok(NULL, "\t");
            if(token != NULL) {
                strcpy(process->status, token);
            }
        }
    }
    fclose(file);
    // Get the memory usage of the process
    get_memory_usage(pid, process->memory);
}

int main() {
    // Open the directory "/proc"
    DIR* directory = opendir("/proc");
    if(directory == NULL) {
        printf("Failed to open directory.");
        return 0;
    }
    // Define an array to store the process information of all processes
    Process processes[500];
    int index = 0;
    struct dirent* dirent;
    while((dirent = readdir(directory))) {
        // Check whether the name of the directory is a number or not
        int is_process = 1;
        for(int i=0;i<strlen(dirent->d_name);i++) {
            if(!is_digit(dirent->d_name[i])) {
                is_process = 0;
                break;
            }
        }
        if(is_process) {
            // If the name of the directory is a number, then get the process information
            get_process_info(&processes[index], dirent->d_name);
            strcpy(processes[index].pid, dirent->d_name);
            index++;
        }
    }
    closedir(directory);
    // Print the process information of all processes
    printf("Process ID\tProcess Name\tProcess Status\tMemory Usage\n");
    for(int i=0;i<index;i++) {
        printf("%s\t\t%s\t\t%s\t\t%s\n", processes[i].pid, processes[i].name, processes[i].status, processes[i].memory);
    }
    return 0;
}
//FormAI DATASET v1.0 Category: System process viewer ; Style: invasive
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

// Function to get the process name
char* get_process_name(char* pid) {
    // Creating file path
    char path[100];
    sprintf(path, "/proc/%s/stat", pid);
     
    // Open the file for reading
    FILE* fp = fopen(path, "r");
 
    if (fp == NULL) {
        return "N/A";
    }
 
    // Read the file and get the process name
    char buffer[100];
    fgets(buffer,sizeof(buffer),fp);
    char* name = strtok(buffer, " ");
 
    fclose(fp);
    return name;
}

// Function to get the process status
char* get_process_status(char* pid) {
    // Creating file path
   char path[100];
   sprintf(path, "/proc/%s/status", pid);

   // Open the file for reading
   FILE* fp = fopen(path, "r");
 
    if (fp == NULL) {
        return "N/A";
    }
 
    char buffer[100];
    while(fgets(buffer, 100, fp) != NULL) {
        if(strncmp(buffer, "State:", 6) == 0) {
            char* status = strtok(buffer+7, "\n");
            fclose(fp);
            return status;
        }
    }
    return "N/A";
}

// Function to get the memory usage (in kilobytes)
long int get_memory_usage(char* pid) {
    // Creating file path
    char path[100];
    sprintf(path, "/proc/%s/statm", pid);

    // Open the file for reading
    FILE* fp = fopen(path, "r");
    if (fp == NULL) {
      return -1;
    }

    // Read the file and get the resident memory size
    long int memory;
    fscanf(fp, "%ld", &memory);

    // Closing file handle
    fclose(fp);

    return memory;
}

// Function to print the process information
void print_process_information(char* pid, char* name) {
    // Print process information
    printf("PID: %s\n", pid);
    printf("Process Name: %s\n", name);
    printf("Process Status: %s\n", get_process_status(pid));
    printf("Memory Usage: %ld KB\n", get_memory_usage(pid));
    printf("\n");
}

int main() {
    // Open the directory for reading
    DIR *directory = opendir("/proc");

    if (directory == NULL) {
        printf("Error: Unable to open directory /proc\n");
        exit(1);
    }

    // Loop over each file in the directory /proc
    struct dirent* file;
    while ((file = readdir(directory)) != NULL) {
        // Checking if the filename is a process ID
        if (atoi(file->d_name) != 0) {
            char* pid = file->d_name;

            // Getting process name and printing process information
            char* process_name = get_process_name(pid);
            print_process_information(pid, process_name);
        }
    }

    // Closing directory handle
    closedir(directory);

    return 0;
}
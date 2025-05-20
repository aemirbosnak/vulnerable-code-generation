//FormAI DATASET v1.0 Category: System process viewer ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <dirent.h>
#include <pthread.h>

// Structure to store stats of system processes
typedef struct process_info{
    char name[50];
    int pid;
    int ppid;
    int threads;
} process_info;

// Declare mutex lock to ensure thread safety
pthread_mutex_t lock;

// Function to count number of threads of a process
void count_threads(int pid, process_info *p_info){
    // Create a file path with the process id
    char file_path[100];
    sprintf(file_path, "/proc/%d/status", pid);
    
    // Open the file
    FILE *fp = fopen(file_path, "r");
    if(fp == NULL){
        perror("Error opening file");
        exit(1);
    }
    
    // Read the lines of the file until Threads line is found
    char line[256];
    while(fgets(line, sizeof(line), fp)){
        if(strncmp(line, "Threads:", 8) == 0){
            // Extract the thread count and store in the process info structure
            sscanf(line, "%*s %d", &p_info->threads);
            break;
        }
    }
    
    // Close the file
    fclose(fp);
}

// Function to retrieve information of all processes
void get_all_processes(process_info *processes, int *num_processes){
    // Open the proc directory
    DIR *dir = opendir("/proc");
    struct dirent *entry;
    int i = 0;
    
    // Loop through each directory entry to find process directories
    while((entry = readdir(dir)) != NULL){
        if(entry->d_type == DT_DIR && atoi(entry->d_name) > 0){
            // If process directory is found, extract process information and add to processes array
            char file_path[100];
            sprintf(file_path, "/proc/%s/stat", entry->d_name);
            
            FILE *fp = fopen(file_path, "r");
            if(fp == NULL){
                perror("Error opening file");
                exit(1);
            }
            
            process_info p_info;
            char comm[50];
            
            // Extract process information
            fscanf(fp, "%d %s %*c %d", &p_info.pid, comm, &p_info.ppid);
            strncpy(p_info.name, comm+1, strlen(comm)-2);
            
            fclose(fp);
            
            // Count number of threads of the process
            count_threads(p_info.pid, &p_info);
            
            // Add the process info to the processes array
            processes[i] = p_info;
            i++;
        }
    }
    
    *num_processes = i;
    closedir(dir);
}

// Function to print process information
void print_processes(process_info *processes, int num_processes){
    // Acquire the lock to ensure thread safety
    pthread_mutex_lock(&lock);
    
    printf("%-20s %-10s %-10s %s\n", "NAME", "PID", "PPID", "THREADS");
    for(int i=0; i<num_processes; i++){
        printf("%-20s %-10d %-10d %d\n", processes[i].name, processes[i].pid, processes[i].ppid, processes[i].threads);
    }
    
    // Release the lock
    pthread_mutex_unlock(&lock);
}

// Thread function to periodically print process information
void *print_process_info(void *args){
    process_info *processes = (process_info *)args;
    
    while(true){
        // Sleep for 5 seconds
        sleep(5);
        print_processes(processes, *(int *)args);
    }
}

int main(){
    process_info processes[500];
    int num_processes = 0;
    
    // Get information of all processes and store in processes array
    get_all_processes(processes, &num_processes);
    
    // Create a thread to periodically print process information
    pthread_t t_id;
    
    if(pthread_mutex_init(&lock, NULL) != 0){
        perror("Error initializing mutex lock");
        exit(1);
    }
    
    if(pthread_create(&t_id, NULL, print_process_info, &num_processes) != 0){
        perror("Error creating thread");
        exit(1);
    }
    
    // Main thread sleeps until program is terminated by user
    while(true){
        sleep(3600);
    }
    
    return 0;
}
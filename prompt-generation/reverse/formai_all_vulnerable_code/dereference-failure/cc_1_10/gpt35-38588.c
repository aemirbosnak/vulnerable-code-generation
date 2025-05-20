//FormAI DATASET v1.0 Category: System process viewer ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <fcntl.h>
#include <unistd.h>

// Function to get the process name from process id
void get_process_name(int pid, char *pname){
    char proc_path[100];
    sprintf(proc_path, "/proc/%d/cmdline", pid);
    FILE *fp = fopen(proc_path, "r");
    if(fp == NULL){
        strcpy(pname, "N/A");
        return;
    }
    fscanf(fp, "%s", pname);
    fclose(fp);
}

// Function to get the process status from process id
void get_process_status(int pid, char *status){
    char proc_path[100];
    sprintf(proc_path, "/proc/%d/status", pid);
    FILE *fp = fopen(proc_path, "r");
    if(fp == NULL){
        strcpy(status, "N/A");
        return; 
    }
    char line[100], field[100], value[100];
    while(fgets(line, 100, fp) != NULL){
        sscanf(line, "%s %s", field, value);
        if(strcmp(field, "State:") == 0){
            strcpy(status, value);
            break;
        }
    }
    fclose(fp);
}

// Main Program
int main(){
    DIR *dir = opendir("/proc");
    if(dir == NULL){
        perror("Failed to open directory /proc");
        exit(1);
    }
    struct dirent *dir_entry;
    printf("PID  \t Process Name  \t Status\n");
    printf("=============================================\n");
    while((dir_entry = readdir(dir)) != NULL){
        if(dir_entry->d_type != DT_DIR)
            continue;
        char *dir_name = dir_entry->d_name;
        int pid = atoi(dir_name);
        if(pid == 0) // Skip invalid pid directory
            continue;
        char pname[100], status[100];
        get_process_name(pid, pname);
        get_process_status(pid, status);
        printf("%d \t %-15s \t %s\n", pid, pname, status);
    }
    closedir(dir);
    return 0;
}
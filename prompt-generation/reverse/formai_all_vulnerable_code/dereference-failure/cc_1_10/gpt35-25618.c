//FormAI DATASET v1.0 Category: System process viewer ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <dirent.h>
#include <unistd.h>

#define MAX_PID_LENGTH 6
#define MAX_LINE_LENGTH 256

/* Function to get the process name from process id */
char* get_process_name(char *pid) {
    FILE *fp;
    char *path = malloc(strlen("/proc//comm") + strlen(pid) + 1);
    char *process_name = malloc(MAX_LINE_LENGTH);
    
    /* Create file path using process id */
    strcpy(path, "/proc/");
    strcat(path, pid);
    strcat(path, "/comm");
    
    /* Read process name from file */
    fp = fopen(path, "r");
    if(fp == NULL) {
        printf("Failed to open file %s\n", path);
        exit(EXIT_FAILURE);
    }
    fgets(process_name, MAX_LINE_LENGTH, fp);
    fclose(fp);
    
    /* Strip newline character from process name */
    if(process_name[strlen(process_name) - 1] == '\n') {
        process_name[strlen(process_name) - 1] = '\0';
    }
    free(path);
    return process_name;
}

/* Function to display process information */
void display_process_info(char *pid) {
    char *process_name;
    char *status_path = malloc(strlen("/proc//status") + strlen(pid) + 1);
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    
    /* Create status file path using process id */
    strcpy(status_path, "/proc/");
    strcat(status_path, pid);
    strcat(status_path, "/status");
    
    /* Open status file for reading */
    fp = fopen(status_path, "r");
    if(fp == NULL) {
        printf("Failed to open file %s\n", status_path);
        exit(EXIT_FAILURE);
    }
    
    /* Read process information from status file */
    printf("PID:\t\t%s\n", pid);
    while(fgets(line, MAX_LINE_LENGTH, fp)) {
        if(strncmp(line, "Name:", 5) == 0) {
            process_name = strtok(line + 5, "\n");
            printf("Name:\t\t%s\n", process_name);
        }
        else if(strncmp(line, "State:", 6) == 0) {
            printf("State:\t\t%s", line + 6);
        }
        else if(strncmp(line, "VmPeak:", 7) == 0) {
            printf("VmPeak:\t\t%s", line + 7);
        }
        else if(strncmp(line, "VmSize:", 7) == 0) {
            printf("VmSize:\t\t%s", line + 7);
        }
        else if(strncmp(line, "VmHWM:", 6) == 0) {
            printf("VmHWM:\t\t%s", line + 6);
        }
        else if(strncmp(line, "Threads:", 8) == 0) {
            printf("Threads:\t%s", line + 8);
        }
    }
    
    /* Close status file and free memory */
    fclose(fp);
    free(status_path);
}

/* Main function */
int main(void) {
    DIR *dirp;
    struct dirent *entry;
    char *pid_list[MAX_PID_LENGTH];
    char pid[MAX_PID_LENGTH];
    int pid_count = 0;
    int i, j;
    
    /* Open /proc directory for reading */
    dirp = opendir("/proc");
    if(dirp == NULL) {
        printf("Failed to open directory /proc\n");
        exit(EXIT_FAILURE);
    }
    
    /* Loop through each entry in the /proc directory */
    while((entry = readdir(dirp)) != NULL) {
        /* Check if entry name is a number */
        for(i = 0; i < strlen(entry->d_name); i++) {
            if(!isdigit(entry->d_name[i])) {
                break;
            }
        }
        if(i == strlen(entry->d_name)) {
            pid_list[pid_count] = malloc(strlen(entry->d_name) + 1);
            strcpy(pid_list[pid_count], entry->d_name);
            pid_count++;
        }
    }
    
    /* Sort the list of process ids */
    for(i = 0; i < pid_count - 1; i++) {
        for(j = i + 1; j < pid_count; j++) {
            if(atoi(pid_list[i]) > atoi(pid_list[j])) {
                char *temp = pid_list[i];
                pid_list[i] = pid_list[j];
                pid_list[j] = temp;
            }
        }
    }
    
    /* Display process information for each process */
    for(i = 0; i < pid_count; i++) {
        display_process_info(pid_list[i]);
        printf("\n");
        free(pid_list[i]);
    }
    
    /* Free memory and close directory */
    closedir(dirp);
    return(EXIT_SUCCESS);
}
//FormAI DATASET v1.0 Category: System process viewer ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <dirent.h>
#include <unistd.h>

// function to get all the currently running process IDs
int* get_process_ids(int* count) {
    DIR* dir;
    struct dirent* dir_info;
    int* process_ids = (int*)malloc(sizeof(int) * 500); // assuming max number of processes as 500
    int i = 0;
    if ((dir = opendir("/proc")) != NULL) {
        while ((dir_info = readdir(dir)) != NULL) {
            if (isdigit(dir_info->d_name[0])) {
                process_ids[i++] = atoi(dir_info->d_name);
            }
        }
        closedir(dir);
    }
    *count = i;
    return process_ids;
}

// function to get the name of a process given its ID
char* get_process_name(int pid) {
    char* path = (char*)malloc(sizeof(char) * 100);
    sprintf(path, "/proc/%d/stat", pid);
    FILE* file = fopen(path, "r");
    char name[100];
    fscanf(file, "%*d (%[^)])", name);
    fclose(file);
    char* process_name = (char*)malloc(sizeof(char) * strlen(name));
    strcpy(process_name, name);
    free(path);
    return process_name;
}

// function to get the status of a process given its ID
char* get_process_status(int pid) {
    char* path = (char*)malloc(sizeof(char) * 100);
    sprintf(path, "/proc/%d/status", pid);
    FILE* file = fopen(path, "r");
    char status[100], value[100];
    while (fscanf(file, "%s %s", status, value) > 0) {
        if (strcmp(status, "State:") == 0) {
            fclose(file);
            char* process_status = (char*)malloc(sizeof(char) * strlen(value));
            strcpy(process_status, value);
            free(path);
            return process_status;
        }
    }
    fclose(file);
    free(path);
    return NULL;
}

// main function to display all currently running processes and their details
int main() {
    int count;
    int* process_ids = get_process_ids(&count);
    printf("Total number of processes : %d\n\n", count);
    printf("%10s | %30s | %10s\n", "PID", "Process Name", "Status");
    printf("---------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        char* process_name = get_process_name(process_ids[i]);
        char* process_status = get_process_status(process_ids[i]);
        printf("%10d | %30s | %10s\n", process_ids[i], process_name, process_status);
        free(process_name);
        free(process_status);
    }
    free(process_ids);
    return 0;
}
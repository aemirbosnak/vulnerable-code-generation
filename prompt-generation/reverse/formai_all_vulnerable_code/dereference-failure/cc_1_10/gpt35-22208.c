//FormAI DATASET v1.0 Category: System process viewer ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

// Defining maximum length for process ID 
#define MAX_PROC_ID_LEN 6

// Function to check if string is a valid number
int is_number(const char *str){
    while(*str){
        if(!isdigit(*str)) return 0;
        str++;
    }
    return 1;
}

// Function to read the contents of file
char* read_file(char* path){
    char *content = NULL;
    FILE* file = fopen(path, "r");
    if(file){
        fseek(file, 0, SEEK_END);
        long size = ftell(file);
        fseek(file, 0, SEEK_SET);
        content = malloc(size + 1);
        fread(content, 1, size, file);
        content[size] = '\0';
        fclose(file);
    }
    return content;
}

// Function to extract name of process from "/proc/[pid]/cmdline" file
char* get_process_name(char* pid_path){
    char* cmdline_path = malloc(strlen(pid_path) + 11);
    strcpy(cmdline_path, pid_path);
    strcat(cmdline_path, "/cmdline");
    char* cmdline_content = read_file(cmdline_path);
    free(cmdline_path);
    if(cmdline_content){
        char *process_name = strtok(cmdline_content, "\0");
        return process_name;
    }
    return NULL;
}

int main() {
    DIR *dir;
    struct dirent *entry;
    printf("   PID    |   NAME\n");
    printf("__________|_____________\n");

    // Open the directory /proc
    dir = opendir("/proc");
    if (dir == NULL) {
        return 0;
    }

    // Loop through every subdirectory in /proc
    while ((entry = readdir(dir)) != NULL) {
        if (is_number(entry->d_name)) {
            char* pid = entry->d_name;
            char* pid_path = malloc(strlen(pid) + 7);
            strcpy(pid_path, "/proc/");
            strcat(pid_path, pid);
            char* process_name = get_process_name(pid_path);
            if(process_name){
                printf(" %-9s|  %s\n", pid, process_name);
            }
            free(pid_path);
            free(process_name);
        }
    }

    // Close the directory
    closedir(dir);
    return 0;
}
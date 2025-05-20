//FormAI DATASET v1.0 Category: System process viewer ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

// function to check if given character is a digit
int is_digit(char c) {
    return c >= '0' && c <= '9';
}

// function to get process name from process ID
char* get_process_name(int pid) {
    char* name = (char*)malloc(sizeof(char) * 1024);
    sprintf(name, "/proc/%d/cmdline", pid);
    
    FILE* fp = fopen(name, "r");
    if (fp == NULL) {
        sprintf(name, "unknown");
        return name;
    }
    
    char* buffer = (char*)malloc(sizeof(char) * 1024);
    size_t buffer_size = 1024;
    ssize_t read_size = getline(&buffer, &buffer_size, fp);
    fclose(fp);
    
    if (read_size <= 0) {
        sprintf(name, "unknown");
        free(buffer);
        return name;
    }
    
    // process name is the first argument in the command line
    char* token = strtok(buffer, " ");
    sprintf(name, "%s", token);
    free(buffer);
    
    return name;
}

// main function
int main() {
    printf("Hello! Welcome to the Process Viewer program.\n");
    printf("Here, you can view all the running processes on your system.\n");
    printf("Press enter to continue...\n");
    getchar();
    
    DIR* proc_dir = opendir("/proc");
    if (proc_dir == NULL) {
        printf("Error: could not open /proc directory.\n");
        return 1;
    }
    
    struct dirent* entry;
    
    printf("\n");
    printf("%-6s %-20s %-10s\n", "PID", "Name", "State");
    printf("==============================================\n");
    
    while ((entry = readdir(proc_dir)) != NULL) {
        // check if the entry is a process directory
        if (is_digit(entry->d_name[0])) {
            int pid = atoi(entry->d_name);
            
            // get process name and state from process status file
            char stat_file[1024];
            sprintf(stat_file, "/proc/%d/status", pid);
            
            FILE* fp = fopen(stat_file, "r");
            if (fp == NULL) {
                continue;
            }
            
            char* line = NULL;
            size_t len = 0;
            ssize_t read;

            char state = ' ';
            char name[1024];
            memset(name, 0, sizeof(char) * 1024);

            while ((read = getline(&line, &len, fp)) != -1) {
                if (strncmp(line, "Name:", 5) == 0) {
                    strcpy(name, line + 5);
                    name[strlen(name) - 1] = '\0';
                } else if (strncmp(line, "State:", 6) == 0) {
                    state = line[7];
                }
            }

            free(line);
            fclose(fp);

            if (strlen(name) > 0) {
                printf("%-6d %-20s %-10c\n", pid, get_process_name(pid), state);
            }
        }
    }
    
    closedir(proc_dir);
    printf("\n");
    printf("Thank you for using the Process Viewer program. Press enter to exit...\n");
    getchar();
    
    return 0;
}
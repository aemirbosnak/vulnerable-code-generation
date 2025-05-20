//FormAI DATASET v1.0 Category: System process viewer ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>
#include<ctype.h>
#include<unistd.h>

#define MAX_PATH_LENGTH 4096
#define MAX_PID_LENGTH 10

void print_process_info(char* pid) {
    char stat_file_path[MAX_PATH_LENGTH];
    sprintf(stat_file_path, "/proc/%s/stat", pid);

    FILE* stat_file = fopen(stat_file_path, "r");

    char* line_buffer = NULL;
    size_t buffer_length = 0;

    if(stat_file == NULL) {
        printf("Error: Process with PID %s not found\n", pid);
        return;
    }

    getline(&line_buffer, &buffer_length, stat_file);

    char* token = strtok(line_buffer, " ");

    int count = 0;

    while(token != NULL) {
        switch(count) {
            case 0:
                printf("PID: %s\n", token);
                break;
            case 1:
                printf("Process name: %s\n", token);
                break;
            case 2:
                printf("Process state: %s\n", token);
                break;
            case 3:
                printf("Parent PID: %s\n", token);
                break;
            case 13:
                printf("Processor time used (in clock ticks): %s\n", token);
                break;
            case 21:
                printf("Virtual memory size in bytes: %s\n", token);
                break;
        }

        token = strtok(NULL, " ");
        count++;
    }

    fclose(stat_file);
    free(line_buffer);
}

void show_processes() {
    DIR* proc_dir = opendir("/proc");
    struct dirent* dir_entry;

    while((dir_entry = readdir(proc_dir)) != NULL) {
        if(isdigit(dir_entry->d_name[0])) {
            char pid[MAX_PID_LENGTH];
            strcpy(pid, dir_entry->d_name);
            print_process_info(pid);
            printf("\n");
        }
    }

    closedir(proc_dir);
}

int main() {
    printf("Process viewer\n\n");
    printf("Processes:\n");

    show_processes();
    
    return 0;
}
//FormAI DATASET v1.0 Category: System process viewer ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

// Define constants
#define PROC_DIRECTORY "/proc"
#define STAT_FILE "/stat"
#define CMDLINE_FILE "/cmdline"
#define MAX_COMMAND_LENGTH 4096

// Define struct to store process information
typedef struct process_info {
    int pid;
    char* name;
    char status;
} process_info;

// Function to extract process name from stat file
char* get_process_name(int pid) {
    char stat_path[1024];
    snprintf(stat_path, 1024, "%s/%d%s", PROC_DIRECTORY, pid, STAT_FILE);
    FILE* stat_file = fopen(stat_path, "r");
    if (stat_file == NULL) {
        return "";
    }
    char* buffer = (char*) malloc(MAX_COMMAND_LENGTH);
    size_t size = MAX_COMMAND_LENGTH;
    getline(&buffer, &size, stat_file);
    char* start_ptr = strchr(buffer, '(') + 1;
    char* end_ptr = strchr(buffer, ')');
    strncpy(buffer, start_ptr, end_ptr - start_ptr);
    buffer[end_ptr - start_ptr] = '\0';
    fclose(stat_file);
    return buffer;
}

// Function to check if a process is running
int check_process(int pid) {
    char proc_path[1024];
    snprintf(proc_path, 1024, "%s/%d", PROC_DIRECTORY, pid);
    DIR* proc_dir = opendir(proc_path);
    if (proc_dir) {
        closedir(proc_dir);
        return 1;
    } else {
        return 0;
    }
}

// Function to print a list of running processes
void print_process_list() {
    DIR* proc_dir = opendir(PROC_DIRECTORY);
    struct dirent* entry;
    while (entry = readdir(proc_dir)) {
        if (entry->d_type == DT_DIR) {
            int pid = atoi(entry->d_name);
            if (pid != 0 && check_process(pid)) {
                char* name = get_process_name(pid);
                if (strlen(name) != 0) {
                    process_info* info = (process_info*) malloc(sizeof(process_info));
                    info->pid = pid;
                    info->name = name;
                    char status_path[1024];
                    snprintf(status_path, 1024, "%s/%d/status", PROC_DIRECTORY, pid);
                    FILE* status_file = fopen(status_path, "r");
                    char* line = NULL;
                    size_t len = 0;
                    while (getline(&line, &len, status_file) != -1) {
                        if (strncmp(line, "State:", 6) == 0) {
                            info->status = line[7];
                            break;
                        }
                    }
                    printf("%d\t%s\t%c\n", info->pid, info->name, info->status);
                    free(info);
                }
            }
        }
    }
    closedir(proc_dir);
}

int main() {
    print_process_list();
    return 0;
}
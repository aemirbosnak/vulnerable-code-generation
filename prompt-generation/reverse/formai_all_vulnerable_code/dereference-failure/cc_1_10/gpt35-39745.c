//FormAI DATASET v1.0 Category: System process viewer ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <ctype.h>

#define MAX_PID_LENGTH 6
#define BUFFER_SIZE 1024

void print_process_details(const char *pid) {
    char status_file_path[BUFFER_SIZE];
    snprintf(status_file_path, BUFFER_SIZE, "/proc/%s/status", pid);
    FILE *status_file = fopen(status_file_path, "r");

    if (status_file == NULL) {
        return;
    }

    char line[BUFFER_SIZE];
    int line_number = 0;
    while (fgets(line, BUFFER_SIZE, status_file)) {
        line_number++;
        if (line_number == 3) {
            printf("Process Name: %s", line+6);
        }
        if (line_number == 7) {
            printf("Resident Set Size: %s", line+24);
        }
    }

    fclose(status_file);
}

void list_processes() {
    DIR *proc_dir;
    struct dirent *dir_entry;
    char pid[MAX_PID_LENGTH];

    proc_dir = opendir("/proc");
    if (proc_dir == NULL) {
        return;
    }

    printf("~~~ SURREALIST PROCESS VIEWER ~~~\n");

    while ((dir_entry = readdir(proc_dir)) != NULL) {
        if (isdigit(*dir_entry->d_name)) {
            strncpy(pid, dir_entry->d_name, MAX_PID_LENGTH);
            printf("\nPID: %s\n", pid);
            print_process_details(pid);
        }
    }

    closedir(proc_dir);
}

int main() {
    list_processes();
    return 0;
}
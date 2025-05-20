//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

#define BUFFER_SIZE 256

void trim_newline(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len-1] == '\n') {
        str[len-1] = '\0';
    }
}

int is_number(const char *str) {
    while (*str) {
        if (!isdigit(*str)) return 0;
        str++;
    }
    return 1;
}

void get_process_info(const char *pid) {
    char path[BUFFER_SIZE];
    snprintf(path, sizeof(path), "/proc/%s/stat", pid);
    
    FILE *file = fopen(path, "r");
    if (!file) return;

    char buffer[BUFFER_SIZE];
    fgets(buffer, sizeof(buffer), file);
    
    char *token = strtok(buffer, " ");
    int count = 0;
    char *comm = NULL;

    while (token) {
        if (count == 1)
            comm = token; // command name
        if (count == 22) // CPU time (utime + stime)
            printf("PID: %s, Comm: %s, CPU time: %s\n", pid, comm, token);
        if (count == 23) // memory usage
            printf("Memory: %s\n", token);
        token = strtok(NULL, " ");
        count++;
    }

    fclose(file);
}

void list_processes() {
    DIR *proc_dir = opendir("/proc");
    struct dirent *entry;

    if (!proc_dir) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(proc_dir))) {
        if (is_number(entry->d_name)) {
            get_process_info(entry->d_name);
        }
    }

    closedir(proc_dir);
}

void print_header() {
    printf("==== Process Viewer ====\n");
    printf("PID\tComm\tCPU time\tMemory\n");
    printf("========================\n");
}

int main() {
    print_header();
    list_processes();
    return 0;
}
//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 256

void print_process_info(const char *pid) {
    char path[BUFFER_SIZE];
    snprintf(path, sizeof(path), "/proc/%s/stat", pid);

    FILE *file = fopen(path, "r");
    if (file) {
        char comm[BUFFER_SIZE]; 
        char state;
        long ppid;
        
        fscanf(file, "%*s %s %c %ld", comm, &state, &ppid);
        fclose(file);

        printf("PID: %-5s Comm: %-25s State: %c PPID: %ld\n", pid, comm, state, ppid);
    }
}

void list_processes() {
    struct dirent *entry;
    DIR *dp = opendir("/proc");

    if (dp == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    printf("%-7s %-25s %-6s %-10s\n", "PID", "Command", "State", "PPID");
    printf("%-7s %-25s %-6s %-10s\n", "---", "-------", "-----", "----");

    while ((entry = readdir(dp)) != NULL) {
        if (isdigit(entry->d_name[0])) {
            print_process_info(entry->d_name);
        }
    }

    closedir(dp);
}

int main() {
    printf("Simple Process Viewer - Ken Thompson Style\n");
    printf("============================================\n");
    list_processes();
    return 0;
}
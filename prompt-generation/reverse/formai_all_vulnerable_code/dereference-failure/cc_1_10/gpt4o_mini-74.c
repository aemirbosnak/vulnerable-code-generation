//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>

#define PROC_DIR "/proc"
#define BUF_SIZE 256

void display_process_info(const char *pid) {
    char path[BUF_SIZE];
    snprintf(path, sizeof(path), "%s/%s/status", PROC_DIR, pid);
    
    FILE *file = fopen(path, "r");
    if (!file) {
        perror("Failed to open process file");
        return;
    }

    char line[BUF_SIZE];
    printf("Process ID: %s\n", pid);
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, "Name:") || strstr(line, "State:") || 
            strstr(line, "Pid:") || strstr(line, "Uid:")) {
            printf("%s", line);
        }
    }
    fclose(file);
}

void list_processes() {
    DIR *proc = opendir(PROC_DIR);
    struct dirent *entry;

    if (!proc) {
        perror("Could not open " PROC_DIR);
        exit(EXIT_FAILURE);
    }

    printf("List of running processes:\n");
    while ((entry = readdir(proc))) {
        if (entry->d_type == DT_DIR) {
            char *endptr;
            long pid = strtol(entry->d_name, &endptr, 10);
            if (*endptr == '\0') { // Valid PID directory
                display_process_info(entry->d_name);
                printf("\n");
            }
        }
    }

    closedir(proc);
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        list_processes();
    } else {
        for (int i = 1; i < argc; i++) {
            display_process_info(argv[i]);
            printf("\n");
        }
    }
    return 0;
}
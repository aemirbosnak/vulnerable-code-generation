//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <ctype.h>

#define PROC_DIR "/proc"
#define MAX_BUF 256

void display_process_info(const char *pid) {
    char path[MAX_BUF], buf[MAX_BUF];
    snprintf(path, sizeof(path), "/proc/%s/status", pid);
    
    FILE *file = fopen(path, "r");
    if (!file) {
        perror("fopen");
        return;
    }

    printf("Process ID: %s\n", pid);
    while (fgets(buf, sizeof(buf), file)) {
        if (strncmp(buf, "Name:", 5) == 0 ||
            strncmp(buf, "State:", 6) == 0 ||
            strncmp(buf, "Pid:", 4) == 0 ||
            strncmp(buf, "PPid:", 5) == 0 ||
            strncmp(buf, "Uid:", 4) == 0 ||
            strncmp(buf, "Gid:", 4) == 0) {
            printf("%s", buf);
        }
    }
    fclose(file);
    printf("\n");
}

void list_processes() {
    DIR *proc_dir = opendir(PROC_DIR);
    if (!proc_dir) {
        perror("opendir");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(proc_dir)) != NULL) {
        if (isdigit(*entry->d_name)) {
            display_process_info(entry->d_name);
        }
    }
    closedir(proc_dir);
}

void print_help() {
    printf("Minimalist Process Viewer\n");
    printf("Usage: ./process_viewer\n");
    printf("This program lists all running processes and their information.\n");
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        if (strcmp(argv[1], "--help") == 0) {
            print_help();
            return 0;
        } else {
            printf("Unknown option: %s\n", argv[1]);
            print_help();
            return 1;
        }
    }

    printf("Fetching process information...\n\n");
    list_processes();
    return 0;
}
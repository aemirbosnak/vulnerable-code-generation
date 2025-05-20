//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>

#define PROC_DIR "/proc"
#define CMDLINE_BUFFER 256

void display_process_info(int pid) {
    char cmdline_path[CMDLINE_BUFFER];
    snprintf(cmdline_path, sizeof(cmdline_path), "%s/%d/cmdline", PROC_DIR, pid);
    
    FILE *file = fopen(cmdline_path, "r");
    if (file) {
        char cmdline[CMDLINE_BUFFER];
        if (fgets(cmdline, sizeof(cmdline), file)) {
            printf("PID: %-5d Command: %s\n", pid, cmdline);
        }
        fclose(file);
    } else {
        printf("PID: %-5d Command: <unable to read>\n", pid);
    }
}

void inspect_proc_directory() {
    struct dirent *entry;
    DIR *proc_directory = opendir(PROC_DIR);
    
    if (proc_directory == NULL) {
        perror("Could not open /proc directory");
        exit(EXIT_FAILURE);
    }

    printf("Sherlock Holmes Process Viewer\n");
    printf("Unveiling the mysteries of the processes lurking in the shadows...\n\n");
    
    while ((entry = readdir(proc_directory)) != NULL) {
        if (entry->d_type == DT_DIR) {
            int pid = atoi(entry->d_name);
            if (pid > 0) {
                display_process_info(pid);
            }
        }
    }

    closedir(proc_directory);
    printf("\nThe case of the elusive processes has been solved!\n");
}

void reveal_help() {
    printf("Welcome to the Sherlock Holmes Process Viewer!\n");
    printf("Use this program to reveal the hidden processes in your system's:\n");
    printf("1. Command Identifier (PID)\n");
    printf("2. Command Line Arguments\n\n");
    printf("Simply run the program without any arguments, and it will list all processes.\n");
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        reveal_help();
        return EXIT_FAILURE;
    }

    inspect_proc_directory();
    return EXIT_SUCCESS;
}
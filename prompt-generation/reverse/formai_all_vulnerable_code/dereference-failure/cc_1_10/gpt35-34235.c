//FormAI DATASET v1.0 Category: System process viewer ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>

/* Function to check if a given pid exists */
int pid_exists(int pid) {
    char proc_path[50];
    sprintf(proc_path, "/proc/%d", pid);
    DIR* proc_dir = opendir(proc_path);
    if (proc_dir) {
        /* Process directory exists */
        closedir(proc_dir);
        return 1;
    }
    else {
        /* Process directory does not exist */
        return 0;
    }
}

/* Main function */
int main() {
    printf("System Process Viewer - Shocking Edition!\n\n");
    
    /* Get list of all directories in /proc directory */
    DIR* proc_dir = opendir("/proc");
    if (proc_dir) {
        struct dirent* proc_entry;
        while ((proc_entry = readdir(proc_dir)) != NULL) {
            /* Check if this is a directory containing only digits */
            int pid = atoi(proc_entry->d_name);
            if (pid > 0 && pid_exists(pid)) {
                /* This is a valid process, print its details */
                char proc_name[50];
                sprintf(proc_name, "/proc/%d/cmdline", pid);
                FILE* cmdline_file = fopen(proc_name, "r");
                if (cmdline_file) {
                    /* Successfully opened cmdline file */
                    char cmdline[100];
                    fgets(cmdline, 100, cmdline_file);
                    fclose(cmdline_file);
                    /* Replace any null characters with spaces in command line */
                    for (int i = 0; i < strlen(cmdline); i++) {
                        if (cmdline[i] == '\0') {
                            cmdline[i] = ' ';
                        }
                    }
                    printf("PID: %d, Command: %s\n", pid, cmdline);
                }
            }
        }
        closedir(proc_dir);
        printf("\nShocking, right? Who knew there were so many processes running on your system!\n");
    }
    else {
        printf("Error: Could not open /proc directory.\n");
    }
    
    return 0;
}
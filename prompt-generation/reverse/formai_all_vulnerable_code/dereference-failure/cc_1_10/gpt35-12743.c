//FormAI DATASET v1.0 Category: System process viewer ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

#define MAX_PATH_LENGTH 1000

int main() {
    char path[MAX_PATH_LENGTH];
    struct dirent *entry;
    DIR *dir;
    FILE *fp;
    char cmd[1000];

    // Get current directory
    if(getcwd(path, sizeof(path)) == NULL) {
        printf("Unable to get current directory\n");
        return 1;
    }

    // Open directory
    dir = opendir(path);
    if(dir == NULL) {
        printf("Unable to open directory\n");
        return 1;
    }

    printf("===== PROCESS VIEWER =====\n");

    // Loop through each file in directory
    while((entry = readdir(dir)) != NULL) {
        // Check if filename contains only digits (process id)
        if(strspn(entry->d_name, "0123456789") == strlen(entry->d_name)) {
            // Open process status file
            sprintf(cmd, "cat /proc/%s/status", entry->d_name);
            fp = popen(cmd, "r");

            if(fp == NULL) {
                printf("Unable to open process status file for %s\n", entry->d_name);
            } else {
                char line[1000];
                char *name = NULL;
                int pid = atoi(entry->d_name);
                int ppid = 0;
                int vm_size = 0;

                // Parse process status file
                while(fgets(line, sizeof(line), fp)) {
                    if(strncmp(line, "Name:", 5) == 0) {
                        name = strdup(line + 6);
                        name[strlen(name) - 1] = '\0';
                    } else if(strncmp(line, "PPid:", 5) == 0) {
                        ppid = atoi(line + 6);
                    } else if(strncmp(line, "VmSize:", 7) == 0) {
                        vm_size = atoi(line + 8);
                    }
                }

                // Print process info
                printf("[%d] %s (Parent: %d, Memory: %dk)\n", pid, name, ppid, vm_size);
                free(name);
                pclose(fp);
            }
        }
    }

    // Close directory
    closedir(dir);

    return 0;
}
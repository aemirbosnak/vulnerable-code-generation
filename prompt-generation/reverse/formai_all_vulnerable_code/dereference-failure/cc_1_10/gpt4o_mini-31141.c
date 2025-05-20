//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>

#define BUFFER_SIZE 256

void investigate_process(int pid) {
    char filepath[BUFFER_SIZE];
    snprintf(filepath, sizeof(filepath), "/proc/%d/status", pid);
    
    FILE *file = fopen(filepath, "r");
    if (!file) {
        printf("Alas! The process with PID %d has vanished into the ether.\n", pid);
        return;
    }
    
    printf("Investigating process with PID: %d\n", pid);
    char line[BUFFER_SIZE];
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, "Name:") || strstr(line, "State:") || strstr(line, "Pid:") || strstr(line, "PPid:")) {
            printf("\t%s", line);
        }
    }
    fclose(file);
    printf("The investigation of PID %d has come to a close.\n\n", pid);
}

void observe_directory(const char *path) {
    DIR *directory = opendir(path);
    if (!directory) {
        fprintf(stderr, "It seems the location is uncharted territory: %s\n", path);
        return;
    }

    struct dirent *entry;
    printf("Venturing into: %s\n", path);
    while ((entry = readdir(directory)) != NULL) {
        if (entry->d_type == DT_DIR) {
            int pid = atoi(entry->d_name);
            if (pid > 0) {
                investigate_process(pid);
            }
        }
    }
    closedir(directory);
}

int main() {
    printf("Sherlock Holmes \nProcess Viewer of London\n\n");
    printf("I shall examine the processes of our fair system...\n");
    
    observe_directory("/proc");
    
    printf("The case of the missing processes has been thoroughly explored.\n");
    printf("Your faithful detective work is concluded here.\n");

    return 0;
}
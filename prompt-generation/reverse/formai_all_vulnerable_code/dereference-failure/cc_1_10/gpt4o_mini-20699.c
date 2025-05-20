//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define MAX_PROCESS_NAME 256
#define MAX_BUFFER 1024

typedef struct {
    int pid;
    char name[MAX_PROCESS_NAME];
} Process;

void display_process(Process *p) {
    printf("PID: %d, Name: %s\n", p->pid, p->name);
}

void list_processes() {
    DIR *dir;
    struct dirent *entry;

    Process processes[MAX_BUFFER];
    int count = 0;

    // Open the /proc directory
    dir = opendir("/proc");
    if (dir == NULL) {
        perror("Error opening /proc directory");
        return;
    }

    // Loop through entries in the /proc directory
    while ((entry = readdir(dir)) != NULL) {
        // Check if the entry is a number (process id)
        if (isdigit(entry->d_name[0])) {
            Process p;
            p.pid = atoi(entry->d_name);

            // Read the process name from the status file
            char stat_file[MAX_BUFFER];
            snprintf(stat_file, sizeof(stat_file), "/proc/%d/stat", p.pid);
            FILE *fp = fopen(stat_file, "r");
            if (fp) {
                fscanf(fp, "%*d %s", p.name); // Ignore other fields, get the name
                fclose(fp);
                // Remove surrounding parentheses
                if (p.name[0] == '(') {
                    memmove(p.name, p.name + 1, strlen(p.name)); // Remove first char
                }
                p.name[strlen(p.name) - 1] = '\0'; // Remove last char

                processes[count++] = p; // Store process
            }
        }
    }

    closedir(dir);

    // Sort processes based on PID for a clean output
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (processes[i].pid > processes[j].pid) {
                Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }

    // Display processed results
    printf("Futuristic Process Viewer\n");
    printf("=========================\n");
    for (int i = 0; i < count; i++) {
        display_process(&processes[i]);
    }
}

int main() {
    printf("Initializing Futuristic Process Viewer...\n");
    list_processes();
    printf("Process viewing complete. Have a productive day!\n");
    return 0;
}
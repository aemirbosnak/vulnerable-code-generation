//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <ctype.h>

#define MAX_PROCESSES 1024
#define BUFFER_SIZE 256

typedef struct {
    int pid;
    char command[BUFFER_SIZE];
    int uid;
    unsigned long memory;
} Process;

void clearScreen() {
    printf("\033[H\033[J");
}

int isDigitString(const char *str) {
    while (*str) {
        if (!isdigit(*str)) {
            return 0;
        }
        str++;
    }
    return 1;
}

unsigned long getMemoryUsage(int pid) {
    char path[BUFFER_SIZE];
    snprintf(path, sizeof(path), "/proc/%d/status", pid);
    FILE *file = fopen(path, "r");
    if (file == NULL) {
        return 0;
    }
    
    char line[BUFFER_SIZE];
    unsigned long memory = 0;

    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "VmSize:", 7) == 0) {
            sscanf(line + 7, "%lu", &memory);
            break;
        }
    }
    fclose(file);
    return memory;
}

void getProcesses(Process processes[], int *count) {
    DIR *dir = opendir("/proc");
    struct dirent *entry;
    *count = 0;

    if (dir == NULL) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (isDigitString(entry->d_name)) {
            int pid = atoi(entry->d_name);
            char path[BUFFER_SIZE];
            snprintf(path, sizeof(path), "/proc/%d/comm", pid);
            FILE *file = fopen(path, "r");
            if (file != NULL) {
                fread(processes[*count].command, 1, BUFFER_SIZE - 1, file);
                processes[*count].command[strcspn(processes[*count].command, "\n")] = 0; // Remove newline
                fclose(file);
                
                processes[*count].pid = pid;
                processes[*count].uid = getuid(); // Getting the UID of the current user
                processes[*count].memory = getMemoryUsage(pid);
                (*count)++;
            }
        }
    }
    closedir(dir);
}

void displayProcesses(Process processes[], int count) {
    printf("%-6s %-25s %-6s %-10s\n", "PID", "Command", "UID", "Memory");
    printf("---------------------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-6d %-25s %-6d %-10lu KB\n", processes[i].pid, processes[i].command, processes[i].uid, processes[i].memory / 1024); // Convert to KB
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int count = 0;
    char choice;

    while (1) {
        clearScreen();
        getProcesses(processes, &count);
        displayProcesses(processes, count);

        printf("\nPress 'q' to quit or any other key to refresh...\n");
        choice = getchar();
        getchar(); // Consume newline character
        if (choice == 'q' || choice == 'Q') {
            break;
        }
        sleep(2); // Delay for 2 seconds before refreshing
    }

    return 0;
}
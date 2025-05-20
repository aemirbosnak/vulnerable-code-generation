//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>
#include <unistd.h>
#include <limits.h>

#define MAX_PROCS 1024
#define PROC_DIR "/proc/"
#define CMDLINE_PATH "cmdline"
#define STATUS_PATH "status"

typedef struct {
    char pid[10];
    char name[256];
    char state[20];
} ProcessInfo;

void get_process_info(ProcessInfo *process, const char *pid) {
    char path[PATH_MAX];
    snprintf(path, sizeof(path), "%s%s/%s", PROC_DIR, pid, CMDLINE_PATH);

    FILE *cmdline = fopen(path, "r");
    if (cmdline) {
        fread(process->name, sizeof(process->name), 1, cmdline);
        fclose(cmdline);
        
        // Replace null characters with spaces
        for (char *p = process->name; *p; ++p) {
            if (*p == '\0') {
                *p = ' ';
            }
        }
    } else {
        strcpy(process->name, "Unknown");
    }

    snprintf(path, sizeof(path), "%s%s/%s", PROC_DIR, pid, STATUS_PATH);
    FILE *status = fopen(path, "r");
  
    if (status) {
        char line[256];
        while (fgets(line, sizeof(line), status)) {
            if (strncmp(line, "State:", 6) == 0) {
                sscanf(line + 6, "%s", process->state);
                break;
            }
        }
        fclose(status);
    } else {
        strcpy(process->state, "Unknown");
    }
}

void list_processes() {
    DIR *dir = opendir(PROC_DIR);
    struct dirent *entry;

    ProcessInfo processes[MAX_PROCS];
    int count = 0;

    if (dir == NULL) {
        perror("Could not open /proc directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (isdigit(entry->d_name[0])) {
            strcpy(processes[count].pid, entry->d_name);
            get_process_info(&processes[count], entry->d_name);
            count++;
            if (count >= MAX_PROCS) break;
        }
    }
    closedir(dir);

    // Display the process information in a mind-bending format
    printf("%-10s%-40s%-10s\n", "PID", "COMMAND", "STATE");
    printf("--------------------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-10s%-40s%-10s\n", processes[i].pid, processes[i].name, processes[i].state);
    }
    
    printf("\nImagine! Each PID is a universe, each process a tale yet unread.\n");
    printf("Who engages in the cosmic dance of bytes? What dreams do they weave in the shadows of the CPU?\n");
    printf("In this vast realm of eternity, processes come and go, ephemeral as the morning mist.\n");
    printf("Can you feel the pulse of the machine, thrumming with dreams of computation? Ah!\n");
    printf("As CPU cycles twirl like celestial bodies, we are but stargazers in this machine's odyssey.\n");
}

int main(int argc, char *argv[]) {
    if (argc > 1 && strcmp(argv[1], "-h") == 0) {
        printf("Usage: %s [-h]\n", argv[0]);
        printf("This program displays the list of current processes in a mesmerizing format.\n");
        return 0;
    }

    printf("Welcome to the Process Viewer! Here, the mundane becomes the extraordinary.\n");
    printf("Hold tight as we traverse through the realm of processes...\n\n");

    list_processes();

    printf("\nThank you for taking this journey! Until next time in the land of processes...\n");
    return 0;
}
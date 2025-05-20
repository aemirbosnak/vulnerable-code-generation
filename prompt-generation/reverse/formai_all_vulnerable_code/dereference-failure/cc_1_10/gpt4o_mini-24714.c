//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#define PROC_PATH "/proc"
#define MAX_PROCESS_NAME 256
#define MAX_BUFFER 1024

typedef struct {
    int pid;
    char name[MAX_PROCESS_NAME];
} Process;

void print_process(Process p) {
    printf("PID: %d | Name: %s\n", p.pid, p.name);
}

int is_number(const char *str) {
    while(*str) {
        if(!isdigit(*str)) return 0;
        str++;
    }
    return 1;
}

void list_processes() {
    DIR *dir = opendir(PROC_PATH);
    struct dirent *entry;

    if (!dir) {
        perror("Could not open /proc directory");
        return;
    }

    Process processes[MAX_BUFFER];
    int count = 0;

    // Scan through all entries in the /proc directory
    while ((entry = readdir(dir)) != NULL) {
        if (is_number(entry->d_name)) {
            int pid = atoi(entry->d_name);
            char path[MAX_BUFFER];
            snprintf(path, sizeof(path), "%s/%s/comm", PROC_PATH, entry->d_name);

            FILE *fp = fopen(path, "r");
            if (fp) {
                Process proc;
                proc.pid = pid;
                fgets(proc.name, sizeof(proc.name), fp);
                // Remove new line character if any
                proc.name[strcspn(proc.name, "\n")] = 0;
                
                processes[count++] = proc;
                fclose(fp);
            }
        }
    }

    closedir(dir);

    // Sort processes in ascending order by PID
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (processes[j].pid > processes[j + 1].pid) {
                Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }

    printf("Currently running processes:\n");
    printf("==========================\n");
    
    for (int i = 0; i < count; i++) {
        print_process(processes[i]);
    }
}

void show_menu() {
    printf("\n=== Process Viewer ===\n");
    printf("1. List all running processes\n");
    printf("2. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice = 0;

    while (1) {
        show_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                list_processes();
                break;
            case 2:
                printf("Exiting Process Viewer. Bye!\n");
                return 0;
            default:
                printf("Invalid choice. Please select again.\n");
        }
    }

    return 0;
}
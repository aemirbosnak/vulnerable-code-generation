//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#define PROC_PATH "/proc"
#define MAX_LINE_LENGTH 256

void display_process_info(const char* pid) {
    char path[MAX_LINE_LENGTH];
    snprintf(path, sizeof(path), "%s/%s/stat", PROC_PATH, pid);
    
    FILE* fp = fopen(path, "r");
    if (!fp) {
        perror("fopen");
        return;
    }
    
    char buf[MAX_LINE_LENGTH];
    if (fgets(buf, sizeof(buf), fp) != NULL) {
        char state;
        char comm[MAX_LINE_LENGTH];
        
        // Skip the first 2 fields (PID and Comm, which we need)
        int pid_num;
        sscanf(buf, "%d %s %c", &pid_num, comm, &state);
        
        printf("PID: %d, COMMAND: %s, STATE: %c\n", pid_num, comm, state);
    }

    fclose(fp);
}

void list_processes() {
    DIR* dir = opendir(PROC_PATH);
    if (!dir) {
        perror("opendir");
        return;
    }
    
    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        if (isdigit(entry->d_name[0])) {  // Check if the entry is a PID
            display_process_info(entry->d_name);
        }
    }
    
    closedir(dir);
}

void display_menu() {
    printf("\n=== Simple Process Viewer ===\n");
    printf("1. List all processes\n");
    printf("2. Exit\n");
    printf("=============================\n");
}

int main() {
    int choice;

    do {
        display_menu();
        printf("Select an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("\nListing all running processes:\n");
                list_processes();
                break;
            case 2:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 2);
    
    return 0;
}
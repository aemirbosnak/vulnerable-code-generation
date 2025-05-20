//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <ctype.h>

#define PROC_DIR "/proc"
#define MAX_PID_LEN 10
#define BUFFER_SIZE 256

void peek_inside_proc(const char *pid);
void display_process_info(const char *pid);
void list_all_processes();

int main() {
    char choice[MAX_PID_LEN + 1];

    while (1) {
        printf("\n--- Welcome to the Process Viewer ---\n");
        list_all_processes();
        printf("To examine a process, enter its PID (or 'exit' to quit): ");
        fgets(choice, sizeof(choice), stdin);
        choice[strcspn(choice, "\n")] = 0; // Remove newline character

        if (strcmp(choice, "exit") == 0) {
            printf("Exiting... Farewell!\n");
            break;
        }

        // Check if input is a valid PID
        if (strlen(choice) > 0 && strspn(choice, "0123456789") == strlen(choice)) {
            peek_inside_proc(choice);
        } else {
            printf("Invalid input. Please enter a numeric PID.\n");
        }
    }
    return 0;
}

void list_all_processes() {
    struct dirent *entry;
    DIR *dp = opendir(PROC_DIR);

    if (dp == NULL) {
        perror("opendir");
        return;
    }

    printf("\nAvailable PIDs:\n");
    while ((entry = readdir(dp))) {
        if (isdigit(entry->d_name[0])) { // Only list PIDs
            printf("PID: %s\n", entry->d_name);
        }
    }
    closedir(dp);
}

void peek_inside_proc(const char *pid) {
    char path[BUFFER_SIZE];
    snprintf(path, sizeof(path), "%s/%s/status", PROC_DIR, pid);
    
    FILE *file = fopen(path, "r");
    if (file == NULL) {
        printf("Could not open process information for PID: %s\n", pid);
        return;
    }
    
    printf("\n--- Process Information for PID: %s ---\n", pid);
    char line[BUFFER_SIZE];
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, "Name:") || strstr(line, "State:") || strstr(line, "Pid:") || 
            strstr(line, "Uid:") || strstr(line, "Gid:")) {
            printf("%s", line);
        }
    }
    fclose(file);
    printf("--- End of Information ---\n");
}
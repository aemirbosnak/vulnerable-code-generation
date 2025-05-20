//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

#define PROC_DIR "/proc"
#define BUF_SIZE 256

void print_process_info(pid_t pid);
void list_processes();
void print_line(const char *label, const char *value);
void print_uid_username(uid_t uid);

int main() {
    printf("Welcome to the Ephemeral C Process Viewer!\n");
    printf("===========================================\n");
    
    while (1) {
        list_processes();
        printf("\nPress Enter to refresh the process list or type 'exit' to quit.\n");
        
        // Temporarily hold input for exit or continue
        char input[10];
        if (fgets(input, sizeof(input), stdin) != NULL) {
            if (strcasecmp(input, "exit\n") == 0) {
                break;
            }
        }
    }
    
    printf("Exiting the Ephemeral C Process Viewer. Goodbye!\n");
    return 0;
}

void list_processes() {
    DIR *dir;
    struct dirent *entry;
    
    if ((dir = opendir(PROC_DIR)) == NULL) {
        perror("Failed to open /proc directory");
        return;
    }

    printf("\nCurrent Running Processes:\n");
    printf("PID\tCommand\t\t\tUser\n");
    printf("===========================================\n");

    while ((entry = readdir(dir)) != NULL) {
        if (isdigit(*entry->d_name)) { // Filter only numeric ids
            pid_t pid = atoi(entry->d_name);
            print_process_info(pid);
        }
    }

    closedir(dir);
}

void print_process_info(pid_t pid) {
    char path[BUF_SIZE];
    snprintf(path, sizeof(path), "%s/%d/stat", PROC_DIR, pid);
    
    FILE *fp = fopen(path, "r");
    if (fp == NULL) {
        return; // Could not open; it may no longer exist
    }

    char buf[BUF_SIZE];
    fscanf(fp, "%*[d] %s", buf); // Skip pid and get the command name
    char cmd[BUF_SIZE];
    strncpy(cmd, buf, sizeof(cmd));
    cmd[sizeof(cmd) - 1] = '\0'; // Safety null-terminated

    // Get the username
    uid_t uid;
    fscanf(fp, "%*s %*s %*c %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %d", &uid);
    print_uid_username(uid);

    fclose(fp);

    printf("%d\t%s\t\t\t%s\n", pid, cmd, getpwuid(uid)->pw_name);
}

void print_uid_username(uid_t uid) {
    struct passwd *pw = getpwuid(uid);
    if (pw == NULL) {
        printf("UID: %d", uid);
    } else {
        printf("User: %s", pw->pw_name);
    }
}
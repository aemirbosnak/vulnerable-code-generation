//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <pwd.h>

#define MAX_PATH 256
#define MAX_LINE 1024

void print_process_info(const char *pid, const char *username) {
    char stat_file[MAX_PATH];
    char status_file[MAX_PATH];
    char line[MAX_LINE];
    FILE *file;
    char user[32];
    unsigned long utime, stime;
    char state;
    char cmdline[MAX_LINE];

    // Constructing file paths
    snprintf(stat_file, sizeof(stat_file), "/proc/%s/stat", pid);
    snprintf(status_file, sizeof(status_file), "/proc/%s/status", pid);
    snprintf(cmdline, sizeof(cmdline), "/proc/%s/cmdline", pid);

    // Reading the stat file
    file = fopen(stat_file, "r");
    if (file == NULL) return;

    fscanf(file, "%*d %*s %c %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %lu %lu", &state, &utime, &stime);
    fclose(file);

    // Get user information from the status file
    file = fopen(status_file, "r");
    if (file == NULL) return;

    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "Uid:", 4) == 0) {
            sscanf(line, "Uid:\t%d", &user);
            struct passwd *pwd = getpwuid(user);
            if (pwd != NULL) {
                strncpy(user, pwd->pw_name, sizeof(user));
            }
            break;
        }
    }
    fclose(file);

    // Checking if we want to filter by user
    if (username != NULL && strcmp(username, user) != 0) return;

    // Reading the command line
    file = fopen(cmdline, "r");
    if (file == NULL) return;

    fgets(cmdline, sizeof(cmdline), file);
    fclose(file);

    // Print process details
    printf("PID: %s, User: %s, State: %c, UTime: %lu, STime: %lu, Command: %s\n",
            pid, user, state, utime, stime, cmdline);
}

void list_processes(const char *username) {
    DIR *dir;
    struct dirent *entry;

    dir = opendir("/proc");
    if (dir == NULL) {
        perror("Could not open /proc directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            // Check if the directory name is a number (PID)
            if (isdigit(entry->d_name[0])) {
                print_process_info(entry->d_name, username);
            }
        }
    }
    closedir(dir);
}

int main(int argc, char *argv[]) {
    const char *username = NULL;

    // Check if user parameter provided
    if (argc > 1) {
        username = argv[1];
    }

    printf("Process Viewer\n");
    printf("==============================\n");

    list_processes(username);

    return 0;
}
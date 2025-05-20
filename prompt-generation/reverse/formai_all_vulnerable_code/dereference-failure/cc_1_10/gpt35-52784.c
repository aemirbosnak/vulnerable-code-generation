//FormAI DATASET v1.0 Category: System process viewer ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/stat.h>

#define PROCESS_DIR "/proc"

int is_process(char *pid) {
    // Check if pid is a number
    for (int i = 0; pid[i] != '\0'; i++) {
        if (!isdigit(pid[i])) {
            return 0;
        }
    }

    // Check if /proc/<pid>/ exists
    char process_path[256];
    snprintf(process_path, sizeof(process_path), "%s/%s", PROCESS_DIR, pid);
    struct stat st;
    if (stat(process_path, &st) == -1 || !S_ISDIR(st.st_mode)) {
        return 0;
    }

    return 1;
}

void print_process_info(char *pid) {
    char process_path[256];
    snprintf(process_path, sizeof(process_path), "%s/%s", PROCESS_DIR, pid);

    // Read process info from /proc/<pid>/status
    char status_path[256];
    snprintf(status_path, sizeof(status_path), "%s/status", process_path);
    FILE *status_file = fopen(status_path, "r");
    if (status_file == NULL) {
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), status_file) != NULL) {
        if (strstr(line, "Name:") != NULL) {
            printf("%s", line);
        } else if (strstr(line, "State:") != NULL) {
            printf("%s", line);
        } else if (strstr(line, "VmRSS:") != NULL) {
            printf("%s", line);
        }
    }

    fclose(status_file);
}

int main(void) {
    DIR *dp;
    struct dirent *dir;

    dp = opendir(PROCESS_DIR);
    if (dp == NULL) {
        perror("opendir failed");
        exit(EXIT_FAILURE);
    }

    // Read all directories in /proc
    while ((dir = readdir(dp)) != NULL) {
        if (is_process(dir->d_name)) {
            print_process_info(dir->d_name);
        }
    }

    closedir(dp);
    return 0;
}
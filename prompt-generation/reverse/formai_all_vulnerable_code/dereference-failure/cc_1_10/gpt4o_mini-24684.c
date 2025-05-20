//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

void trim_whitespace(char *str) {
    char *end;

    // Trim leading space
    while (isspace((unsigned char)*str)) str++;

    // Trim trailing space
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;

    end[1] = '\0';
}

void list_processes() {
    DIR *proc_dir;
    struct dirent *entry;
    char path[256], buffer[256];
    FILE *status_file;
    int pid;

    proc_dir = opendir("/proc");
    if (!proc_dir) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    printf("%-10s %-25s\n", "PID", "COMMAND");
    printf("%-10s %-25s\n", "---", "-------");

    while ((entry = readdir(proc_dir)) != NULL) {
        if (isdigit(*entry->d_name)) {
            pid = atoi(entry->d_name);
            snprintf(path, sizeof(path), "/proc/%s/comm", entry->d_name);

            status_file = fopen(path, "r");
            if (status_file) {
                fgets(buffer, sizeof(buffer), status_file);
                trim_whitespace(buffer);
                printf("%-10d %-25s\n", pid, buffer);
                fclose(status_file);
            }
        }
    }

    closedir(proc_dir);
}

int main() {
    printf("Process Viewer\n");
    printf("---------------\n");
    list_processes();
    return 0;
}
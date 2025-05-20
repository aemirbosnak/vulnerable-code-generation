//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

#define MAX_LEN 256
#define STATUS_PATH "/proc/%s/status"

typedef struct {
    int pid;
    char name[MAX_LEN];
} Process;

void list_processes(const char *filter) {
    DIR *dir = opendir("/proc");
    struct dirent *entry;

    if (!dir) {
        perror("opendir");
        return;
    }

    printf("%-8s %-25s\n", "PID", "Process Name");

    while ((entry = readdir(dir)) != NULL) {
        if (isdigit(*entry->d_name)) {
            int pid = atoi(entry->d_name);
            char status_file[MAX_LEN];
            snprintf(status_file, sizeof(status_file), STATUS_PATH, entry->d_name);

            FILE *file = fopen(status_file, "r");
            if (file) {
                char line[MAX_LEN];
                Process proc;
                proc.pid = pid;

                // Read process name
                while (fgets(line, sizeof(line), file)) {
                    if (sscanf(line, "Name:\t%s", proc.name) == 1) {
                        break;
                    }
                }
                fclose(file);

                // Check if the process name matches the filter
                if (filter == NULL || (strstr(proc.name, filter) != NULL)) {
                    printf("%-8d %-25s\n", proc.pid, proc.name);
                }
            }
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    const char *filter = NULL;

    if (argc > 1) {
        filter = argv[1];
    }

    printf("Simple Linux Process Viewer\n");
    printf("---------------------------\n");
    list_processes(filter);
    return 0;
}
//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <pwd.h>
#include <grp.h>

void print_process_info(pid_t pid) {
    char path[128];
    snprintf(path, sizeof(path), "/proc/%d/status", pid);
    FILE *fp = fopen(path, "r");
    if (!fp) {
        perror("fopen");
        return;
    }

    char line[1024];
    while (fgets(line, sizeof(line), fp)) {
        char *key = strtok(line, ":");
        if (key) {
            char *value = strtok(NULL, "\n");
            if (value) {
                printf("%s: %s\n", key, value);
            }
        }
    }

    fclose(fp);
}

int main() {
    DIR *dp = opendir("/proc");
    if (!dp) {
        perror("opendir");
        return EXIT_FAILURE;
    }

    struct dirent *entry;
    while ((entry = readdir(dp))) {
        pid_t pid = (pid_t) atoi(entry->d_name);
        if (pid > 0) {
            printf("Process %d:\n", pid);
            print_process_info(pid);
            printf("\n");
        }
    }

    closedir(dp);

    return EXIT_SUCCESS;
}
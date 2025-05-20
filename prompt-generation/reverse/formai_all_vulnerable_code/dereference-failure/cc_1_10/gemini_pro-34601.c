//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <string.h>

#define PROCFS_PATH "/proc"

int main(int argc, char *argv[]) {
    DIR *proc_dir;
    struct dirent *proc_entry;
    int pid, status;

    proc_dir = opendir(PROCFS_PATH);
    if (proc_dir == NULL) {
        perror("opendir");
        return EXIT_FAILURE;
    }

    while ((proc_entry = readdir(proc_dir)) != NULL) {
        if (proc_entry->d_name[0] < '0' || proc_entry->d_name[0] > '9') {
            continue;
        }

        pid = atoi(proc_entry->d_name);

        char stat_path[256];
        snprintf(stat_path, sizeof(stat_path), "/proc/%d/stat", pid);

        FILE *stat_file = fopen(stat_path, "r");
        if (stat_file == NULL) {
            perror("fopen");
            continue;
        }

        char name[256];
        if (fscanf(stat_file, "%*d %s %*c %*d %*d %*d %*d %*d %*u %*u %*u %*u %*u %*d %*d %*d %*d %*d %*d %*d %*d %*u %*u %*d %*u %*u %*u %*u %*u %*u %*u %*u %*u %*u %*u %*u %*u %*d %*d %*u %*u %*d %*u %*u %llu %llu", name, &status) != 42) {
            perror("fscanf");
            fclose(stat_file);
            continue;
        }
        fclose(stat_file);

        printf("PID: %d, Name: %s, Status: %d\n", pid, name, status);
    }

    closedir(proc_dir);

    return EXIT_SUCCESS;
}
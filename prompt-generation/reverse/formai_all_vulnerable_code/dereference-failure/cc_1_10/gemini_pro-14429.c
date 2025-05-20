//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <string.h>

#define MAX_PATH_LENGTH 1024

void print_process_info(pid_t pid) {
    char path[MAX_PATH_LENGTH];
    snprintf(path, MAX_PATH_LENGTH, "/proc/%d/status", pid);
    int fd = open(path, O_RDONLY);
    if (fd == -1) {
        perror("open");
        return;
    }

    char buffer[4096];
    ssize_t bytes_read = read(fd, buffer, sizeof(buffer));
    if (bytes_read == -1) {
        perror("read");
        close(fd);
        return;
    }
    close(fd);

    char *line = strtok(buffer, "\n");
    while (line != NULL) {
        printf("%s\n", line);
        line = strtok(NULL, "\n");
    }
}

int main(int argc, char **argv) {
    DIR *proc_dir = opendir("/proc");
    if (proc_dir == NULL) {
        perror("opendir");
        return EXIT_FAILURE;
    }

    struct dirent *entry;
    while ((entry = readdir(proc_dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        pid_t pid = (pid_t)atoi(entry->d_name);
        if (pid <= 0) {
            continue;
        }

        printf("Process %d:\n", pid);
        print_process_info(pid);
        printf("\n");
    }

    closedir(proc_dir);

    return EXIT_SUCCESS;
}
//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <string.h>

void print_process_info(pid_t pid) {
    char path[256];
    snprintf(path, sizeof(path), "/proc/%d", pid);

    DIR *dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char file_path[256];
        snprintf(file_path, sizeof(file_path), "%s/%s", path, entry->d_name);

        struct stat statbuf;
        if (stat(file_path, &statbuf) != 0) {
            perror("stat");
            continue;
        }

        if (S_ISREG(statbuf.st_mode)) {
            FILE *file = fopen(file_path, "r");
            if (file == NULL) {
                perror("fopen");
                continue;
            }

            char line[256];
            while (fgets(line, sizeof(line), file) != NULL) {
                printf("%s", line);
            }

            fclose(file);
        } else if (S_ISDIR(statbuf.st_mode)) {
            pid_t child_pid = atoi(entry->d_name);
            print_process_info(child_pid);
        }
    }

    closedir(dir);
}

int main() {
    print_process_info(getpid());
    return 0;
}
//FormAI DATASET v1.0 Category: System process viewer ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

void print_process_info(char* pid) {
    char path[50];
    sprintf(path, "/proc/%s/status", pid);

    FILE* f = fopen(path, "r");
    if (!f) {
        printf("unable to open the file %s", path);
        return;
    }

    char line[100];
    char name[30];
    while (fgets(line, 100, f)) {
        if (sscanf(line, "Name: %s", name) == 1) {
            break;
        }
    }

    fclose(f);
    printf("%-10s %-20s\n", pid, name);
    return;
}

void traverse_directory(char* path) {
    DIR* d = opendir(path);
    if (!d) {
        printf("unable to open the directory %s", path);
        return;
    }

    struct dirent* entry;
    while ((entry = readdir(d))) {
        if (entry->d_type == DT_DIR) {
            if (entry->d_name[0] != '.') {
                traverse_directory(entry->d_name);
            }
        } else {
            if (strcmp(entry->d_name, "status") == 0) {
                print_process_info(strtok(path, "/"));
            }
        }
    }

    closedir(d);
}

int main() {
    printf("%-10s %-20s\n", "PID", "NAME");

    traverse_directory("/proc");

    return 0;
}
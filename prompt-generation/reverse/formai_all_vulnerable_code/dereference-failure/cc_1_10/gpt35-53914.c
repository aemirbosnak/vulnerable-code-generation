//FormAI DATASET v1.0 Category: System process viewer ; Style: recursive
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define PROC_DIR "/proc"

bool is_numeric(const char *str) {
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] < '0' || str[i] > '9') {
            return false;
        }
    }
    return true;
}

void print_process_info(const char *pid) {
    char path[50], line[100];
    FILE *fp;
    snprintf(path, sizeof(path), "%s/%s/stat", PROC_DIR, pid);
    fp = fopen(path, "r");
    fgets(line, sizeof(line), fp);
    char *name = strtok(line, " ");
    printf("%-10s %s\n", "Name:", name + 1);
    char *state = strtok(NULL, " ");
    printf("%-10s %s\n", "State:", state);
    fclose(fp);
}

void traverse_processes(const char *dir_path) {
    DIR *dir;
    struct dirent *entry;
    if ((dir = opendir(dir_path)) == NULL) {
        perror(dir_path);
        return;
    }
    while ((entry = readdir(dir)) != NULL) {
        if (is_numeric(entry->d_name)) {
            printf("\nProcess ID: %s\n", entry->d_name);
            print_process_info(entry->d_name);
        }
        char path[50];
        snprintf(path, sizeof(path), "%s/%s", dir_path, entry->d_name);
        if (entry->d_type == DT_DIR && strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            traverse_processes(path);
        }
    }
    closedir(dir);
}

int main() {
    printf("Process viewer\n");
    printf("=================\n");
    traverse_processes(PROC_DIR);
    return 0;
}
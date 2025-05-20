//FormAI DATASET v1.0 Category: System process viewer ; Style: beginner-friendly
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>

#define BUF_SIZE 1024
#define PROC_PATH "/proc"

int is_digit(const char *str) {
    while (*str != '\0') {
        if (!isdigit(*str)) return 0;
        str++;
    }
    return 1;
}

void print_proc_details(const char *pid) {
    char proc_path[BUF_SIZE] = {0};
    snprintf(proc_path, BUF_SIZE, "%s/%s/stat", PROC_PATH, pid);
    FILE *fp = fopen(proc_path, "r");
    if (fp == NULL) {
        fprintf(stderr, "Unable to open file %s\n", proc_path);
        return;
    }
    char buf[BUF_SIZE] = {0};
    if (fgets(buf, BUF_SIZE, fp) != NULL) {
        // Read and extract details from the process stat file
        char *token = strtok(buf, " ");
        int count = 1;
        while (token != NULL) {
            if (count == 2) {
                printf("PID: %s\n", token);
            } else if (count == 3) {
                printf("Process Name: %s\n", token);
            } else if (count == 14) {
                printf("CPU Usage (in Tick): %s\n", token);
            }
            token = strtok(NULL, " ");
            count++;
        }
    }
    fclose(fp);
}

int main(void) {
    DIR *proc_dir = opendir(PROC_PATH);
    struct dirent *entry;
    printf("------------------------------\n");
    printf("      Process Viewer\n");
    printf("------------------------------\n");
    if (proc_dir == NULL) {
        fprintf(stderr, "Unable to open directory %s\n", PROC_PATH);
        return 1;
    }
    while ((entry = readdir(proc_dir)) != NULL) {
        // Look for only directories with numeric names (Process Diretory)
        if (is_digit(entry->d_name)) {
            print_proc_details(entry->d_name);
        }
    }
    closedir(proc_dir);
    return 0;
}
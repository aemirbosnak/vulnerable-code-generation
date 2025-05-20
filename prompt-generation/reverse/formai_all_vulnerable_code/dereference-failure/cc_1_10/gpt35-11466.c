//FormAI DATASET v1.0 Category: System process viewer ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <fcntl.h>
#include <unistd.h>
#include <limits.h>
#include <ctype.h>

#define MAX_PATH_LENGTH 1024
#define MAX_BUFF_LENGTH 512

void print_process_info(char *pid)
{
    char path[MAX_PATH_LENGTH];
    char buff[MAX_BUFF_LENGTH];
    char *tok;
    FILE *fp;

    snprintf(path, sizeof(path), "/proc/%s/status", pid);

    fp = fopen(path, "r");
    if (!fp) {
        printf("Cannot open file %s for reading\n", path);
        return;
    }

    while (fgets(buff, sizeof(buff), fp)) {
        if (strstr(buff, "Name:") || strstr(buff, "State:") ||
            strstr(buff, "PPid:") || strstr(buff, "Threads:")) {
            tok = strtok(buff, ":\n");
            printf("%-10s", tok);
            tok = strtok(NULL, ":\n");
            printf("%s\n", tok);
        }
    }

    fclose(fp);
}

void get_process_pids()
{
    DIR *dir;
    struct dirent *entry;
    char path[MAX_PATH_LENGTH];

    dir = opendir("/proc");
    if (!dir) {
        printf("Cannot open directory /proc\n");
        return;
    }

    printf("%-10s%-20s%-10s%s\n", "PID", "NAME", "PPID", "THREADS");
    while ((entry = readdir(dir)) != NULL) {
        if (!isdigit(entry->d_name[0]))
            continue;

        snprintf(path, sizeof(path), "/proc/%s", entry->d_name);
        if (access(path, R_OK)) /* Skip if we don't have read permissions */
            continue;

        print_process_info(entry->d_name);
    }

    closedir(dir);
}

int main(int argc, char *argv[])
{
    printf("System Process Viewer\n");
    printf("---------------------\n");

    get_process_pids();

    return EXIT_SUCCESS;
}
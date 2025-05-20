//FormAI DATASET v1.0 Category: System process viewer ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

#define MAX_NAME_LEN 256
#define MAX_PATH_LEN 1024
#define MAX_PID_LEN 10

/* This program lists all the running processes with their 
 * name, pid, and memory usage.
*/

struct proc_info {
    char name[MAX_NAME_LEN];
    int pid;
    unsigned long int mem;
};

/* Helper function to read the contents of a directory. */
int read_dir(const char *path, char ***entries) {
    DIR *dir = opendir(path);
    if (!dir) {
        return -1;
    }

    struct dirent *entry;
    int count = 0;
    while ((entry = readdir(dir)) != NULL) {
        if (isdigit(entry->d_name[0])) {
            count++;
        }
    }

    *entries = calloc(count, sizeof(char *));
    rewinddir(dir);

    int i = 0;
    while ((entry = readdir(dir)) != NULL) {
        if (isdigit(entry->d_name[0])) {
            (*entries)[i] = calloc(strlen(entry->d_name) + 1, sizeof(char));
            strcpy((*entries)[i], entry->d_name);
            i++;
        }
    }

    closedir(dir);
    return count;
}

/* Helper function to read the information about a process
 * given its pid.
 */
int read_proc_info(int pid, struct proc_info *info) {
    char path[MAX_PATH_LEN];
    snprintf(path, MAX_PATH_LEN, "/proc/%d/stat", pid);

    FILE *file = fopen(path, "r");
    if (!file) {
        return -1;
    }

    fscanf(file, "%d %s %*c %*d %*d %*d %*d %*d %*u %*lu %*lu %*lu %*lu %lu",
           &info->pid, info->name, &info->mem);

    fclose(file);
    return 0;
}

/* Entry point of the program. */
int main(int argc, char **argv) {
    char **entries;
    int proc_count = read_dir("/proc", &entries);

    printf("Name\tPID\tMemory\n");
    printf("===================================\n");

    for (int i = 0; i < proc_count; i++) {
        int pid = atoi(entries[i]);

        struct proc_info info;
        if (read_proc_info(pid, &info) == 0) {
            printf("%s\t%d\t%lu KB\n", info.name, pid, info.mem / 1024);
        }
    }

    /* Free up the memory allocated. */
    for (int i = 0; i < proc_count; i++) {
        free(entries[i]);
    }
    free(entries);

    return 0;
}
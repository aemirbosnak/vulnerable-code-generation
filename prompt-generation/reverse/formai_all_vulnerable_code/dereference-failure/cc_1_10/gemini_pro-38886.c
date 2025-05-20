//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>

typedef struct proc {
    pid_t pid;
    char *name;
} proc;

int comp(const void *a, const void *b) {
    return strcmp(((proc *)a)->name, ((proc *)b)->name);
}

int main() {
    DIR *dir;
    struct dirent *entry;
    proc *procs;
    int num_procs = 0;

    // Open the /proc directory
    dir = opendir("/proc");
    if (dir == NULL) {
        perror("opendir");
        return 1;
    }

    // Count the number of processes
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            num_procs++;
        }
    }

    // Allocate memory for the processes
    procs = malloc(sizeof(proc) * num_procs);
    if (procs == NULL) {
        perror("malloc");
        return 1;
    }

    // Read the /proc directory again and fill the array of processes
    rewinddir(dir);
    num_procs = 0;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            procs[num_procs].pid = atoi(entry->d_name);
            procs[num_procs].name = strdup(entry->d_name);
            num_procs++;
        }
    }

    // Sort the array of processes by name
    qsort(procs, num_procs, sizeof(proc), comp);

    // Print the array of processes
    for (int i = 0; i < num_procs; i++) {
        printf("%d %s\n", procs[i].pid, procs[i].name);
    }

    // Free the memory allocated for the array of processes
    for (int i = 0; i < num_procs; i++) {
        free(procs[i].name);
    }
    free(procs);

    // Close the /proc directory
    closedir(dir);

    return 0;
}
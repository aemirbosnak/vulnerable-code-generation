//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

// Structure to store process information
typedef struct proc_info {
    pid_t pid;             // Process ID
    char *name;            // Process name
    int ppid;             // Parent process ID
    unsigned long rss;      // Resident set size (in bytes)
    unsigned long vsize;    // Virtual memory size (in bytes)
} proc_info;

// Function to compare process info structures by PID
int compare_proc_info(const void *a, const void *b) {
    const proc_info *p1 = a;
    const proc_info *p2 = b;
    return p1->pid - p2->pid;
}

// Function to get process information
proc_info* get_proc_info(pid_t pid) {
    char proc_path[64];
    proc_info *info = malloc(sizeof(proc_info));

    // Get process stat file path
    snprintf(proc_path, sizeof(proc_path), "/proc/%d/stat", pid);

    // Open process stat file
    FILE *fp = fopen(proc_path, "r");
    if (!fp) {
        free(info);
        return NULL;
    }

    // Parse process stat file
    fscanf(fp, "%d %s %c %d %d %d %d %d %u %lu %lu %lu %lu %lu %lu %ld %ld %ld %ld %ld %ld %llu %lu %ld %lu %lu",
        &info->pid, info->name, &info->ppid, &info->rss, &info->vsize,
        &info->name[1], &info->name[2], &info->name[3], 
        &info->name[4], &info->name[5], &info->name[6], &info->name[7], &info->name[8], &info->name[9], &info->name[10], &info->name[11], &info->name[12], &info->name[13], &info->name[14], &info->name[15], &info->name[16], &info->name[17], &info->name[18], &info->name[19], &info->name[20], &info->name[21], &info->name[22], &info->name[23]);

    // Close process stat file
    fclose(fp);

    return info;
}

// Main function
int main() {
    // Get all process IDs
    pid_t *pids = NULL;
    int num_pids = 0;
    char line[1024];
    FILE *fp = fopen("/proc", "r");
    while (fgets(line, sizeof(line), fp)) {
        if (line[0] >= '0' && line[0] <= '9') {
            num_pids++;
            pids = realloc(pids, num_pids * sizeof(pid_t));
            pids[num_pids - 1] = atoi(line);
        }
    }
    fclose(fp);

    // Get process information for each PID
    proc_info **info = malloc(num_pids * sizeof(proc_info*));
    for (int i = 0; i < num_pids; i++) {
        info[i] = get_proc_info(pids[i]);
    }

    // Sort process information by PID
    qsort(info, num_pids, sizeof(proc_info*), compare_proc_info);

    // Print process information
    printf("PID\tName\t\tPPID\tRSS(bytes)\tVSZ(bytes)\n");
    for (int i = 0; i < num_pids; i++) {
        printf("%d\t%s\t%d\t%lu\t%lu\n", info[i]->pid, info[i]->name, info[i]->ppid, info[i]->rss, info[i]->vsize);
        free(info[i]);
    }
    free(pids);
    free(info);

    return 0;
}
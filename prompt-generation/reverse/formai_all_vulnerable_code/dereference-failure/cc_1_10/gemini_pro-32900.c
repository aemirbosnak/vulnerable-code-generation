//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/sysinfo.h>
#include <sys/resource.h>

typedef struct process {
    int pid;
    char name[100];
    char state;
    int ppid;
    int vsize;
    int rss;
    int cpu_time;
} process;

int compare(const void *a, const void *b) {
    const process *pa = (const process *)a;
    const process *pb = (const process *)b;

    return pb->rss - pa->rss;
}

int main() {
    DIR *dir;
    struct dirent *entry;
    char path[100];
    char buf[100];
    process processes[100];
    int num_processes = 0;

    // Get the path to the proc directory
    sprintf(path, "/proc");

    // Open the proc directory
    dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        return 1;
    }

    // Read the entries in the proc directory
    while ((entry = readdir(dir)) != NULL) {
        // Skip non-numeric entries
        if (!isdigit(entry->d_name[0])) {
            continue;
        }

        // Get the process ID
        processes[num_processes].pid = atoi(entry->d_name);

        // Get the process name
        sprintf(buf, "/proc/%s/comm", entry->d_name);
        FILE *file = fopen(buf, "r");
        if (file == NULL) {
            perror("fopen");
            continue;
        }
        fgets(processes[num_processes].name, 100, file);
        fclose(file);

        // Get the process state
        sprintf(buf, "/proc/%s/stat", entry->d_name);
        file = fopen(buf, "r");
        if (file == NULL) {
            perror("fopen");
            continue;
        }
        fscanf(file, "%*d (%s", processes[num_processes].name);
        processes[num_processes].state = processes[num_processes].name[0];
        fclose(file);

        // Get the process parent ID
        sprintf(buf, "/proc/%s/stat", entry->d_name);
        file = fopen(buf, "r");
        if (file == NULL) {
            perror("fopen");
            continue;
        }
        fscanf(file, "%*d (%*s %d", &processes[num_processes].ppid);
        fclose(file);

        // Get the process virtual memory size
        sprintf(buf, "/proc/%s/statm", entry->d_name);
        file = fopen(buf, "r");
        if (file == NULL) {
            perror("fopen");
            continue;
        }
        fscanf(file, "%d", &processes[num_processes].vsize);
        fclose(file);

        // Get the process resident set size
        struct rusage usage;
        getrusage(RUSAGE_SELF, &usage);
        processes[num_processes].rss = usage.ru_maxrss;

        // Get the process CPU time
        sprintf(buf, "/proc/%s/stat", entry->d_name);
        file = fopen(buf, "r");
        if (file == NULL) {
            perror("fopen");
            continue;
        }
        fscanf(file, "%*d (%*s %*d %*c %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %lld", &processes[num_processes].cpu_time);
        fclose(file);

        // Increment the number of processes
        num_processes++;
    }

    // Close the proc directory
    closedir(dir);

    // Sort the processes by RSS in descending order
    qsort(processes, num_processes, sizeof(process), compare);

    // Print the processes
    printf("%-5s %-10s %-5s %-5s %-10s %-5s %-10s\n", "PID", "Name", "State", "PPID", "VSZ", "RSS", "CPU");
    for (int i = 0; i < num_processes; i++) {
        printf("%-5d %-10s %-5c %-5d %-10ld %-5ld %-10ld\n", processes[i].pid, processes[i].name, processes[i].state, processes[i].ppid, processes[i].vsize, processes[i].rss, processes[i].cpu_time);
    }

    return 0;
}
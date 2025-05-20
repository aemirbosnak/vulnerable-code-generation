//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/resource.h>
#include <pwd.h>

// Function to get the number of processes running
int get_num_processes() {
    DIR *dir;
    struct dirent *entry;
    int num_processes = 0;

    dir = opendir("/proc");
    if (dir == NULL) {
        perror("opendir");
        return -1;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        num_processes++;
    }

    closedir(dir);

    return num_processes;
}

// Function to get the process information
int get_process_info(int pid, struct rusage *usage) {
    char path[256];
    FILE *fp;

    // Get the path to the process status file
    snprintf(path, sizeof(path), "/proc/%d/stat", pid);

    // Open the process status file
    fp = fopen(path, "r");
    if (fp == NULL) {
        perror("fopen");
        return -1;
    }

    // Read the process status file
    char line[1024];
    if (fgets(line, sizeof(line), fp) == NULL) {
        perror("fgets");
        fclose(fp);
        return -1;
    }

    // Parse the process status file
    char *fields[100];
    int num_fields = 0;
    char *field = strtok(line, " ");
    while (field != NULL) {
        fields[num_fields++] = field;
        field = strtok(NULL, " ");
    }

    // Get the process name
    char *process_name = fields[1];

    // Get the process state
    char *process_state = fields[2];

    // Get the process user ID
    int process_uid = atoi(fields[10]);

    // Get the process start time
    unsigned long long start_time = atoll(fields[21]);

    // Get the process CPU time
    unsigned long long cpu_time = atoll(fields[13]) + atoll(fields[14]);

    // Get the process memory usage
    unsigned long long memory_usage = atoll(fields[23]);

    // Close the process status file
    fclose(fp);

    // Get the process resource usage
    if (getrusage(RUSAGE_SELF, usage) == -1) {
        perror("getrusage");
        return -1;
    }

    // Print the process information
    printf("Process ID: %d\n", pid);
    printf("Process name: %s\n", process_name);
    printf("Process state: %s\n", process_state);
    printf("Process user ID: %d\n", process_uid);
    printf("Process start time: %llu\n", start_time);
    printf("Process CPU time: %llu\n", cpu_time);
    printf("Process memory usage: %llu\n", memory_usage);
    printf("Process resource usage:\n");
    printf("  - User time: %ld\n", usage->ru_utime.tv_sec);
    printf("  - System time: %ld\n", usage->ru_stime.tv_sec);
    printf("  - Max resident set size: %ld\n", usage->ru_maxrss);
    printf("  - Page faults: %ld\n", usage->ru_majflt);

    return 0;
}

int main() {
    // Get the number of processes running
    int num_processes = get_num_processes();
    if (num_processes == -1) {
        return 1;
    }

    printf("Number of processes running: %d\n\n", num_processes);

    // Get the process information for each process
    for (int i = 0; i < num_processes; i++) {
        struct rusage usage;
        int pid = i + 1;

        if (get_process_info(pid, &usage) == -1) {
            return 1;
        }

        printf("\n");
    }

    return 0;
}
//FormAI DATASET v1.0 Category: System process viewer ; Style: detailed
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Define constant variables
#define MAX_PATH_LENGTH 1024
#define MAX_PID_LENGTH 16

// Struct for storing process information
typedef struct {
    char name[MAX_PATH_LENGTH];       // process name
    char pid[MAX_PID_LENGTH];         // process ID
    double cpu_usage;                 // CPU usage in percentage
    unsigned long long int memory;    // memory usage in bytes
} ProcessInfo;

// Function prototypes
void get_proc_name(char*, char*, const size_t);
void get_proc_stat(char*, char*, const size_t);
unsigned long long int get_proc_memory(const char*);
void get_cpu_usage(double*, const unsigned long int, const unsigned long int, const unsigned long int, const unsigned long int);

int main() {

    // Variable initialization
    DIR* proc_dir;
    struct dirent* entry;
    char proc_path[MAX_PATH_LENGTH], proc_name[MAX_PATH_LENGTH], proc_stat[MAX_PATH_LENGTH];
    unsigned long int idle_cpu_time, total_cpu_time, prev_idle_cpu_time = 0, prev_total_cpu_time = 0;
    double cpu_usage;
    unsigned long long int mem_usage;
    ProcessInfo process_info;

    // Loop through all the directories in /proc
    proc_dir = opendir("/proc");
    while ((entry = readdir(proc_dir)) != NULL) {

        // Check if the entry name is a number (i.e., a process ID)
        if (isdigit(entry->d_name[0])) {

            // Get process name and status file paths
            snprintf(proc_path, sizeof proc_path, "/proc/%s/", entry->d_name);
            get_proc_name(entry->d_name, proc_name, sizeof proc_name);
            get_proc_stat(entry->d_name, proc_stat, sizeof proc_stat);
            mem_usage = get_proc_memory(entry->d_name);

            // Get CPU usage
            sscanf(proc_stat, "%*s%*s%*s%*s%*s%*s%*s%*s%*s%lu%lu%*s%*s%*s%lu", &total_cpu_time, &idle_cpu_time, &process_info.memory);
            get_cpu_usage(&cpu_usage, idle_cpu_time, total_cpu_time, prev_idle_cpu_time, prev_total_cpu_time);
            prev_idle_cpu_time = idle_cpu_time;
            prev_total_cpu_time = total_cpu_time;

            // Save process information to struct
            strcpy(process_info.name, proc_name);
            strcpy(process_info.pid, entry->d_name);
            process_info.cpu_usage = cpu_usage;
            process_info.memory = mem_usage;

            // Print process information to console
            printf("Process %s (PID %s) CPU Usage: %.2f%% Memory Usage: %llu bytes\n", process_info.name, process_info.pid, process_info.cpu_usage, process_info.memory);
        }
    }
    closedir(proc_dir);

    return 0;
}

// Function to get process name given its PID
void get_proc_name(char* pid, char* name, const size_t size) {

    // Variable initialization
    FILE* fp;
    char path[MAX_PATH_LENGTH];

    // Construct path to process status file
    snprintf(path, sizeof path, "/proc/%s/stat", pid);

    // Open process status file
    fp = fopen(path, "r");
    if (fp == NULL) {
        perror("Failed to open process status file");
        exit(EXIT_FAILURE);
    }

    // Read process name from status file
    fscanf(fp, "%*d (%[^)])", name);

    // Close file
    fclose(fp);
}

// Function to get process usage statistics
void get_proc_stat(char* pid, char* stat, const size_t size) {

    // Variable initialization
    FILE* fp;
    char path[MAX_PATH_LENGTH];

    // Construct path to process status file
    snprintf(path, sizeof path, "/proc/%s/stat", pid);

    // Open process status file
    fp = fopen(path, "r");
    if (fp == NULL) {
        perror("Failed to open process status file");
        exit(EXIT_FAILURE);
    }

    // Read process statistics from status file
    fgets(stat, size, fp);

    // Close file
    fclose(fp);
}

// Function to get process memory usage in bytes
unsigned long long int get_proc_memory(const char* pid) {

    // Variable initialization
    FILE* fp;
    char path[MAX_PATH_LENGTH];
    unsigned long long int mem;

    // Construct path to process status file
    snprintf(path, sizeof path, "/proc/%s/statm", pid);

    // Open process status file
    fp = fopen(path, "r");
    if (fp == NULL) {
        perror("Failed to open process status file");
        exit(EXIT_FAILURE);
    }

    // Read memory usage from status file
    fscanf(fp, "%*s%llu", &mem);
    mem *= getpagesize();

    // Close file
    fclose(fp);

    return mem;
}

// Function to get CPU usage given idle and total times
void get_cpu_usage(double* usage, const unsigned long int idle1, const unsigned long int total1, const unsigned long int idle2, const unsigned long int total2) {

    // Calculate CPU usage
    const double interval = (double) (total2 - total1);
    if (interval != 0) {
        *usage = 100.0 * (1 - ((double) (idle2 - idle1) / interval));
    } else {
        *usage = 0.0;
    }
}
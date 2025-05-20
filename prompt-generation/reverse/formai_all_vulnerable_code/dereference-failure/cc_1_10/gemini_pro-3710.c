//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/sysinfo.h>
#include <unistd.h>
#include <pwd.h>
#include <time.h>

// Function to get the current time
char* get_current_time() {
    time_t current_time;
    time(&current_time);
    return ctime(&current_time);
}

// Function to get the username of the current user
char* get_current_user() {
    uid_t uid = geteuid();
    struct passwd *pw = getpwuid(uid);
    return pw->pw_name;
}

// Function to get the hostname of the current machine
char* get_hostname() {
    char hostname[256];
    gethostname(hostname, sizeof(hostname));
    return hostname;
}

// Function to get the uptime of the system
long long get_uptime() {
    struct sysinfo info;
    sysinfo(&info);
    return info.uptime;
}

// Function to get the number of processes running on the system
long long get_num_processes() {
    struct sysinfo info;
    sysinfo(&info);
    return info.procs;
}

// Function to get the total amount of memory on the system
long long get_total_memory() {
    struct sysinfo info;
    sysinfo(&info);
    return info.totalram;
}

// Function to get the amount of free memory on the system
long long get_free_memory() {
    struct sysinfo info;
    sysinfo(&info);
    return info.freeram;
}

// Function to get the amount of used memory on the system
long long get_used_memory() {
    return get_total_memory() - get_free_memory();
}

// Function to get the percentage of memory used on the system
int get_memory_usage() {
    return (get_used_memory() * 100) / get_total_memory();
}

// Function to get the number of CPUs on the system
int get_num_cpus() {
    return sysconf(_SC_NPROCESSORS_ONLN);
}

// Function to get the load average of the system
double get_load_average() {
    double loadavg[3];
    getloadavg(loadavg, 3);
    return loadavg[0];
}

// Function to print the system information
void print_system_info() {
    printf("Current time: %s", get_current_time());
    printf("Current user: %s\n", get_current_user());
    printf("Hostname: %s\n", get_hostname());
    printf("Uptime: %lld seconds\n", get_uptime());
    printf("Number of processes: %lld\n", get_num_processes());
    printf("Total memory: %lld MB\n", get_total_memory() / 1024 / 1024);
    printf("Free memory: %lld MB\n", get_free_memory() / 1024 / 1024);
    printf("Used memory: %lld MB\n", get_used_memory() / 1024 / 1024);
    printf("Memory usage: %d%%\n", get_memory_usage());
    printf("Number of CPUs: %d\n", get_num_cpus());
    printf("Load average: %.2f\n", get_load_average());
}

int main() {
    // Print a header
    printf("Welcome to the System Process Viewer!\n\n");

    // Print the system information
    print_system_info();

    // Print a footer
    printf("\nThank you for using the System Process Viewer!\n");

    return 0;
}
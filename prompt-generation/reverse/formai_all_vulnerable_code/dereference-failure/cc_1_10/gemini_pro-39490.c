//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <time.h>
#include <pwd.h>

// Define the maximum number of processes to display
#define MAX_PROCESSES 100

// Define the maximum length of a process name
#define MAX_NAME_LENGTH 256

// Define the maximum length of a process command line
#define MAX_COMMAND_LINE_LENGTH 1024

// Structure to store information about a process
typedef struct {
    pid_t pid;
    char name[MAX_NAME_LENGTH];
    char command_line[MAX_COMMAND_LINE_LENGTH];
    time_t start_time;
    uid_t uid;
} process_info_t;

// Function to compare two process_info_t structures by PID
int compare_process_info(const void *a, const void *b) {
    const process_info_t *pa = (const process_info_t *)a;
    const process_info_t *pb = (const process_info_t *)b;
    return pa->pid - pb->pid;
}

// Function to print information about a process
void print_process_info(const process_info_t *process_info) {
    // Get the user name
    struct passwd *passwd = getpwuid(process_info->uid);
    char *user_name = passwd ? passwd->pw_name : "Unknown";

    // Print the process information
    printf("%d %s %s %s %s\n",
        process_info->pid,
        process_info->name,
        process_info->command_line,
        ctime(&process_info->start_time),
        user_name);
}

// Function to get information about all processes
int get_process_info(process_info_t *process_info, int max_processes) {
    // Open the /proc directory
    DIR *proc_dir = opendir("/proc");
    if (proc_dir == NULL) {
        perror("opendir");
        return -1;
    }

    // Get information about each process
    int num_processes = 0;
    while (num_processes < max_processes) {
        // Get the next entry in the /proc directory
        struct dirent *entry = readdir(proc_dir);
        if (entry == NULL) {
            break;
        }

        // Check if the entry is a directory
        if (!strcmp(entry->d_type, DT_DIR)) {
            // Check if the directory name is a PID
            pid_t pid = atoi(entry->d_name);
            if (pid > 0) {
                // Get the process name
                char name_path[MAX_NAME_LENGTH];
                snprintf(name_path, sizeof(name_path), "/proc/%d/comm", pid);
                FILE *name_file = fopen(name_path, "r");
                if (name_file != NULL) {
                    fgets(process_info[num_processes].name, sizeof(process_info[num_processes].name), name_file);
                    fclose(name_file);
                }

                // Get the process command line
                char command_line_path[MAX_COMMAND_LINE_LENGTH];
                snprintf(command_line_path, sizeof(command_line_path), "/proc/%d/cmdline", pid);
                FILE *command_line_file = fopen(command_line_path, "r");
                if (command_line_file != NULL) {
                    fgets(process_info[num_processes].command_line, sizeof(process_info[num_processes].command_line), command_line_file);
                    fclose(command_line_file);
                }

                // Get the process start time
                char start_time_path[MAX_COMMAND_LINE_LENGTH];
                snprintf(start_time_path, sizeof(start_time_path), "/proc/%d/stat", pid);
                FILE *start_time_file = fopen(start_time_path, "r");
                if (start_time_file != NULL) {
                    char start_time_str[64];
                    fscanf(start_time_file, "%*d %*s %*c %*d %*d %*d %*d %*d %*u %*Lu %*Lu %*Lu %*Lu %*Lu %*Lu %*Ld %*Ld %*d %*d %*d %*d %*d %Ld\n", &start_time_str);
                    process_info[num_processes].start_time = atol(start_time_str);
                    fclose(start_time_file);
                }

                // Get the process UID
                process_info[num_processes].uid = getuid();

                // Increment the number of processes
                num_processes++;
            }
        }
    }

    // Close the /proc directory
    closedir(proc_dir);

    // Sort the process information by PID
    qsort(process_info, num_processes, sizeof(process_info_t), compare_process_info);

    // Return the number of processes
    return num_processes;
}

// Main function
int main(void) {
    // Get information about all processes
    process_info_t process_info[MAX_PROCESSES];
    int num_processes = get_process_info(process_info, MAX_PROCESSES);

    // Print the process information
    for (int i = 0; i < num_processes; i++) {
        print_process_info(&process_info[i]);
    }

    return 0;
}
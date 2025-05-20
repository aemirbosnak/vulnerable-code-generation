//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <ctype.h>

#define MAX_LINE 256

void get_children(pid_t pid, int depth);
void print_indent(int depth);

int main() {
    // Get the list of processes from the /proc directory
    DIR *proc_dir = opendir("/proc");
    struct dirent *entry;

    if (!proc_dir) {
        perror("Could not open /proc directory");
        return EXIT_FAILURE;
    }

    printf("Process Viewer:\n");

    // Read each entry in the /proc folder
    while ((entry = readdir(proc_dir)) != NULL) {
        // Check if the entry is a digit (indicating a PID)
        if (isdigit(entry->d_name[0])) {
            pid_t pid = atoi(entry->d_name);
            printf("Process ID: %d\n", pid);
            get_children(pid, 1);
            printf("\n");
        }
    }

    closedir(proc_dir);
    return EXIT_SUCCESS;
}

void get_children(pid_t pid, int depth) {
    char path[MAX_LINE];
    FILE *status_file;
    pid_t ppid;

    // Construct the path to the status file of the process
    snprintf(path, sizeof(path), "/proc/%d/status", pid);
    status_file = fopen(path, "r");
    if (!status_file) {
        return; // Maybe the process has exited
    }

    // Read the status file to find the parent process ID (PPID)
    while (fgets(path, sizeof(path), status_file) != NULL) {
        if (strncmp(path, "PPid:", 5) == 0) {
            sscanf(path + 5, "%d", &ppid);
            break;
        }
    }
    fclose(status_file);

    // Print the process information
    print_indent(depth);
    printf("Process ID: %d, Parent ID: %d\n", pid, ppid);

    // Now we will check for children of this process
    DIR *proc_dir = opendir("/proc");
    struct dirent *entry;
    if (!proc_dir) {
        return; // Could not open proc directory
    }

    // Look for child processes
    while ((entry = readdir(proc_dir)) != NULL) {
        if (isdigit(entry->d_name[0])) {
            int child_pid = atoi(entry->d_name);
            // Check if this child process has the current process as a parent
            snprintf(path, sizeof(path), "/proc/%d/status", child_pid);
            FILE *child_status_file = fopen(path, "r");
            if (child_status_file) {
                while (fgets(path, sizeof(path), child_status_file) != NULL) {
                    if (strncmp(path, "PPid:", 5) == 0) {
                        int child_ppid;
                        sscanf(path + 5, "%d", &child_ppid);
                        if (child_ppid == pid) {
                            // Found a child process
                            get_children(child_pid, depth + 1);
                        }
                        break;
                    }
                }
                fclose(child_status_file);
            }
        }
    }

    closedir(proc_dir);
}

void print_indent(int depth) {
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
}
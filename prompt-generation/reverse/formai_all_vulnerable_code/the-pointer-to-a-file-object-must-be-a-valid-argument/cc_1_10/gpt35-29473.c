//FormAI DATASET v1.0 Category: System process viewer ; Style: calm
/* C System Process Viewer Example Program */
#include <stdio.h>
#include <string.h>
#include <dirent.h>

/* Define global constants */
#define MAX_PATH 1024
#define BUFFER_SIZE 1024

/* Define process information structure */
typedef struct process_info {
    char name[64];
    int pid;
    char status;
} process_info_t;

/* Define function to retrieve process information */
process_info_t get_process_info(const char *pid_str) {
    process_info_t pi;

    /* Open the /proc/[pid]/status file */
    char status_path[MAX_PATH];
    snprintf(status_path, MAX_PATH, "/proc/%s/status", pid_str);
    FILE *status_file = fopen(status_path, "r");

    /* Read the process name and status from the status file */
    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, status_file)) {
        if (strstr(buffer, "Name:")) {
            sscanf(buffer, "Name:\t%s", pi.name);
        } else if (strstr(buffer, "State:")) {
            sscanf(buffer, "State:\t%c", &pi.status);
        }
    }

    /* Close the status file */
    fclose(status_file);

    /* Set the PID */
    pi.pid = atoi(pid_str);

    /* Return the process info */
    return pi;
}

/* Define the main function */
int main() {
    DIR *dir;
    struct dirent *entry;
    process_info_t pi;

    /* Open the /proc directory */
    dir = opendir("/proc");
    if (!dir) {
        perror("Error opening /proc directory");
        return 1;
    }

    /* Print the header */
    printf("%10s %-20s %s\n", "PID", "NAME", "STATUS");

    /* Read each entry from the /proc directory */
    while ((entry = readdir(dir))) {
        /* Skip entries that are not directories */
        if (entry->d_type != DT_DIR) {
            continue;
        }

        /* Check if the name of the directory is a number */
        int is_number = 1;
        for (int i = 0; i < strlen(entry->d_name); i++) {
            if (entry->d_name[i] < '0' || entry->d_name[i] > '9') {
                is_number = 0;
                break;
            }
        }
        if (!is_number) {
            continue;
        }

        /* Get the process info */
        pi = get_process_info(entry->d_name);

        /* Print the process info */
        printf("%10d %-20s %c\n", pi.pid, pi.name, pi.status);
    }

    /* Close the /proc directory */
    closedir(dir);

    /* Return success */
    return 0;
}
//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>

// A struct to store process information
typedef struct {
    long int pid;
    char cmd[256];
    long int status;
} ProcessInfo;

// A function to compare two process infos by PID
int compare_by_pid(const void *a, const void *b) {
    const ProcessInfo *p1 = (const ProcessInfo *)a;
    const ProcessInfo *p2 = (const ProcessInfo *)b;

    return p1->pid - p2->pid;
}

// A function to get the process information
int get_process_info(ProcessInfo *p) {
    char path[256];
    char line[256];
    FILE *fp;

    // Get the process status
    snprintf(path, sizeof(path), "/proc/%d/status", p->pid);
    if ((fp = fopen(path, "r")) == NULL) {
        return -1;
    }
    while (fgets(line, sizeof(line), fp) != NULL) {
        if (strncmp(line, "State:", 6) == 0) {
            sscanf(line, "State: %s", p->cmd);
        } else if (strncmp(line, "Pid:", 4) == 0) {
            sscanf(line, "Pid: %ld", &p->pid);
        }
    }
    fclose(fp);

    return 0;
}

// A function to print the process information
void print_process_info(const ProcessInfo *p) {
    printf("%-5ld %-25s %ld\n", p->pid, p->cmd, p->status);
}

// A function to get all the process information
int get_all_process_info(ProcessInfo **p) {
    DIR *dir;
    struct dirent *entry;
    int count = 0;

    // Allocate memory for the process information
    *p = malloc(sizeof(ProcessInfo) * 1024);
    if (*p == NULL) {
        return -1;
    }

    // Open the /proc directory
    if ((dir = opendir("/proc")) == NULL) {
        return -1;
    }

    // Iterate over the /proc directory
    while ((entry = readdir(dir)) != NULL) {
        // Check if the entry is a directory
        if (entry->d_type == DT_DIR) {
            // Get the process ID
            long int pid = atoi(entry->d_name);

            // Get the process information
            if (get_process_info(&(*p)[count]) == 0) {
                count++;
            }
        }
    }

    // Close the /proc directory
    closedir(dir);

    // Sort the process information by PID
    qsort(*p, count, sizeof(ProcessInfo), compare_by_pid);

    return count;
}

// The main function
int main(void) {
    ProcessInfo *p;
    int count;

    // Get all the process information
    if ((count = get_all_process_info(&p)) == -1) {
        perror("get_all_process_info");
        return EXIT_FAILURE;
    }

    // Print the process information
    printf("%-5s %-25s %s\n", "PID", "COMMAND", "STATUS");
    for (int i = 0; i < count; i++) {
        print_process_info(&p[i]);
    }

    // Free the memory allocated for the process information
    free(p);

    return EXIT_SUCCESS;
}
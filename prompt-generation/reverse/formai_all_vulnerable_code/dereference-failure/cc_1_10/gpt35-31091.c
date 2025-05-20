//FormAI DATASET v1.0 Category: System process viewer ; Style: multivariable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <ctype.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <pwd.h>
#include <sys/sysinfo.h>
#include <sys/stat.h>

// Define maximum number of processes to display
#define MAX_PROCESSES 100

// Define struct to store process information
struct process_info {
    pid_t pid;
    char user[32];
    char command[64];
    long int rss;
};

// Function to retrieve the username associated with a uid
char* get_username(uid_t uid) {
    struct passwd *pw = getpwuid(uid);
    if (pw) {
        return pw->pw_name;
    }
    return "";
}

// Function to convert kilobytes to megabytes
double kb_to_mb(long int kb) {
    double mb = kb / 1024.0 / 1024.0;
    return mb;
}

// Function to sort process information by RSS
int sort_by_rss(const void *a, const void *b) {
    struct process_info *pa = (struct process_info *) a;
    struct process_info *pb = (struct process_info *) b;

    if (pa->rss > pb->rss) {
        return -1;
    } else if (pa->rss < pb->rss) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    // Define variables to store information about each process
    struct process_info processes[MAX_PROCESSES];
    char proc_path[64];
    char stat_path[64];
    char line[256];
    char *token;
    int count = 0;

    // Open the proc directory
    DIR *dir = opendir("/proc");
    if (!dir) {
        fprintf(stderr, "Failed to open /proc directory: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Loop through each subdirectory in the proc directory
    struct dirent *ent;
    while ((ent = readdir(dir)) != NULL) {
        // Check if the subdirectory is a valid PID directory
        if (isdigit(ent->d_name[0])) {
            // Build the path to the PID's stat file
            sprintf(stat_path, "/proc/%s/stat", ent->d_name);

            // Open the PID's stat file
            FILE *stat_file = fopen(stat_path, "r");
            if (!stat_file) {
                continue;
            }

            // Read the first token (the PID) from the stat file
            if (!fgets(line, sizeof(line), stat_file)) {
                continue;
            }
            token = strtok(line, " ");

            // Store the PID
            processes[count].pid = atoi(token);

            // Read the second token (the command name) from the stat file
            token = strtok(NULL, " ");
            token = strtok(NULL, " ");
            strncpy(processes[count].command, token, sizeof(processes[count].command) - 1);
            processes[count].command[sizeof(processes[count].command) - 1] = '\0';

            // Read the uid from the stat file
            token = strtok(NULL, " ");
            token = strtok(NULL, " ");
            uid_t uid = atoi(token);

            // Get the username associated with the uid and store it
            char *username = get_username(uid);
            strncpy(processes[count].user, username, sizeof(processes[count].user) - 1);
            processes[count].user[sizeof(processes[count].user) - 1] = '\0';

            // Read the memory usage (RSS) from the stat file
            long int rss;
            for (int i = 0; i < 21; i++) {
                token = strtok(NULL, " ");
                if (i == 18) {
                    rss = atol(token);
                    break;
                }
            }
            processes[count].rss = rss;

            // Close the stat file
            fclose(stat_file);

            count++;
            if (count >= MAX_PROCESSES) {
                break;
            }
        }
    }

    // Close the proc directory
    closedir(dir);

    // Sort the process information by RSS
    qsort(processes, count, sizeof(struct process_info), sort_by_rss);

    // Print the header row
    printf("%-8s %-20s %-20s %-10s\n", "PID", "COMMAND", "USER", "RSS");

    // Print information about each process
    for (int i = 0; i < count; i++) {
        printf("%-8d %-20s %-20s %-10.2f\n",
                processes[i].pid,
                processes[i].command,
                processes[i].user,
                kb_to_mb(processes[i].rss));
    }

    exit(EXIT_SUCCESS);
}
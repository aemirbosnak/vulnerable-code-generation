//FormAI DATASET v1.0 Category: System process viewer ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

pid_t get_process_pid(const char *process_name);
void print_process_details(pid_t pid);

// Main function
int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("Usage: cryptic_process_viewer <process name>\n");
        exit(0);
    }

    pid_t pid = get_process_pid(argv[1]);
    if(pid == -1) {
        printf("Error: Process '%s' not found\n", argv[1]);
        exit(0);
    }

    print_process_details(pid);
    return 0;
}

// Function to get the process ID given the process name
pid_t get_process_pid(const char *process_name) {
    DIR *dir;
    struct dirent *entry;
    char path[1024];

    dir = opendir("/proc");
    if (dir == NULL) {
        printf("Error: Unable to open /proc directory\n");
        exit(0);
    }

    // Loop over all the process directories in /proc directory
    while ((entry = readdir(dir)) != NULL) {
        if (!isdigit(*entry->d_name)) {
            continue;
        }
        sprintf(path, "/proc/%s/cmdline", entry->d_name);

        FILE *fp;
        char buf[1024];

        fp = fopen(path, "r");
        if (fp == NULL) {
            continue;
        }

        // Read the command line arguments of the process
        fgets(buf, sizeof(buf), fp);
        fclose(fp);

        int len = strlen(buf);
        if (len > 0 && buf[len-1] == '\n') {
            buf[len-1] = '\0';
        }

        // Check if the command line arguments contain the process name
        if (strstr(buf, process_name) != NULL) {
            closedir(dir);
            return atoi(entry->d_name);
        }
    }

    closedir(dir);
    return -1;
}

// Function to print the details of a process
void print_process_details(pid_t pid) {
    char status_path[1024];
    sprintf(status_path, "/proc/%d/status", pid);

    FILE *fp;
    char buf[1024];

    fp = fopen(status_path, "r");
    if (fp == NULL) {
        printf("Error: Unable to open status file for process %d\n", pid);
        exit(0);
    }

    // Read the contents of the status file
    while (fgets(buf, sizeof(buf), fp) != NULL) {
        if (strstr(buf, "Name:") != NULL) {
            printf("Process Name: %s\n", strstr(buf, "Name:") + strlen("Name:"));
        }
        else if (strstr(buf, "State:") != NULL) {
            printf("Process State: %s\n", strstr(buf, "State:") + strlen("State:"));
        }
        else if (strstr(buf, "PPid:") != NULL) {
            printf("Parent Process ID: %d\n", atoi(strstr(buf, "PPid:") + strlen("PPid:")));
        }
        else if (strstr(buf, "Uid:") != NULL) {
            printf("User ID: %d\n", atoi(strstr(buf, "Uid:") + strlen("Uid:")));
        }
    }

    fclose(fp);
}
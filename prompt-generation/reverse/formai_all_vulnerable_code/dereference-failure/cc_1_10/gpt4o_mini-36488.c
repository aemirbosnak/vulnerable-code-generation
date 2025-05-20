//GPT-4o-mini DATASET v1.0 Category: System process viewer ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>
#include <unistd.h>

#define BUFFER_SIZE 256

void inquire_process(const char *pid);
void read_status(const char *pid, char *status_info);
void read_cmdline(const char *pid, char *cmdline_info);

int main(void) {
    DIR *proc_dir;
    struct dirent *entry;

    proc_dir = opendir("/proc");
    if (proc_dir == NULL) {
        perror("Error opening /proc");
        return EXIT_FAILURE;
    }

    printf("Welcome to the inquisitive process viewer!\n");
    printf("We will explore the running processes in your system together.\n\n");
    
    while ((entry = readdir(proc_dir)) != NULL) {
        if (isdigit(entry->d_name[0])) {
            // We found a PID (a process)
            char *pid = entry->d_name;
            inquire_process(pid);
        }
    }

    closedir(proc_dir);
    printf("Thank you for exploring the process information!\n");
    return EXIT_SUCCESS;
}

void inquire_process(const char *pid) {
    char status_info[BUFFER_SIZE];
    char cmdline_info[BUFFER_SIZE];

    printf("Oh, look! There's a process with PID: %s.\n", pid);
    read_status(pid, status_info);
    printf("Details of the process:\n%s\n", status_info);

    read_cmdline(pid, cmdline_info);
    printf("Curious to know what it was running? Here is the command line:\n%s\n", cmdline_info);
    
    printf("Would you like to continue exploring? (y/n): ");
    char response;
    scanf(" %c", &response);
    
    if (response == 'n' || response == 'N') {
        printf("Okay, we won't delve further into the abyss of processes!\n\n");
    } else {
        printf("Onward we go!\n\n");
    }
}

void read_status(const char *pid, char *status_info) {
    char status_file[BUFFER_SIZE];
    snprintf(status_file, sizeof(status_file), "/proc/%s/status", pid);

    FILE *file = fopen(status_file, "r");
    if (file == NULL) {
        strcpy(status_info, "Unable to read status information.");
        return;
    }

    char line[BUFFER_SIZE];
    strcpy(status_info, "Process Status:\n");

    while (fgets(line, sizeof(line), file)) {
        strcat(status_info, line);
    }
    fclose(file);
}

void read_cmdline(const char *pid, char *cmdline_info) {
    char cmdline_file[BUFFER_SIZE];
    snprintf(cmdline_file, sizeof(cmdline_file), "/proc/%s/cmdline", pid);

    FILE *file = fopen(cmdline_file, "r");
    if (file == NULL) {
        strcpy(cmdline_info, "Unable to read command line information.");
        return;
    }

    char line[BUFFER_SIZE];
    if (fgets(line, sizeof(line), file)) {
        // Replace null bytes with spaces
        for (char *p = line; *p; p++) {
            if (*p == '\0') {
                *p = ' ';
            }
        }
        strcpy(cmdline_info, line);
    } else {
        strcpy(cmdline_info, "No command line information available.");
    }
    fclose(file);
}
//FormAI DATASET v1.0 Category: System administration ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_LINE 80
#define TRUE     1
#define FALSE    0

/*
 * This program is a simple demonstration of a system administration tool
 * that allows a regular user to query the system for information about
 * the current system status and perform some basic maintenance tasks.
 */

int main(int argc, char *argv[]) {
    char *line;
    int should_run = TRUE; // Flag for while loop
    int exit_status = 0;   // Return value of program
    int fd_stdout;         // File descriptor for stdout
    mode_t stored_mode;    // Variable to store current file mode
    int stored_out;        // Variable to store current stdout

    // Allocate memory for command line input
    line = (char*)malloc(MAX_LINE*sizeof(char));

    // Check for successful allocation
    if (line == NULL) {
        printf("Error: unable to allocate memory\n");
        exit(1);
    }

    // Welcome message
    printf("Welcome to the system administration tool!\n");

    // Main program loop
    while (should_run) {
        // Prompt user for input
        printf("admin@system:~$ ");
        fflush(stdout);

        // Read user input
        fgets(line, MAX_LINE, stdin);

        // Remove the newline at the end of the string
        line[strlen(line)-1] = '\0';

        // Check if user wants to exit program
        if (strcmp(line, "exit") == 0) {
            should_run = FALSE;
            printf("Goodbye!\n");
            continue;
        }

        // Check if user wants to view system status
        if (strcmp(line, "status") == 0) {
            printf("Current system status:\n");
            system("status");
            continue;
        }

        // Check if user wants to perform maintenance tasks
        if (strcmp(line, "maintenance") == 0) {
            // Check if user is root
            if (geteuid() != 0) {
                printf("Error: you must be root to perform maintenance tasks\n");
                continue;
            }

            // Make backup of important files
            printf("Making backup of important files...\n");
            system("cp /etc/fstab /etc/fstab.bak");
            system("cp /etc/passwd /etc/passwd.bak");

            // Modify important files
            printf("Modifying important files...\n");
            fd_stdout = open("/etc/fstab", O_WRONLY);
            stored_out = dup(STDOUT_FILENO); // Store current stdout
            dup2(fd_stdout, STDOUT_FILENO); // Redirect stdout to file
            system("echo '/dev/sdb1 /mnt/backup ext4 defaults 0 0' >> /etc/fstab");
            dup2(stored_out, STDOUT_FILENO); // Restore stdout
            close(fd_stdout);

            fd_stdout = open("/etc/passwd", O_WRONLY);
            stored_out = dup(STDOUT_FILENO); // Store current stdout
            dup2(fd_stdout, STDOUT_FILENO); // Redirect stdout to file
            system("useradd backup");
            dup2(stored_out, STDOUT_FILENO); // Restore stdout
            close(fd_stdout);

            // Change file permissions
            printf("Changing permissions of important files...\n");
            stored_mode = umask(0077); // Set umask to restrict permissions
            chmod("/etc/fstab.bak", 0600);
            chmod("/etc/passwd.bak", 0600);
            umask(stored_mode); // Reset umask

            continue;
        }

        // If command not recognized, print error message
        printf("Error: command not recognized\n");
    }

    // Free memory allocated for input string
    free(line);

    return exit_status;
}
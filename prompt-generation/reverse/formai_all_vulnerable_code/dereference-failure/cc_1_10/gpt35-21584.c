//FormAI DATASET v1.0 Category: System administration ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_OUTPUT_LENGTH 1000

/**
 * Executes a shell command and returns its output as a string
 */
char* execute_command(char* command) {
    char output[MAX_OUTPUT_LENGTH];
    FILE* fp = popen(command, "r");
    if (fp == NULL) {
        perror("popen() failed");
        exit(EXIT_FAILURE);
    }
    fgets(output, MAX_OUTPUT_LENGTH, fp);
    pclose(fp);
    return strdup(output);
}

/**
 * Prints system information such as the number of CPUs and total memory
 */
void print_system_info() {
    printf("System Info\n");
    printf("--------------------\n");

    // Number of CPUs
    char* ncpus_output = execute_command("nproc");
    int ncpus = atoi(ncpus_output);
    printf("Number of CPUs: %d\n", ncpus);

    // Total memory
    char* meminfo_output = execute_command("grep MemTotal /proc/meminfo");
    int total_memory = atoi(&meminfo_output[10]); // The output format is "MemTotal: XXX kB"
    printf("Total Memory: %d kB\n", total_memory);

    free(ncpus_output);
}

/**
 * Kills a process with the given PID
 */
void kill_process(int pid) {
    printf("Killing process with PID %d\n", pid);
    kill(pid, SIGKILL);
}

/**
 * Prompts the user for a command and executes it
 */
void run_user_command() {
    char command[MAX_COMMAND_LENGTH];
    printf("\nEnter a command (or 'exit' to quit): ");
    fgets(command, MAX_COMMAND_LENGTH, stdin);
    command[strcspn(command, "\n")] = '\0'; // Strip the newline character

    if (strcmp(command, "exit") == 0) {
        exit(EXIT_SUCCESS);
    }

    char* output = execute_command(command);
    printf("Output: %s\n", output);
    free(output);
}

int main() {
    printf("Welcome to the System Administration Program!\n\n");

    while (true) {
        printf("Please choose an option:\n");
        printf("1. Print System Info\n");
        printf("2. Kill a Process\n");
        printf("3. Run a Command\n");
        printf("4. Exit\n");

        char option_input[MAX_COMMAND_LENGTH];
        printf("\nEnter your option: ");
        fgets(option_input, MAX_COMMAND_LENGTH, stdin);
        int option = atoi(option_input);

        switch (option) {
            case 1:
                print_system_info();
                break;
            case 2: {
                char pid_input[MAX_COMMAND_LENGTH];
                printf("Enter the PID of the process to kill: ");
                fgets(pid_input, MAX_COMMAND_LENGTH, stdin);
                int pid = atoi(pid_input);
                kill_process(pid);
                break;
            }
            case 3:
                run_user_command();
                break;
            case 4:
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid option.\n");
        }

        printf("\n");
    }
}
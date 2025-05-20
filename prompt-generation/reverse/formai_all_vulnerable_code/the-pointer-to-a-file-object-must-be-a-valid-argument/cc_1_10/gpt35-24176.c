//FormAI DATASET v1.0 Category: System process viewer ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Get the command output of "ps aux" using a pipe
    FILE *pipe = popen("ps aux", "r");
    char buffer[1024];
    int count = 0;

    // Print a colorful title using ANSI color codes
    printf("\033[1;36m");
    printf("************************************************\n");
    printf("*           WELCOME TO PROCESS VIEWER           *\n");
    printf("************************************************\n");
    printf("\033[0m");

    // Read the command output line by line and display the process details
    while (fgets(buffer, sizeof(buffer), pipe)) {
        if (count == 0) {
            // Print a colorful header using ANSI color codes
            printf("\033[1;33m%-10s %-6s %-10s %-20s %-20s\n", "USER", "PID", "%CPU", "%MEM", "COMMAND");
            printf("\033[0m");
        } else {
            // Extract the process details from the output using sscanf
            char user[10];
            int pid;
            float cpu;
            float mem;
            char command[50];
            sscanf(buffer, "%s %d %f %f %s", user, &pid, &cpu, &mem, command);
            // Print the process details in a colorful way using ANSI color codes
            if (count % 2 == 0) {
                printf("\033[1;32m%-10s %-6d %-10.2f %-20.2f %-20s\n", user, pid, cpu, mem, command);
            } else {
                printf("\033[1;34m%-10s %-6d %-10.2f %-20.2f %-20s\n", user, pid, cpu, mem, command);
            }
        }
        count++;
    }

    // Print a cheerful goodbye message using ANSI color codes
    printf("\033[1;36m");
    printf("\n\n************************************************\n");
    printf("*               GOODBYE FROM PV                 *\n");
    printf("************************************************\n");
    printf("\033[0m");

    // Close the pipe and exit the program
    pclose(pipe);
    return 0;
}
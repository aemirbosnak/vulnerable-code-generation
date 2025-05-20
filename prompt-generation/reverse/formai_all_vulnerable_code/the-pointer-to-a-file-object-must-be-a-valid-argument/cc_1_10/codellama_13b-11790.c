//Code Llama-13B DATASET v1.0 Category: RAM usage monitor ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define PROGRAM_NAME "RAM usage monitor"
#define SLEEP_TIME 1 // in seconds

// Function to get the current RAM usage
unsigned long get_ram_usage() {
    FILE *fp;
    char cmd[50];
    char line[1024];
    unsigned long total_mem, free_mem, used_mem;

    // Get the total and free memory
    sprintf(cmd, "/bin/sh -c 'free | awk 'NR==2{print $2}'");
    fp = popen(cmd, "r");
    fgets(line, sizeof(line), fp);
    pclose(fp);
    total_mem = atol(line);

    sprintf(cmd, "/bin/sh -c 'free | awk 'NR==2{print $4}'");
    fp = popen(cmd, "r");
    fgets(line, sizeof(line), fp);
    pclose(fp);
    free_mem = atol(line);

    // Calculate the used memory
    used_mem = total_mem - free_mem;

    return used_mem;
}

// Function to print the RAM usage
void print_ram_usage(unsigned long used_mem) {
    printf("RAM usage: %lu MB\n", used_mem / 1024);
}

// Main function
int main() {
    unsigned long used_mem;

    // Initialize the program
    printf("%s\n", PROGRAM_NAME);

    // Monitor the RAM usage
    while (1) {
        used_mem = get_ram_usage();
        print_ram_usage(used_mem);
        sleep(SLEEP_TIME);
    }

    return 0;
}
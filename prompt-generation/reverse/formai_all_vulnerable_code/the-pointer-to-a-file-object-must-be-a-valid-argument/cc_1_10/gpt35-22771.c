//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
* This program recursively monitors the current C RAM usage by the system.
* It prints out the usage in KiB every 2 seconds until the user decides to stop it.
* The recursive function is used to continuously fetch and print the current usage.
*/

void monitor_ram_usage()
{
    FILE *fp;
    char buffer[100];
    int ram_usage, i;

    // Read the file that contains current RAM usage
    fp = fopen("/proc/meminfo", "r");
    for (i = 0; i < 20; i++) {
        fgets(buffer, sizeof(buffer), fp);
    }
    sscanf(buffer, "MemTotal: %*u kB\nMemFree: %*u kB\nMemAvailable: %u", &ram_usage);
    fclose(fp);

    // Print the current RAM usage in KiB
    printf("Current RAM usage: %d KiB\n", ram_usage);

    // Wait for 2 seconds
    sleep(2);

    // Recursively call the function to monitor RAM usage continuously
    monitor_ram_usage();
}

int main()
{
    char choice;

    // Ask the user if they want to monitor RAM usage
    printf("Do you want to monitor RAM usage? (Y/N): ");
    scanf("%c", &choice);

    if (choice == 'Y' || choice == 'y') {
        monitor_ram_usage();
    } else {
        printf("Exiting...\n");
    }

    return 0;
}
//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define THRESHOLD 90
#define BUFFER_SIZE 256

void check_disk_space() {
    FILE *fp;
    char buffer[BUFFER_SIZE];
    
    // Using `df` command to get disk space usage
    fp = popen("df -h", "r");
    if (fp == NULL) {
        perror("Failed to run command");
        exit(EXIT_FAILURE);
    }

    printf("Disk Space Usage:\n");
    printf("Filesystem     Size  Used Avail Use%% Mounted on\n");
    
    // Read the output a line at a time - output it.
    while (fgets(buffer, sizeof(buffer) - 1, fp) != NULL) {
        printf("%s", buffer);
        
        // Parse the output to check for the threshold
        char filesystem[50], size[10], used[10], avail[10], use_percent[10], mounted_on[50];
        if (sscanf(buffer, "%s %s %s %s %s %s", filesystem, size, used, avail, use_percent, mounted_on) == 6) {
            int usage;
            if (use_percent[strlen(use_percent) - 1] == '%') {
                use_percent[strlen(use_percent) - 1] = '\0'; // Remove the '%' character
            }
            usage = atoi(use_percent);
            if (usage >= THRESHOLD) {
                printf("Warning: %s mounted on %s is at %d%% usage!\n", filesystem, mounted_on, usage);
            }
        }
    }

    // Close the command stream
    pclose(fp);
}

void display_help() {
    printf("Disk Space Monitoring Utility\n");
    printf("Usage:\n");
    printf("  ./disk_space_monitor\n");
    printf("This program checks the disk space usage and alerts if usage exceeds %d%%.\n", THRESHOLD);
}

int main(int argc, char *argv[]) {
    if (argc > 1 && strcmp(argv[1], "--help") == 0) {
        display_help();
        return EXIT_SUCCESS;
    }

    printf("Starting disk space monitoring...\n");
    check_disk_space();

    printf("\nMonitoring complete. Exiting program.\n");
    return EXIT_SUCCESS;
}
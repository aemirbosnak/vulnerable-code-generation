//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/statvfs.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define BUF_SIZE 1024

int main() {
    FILE *fp;
    char buf[BUF_SIZE];
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int fd;
    struct statvfs statvfs;

    // Open the file for reading
    fp = fopen("/proc/meminfo", "r");
    if (fp == NULL) {
        printf("Error opening /proc/meminfo\n");
        exit(1);
    }

    // Read the file line by line
    while ((read = getline(&line, &len, fp))!= -1) {
        // Check if this line contains the total memory size
        if (strstr(line, "MemTotal:")!= NULL) {
            // Extract the value of total memory
            char *token = strtok(line, " ");
            int total_mem = atoi(token);

            // Open /proc/self/statm to get the current process's memory usage
            fd = open("/proc/self/statm", O_RDONLY);
            if (fd == -1) {
                printf("Error opening /proc/self/statm\n");
                exit(1);
            }

            // Get the current process's memory usage
            fstatvfs(fd, &statvfs);
            int process_mem = (int) (statvfs.f_frsize * statvfs.f_blocks);

            // Calculate the percentage of memory used by the current process
            int mem_percentage = (process_mem * 100) / total_mem;

            // Print the current process's memory usage
            printf("Current process memory usage: %d KB (%d%%)\n", process_mem, mem_percentage);

            // Close the file descriptor
            close(fd);
            break;
        }
    }

    // Close the file
    fclose(fp);
    return 0;
}
//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define MAX_CPU_NUM 64
#define FILENAME_BUFFER_SIZE 32
#define LINE_BUFFER_SIZE 256

int main(int argc, char *argv[]) {
    // Define variables to store current and previous CPU usage times for each core.
    long long currUsage[MAX_CPU_NUM];
    long long prevUsage[MAX_CPU_NUM];
    // Initialize arrays to contain zeroes.
    memset(currUsage, 0, MAX_CPU_NUM * sizeof(long long));
    memset(prevUsage, 0, MAX_CPU_NUM * sizeof(long long));

    // Use the command-line argument to specify the update interval for the program.
    int updateInterval = atoi(argv[1]);

    // Define an array to hold the filenames of the various CPU usage statistic files.
    char filenameBuffer[FILENAME_BUFFER_SIZE] = "/proc/stat";
    int cpuNum = 0;
    for(; cpuNum < MAX_CPU_NUM; cpuNum++) {
        snprintf(filenameBuffer + 9, FILENAME_BUFFER_SIZE - 9, "%d", cpuNum);
        int fd = open(filenameBuffer, O_RDONLY);
        if(fd != -1) {
            // Read the first line from the file to get the current CPU usage times.
            char lineBuffer[LINE_BUFFER_SIZE];
            int bytesRead = read(fd, lineBuffer, LINE_BUFFER_SIZE - 1);
            if(bytesRead > 0) {
                lineBuffer[bytesRead] = '\0';
                char *bufPtr = lineBuffer;
                // Skip the first token in the line, which is the word "cpu".
                strtok(bufPtr, " ");
                // Store the usage times for each core in the currUsage array.
                for(int i = 0; i < 10; i++) {
                    bufPtr = strtok(NULL, " ");
                    currUsage[cpuNum] += atoll(bufPtr);
                }
            }
            close(fd);
        } else {
            // No more CPU files found, so break out of the loop.
            break;
        }
    }

    // Continuously read the CPU usage statistic files at intervals specified by the user.
    while(1) {
        // Sleep for the specified interval.
        sleep(updateInterval);

        // Reset the cpuNum counter.
        cpuNum = 0;
        for(; cpuNum < MAX_CPU_NUM; cpuNum++) {
            snprintf(filenameBuffer + 9, FILENAME_BUFFER_SIZE - 9, "%d", cpuNum);
            int fd = open(filenameBuffer, O_RDONLY);
            if(fd != -1) {
                // Read the first line from the file to get the current CPU usage times.
                char lineBuffer[LINE_BUFFER_SIZE];
                int bytesRead = read(fd, lineBuffer, LINE_BUFFER_SIZE - 1);
                if(bytesRead > 0) {
                    lineBuffer[bytesRead] = '\0';
                    char *bufPtr = lineBuffer;
                    // Skip the first token in the line, which is the word "cpu".
                    strtok(bufPtr, " ");
                    long long totalUsage = 0;
                    // Store the usage times for each core in the currUsage array and calculate the total usage.
                    for(int i = 0; i < 10; i++) {
                        bufPtr = strtok(NULL, " ");
                        currUsage[cpuNum] += atoll(bufPtr);
                        totalUsage += currUsage[cpuNum] - prevUsage[cpuNum];
                        prevUsage[cpuNum] = currUsage[cpuNum];
                    }
                    // Calculate the usage percentage and print it to the console.
                    double usagePercent = ((double)totalUsage / (double)updateInterval) / 10000000;
                    printf("CPU %d usage: %.2f%%\n", cpuNum, usagePercent);
                }
                close(fd);
            } else {
                // No more CPU files found, so break out of the loop.
                break;
            }
        }
    }

    // Exit the program.
    return 0;
}
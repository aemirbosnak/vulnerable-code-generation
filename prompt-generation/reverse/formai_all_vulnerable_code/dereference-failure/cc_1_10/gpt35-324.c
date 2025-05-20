//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: creative
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void runSpeedTest(int fileSizeInMB) {
    // Define file size in bytes
    int fileSizeInBytes = fileSizeInMB * 1024 * 1024;
    
    // Generate random bytes to fill the file
    char *fileData = malloc(fileSizeInBytes);
    for (int i = 0; i < fileSizeInBytes; i++) {
        fileData[i] = rand() % 256;
    }
    
    // Write the data to a temporary file
    FILE *tempFile = fopen("temp.bin", "wb");
    fwrite(fileData, 1, fileSizeInBytes, tempFile);
    fclose(tempFile);
    
    // Measure the time it takes to read the file
    clock_t startTime = clock();
    FILE *file = fopen("temp.bin", "rb");
    fread(fileData, 1, fileSizeInBytes, file);
    fclose(file);
    clock_t endTime = clock();
    
    // Calculate the elapsed time and the speed in MB/s
    double elapsedTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;
    double speedInMBps = ((double)fileSizeInBytes / (1024 * 1024)) / elapsedTime;
    
    // Print the results
    printf("\nSpeed Test Results:\n");
    printf("File Size: %d MB\n", fileSizeInMB);
    printf("Elapsed Time: %.3f seconds\n", elapsedTime);
    printf("Speed: %.3f MB/s\n", speedInMBps);
    
    // Remove the temporary file
    remove("temp.bin");
}

int main() {
    int fileSizeInMB;
    printf("Welcome to the Internet Speed Test.\n");
    printf("Enter the file size to be used for the speed test (in megabytes): ");
    scanf("%d", &fileSizeInMB);
    
    runSpeedTest(fileSizeInMB);
    
    return 0;
}
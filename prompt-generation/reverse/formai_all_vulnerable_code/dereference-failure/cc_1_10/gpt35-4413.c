//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define BUFFER_SIZE 1024

void runSpeedTest() {
    // Generate random data for upload/download
    srand(time(NULL));
    char* data = (char*)malloc(BUFFER_SIZE*sizeof(char));
    for (int i=0; i<BUFFER_SIZE; i++) {
        data[i] = (char)(rand() % 256);
    }

    printf("\nStarting internet speed test...\n\n");

    // Measure upload speed
    printf("Uploading data...\n");
    clock_t startTime = clock();
    // simulate upload
    for (int i=0; i<10; i++) {
        printf("> %d%% complete\n", i*10);
        // send data to server (not implemented for simplicity)
    }
    clock_t endTime = clock();
    double uploadTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;
    printf("Upload finished in %.2f seconds\n", uploadTime);

    // Measure download speed
    printf("\nDownloading data...\n");
    startTime = clock();
    // simulate download
    for (int i=0; i<10; i++) {
        printf("> %d%% complete\n", i*10);
        // receive data from server (not implemented for simplicity)
    }
    endTime = clock();
    double downloadTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;
    printf("Download finished in %.2f seconds\n", downloadTime);

    // Calculate internet speed
    double uploadSpeed = (double)BUFFER_SIZE / uploadTime;
    double downloadSpeed = (double)BUFFER_SIZE / downloadTime;
    printf("\nYour internet speed is:\n");
    printf("Upload speed: %.2f Kbps\n", uploadSpeed*8/1000);
    printf("Download speed: %.2f Kbps\n", downloadSpeed*8/1000);

    free(data);
}

int main() {
    runSpeedTest();

    return 0;
}
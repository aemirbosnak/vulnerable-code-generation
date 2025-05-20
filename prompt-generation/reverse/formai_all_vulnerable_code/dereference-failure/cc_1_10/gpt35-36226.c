//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <sys/time.h>

#define TEST_SIZE 100000000 // bytes

double timedifference_msec(struct timeval t0, struct timeval t1)
{
    return (double)(t1.tv_sec - t0.tv_sec) * 1000.0 + (double)(t1.tv_usec - t0.tv_usec) / 1000.0;
}

int main()
{
    printf("Starting Internet Speed Test...\n");

    char buffer[100];
    int speedMbps;
    double elapsedTime;
    struct timeval t0, t1;

    // generate random file content
    srand(time(NULL));
    char* testData = (char*) malloc(TEST_SIZE);
    for(int i = 0; i < TEST_SIZE; i++) {
        testData[i] = rand() % 256;
    }

    // create test file
    FILE* testFile = fopen("testfile.dat", "wb");
    fwrite(testData, sizeof(char), TEST_SIZE, testFile);
    fclose(testFile);
    free(testData);

    // perform speed test
    gettimeofday(&t0, NULL);
    testFile = fopen("testfile.dat", "rb");
    while (fread(buffer, sizeof(char), 100, testFile)) {
        // do nothing
    }
    gettimeofday(&t1, NULL);
    fclose(testFile);

    // calculate download speed, round to nearest Mbps
    speedMbps = round(TEST_SIZE / timedifference_msec(t0, t1) * 8 / 1000000);
    printf("Your Internet Download Speed is: %d Mbps\n", speedMbps);
    remove("testfile.dat");

    return 0;
}
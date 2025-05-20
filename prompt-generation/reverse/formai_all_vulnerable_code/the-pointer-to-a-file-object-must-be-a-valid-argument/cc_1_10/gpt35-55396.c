//FormAI DATASET v1.0 Category: System administration ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *checkDiskSpace(void *arg);

int main()
{
    pthread_t tid;
    int err;
    int diskSpaceLimit = 1000000000; // 1 GB disk space limit

    err = pthread_create(&tid, NULL, &checkDiskSpace, (void *)&diskSpaceLimit);
    if (err != 0)
    {
        printf("Error creating thread!\n");
        exit(EXIT_FAILURE);
    }

    while (1)
    {
        // perform other tasks in the main thread
        printf("Performing other tasks in the main thread...\n");
        sleep(5);
    }

    return 0;
}

void *checkDiskSpace(void *arg)
{
    int *diskSpaceLimit = (int *)arg;
    while (1)
    {
        // get current disk space usage
        FILE *fp = popen("df -k / | awk '{print $4}'", "r");
        char buffer[10];
        fgets(buffer, sizeof(buffer), fp);

        int currentDiskSpace = atoi(buffer) * 1024; // convert from KB to bytes

        printf("Current disk space usage: %d bytes\n", currentDiskSpace);

        if (currentDiskSpace < *diskSpaceLimit)
        {
            // send alert message to system administrators
            printf("Sending alert message to system administrators...\n");
        }

        pclose(fp);

        sleep(10); // check disk space every 10 seconds
    }

    pthread_exit(NULL);
}
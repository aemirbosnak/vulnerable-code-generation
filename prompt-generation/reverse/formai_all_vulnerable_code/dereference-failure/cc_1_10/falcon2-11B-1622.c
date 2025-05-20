//Falcon2-11B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Helper function to move disk from source to destination
void moveDisk(int source, int destination, int *diskSize)
{
    printf("Move disk %d from rod %d to rod %d.\n", *diskSize, source, destination);
    *diskSize = *diskSize - 1;
}

// Helper function to print disk positions
void printDiskPositions(int diskSize)
{
    if (diskSize > 0)
    {
        printf("Rod 0: ");
        for (int i = 0; i < diskSize; i++)
            printf("%d ", i);
        printf("\n");
        printDiskPositions(diskSize - 1);
        printf("Rod 1: ");
        for (int i = 0; i < diskSize; i++)
            printf("%d ", i);
        printf("\n");
        printf("Rod 2: ");
        for (int i = 0; i < diskSize; i++)
            printf("%d ", i);
        printf("\n");
    }
}

int main()
{
    // Define disk sizes
    int n = 5;
    int *diskSize = (int*)malloc(sizeof(int));
    diskSize[0] = n;

    // Set initial positions
    printf("Initial positions:\n");
    printDiskPositions(n);

    // Move disks to the destination
    int source, destination;
    for (int i = 0; i < n; i++)
    {
        source = rand() % 3;
        destination = rand() % 3;
        if (source!= destination)
        {
            moveDisk(source, destination, diskSize);
        }
    }

    // Print final positions
    printf("Final positions:\n");
    printDiskPositions(n);

    return 0;
}
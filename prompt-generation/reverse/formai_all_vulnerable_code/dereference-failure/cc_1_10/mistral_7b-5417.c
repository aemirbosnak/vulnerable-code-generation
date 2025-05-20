//MISTRAL-7B DATASET v1.0 Category: Data mining ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_INT 2147483647

int main(int argc, char *argv[]) {
    int dataSize, i, mode, count = 0, maxCount = 0;
    int *dataSet;

    if (argc != 2) {
        printf("Usage : %s <Number of integers>\n", argv[0]);
        return -1;
    }

    dataSize = atoi(argv[1]);

    if (dataSize <= 0) {
        printf("Invalid data size\n");
        return -1;
    }

    dataSet = (int *)malloc(dataSize * sizeof(int));

    if (dataSet == NULL) {
        printf("Memory allocation failed\n");
        return -1;
    }

    printf("Enter %d integers:\n", dataSize);

    for (i = 0; i < dataSize; i++) {
        scanf("%d", &dataSet[i]);
    }

    mode = dataSet[0];
    count = 1;

    for (i = 1; i < dataSize; i++) {
        if (dataSet[i] == mode) {
            count++;
        } else {
            if (count > maxCount) {
                maxCount = count;
            }
            mode = dataSet[i];
            count = 1;
        }
    }

    if (count > maxCount) {
        maxCount = count;
        mode = dataSet[i];
    }

    printf("Mode : %d\n", mode);
    printf("Frequency : %d\n", maxCount);

    free(dataSet);
    return 0;
}
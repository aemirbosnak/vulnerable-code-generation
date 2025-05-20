//Falcon2-11B DATASET v1.0 Category: Threading Library Implementation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* sortThread(void* arg) {
    int* list = (int*)arg;
    int len = *((int*)arg+1);

    for (int i=0; i<len; i++) {
        for (int j=0; j<len-1; j++) {
            if (list[j] > list[j+1]) {
                int temp = list[j];
                list[j] = list[j+1];
                list[j+1] = temp;
            }
        }
    }

    return NULL;
}

int main() {
    int nums[] = {5, 3, 2, 1, 4};
    int len = sizeof(nums)/sizeof(nums[0]);
    pthread_t threads[len];

    int* args[len];

    for (int i=0; i<len; i++) {
        args[i] = malloc(sizeof(int) * 2);
        args[i][0] = nums;
        args[i][1] = len;
    }

    for (int i=0; i<len; i++) {
        pthread_create(&threads[i], NULL, sortThread, args[i]);
    }

    for (int i=0; i<len; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Sorted list: ");
    for (int i=0; i<len; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}
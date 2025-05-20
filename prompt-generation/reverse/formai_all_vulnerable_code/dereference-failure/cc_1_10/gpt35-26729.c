//FormAI DATASET v1.0 Category: Interprocess communication ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <string.h>
#define MAXSIZE 100

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++)      
  
    // Last i elements are already in place   
    for (j = 0; j < n-i-1; j++)
        if (arr[j] > arr[j+1])
            swap(&arr[j], &arr[j+1]);
}

int main() {
    int shmid;
    key_t key;
    int *shm, *s;
    int arr[MAXSIZE], n, i;

    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array:\n");

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bubbleSort(arr, n);

    /* make the key */
    if ((key = ftok("shared_memory.c", 'R')) == -1) {
        perror("ftok");
        exit(1);
    }

    /* connect to segment */
    if ((shmid = shmget(key, MAXSIZE, 0644 | IPC_CREAT)) == -1) {
        perror("shmget");
        exit(1);
    }

    /* attach to the segment to get a pointer to it: */
    shm = shmat(shmid, (void *)0, 0);
    if (*shm == -1) {
        perror("shmat");
        exit(1);
    }

    /* read or modify the segment */
    s = shm;
    for (i = 0; i < n; i++) {
        *s++ = arr[i]; 
    }

    *s = 0;

    /* detach from the segment: */
    if (shmdt(shm) == -1) {
        perror("shmdt");
        exit(1);
    }

    return 0;
}
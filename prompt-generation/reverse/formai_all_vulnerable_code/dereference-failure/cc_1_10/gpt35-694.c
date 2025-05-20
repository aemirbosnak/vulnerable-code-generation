//FormAI DATASET v1.0 Category: Sorting ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define SIZE 20

int arr[SIZE] = { 12, 54, 7, 23, 8, 45, 87, 34, 57, 67, 35, 14, 32, 76, 89, 43, 21, 9, 19, 27 };

void* sort(void* arg) {
    int* ptr = (int*)arg;
    int i, j, temp;

    for (i = 0; i < SIZE - 1; i++) {
        for (j = i + 1; j < SIZE; j++) {
            if (ptr[i] > ptr[j]) {
                temp = ptr[i];
                ptr[i] = ptr[j];
                ptr[j] = temp;
            }
        }
    }

    pthread_exit(NULL);
}

int main() {
    int i;
    int* subarr1 = malloc((SIZE / 2) * sizeof(int));
    int* subarr2 = malloc((SIZE / 2) * sizeof(int));

    pthread_t tid[2];

    for (i = 0; i < SIZE / 2; i++) {
        subarr1[i] = arr[i];
        subarr2[i] = arr[i + (SIZE / 2)];
    }

    pthread_create(&tid[0], NULL, sort, (void*)subarr1);
    pthread_create(&tid[1], NULL, sort, (void*)subarr2);

    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);

    int k = 0, l = 0;
    int sorted_arr[SIZE];

    for (i = 0; i < SIZE; i++) {
        if (subarr1[k] < subarr2[l]) {
            sorted_arr[i] = subarr1[k];
            k++;
        }
        else {
            sorted_arr[i] = subarr2[l];
            l++;
        }

        if (k == SIZE / 2) {
            for (int j = i + 1; j < SIZE; j++, l++)
                sorted_arr[j] = subarr2[l];

            break;
        }

        if (l == SIZE / 2) {
            for (int j = i + 1; j < SIZE; j++, k++)
                sorted_arr[j] = subarr1[k];

            break;
        }
    }

    printf("Sorted array: ");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", sorted_arr[i]);
    }

    printf("\n");

    free(subarr1);
    free(subarr2);

    return 0;
}
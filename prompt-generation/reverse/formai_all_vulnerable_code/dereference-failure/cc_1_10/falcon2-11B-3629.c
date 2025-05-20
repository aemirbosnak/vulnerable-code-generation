//Falcon2-11B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int size;
    int* data;
} Array;

Array* createArray(int size) {
    Array* array = malloc(sizeof(Array));
    array->size = size;
    array->data = calloc(size, sizeof(int));
    return array;
}

void deleteArray(Array* array) {
    free(array->data);
    free(array);
}

void printArray(Array* array) {
    for (int i = 0; i < array->size; i++) {
        printf("%d ", array->data[i]);
    }
    printf("\n");
}

int partition(Array* array, int left, int right) {
    int pivot = array->data[left];
    int i = left;
    int j = right + 1;
    
    while (i < j) {
        while (array->data[++i] < pivot);
        while (array->data[--j] > pivot);
        
        if (i < j) {
            int temp = array->data[i];
            array->data[i] = array->data[j];
            array->data[j] = temp;
        }
    }
    
    int temp = array->data[left];
    array->data[left] = array->data[j];
    array->data[j] = temp;
    
    return j;
}

void quickSort(Array* array, int left, int right) {
    if (left < right) {
        int p = partition(array, left, right);
        quickSort(array, left, p - 1);
        quickSort(array, p + 1, right);
    }
}

void kmeans(Array* data, int k, int* centers) {
    Array* clusters = createArray(k);
    for (int i = 0; i < k; i++) {
        clusters->data[i] = centers[i];
    }
    quickSort(clusters, 0, k - 1);
    for (int i = 0; i < data->size; i++) {
        int min_dist = 1000;
        int min_idx = -1;
        for (int j = 0; j < k; j++) {
            int dist = (int)sqrt((data->data[i] - centers[j]) * (data->data[i] - centers[j]));
            if (dist < min_dist) {
                min_dist = dist;
                min_idx = j;
            }
        }
        clusters->data[min_idx] += data->data[i];
        data->data[i] = min_idx;
    }
    printArray(data);
    printArray(clusters);
}

int main() {
    Array* data = createArray(10);
    for (int i = 0; i < 10; i++) {
        data->data[i] = rand() % 100;
    }
    printArray(data);
    
    int k = 3;
    int centers[k];
    for (int i = 0; i < k; i++) {
        centers[i] = rand() % 100;
    }
    printArray(centers);
    
    kmeans(data, k, centers);
    
    return 0;
}
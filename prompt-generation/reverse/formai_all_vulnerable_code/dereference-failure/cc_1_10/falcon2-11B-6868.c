//Falcon2-11B DATASET v1.0 Category: Greedy Algorithms ; Style: puzzling
//Greedy Algorithm Example Program in C
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

typedef struct {
    int start;
    int end;
    int index;
} Position;

int compare(const void* a, const void* b) {
    const Position* pos1 = (const Position*)a;
    const Position* pos2 = (const Position*)b;
    if(pos1->start < pos2->start)
        return -1;
    if(pos1->start > pos2->start)
        return 1;
    return 0;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quickSort(int* array, int left, int right) {
    if(left < right) {
        int pivot = array[(left + right) / 2];
        int i = left;
        int j = right;

        while(i < j) {
            while(array[i] < pivot)
                i++;
            while(array[j] > pivot)
                j--;
            if(i < j) {
                swap(&array[i], &array[j]);
                i++;
                j--;
            }
        }

        swap(&array[i], &array[j]);

        quickSort(array, left, j);
        quickSort(array, i, right);
    }
}

int main() {
    int array[] = {10, 8, 5, 12, 1, 9, 6, 11, 4, 7, 3};
    int n = sizeof(array)/sizeof(array[0]);
    srand(time(0));
    Position* positions = malloc(n * sizeof(Position));

    for(int i = 0; i < n; i++) {
        positions[i].start = rand() % 100;
        positions[i].end = rand() % 100;
        positions[i].index = i;
    }

    qsort(positions, n, sizeof(Position), compare);

    for(int i = 0; i < n; i++) {
        printf("%d %d %d\n", positions[i].start, positions[i].end, positions[i].index);
    }

    int* sorted = malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) {
        sorted[i] = array[positions[i].index];
    }

    qsort(sorted, n, sizeof(int), compare);

    for(int i = 0; i < n; i++) {
        printf("%d ", sorted[i]);
    }
    printf("\n");

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: secure
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 100

typedef struct {
    int value;
    int index;
} item;

void swap(item *a, item *b) {
    item temp = *a;
    *a = *b;
    *b = temp;
}

void sort(item *arr, int n) {
    int i, j;
    for(i=0; i<n-1; i++) {
        for(j=0; j<n-i-1; j++) {
            if(arr[j].value > arr[j+1].value) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    item arr[n];

    printf("Enter the items:\n");
    for(int i=0; i<n; i++) {
        printf("Value of item %d: ", i+1);
        scanf("%d", &arr[i].value);
        arr[i].index = i;
    }

    sort(arr, n);

    printf("Sorted items:\n");
    for(int i=0; i<n; i++) {
        printf("Item %d: Value %d\n", arr[i].index+1, arr[i].value);
    }

    return 0;
}
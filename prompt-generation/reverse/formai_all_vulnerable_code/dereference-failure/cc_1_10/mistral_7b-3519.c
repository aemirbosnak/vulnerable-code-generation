//MISTRAL-7B DATASET v1.0 Category: Greedy Algorithms ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#define MAX_ITEMS 50
#define MAX_CAPACITY 100

typedef struct {
    int id;
    int value;
    int weight;
} Item;

void swap(Item *a, Item *b) {
    Item temp = *a;
    *a = *b;
    *b = temp;
}

int partition(Item arr[], int low, int high) {
    int pivot = arr[high].value;
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].value > pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(Item arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    Item items[MAX_ITEMS];
    int n, capacity;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the details of items (%d):\n", n);
    for (int i = 0; i < n; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d%d", &items[i].id, &items[i].value);
        items[i].weight = items[i].value; // for simplicity, assuming value = weight
    }

    printf("Enter the knapsack capacity: ");
    scanf("%d", &capacity);

    quickSort(items, 0, n - 1);

    int result[MAX_ITEMS];
    int numItems = 0;

    for (int i = n - 1; i >= 0 && capacity > 0; i--) {
        if (capacity >= items[i].weight) {
            result[numItems++] = items[i].id;
            capacity -= items[i].weight;
        }
    }

    printf("Selected Items: ");
    for (int i = numItems - 1; i >= 0; i--) {
        printf("%d ", result[i]);
    }
    printf("\nTotal Value: %d", items[0].value + (sum(result, numItems)));

    return 0;
}

int sum(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}
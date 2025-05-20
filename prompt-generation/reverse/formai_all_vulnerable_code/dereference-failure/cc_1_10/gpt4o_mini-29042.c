//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100
#define MAX_ITEMS 1000
#define SWAP(a, b) { int t = a; a = b; b = t; }

void print_array(int arr[], int size);
void selection_sort(int arr[], int size);
void bubble_sort(int arr[], int size);
void insertion_sort(int arr[], int size);
void merge(int arr[], int left, int mid, int right);
void merge_sort(int arr[], int left, int right);
int partition(int arr[], int low, int high);
void quick_sort(int arr[], int low, int high);
void count_sort(int arr[], int size);
void validate_array(int arr[], int size);
char *get_sorting_algorithm(int choice);

int main() {
    int arr[MAX_ITEMS], size, choice;

    printf("Enter number of elements (max %d): ", MAX_ITEMS);
    scanf("%d", &size);
    if (size > MAX_ITEMS) {
        printf("Size exceeds maximum limit of %d.\n", MAX_ITEMS);
        return 1;
    }

    printf("Enter %d integers:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    validate_array(arr, size);

    printf("Choose sorting algorithm:\n");
    printf("1. Selection Sort\n");
    printf("2. Bubble Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. Merge Sort\n");
    printf("5. Quick Sort\n");
    printf("6. Counting Sort\n");
    printf("Enter your choice (1-6): ");
    scanf("%d", &choice);

    char *algorithm = get_sorting_algorithm(choice);
    printf("Sorting using %s...\n", algorithm);

    switch (choice) {
        case 1:
            selection_sort(arr, size);
            break;
        case 2:
            bubble_sort(arr, size);
            break;
        case 3:
            insertion_sort(arr, size);
            break;
        case 4:
            merge_sort(arr, 0, size - 1);
            break;
        case 5:
            quick_sort(arr, 0, size - 1);
            break;
        case 6:
            count_sort(arr, size);
            break;
        default:
            printf("Invalid choice!\n");
            return 1;
    }
    
    printf("Sorted array:\n");
    print_array(arr, size);
    return 0;
}

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selection_sort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        SWAP(arr[i], arr[min_index]);
    }
}

void bubble_sort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                SWAP(arr[j], arr[j + 1]);
            }
        }
    }
}

void insertion_sort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void merge(int arr[], int left, int mid, int right) {
    int i, j, k, n1 = mid - left + 1, n2 = right - mid;
    int L[MAX_LENGTH], R[MAX_LENGTH];
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0; j = 0; k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            SWAP(arr[i], arr[j]);
        }
    }
    SWAP(arr[i + 1], arr[high]);
    return (i + 1);
}

void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

void count_sort(int arr[], int size) {
    int output[MAX_ITEMS], count[MAX_LENGTH] = {0};

    for (int i = 0; i < size; i++)
        count[arr[i]]++;
    
    for (int i = 1; i < MAX_LENGTH; i++)
        count[i] += count[i - 1];

    for (int i = size - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (int i = 0; i < size; i++)
        arr[i] = output[i];
}

void validate_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] < 0 || arr[i] >= MAX_LENGTH) {
            printf("Array elements should be non-negative and less than %d.\n", MAX_LENGTH);
            exit(1);
        }
    }
}

char *get_sorting_algorithm(int choice) {
    switch (choice) {
        case 1: return "Selection Sort";
        case 2: return "Bubble Sort";
        case 3: return "Insertion Sort";
        case 4: return "Merge Sort";
        case 5: return "Quick Sort";
        case 6: return "Counting Sort";
        default: return "Unknown Algorithm";
    }
}
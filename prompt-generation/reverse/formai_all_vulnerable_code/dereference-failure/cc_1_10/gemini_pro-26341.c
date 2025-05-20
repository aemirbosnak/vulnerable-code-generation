//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

// Our fearless leader, the intrepid binary search algorithm
int binarySearch(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    while (low <= high) {
        // Divide and conquer, baby
        int mid = (low + high) / 2;
        if (target == arr[mid])
            return mid;
        else if (target < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1; // Target not found, bummer
}

// Just a friendly neighborhood linear search
int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        // Basic but effective
        if (target == arr[i])
            return i;
    }
    return -1; // Target not found, oh well
}

// Feeling fancy with interpolation search
int interpolationSearch(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    while (low <= high) {
        // A little bit smarter than binary search
        int pos = low + (((target - arr[low]) * (high - low)) / (arr[high] - arr[low]));
        if (target == arr[pos])
            return pos;
        else if (target < arr[pos])
            high = pos - 1;
        else
            low = pos + 1;
    }
    return -1; // Target not found, bummer
}

// A fun adventure with ternary search
int ternarySearch(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    while (low <= high) {
        // Divide, conquer, and think outside the box
        int mid1 = low + (high - low) / 3;
        int mid2 = high - (high - low) / 3;
        if (target == arr[mid1])
            return mid1;
        else if (target == arr[mid2])
            return mid2;
        else if (target < arr[mid1])
            high = mid1 - 1;
        else if (target > arr[mid2])
            low = mid2 + 1;
        else
            return -1; // Target not found, bummer
    }
    return -1; // Target not found, bummer
}

int main() {
    int n, target;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Let's create our very own array
    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Time to ignite the search engine!
    printf("Enter the target value: ");
    scanf("%d", &target);

    // Binary search, let's dive right in
    int binaryResult = binarySearch(arr, n, target);
    printf("Binary search result: ");
    binaryResult != -1 ? printf("Target found at index %d\n", binaryResult) : printf("Target not found\n");

    // Linear search, simple and straightforward
    int linearResult = linearSearch(arr, n, target);
    printf("Linear search result: ");
    linearResult != -1 ? printf("Target found at index %d\n", linearResult) : printf("Target not found\n");

    // Interpolation search, a touch of sophistication
    int interpolationResult = interpolationSearch(arr, n, target);
    printf("Interpolation search result: ");
    interpolationResult != -1 ? printf("Target found at index %d\n", interpolationResult) : printf("Target not found\n");

    // Ternary search, a clever twist
    int ternaryResult = ternarySearch(arr, n, target);
    printf("Ternary search result: ");
    ternaryResult != -1 ? printf("Target found at index %d\n", ternaryResult) : printf("Target not found\n");

    return 0;
}
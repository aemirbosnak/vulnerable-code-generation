//GEMINI-pro DATASET v1.0 Category: Sorting ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

// Let's picture a romantic dance of sorting a bouquet of hearts.
// Each heart is a number, and we'll use the merge sort algorithm.

// Divide the bouquet into smaller bunches.
void divide(int hearts[], int left, int right) {
    if (left >= right) return; // Base case: a single heart
    
    // Find the suitor's heart.
    int mid = (left + right) / 2;
    
    // Recursively divide the bunches.
    divide(hearts, left, mid);
    divide(hearts, mid + 1, right);
}

// Merge the bunches into a graceful arrangement.
void merge(int hearts[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = 0;
    int *temp = (int *)malloc((right - left + 1) * sizeof(int)); // A temporary dance floor
    
    // Gracefully weave the hearts together.
    while (i <= mid && j <= right) {
        if (hearts[i] <= hearts[j]) temp[k++] = hearts[i++];
        else                     temp[k++] = hearts[j++];
    }
    
    // Gather any remaining hearts.
    while (i <= mid) temp[k++] = hearts[i++];
    while (j <= right) temp[k++] = hearts[j++];
    
    // Copy the hearts back into the original bouquet.
    for (i = left; i <= right; i++)
        hearts[i] = temp[i - left];
    free(temp); // Return the dance floor
}

// Let's begin the graceful dance of sorting.
void merge_sort(int hearts[], int left, int right) {
    divide(hearts, left, right);
    merge(hearts, left, (left + right) / 2, right);
}

// Display the sorted bouquet of hearts.
void display(int hearts[], int size) {
    printf("Your sorted bouquet of hearts: ");
    for (int i = 0; i < size; i++)
        printf(" %d", hearts[i]);
    printf("\n");
}

// Let's create a bouquet of hearts.
int main() {
    int num_hearts;
    int hearts[] = { 8, 4, 3, 1, 5, 9, 2, 6, 7 };
    num_hearts = sizeof(hearts) / sizeof(int);
    
    printf("Unsorted bouquet of hearts: ");
    for (int i = 0; i < num_hearts; i++)
        printf(" %d", hearts[i]);
    printf("\n\n");
    
    // Begin the dance of sorting.
    merge_sort(hearts, 0, num_hearts - 1);
    display(hearts, num_hearts);
    
    return 0;
}
//FormAI DATASET v1.0 Category: Memory Game ; Style: configurable
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Function to shuffle the array
void shuffle(int *arr, int n) {
    srand(time(NULL));
    for(int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main() {
    int n, count = 0, attempts = 0;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    if(n%2 != 0) {
        printf("Number of elements should be even.\n");
        return 0;
    }
    int arr[n];
    for(int i = 0; i < n/2; i++) {
        arr[i] = i + 1; // First half of array
        arr[i + n/2] = i + 1; // Second half of array
    }
    shuffle(arr, n);
    int temp[n];
    for(int i = 0; i < n; i++) {
        temp[i] = 0; // All elements are initially hidden
    }
    // Game loop
    while(count < n/2) {
        printf("Attempts: %d\n", attempts);
        // Display the current state of the array
        for(int i = 0; i < n; i++) {
            if(temp[i] == 0) { // Element is hidden
                printf(" * ");
            } else { // Element is revealed
                printf("%2d ", arr[i]);
            }
        }
        printf("\n");
        // Get user input
        int index1, index2;
        printf("Enter two different indices to reveal (1 - %d): ", n);
        scanf("%d %d", &index1, &index2);
        index1--; index2--; // Converting to 0-based indices for array
        // Check if valid indices are entered
        if(index1 < 0 || index1 >= n || index2 < 0 || index2 >= n || index1 == index2) {
            printf("Invalid indices entered. Try again.\n");
            continue;
        }
        // Check if both elements are same
        if(arr[index1] == arr[index2]) {
            temp[index1] = 1; // Reveal first element
            temp[index2] = 1; // Reveal second element
            count++; // Increment the count of matched elements
            printf("Match found.\n");
        } else {
            printf("No match found.\n");
        }
        attempts++; // Increment the number of attempts
    }
    printf("Game completed in %d attempts.\n", attempts);
    return 0;
}
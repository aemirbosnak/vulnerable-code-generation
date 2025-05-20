//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: happy
#include <stdio.h>
#include <stdlib.h>

// Function to generate an array of happy numbers
void generateHappyNumbers(int* array, int size) {
    int count = 0;
    int num = 1;
    while (count < size) {
        int n = num;
        int visited[100] = {0};  // Array to keep track of visited numbers
        while (n != 1 && !visited[n]) {
            visited[n] = 1; // Mark the number as visited
            n = 0;
            while (num > 0) {
                int digit = num % 10;
                n += digit * digit;
                num /= 10;
            }
            num = n;  // Update num to check next number
        }
        if (n == 1) {
            array[count++] = count + 1;  // Store happy number in array
        }
        num++;
    }
}

// Binary Search Function
int happyBinarySearch(int* array, int size, int target) {
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (array[mid] == target) {
            return mid;  // Target found
        }
        if (array[mid] < target) {
            left = mid + 1;  // Move right
        } else {
            right = mid - 1;  // Move left
        }
    }
    return -1;  // Target not found
}

int main() {
    int size = 20; // Size of the happy numbers array
    int* happyNumbers = (int*)malloc(size * sizeof(int));
    generateHappyNumbers(happyNumbers, size);
    
    printf("Hooray! We've generated the first %d happy numbers:\n", size);
    for (int i = 0; i < size; i++) {
        printf("%d ", happyNumbers[i]);
    }
    printf("\n\n");

    int target;
    printf("Enter a happy number to search for (between 1 and %d): ", size);
    scanf("%d", &target);

    int result = happyBinarySearch(happyNumbers, size, target);
    
    if (result != -1) {
        printf("Yay! Happy number %d found at index %d!\n", target, result);
    } else {
        printf("Oh no! Happy number %d is not present in our list.\n", target);
    }

    free(happyNumbers);  // Free dynamically allocated memory
    printf("Thank you for playing with us! Have a wonderful day!\n");
    
    return 0; // Happy programming!
}
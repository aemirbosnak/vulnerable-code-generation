//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: happy
#include <stdio.h>
#include <stdlib.h>

void print_welcome_message() {
    printf("🎉 Welcome to the Happy Searching Program! 🎉\n");
    printf("Let's find your favorite number in a delightful array!\n\n");
}

void print_array(const int *arr, int size) {
    printf("✨ Here's the magical array of numbers: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("✨\n");
}

int extended_linear_search(const int *arr, int size, int target) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            count++;
            printf("😊 Found %d at index %d! Keep shining! ✨\n", target, i);
        }
    }
    return count;
}

void display_result(int target, int occurrences) {
    if (occurrences > 0) {
        printf("\n🎉 Hooray! The number %d appears %d times in the array! 🎊\n", target, occurrences);
    } else {
        printf("\n😢 Oops! The number %d was not found in the array. Better luck next time! 🌈\n", target);
    }
}

int main() {
    print_welcome_message();

    int size = 10;
    int *numbers = (int *)malloc(size * sizeof(int));

    // Generating a magical array of numbers
    printf("🪄 Generating the array...\n");
    for (int i = 0; i < size; i++) {
        numbers[i] = rand() % 10; // Random numbers between 0 and 9
    }

    print_array(numbers, size);

    int target;
    printf("\nWhat number would you like to search for? (0-9): ");
    scanf("%d", &target);

    // Searching for the target number in the magical array
    int occurrences = extended_linear_search(numbers, size, target);

    // Displaying the final result
    display_result(target, occurrences);

    // Clean up
    free(numbers);
    printf("\n🎊 Thank you for using the Happy Searching Program! Have a wonderful day! 🌟\n");

    return 0;
}
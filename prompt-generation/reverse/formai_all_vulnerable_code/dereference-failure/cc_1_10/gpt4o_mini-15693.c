//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Prototype declaration of the sorting function
void fruit_sort(int *arr, int n);
void print_fruit_fiasco(int *arr, int n);
const char* fruit_name(int num);

int main() {
    srand(time(NULL)); // Initialize random seed

    int n = 10; // We'll have a crazy crew of 10 fruits
    int *fruits = malloc(n * sizeof(int)); // Memory allocation for fruits

    // Generate random fruit weights (1 to 100)
    printf("Gathering the fruits for the grand fruit sorting fiesta!\n");
    for (int i = 0; i < n; i++) {
        fruits[i] = rand() % 100 + 1; // Strong fruits weighing random amounts!
        printf("Fruit %d weighs %d units of fruitiness!\n", i + 1, fruits[i]);
    }

    printf("\n\nLet's get ready to SORT some FRUITS!\n\n");

    // Show the fruit fiasco
    print_fruit_fiasco(fruits, n);

    // Sorting the fruits by their weights
    fruit_sort(fruits, n);

    // Show the sorted fruits
    printf("\nAnd the fruits have been ordered by weight!\n\n");
    print_fruit_fiasco(fruits, n);

    free(fruits); // Freeing memory
    return 0;
}

// This function sorts the fruits as if they are competing in a silly race!
void fruit_sort(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // Checking if we need to swap appetizers!
            if (arr[j] > arr[j + 1]) {
                // They are competing
                printf("%s (%d units) and %s (%d units) swap places!\n",
                        fruit_name(arr[j]), arr[j],
                        fruit_name(arr[j + 1]), arr[j + 1]);
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Print the chaos of fruits from the contest
void print_fruit_fiasco(int *arr, int n) {
    printf("Current fruit order: \n");

    for (int i = 0; i < n; i++) {
        printf("%s (%d units) ", fruit_name(arr[i]), arr[i]);
    }
    printf("\n\n");
}

// Function to get fruit names based on their weights
const char* fruit_name(int num) {
    switch (num % 5) {
        case 0: return "Apple";
        case 1: return "Banana";
        case 2: return "Cherry";
        case 3: return "Date";
        case 4: return "Elderberry";
        default: return "Mystery Fruit"; // Just in case!
    }
}
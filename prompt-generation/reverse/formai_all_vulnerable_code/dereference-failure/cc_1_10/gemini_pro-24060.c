//GEMINI-pro DATASET v1.0 Category: Sorting ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 100
#define MAX_NUM_STRS 1000

int main() {
    // Get the number of strings to sort
    int num_strs;
    printf("Enter the number of strings to sort: ");
    scanf("%d", &num_strs);

    // Check if the number of strings is valid
    if (num_strs <= 0 || num_strs > MAX_NUM_STRS) {
        printf("Invalid number of strings: %d\n", num_strs);
        return 1;
    }

    // Allocate memory for the strings
    char **strs = (char **)malloc(num_strs * sizeof(char *));
    if (strs == NULL) {
        printf("Error allocating memory for strings\n");
        return 1;
    }

    // Get the strings from the user
    for (int i = 0; i < num_strs; i++) {
        // Allocate memory for the string
        strs[i] = (char *)malloc(MAX_STR_LEN * sizeof(char));
        if (strs[i] == NULL) {
            printf("Error allocating memory for string %d\n", i);
            return 1;
        }

        // Get the string from the user
        printf("Enter string %d: ", i);
        scanf("%s", strs[i]);
    }

    // Sort the strings
    qsort(strs, num_strs, sizeof(char *), strcmp);

    // Print the sorted strings
    printf("Sorted strings:\n");
    for (int i = 0; i < num_strs; i++) {
        printf("%s\n", strs[i]);
    }

    // Free the memory allocated for the strings
    for (int i = 0; i < num_strs; i++) {
        free(strs[i]);
    }
    free(strs);

    return 0;
}
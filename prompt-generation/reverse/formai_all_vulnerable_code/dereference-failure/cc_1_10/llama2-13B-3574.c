//LLAMA2-13B DATASET v1.0 Category: Sorting ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STRLEN 100

// Structure to store the list of strings to be sorted
typedef struct {
    char *str;
    size_t len;
} str_list_t;

// Function to sort the list of strings using c-style sorting
void sort_str_list(str_list_t *list) {
    size_t i, j, min_idx;
    char *temp;

    // Loop through the list of strings
    for (i = 0; i < list->len; i++) {
        // Find the smallest index
        min_idx = i;
        for (j = i + 1; j < list->len; j++) {
            if (strcmp(list->str[j], list->str[min_idx]) < 0) {
                min_idx = j;
            }
        }

        // Swap the strings
        temp = list->str[min_idx];
        list->str[min_idx] = list->str[i];
        list->str[i] = temp;
    }
}

int main() {
    str_list_t list = {0};
    char *str_arr[5] = {"hello", "world", "abc", "def", "ghi"};

    // Initialize the list with the given array of strings
    for (size_t i = 0; i < sizeof(str_arr) / sizeof(char *); i++) {
        list.str[i] = str_arr[i];
        list.len = i + 1;
    }

    // Sort the list of strings
    sort_str_list(&list);

    // Print the sorted list of strings
    for (size_t i = 0; i < list.len; i++) {
        printf("%s\n", list.str[i]);
    }

    return 0;
}
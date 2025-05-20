//LLAMA2-13B DATASET v1.0 Category: Searching algorithm ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 25
#define MAX_WORD_LENGTH 10

// Structure to store the search results
typedef struct {
    char name[MAX_NAME_LENGTH];
    char word[MAX_WORD_LENGTH];
} search_result_t;

// Function to perform the search
search_result_t* search(char* haystack, char* needle) {
    // Initialize the search result structure
    search_result_t* result = (search_result_t*)malloc(sizeof(search_result_t));
    result->name[0] = '\0';
    result->word[0] = '\0';

    // Iterate through the haystack
    for (int i = 0; haystack[i] != '\0'; i++) {
        // Check if the current character is the needle
        if (haystack[i] == needle[0]) {
            // Found the needle, calculate the position
            int j = i;
            while (haystack[j] != '\0' && haystack[j] != needle[0]) {
                j++;
            }
            int position = j - i;

            // Store the result
            strncpy(result->name, haystack + i, position);
            result->name[position] = '\0';
            strncpy(result->word, needle, 1);
            result->word[1] = '\0';
            return result;
        }
    }

    // Not found, return an empty structure
    result->name[0] = '\0';
    result->word[0] = '\0';
    return result;
}

int main() {
    // Test cases
    char haystack1[] = "The quick brown fox jumps over the lazy dog";
    char needle1[] = "quick";
    char haystack2[] = "The big black cat purred contentedly on my lap";
    char needle2[] = "black";

    // Perform the search
    search_result_t* result1 = search(haystack1, needle1);
    search_result_t* result2 = search(haystack2, needle2);

    // Print the results
    printf("Found %s in %s\n", result1->word, result1->name);
    printf("Found %s in %s\n", result2->word, result2->name);

    // Free the memory
    free(result1);
    free(result2);

    return 0;
}
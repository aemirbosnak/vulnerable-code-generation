//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Linus Torvalds style searching algorithm

int main(int argc, char *argv[])
{
    // Check if the user provided enough arguments
    if (argc < 3) {
        fprintf(stderr, "Usage: %s target string\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the target string from the command line
    char *target = argv[1];
    int target_len = strlen(target);

    // Get the string to search from the command line
    char *string = argv[2];
    int string_len = strlen(string);

    // Check if the target string is longer than the string to search
    if (target_len > string_len) {
        fprintf(stderr, "Target string is longer than string to search\n");
        return EXIT_FAILURE;
    }

    // Initialize the search index
    int index = 0;

    // Loop through the string to search
    while (index + target_len - 1 < string_len) {
        // Check if the target string matches the substring at the current index
        if (strncmp(target, string + index, target_len) == 0) {
            // Print the index of the match
            printf("Match found at index %d\n", index);

            // Increment the search index by the length of the target string
            index += target_len;
        } else {
            // Increment the search index by 1
            index++;
        }
    }

    // Check if no match was found
    if (index + target_len - 1 >= string_len) {
        printf("No match found\n");
    }

    return EXIT_SUCCESS;
}
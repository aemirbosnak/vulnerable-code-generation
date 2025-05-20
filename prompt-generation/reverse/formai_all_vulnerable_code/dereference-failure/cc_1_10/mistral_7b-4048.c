//MISTRAL-7B DATASET v1.0 Category: Benchmarking ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1024

int main(int argc, char *argv[]) {
    char *str1 = NULL;
    char *str2 = NULL;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <string1> <string2>\n", argv[0]);
        return 1;
    }

    // Check string lengths
    size_t len1 = strlen(argv[1]);
    size_t len2 = strlen(argv[2]);

    if (len1 > MAX_LENGTH || len2 > MAX_LENGTH) {
        fprintf(stderr, "Error: Input strings too long.\n");
        return 1;
    }

    // Allocate memory for strings
    str1 = (char *) malloc((len1 + 1) * sizeof(char));
    str2 = (char *) malloc((len2 + 1) * sizeof(char));

    if (!str1 || !str2) {
        fprintf(stderr, "Error: Failed to allocate memory.\n");
        free(str2);
        free(str1);
        return 1;
    }

    // Copy command-line arguments to allocated memory
    strncpy(str1, argv[1], len1 + 1);
    strncpy(str2, argv[2], len2 + 1);

    // Perform secure string comparison
    int result = memcmp(str1, str2, len1 > len2 ? len1 : len2);

    // Free allocated memory
    free(str1);
    free(str2);

    // Print comparison result
    if (result < 0) {
        printf("%s is less than %s\n", argv[1], argv[2]);
    } else if (result > 0) {
        printf("%s is greater than %s\n", argv[1], argv[2]);
    } else {
        printf("%s is equal to %s\n", argv[1], argv[2]);
    }

    return 0;
}
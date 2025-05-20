//GEMINI-pro DATASET v1.0 Category: Sorting ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 100

int compare_strings(const void *a, const void *b) {
    const char *s1 = (const char *)a;
    const char *s2 = (const char *)b;
    return strcmp(s1, s2);
}

int main() {
    char **strings;
    int num_strings;
    char *input_string;
    size_t input_size = MAX_STR_LEN;
    ssize_t line_len;

    // Get the number of strings
    printf("Enter the number of strings to sort: ");
    scanf("%d", &num_strings);

    // Allocate memory for the strings
    strings = malloc(num_strings * sizeof(char *));
    if (strings == NULL) {
        fprintf(stderr, "Error allocating memory for strings\n");
        return 1;
    }

    // Get the strings from the user
    for (int i = 0; i < num_strings; i++) {
        printf("Enter string %d: ", i + 1);
        input_size = MAX_STR_LEN;
        line_len = getline(&input_string, &input_size, stdin);
        if (line_len == -1) {
            fprintf(stderr, "Error reading string %d\n", i + 1);
            return 1;
        }
        strings[i] = malloc(line_len + 1);
        if (strings[i] == NULL) {
            fprintf(stderr, "Error allocating memory for string %d\n", i + 1);
            return 1;
        }
        strcpy(strings[i], input_string);
    }

    // Sort the strings
    qsort(strings, num_strings, sizeof(char *), compare_strings);

    // Print the sorted strings
    printf("Sorted strings:\n");
    for (int i = 0; i < num_strings; i++) {
        printf("%s", strings[i]);
    }

    // Free the memory allocated for the strings
    for (int i = 0; i < num_strings; i++) {
        free(strings[i]);
    }
    free(strings);
    free(input_string);

    return 0;
}
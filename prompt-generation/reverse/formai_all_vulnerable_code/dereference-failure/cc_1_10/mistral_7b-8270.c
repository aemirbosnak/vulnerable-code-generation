//MISTRAL-7B DATASET v1.0 Category: Memory management ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN_SIZE 10

int main() {
    size_t capacity = MIN_SIZE;
    size_t num_strings = 0;
    size_t total_length = 0;
    char **strings = calloc(capacity, sizeof(char *));

    if (strings == NULL) {
        fprintf(stderr, "Failed to allocate memory for strings\n");
        return 1;
    }

    while (1) {
        char str[100];
        printf("Enter a string (or type 'quit' to exit): ");
        fgets(str, sizeof(str), stdin);

        if (strlen(str) > 0 && strlen(str) < sizeof(str) - 1) {
            size_t len = strlen(str) + 1;
            strings[num_strings] = realloc(strings, (capacity + 1) * sizeof(char *));
            strings[num_strings][len - 1] = '\0';
            strcpy(strings[num_strings], str);
            total_length += len;
            num_strings++;

            if (num_strings >= capacity) {
                capacity *= 2;
                strings = realloc(strings, capacity * sizeof(char *));
            }
        } else if (strcmp(str, "quit") == 0) {
            break;
        } else {
            printf("Invalid input. Please try again.\n");
        }
    }

    printf("Total number of strings: %zu\n", num_strings);
    printf("Total length of all strings: %zu\n", total_length);

    for (size_t i = 0; i <= num_strings; i++) {
        free(strings[i]);
    }
    free(strings);

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Memory management ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define our custom memory management functions
void *my_malloc(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        printf("Error: Out of memory!\n");
        exit(1);
    }
    return ptr;
}

void my_free(void *ptr) {
    free(ptr);
}

// Define our custom string manipulation functions
char *my_strdup(const char *str) {
    size_t len = strlen(str) + 1;
    char *dup = my_malloc(len);
    strcpy(dup, str);
    return dup;
}

char *my_strcat(char *dest, const char *src) {
    size_t dest_len = strlen(dest);
    size_t src_len = strlen(src);
    size_t new_len = dest_len + src_len + 1;
    char *new_str = my_malloc(new_len);
    strcpy(new_str, dest);
    strcat(new_str, src);
    free(dest);
    return new_str;
}

// Define our main function
int main() {
    // Allocate some memory
    char *str1 = my_strdup("Hello");
    char *str2 = my_strdup("World");

    // Concatenate the strings
    char *result = my_strcat(str1, " ");
    result = my_strcat(result, str2);

    // Print the result
    printf("%s\n", result);

    // Free the memory
    my_free(str1);
    my_free(str2);
    my_free(result);

    return 0;
}
//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_LEN 1024
#define ERR_MSG "Error: %s\n"

void handle_error(const char* func_name, const char* err_msg) {
    printf("Error in %s(): %s\n", func_name, err_msg);
    if (err_msg) {
        printf("Error details: %s\n", err_msg);
    }
    exit(EXIT_FAILURE);
}

int main() {
    char* buffer = NULL;
    size_t len = 0;

    // Try to allocate a buffer with a too-small size
    buffer = malloc(5);
    if (!buffer) {
        handle_error("main", "Failed to allocate buffer");
    }

    // Try to access an invalid index in the buffer
    buffer[6] = 'a';
    if (buffer[6] != '\0') {
        handle_error("main", "Attempted to access invalid index");
    }

    // Try to free an uninitialized buffer
    free(buffer);
    if (buffer != NULL) {
        handle_error("main", "Attempted to free uninitialized buffer");
    }

    // Try to concatenate two strings with a null pointer
    char* str1 = "Hello";
    char* str2 = NULL;
    strcat(str1, str2);
    if (str1[0] != '\0') {
        handle_error("main", "Attempted to concatenate with null pointer");
    }

    // Try to access a null pointer
    char* str3 = NULL;
    printf("%c", str3[0]);
    if (str3 != NULL) {
        handle_error("main", "Attempted to access null pointer");
    }

    return 0;
}
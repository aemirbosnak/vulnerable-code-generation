//Falcon-180B DATASET v1.0 Category: Memory management ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

typedef struct {
    char *string;
    int length;
} string_t;

// Function prototypes
void *my_malloc(size_t size);
void my_free(void *ptr);
string_t *my_strdup(const char *str);

int main() {
    string_t *str1, *str2;

    // Allocate memory for string1
    str1 = my_strdup("Hello World!");

    // Print string1
    printf("String 1: %s\n", str1->string);

    // Allocate memory for string2
    str2 = my_strdup("Goodbye World!");

    // Print string2
    printf("String 2: %s\n", str2->string);

    // Free memory for string1
    my_free(str1);

    // Print string1 again (should be NULL)
    printf("String 1: %s\n", str1->string);

    // Free memory for string2
    my_free(str2);

    // Print string2 again (should be NULL)
    printf("String 2: %s\n", str2->string);

    return 0;
}

// Our custom malloc function
void *my_malloc(size_t size) {
    void *ptr;

    // Allocate memory using the system malloc function
    if ((ptr = malloc(size)) == NULL) {
        fprintf(stderr, "Error: Out of memory!\n");
        exit(1);
    }

    // Initialize the memory to all zeros
    memset(ptr, 0, size);

    return ptr;
}

// Our custom free function
void my_free(void *ptr) {
    free(ptr);
}

// Our custom strdup function
string_t *my_strdup(const char *str) {
    string_t *new_str;

    // Allocate memory for the new string
    if ((new_str = my_malloc(sizeof(string_t))) == NULL) {
        return NULL;
    }

    // Copy the string into the new memory
    if ((new_str->string = my_strdup(str)) == NULL) {
        my_free(new_str);
        return NULL;
    }

    // Set the length of the new string
    new_str->length = strlen(str);

    return new_str;
}
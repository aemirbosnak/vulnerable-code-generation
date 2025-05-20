//Falcon-180B DATASET v1.0 Category: Memory management ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of strings to store
#define MAX_STRINGS 100

// Define the structure of a string with its length
typedef struct {
    char *str;
    int len;
} string_t;

// Define the structure of the memory manager
typedef struct {
    string_t *strings;
    int num_strings;
    int capacity;
} mem_manager_t;

// Initialize the memory manager with the given capacity
void init_mem_manager(mem_manager_t *mm, int capacity) {
    mm->strings = (string_t *) malloc(capacity * sizeof(string_t));
    mm->num_strings = 0;
    mm->capacity = capacity;
}

// Free the memory used by the memory manager
void free_mem_manager(mem_manager_t *mm) {
    free(mm->strings);
}

// Add a string to the memory manager
void add_string(mem_manager_t *mm, char *str, int len) {
    if (mm->num_strings >= mm->capacity) {
        printf("Error: Memory manager is full.\n");
        return;
    }

    mm->strings[mm->num_strings].str = str;
    mm->strings[mm->num_strings].len = len;
    mm->num_strings++;
}

// Print all the strings in the memory manager
void print_strings(mem_manager_t *mm) {
    for (int i = 0; i < mm->num_strings; i++) {
        printf("%s (%d)\n", mm->strings[i].str, mm->strings[i].len);
    }
}

// Main function
int main() {
    // Initialize the memory manager with a capacity of 10 strings
    mem_manager_t mm;
    init_mem_manager(&mm, 10);

    // Add some strings to the memory manager
    add_string(&mm, "Hello", 5);
    add_string(&mm, "World", 5);
    add_string(&mm, "Ephemeral", 9);
    add_string(&mm, "Programming", 11);

    // Print all the strings in the memory manager
    print_strings(&mm);

    // Free the memory used by the memory manager
    free_mem_manager(&mm);

    return 0;
}
//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_SIZE 100

void check_memory(void *ptr) {
    if (ptr == NULL) {
        fprintf(stderr, "Memory allocation failed: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
}

void read_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Unexpected: Could not open file %s: %s\n", filename, strerror(errno));
        exit(EXIT_FAILURE);
    }

    char line[MAX_SIZE];
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("Read line: %s", line);
    }

    if (ferror(file)) {
        fprintf(stderr, "Whoa! Error reading from file %s: %s\n", filename, strerror(errno));
    }

    fclose(file);
}

char* allocate_buffer(size_t size) {
    char *buffer = (char *)malloc(size);
    check_memory(buffer);
    return buffer;
}

void surprise_function(int condition) {
    if (condition == 0) {
        fprintf(stderr, "Surprise! Condition failed, returning!\n");
        return;
    } 
    printf("No surprise here, condition met: %d\n", condition);
}

int main() {
    printf("Let's dive into some file magic!\n");

    const char *filename = "example.txt";
    printf("Attempting to read from a file: %s\n", filename);
    read_file(filename);

    printf("\nNow, let's allocate some memory for our buffer!\n");
    char *buffer = allocate_buffer(MAX_SIZE);
    snprintf(buffer, MAX_SIZE, "Surprise! I've got a buffer to play with!\n");
    printf("%s", buffer);

    printf("\nTesting a surprise function now...\n");
    int test_condition = 0; // Change to 1 to test the successful condition
    surprise_function(test_condition);

    printf("\nAll done! Freeing buffer...\n");
    free(buffer);

    printf("Execution completed successfully, who would've thought?!\n");
    return EXIT_SUCCESS;
}
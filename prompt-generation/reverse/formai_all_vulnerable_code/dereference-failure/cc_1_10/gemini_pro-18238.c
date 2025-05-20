//GEMINI-pro DATASET v1.0 Category: Error handling ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

// This function gracefully handles a file open error.
FILE *open_file(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    return fp;
}

// This function gracefully handles a memory allocation error.
void *allocate_memory(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        perror("Error allocating memory");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

// This function gracefully handles a division by zero error.
int divide(int a, int b) {
    if (b == 0) {
        fprintf(stderr, "Error: division by zero\n");
        exit(EXIT_FAILURE);
    }
    return a / b;
}

// This function gracefully handles an invalid input error.
int get_valid_input(int *input) {
    if (scanf("%d", input) != 1) {
        fprintf(stderr, "Error: invalid input\n");
        exit(EXIT_FAILURE);
    }
    return *input;
}

int main(void) {
    // Let's open a file with gratitude.
    FILE *fp = open_file("input.txt");
    printf("Thank you for opening the file, %s!\n", fp);

    // Let's allocate some memory with gratitude.
    void *ptr = allocate_memory(1024);
    printf("Thank you for allocating the memory, %p!\n", ptr);

    // Let's divide two numbers with gratitude.
    int result = divide(10, 2);
    printf("Thank you for dividing the numbers, %d!\n", result);

    // Let's get a valid input with gratitude.
    int input;
    get_valid_input(&input);
    printf("Thank you for providing the valid input, %d!\n", input);

    // Let's close the file with gratitude.
    fclose(fp);
    printf("Thank you for closing the file, %s!\n", fp);

    // Let's free the memory with gratitude.
    free(ptr);
    printf("Thank you for freeing the memory, %p!\n", ptr);

    return EXIT_SUCCESS;
}
//FormAI DATASET v1.0 Category: Error handling ; Style: enthusiastic
// This program is going to throw a lot of errors
// But don't worry, we're going to handle them like champs!
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    printf("Welcome to the error handling program!\n");

    // Let's start by trying to open a file that doesn't exist
    FILE *fp;
    fp = fopen("non_existent_file.txt", "r");
    if(fp == NULL) {
        fprintf(stderr, "Error opening file: non_existent_file.txt\n");
        perror("Error");
    }
    printf("File opened successfully!\n");

    // Now let's try dividing by zero
    int a = 10, b = 0;
    int c;
    if(b == 0) {
        fprintf(stderr, "Error: division by zero\n");
        perror("Error");
    } else {
        c = a/b;
        printf("Result of division: %d\n", c);
    }

    // Let's also try to allocate memory that we don't have
    int *ptr;
    ptr = (int*) malloc(100000000 * sizeof(int));
    if(ptr == NULL) {
        fprintf(stderr, "Error: could not allocate memory\n");
        perror("Error");
    } else {
        printf("Memory allocation successful!\n");
    }

    // Finally, let's try to execute a command that doesn't exist
    int result = system("non_existent_command");
    if(result == -1) {
        fprintf(stderr, "Error executing command: non_existent_command\n");
        perror("Error");
    } else {
        printf("Command executed successfully!\n");
    }

    printf("Thanks for running the error handling program!\n");

    return 0;
}
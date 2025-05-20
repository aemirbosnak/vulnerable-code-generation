//FormAI DATASET v1.0 Category: Error handling ; Style: modular
#include <stdio.h>
#include <stdlib.h>

void file_error(char *filename) {
    fprintf(stderr, "Error: Could not open file %s\n", filename);
    exit(1);
}

void input_error() {
    fprintf(stderr, "Error: Invalid input\n");
    exit(1);
}

void mem_error() {
    fprintf(stderr, "Error: Out of memory\n");
    exit(1);
}

int main() {
    FILE *fp;
    char filename[] = "example.txt";
    char input[10];
    int *parray, size, i;

    // Open file
    fp = fopen(filename, "r");
    if(fp == NULL) {
        file_error(filename);
    }

    // Get size of array
    fscanf(fp, "%d", &size);
    if(size <= 0) {
        input_error();
    }

    // Allocate memory for array
    parray = (int*) malloc(size * sizeof(int));
    if(parray == NULL) {
        mem_error();
    }

    // Get array elements
    for(i=0; i<size; i++) {
        fscanf(fp, "%d", &parray[i]);
        if(parray[i] < 0) {
            input_error();
        }
    }

    // Print array
    printf("Array: ");
    for(i=0; i<size; i++) {
        printf("%d ", parray[i]);
    }
    printf("\n");

    // Free memory and close file
    free(parray);
    fclose(fp);

    return 0;
}
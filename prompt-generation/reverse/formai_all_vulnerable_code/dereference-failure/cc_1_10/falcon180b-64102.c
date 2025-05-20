//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 1024

// Function to compare two files
int compare_files(const char* file1, const char* file2) {
    FILE* f1 = fopen(file1, "r");
    FILE* f2 = fopen(file2, "r");
    char buffer1[BUFFER_SIZE], buffer2[BUFFER_SIZE];
    int c1, c2;
    
    while ((c1 = fgetc(f1))!= EOF && (c2 = fgetc(f2))!= EOF) {
        if (c1!= c2) {
            fprintf(stderr, "Files are different!\n");
            return 1;
        }
    }
    
    if (c1!= c2) {
        fprintf(stderr, "Files are different!\n");
        return 1;
    }
    
    fclose(f1);
    fclose(f2);
    return 0;
}

int main(int argc, char* argv[]) {
    if (argc!= 4) {
        fprintf(stderr, "Usage: %s <file1> <file2> <output>\n", argv[0]);
        return 1;
    }
    
    const char* file1 = argv[1];
    const char* file2 = argv[2];
    const char* output = argv[3];
    
    // Check if input files exist
    if (!file1 ||!file2) {
        fprintf(stderr, "One or more input files do not exist!\n");
        return 1;
    }
    
    // Compare files
    int result = compare_files(file1, file2);
    
    if (result == 0) {
        fprintf(stdout, "Files are the same.\n");
    } else {
        fprintf(stdout, "Files are different.\n");
    }
    
    return result;
}
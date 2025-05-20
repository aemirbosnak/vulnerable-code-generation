//Falcon2-11B DATASET v1.0 Category: Data recovery tool ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read a file
char *read_file(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }
    
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    
    char *contents = (char *)malloc(size + 1);
    if (contents == NULL) {
        perror("Error allocating memory");
        exit(1);
    }
    
    fread(contents, 1, size, fp);
    fclose(fp);
    
    contents[size] = '\0';
    
    return contents;
}

// Function to write a file
int write_file(const char *filename, const char *contents) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }
    
    fwrite(contents, 1, strlen(contents), fp);
    fclose(fp);
    
    return 0;
}

int main() {
    const char *input_file = "input.txt";
    const char *output_file = "output.txt";
    
    // Read the input file
    char *input_contents = read_file(input_file);
    
    // Write the contents to the output file
    write_file(output_file, input_contents);
    
    // Free the memory
    free(input_contents);
    
    return 0;
}
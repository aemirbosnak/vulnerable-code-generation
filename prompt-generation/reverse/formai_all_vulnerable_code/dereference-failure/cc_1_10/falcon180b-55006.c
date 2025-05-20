//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1024

int main() {
    FILE *file_in, *file_out;
    char *input_file = "input.txt";
    char *output_file = "output.txt";
    char *key = "mysecretkey";
    char buffer[SIZE];
    int i, j;

    // Open input file
    file_in = fopen(input_file, "r");
    if (!file_in) {
        printf("Error opening input file\n");
        exit(1);
    }

    // Open output file
    file_out = fopen(output_file, "w");
    if (!file_out) {
        printf("Error opening output file\n");
        exit(1);
    }

    // Get input file size
    fseek(file_in, 0, SEEK_END);
    int size = ftell(file_in);
    rewind(file_in);

    // Encrypt input file
    for (i = 0; i < size; i++) {
        fread(buffer, 1, 1, file_in);
        for (j = 0; j < strlen(key); j++) {
            buffer[i] ^= key[j];
        }
        fwrite(buffer, 1, 1, file_out);
    }

    // Close files
    fclose(file_in);
    fclose(file_out);

    printf("File encrypted successfully\n");

    return 0;
}
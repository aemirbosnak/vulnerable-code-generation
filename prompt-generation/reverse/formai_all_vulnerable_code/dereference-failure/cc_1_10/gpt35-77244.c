//FormAI DATASET v1.0 Category: Data recovery tool ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "data.file"

int main() {
    // Open file in binary mode to read
    FILE* fp = fopen(FILENAME, "rb");

    if (fp == NULL) {
        printf("ERROR: Unable to open file %s\n", FILENAME);
        return 1;
    }

    // Get the size of file by moving the file pointer to end
    // and then finding its offset from the beginning
    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    // Allocate a buffer to hold data from file
    char* file_data = (char*) malloc(file_size);

    // Read data from file into buffer
    fread(file_data, 1, file_size, fp);

    // Close file
    fclose(fp);

    // Look for deleted data in buffer
    for (int i = 0; i < file_size; i++) {
        if (file_data[i] == '\0') {
            printf("Deleted data found at offset %d\n", i);
            file_data[i] = 'X'; // Replace with some other character to recover
        }
    }

    // Open file in binary mode to write recovered data back to it
    fp = fopen(FILENAME, "wb");

    if (fp == NULL) {
        printf("ERROR: Unable to open file %s\n", FILENAME);
        return 1;
    }

    // Write recovered data to file
    fwrite(file_data, 1, file_size, fp);

    // Close file
    fclose(fp);

    // Free buffer memory
    free(file_data);

    printf("Data recovery complete!\n");

    return 0;
}
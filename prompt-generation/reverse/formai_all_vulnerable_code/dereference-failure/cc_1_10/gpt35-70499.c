//FormAI DATASET v1.0 Category: Data recovery tool ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// function to recover data from a file
void recover_data(char* filename) {
    
    FILE* data_file = fopen(filename, "r");
    
    if (data_file == NULL) {
        printf("Error opening file %s\n", filename);
        return;
    }
    
    // determine file size
    fseek(data_file, 0L, SEEK_END);
    long int file_size = ftell(data_file);
    rewind(data_file);
    
    // allocate memory for buffer to hold data
    char* buffer = (char*) malloc(file_size * sizeof(char));
    if (buffer == NULL) {
        printf("Memory allocation error\n");
        return;
    }
    
    // read data from file into buffer
    fread(buffer, sizeof(char), file_size, data_file);
    
    // search buffer for recoverable data
    int num_recoverable = 0;
    bool found_something = false;
    for (int i = 0; i < file_size; i++) {
        if (buffer[i] == 'X') {
            num_recoverable++;
            found_something = true;
        } 
    }
    
    // print results
    if (found_something) {
        printf("Recovered %d instances of data from file %s\n", num_recoverable, filename);
    } else {
        printf("No recoverable data found in file %s\n", filename);
    }
    
    // free memory and close file
    free(buffer);
    fclose(data_file);
}

// example usage of data recovery function
int main() {
    
    char* file1 = "file1.txt";
    char* file2 = "file2.txt";
    
    recover_data(file1);
    recover_data(file2);

    return 0;
}
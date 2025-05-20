//FormAI DATASET v1.0 Category: Data recovery tool ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 512

int main(int argc, char *argv[]) {
    
    // choose the file to recover
    if (argc != 2) {
        printf("Usage: ./data_recovery_tool FILENAME\n");
        return 1;
    }
    char* filename = argv[1];
    
    // open the file
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error: Could not open file %s\n", filename);
        return 1;
    }
    
    // determine the size of the file
    fseek(file, 0, SEEK_END);
    int filesize = ftell(file);
    fseek(file, 0, SEEK_SET);
    
    // create a buffer to store the file contents
    char buffer[BUFFER_SIZE + 1];
    memset(buffer, 0, BUFFER_SIZE + 1);
    int bytes_read = fread(buffer, 1, BUFFER_SIZE, file);
    
    // create a new file to write the recovered data to
    char* new_filename = strcat(filename, ".recovered");    
    FILE* new_file = fopen(new_filename, "w");
    if (!new_file) {
        printf("Error: Could not create new file %s\n", new_filename);
        return 1;
    }
    
    // write the contents of the buffer to the new file
    fwrite(buffer, 1, bytes_read, new_file);
    
    // close the files
    fclose(file);
    fclose(new_file);
    
    printf("Successfully recovered data from %s and saved it to %s\n", filename, new_filename);
    
    return 0;
}
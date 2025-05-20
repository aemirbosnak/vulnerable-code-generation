//FormAI DATASET v1.0 Category: Data recovery tool ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Usage: data_recovery_tool <filename>\n");
        return 1;
    }
    char filename[256];
    sprintf(filename, "%s", argv[1]);

    FILE *file_ptr;
    file_ptr = fopen(filename, "rb");

    if(file_ptr == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        return 1;
    }

    unsigned char *binary_data = malloc(MAX_FILE_SIZE * sizeof(unsigned char));
    unsigned int data_size;
    unsigned int bytes_read = 0;
    while(!feof(file_ptr)) {
        if(bytes_read >= MAX_FILE_SIZE) {
            printf("Error: Maximum file size exceeded.\n");
            return 1;
        }

        fread(&(binary_data[bytes_read]), 1, 1, file_ptr);
        bytes_read++;
    }
    data_size = bytes_read - 1;

    fclose(file_ptr);

    // Recover the original data by XORing with a key
    unsigned int key = 0xCAFEBABE;
    for(int i = 0; i < data_size; i++) {
        binary_data[i] = binary_data[i] ^ ((key >> (8*(i%4))) & 0xFF);
    }

    // Write recovered data to a new file
    char output_filename[256];
    sprintf(output_filename, "%s.recovered", filename);
    file_ptr = fopen(output_filename, "wb");
    if(file_ptr == NULL) {
        printf("Error: Unable to create output file %s", output_filename);
        return 1;
    }

    fwrite(binary_data, 1, data_size, file_ptr);

    fclose(file_ptr);
    printf("Data recovery complete. Recovered data written to %s\n",output_filename);
    return 0;
}
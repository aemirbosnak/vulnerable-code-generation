//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: creative
// C Checksum Calculator Example Program

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 1024 // Maximum size of data

// Function to calculate the checksum
unsigned int calculate_checksum(unsigned char *data, int size) {
    unsigned int checksum = 0;
    for (int i = 0; i < size; i++) {
        checksum += data[i];
    }
    return checksum;
}

// Function to read data from a file
unsigned char *read_data_from_file(char *filename, int *size) {
    FILE *file;
    unsigned char *data;
    int filesize;

    file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error: Cannot open file %s\n", filename);
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    filesize = ftell(file);
    rewind(file);

    data = (unsigned char *) malloc(filesize);
    if (data == NULL) {
        printf("Error: Cannot allocate memory\n");
        exit(1);
    }

    fread(data, 1, filesize, file);
    fclose(file);

    *size = filesize;
    return data;
}

// Function to write data to a file
void write_data_to_file(char *filename, unsigned char *data, int size) {
    FILE *file;

    file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Error: Cannot open file %s\n", filename);
        exit(1);
    }

    fwrite(data, 1, size, file);
    fclose(file);
}

// Main function
int main(int argc, char *argv[]) {
    char input_filename[MAX_SIZE];
    char output_filename[MAX_SIZE];
    unsigned char *data;
    int size;
    unsigned int checksum;

    // Get input file name from user
    printf("Enter input file name: ");
    scanf("%s", input_filename);

    // Read data from input file
    data = read_data_from_file(input_filename, &size);

    // Calculate checksum
    checksum = calculate_checksum(data, size);

    // Get output file name from user
    printf("Enter output file name: ");
    scanf("%s", output_filename);

    // Write data and checksum to output file
    write_data_to_file(output_filename, data, size);
    write_data_to_file(output_filename, (unsigned char *) &checksum, sizeof(checksum));

    printf("Checksum calculated and written to output file %s\n", output_filename);

    return 0;
}
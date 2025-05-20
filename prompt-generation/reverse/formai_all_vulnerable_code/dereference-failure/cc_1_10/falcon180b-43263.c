//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000 // maximum file size in bytes

// function to read data from a file
void read_file(FILE *fp, char *buffer, int size) {
    int bytes_read = fread(buffer, sizeof(char), size, fp);
    if (bytes_read!= size) {
        printf("Error: could not read entire file.\n");
        exit(1);
    }
}

// function to write data to a file
void write_file(FILE *fp, char *buffer, int size) {
    int bytes_written = fwrite(buffer, sizeof(char), size, fp);
    if (bytes_written!= size) {
        printf("Error: could not write entire file.\n");
        exit(1);
    }
}

// function to recover data from a deleted file
void recover_data(char *filename) {
    FILE *fp;
    char buffer[MAX_FILE_SIZE];
    int file_size = 0;

    // open the file for reading
    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    // read the file contents
    read_file(fp, buffer, MAX_FILE_SIZE);
    file_size = strlen(buffer);

    // close the file
    fclose(fp);

    // open the file for writing
    fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    // write the recovered data to the file
    write_file(fp, buffer, file_size);

    // close the file
    fclose(fp);

    printf("Data recovery successful!\n");
}

int main() {
    char filename[100];

    // get the filename from the user
    printf("Enter the name of the deleted file: ");
    scanf("%s", filename);

    // recover the data from the deleted file
    recover_data(filename);

    return 0;
}
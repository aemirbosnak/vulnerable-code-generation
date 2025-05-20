//Falcon-180B DATASET v1.0 Category: Error handling ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// function to read a file
void read_file(FILE* file, char* buffer, int max_size)
{
    int num_bytes_read = fread(buffer, sizeof(char), max_size, file);
    if (num_bytes_read <= 0) {
        printf("Error reading file\n");
        exit(1);
    }
}

// function to write to a file
void write_file(FILE* file, const char* buffer, int size)
{
    int num_bytes_written = fwrite(buffer, sizeof(char), size, file);
    if (num_bytes_written!= size) {
        printf("Error writing to file\n");
        exit(1);
    }
}

// function to copy a file
void copy_file(const char* source_file, const char* destination_file)
{
    FILE* source = fopen(source_file, "rb");
    if (source == NULL) {
        printf("Error opening source file\n");
        exit(1);
    }

    FILE* destination = fopen(destination_file, "wb");
    if (destination == NULL) {
        printf("Error opening destination file\n");
        exit(1);
    }

    char buffer[1024];
    while (true) {
        read_file(source, buffer, sizeof(buffer));
        int num_bytes_read = fwrite(buffer, sizeof(char), sizeof(buffer), destination);
        if (num_bytes_read!= sizeof(buffer)) {
            printf("Error writing to destination file\n");
            exit(1);
        }
        if (feof(source)) {
            break;
        }
    }

    fclose(source);
    fclose(destination);
}

// function to delete a file
void delete_file(const char* file_name)
{
    if (remove(file_name)!= 0) {
        printf("Error deleting file\n");
        exit(1);
    }
}

int main()
{
    const char* source_file = "source.txt";
    const char* destination_file = "destination.txt";
    const char* file_to_delete = "file_to_delete.txt";

    // copy the source file to the destination file
    copy_file(source_file, destination_file);

    // delete the file to delete
    delete_file(file_to_delete);

    return 0;
}
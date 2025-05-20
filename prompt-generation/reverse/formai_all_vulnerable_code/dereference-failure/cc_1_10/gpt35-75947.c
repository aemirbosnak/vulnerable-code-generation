//FormAI DATASET v1.0 Category: Data recovery tool ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_PATH_LENGTH 256
#define MAX_BUFFER_SIZE 1024

int main()
{
    char file_path[MAX_FILE_PATH_LENGTH], buffer[MAX_BUFFER_SIZE];
    FILE *f_reader, *f_writer;
    long file_size;

    printf("Enter file path to recover: ");
    fgets(file_path, MAX_FILE_PATH_LENGTH, stdin);

    // Remove trailing newline character from file_path
    file_path[strcspn(file_path, "\n")] = 0;

    // Open file for reading
    f_reader = fopen(file_path, "rb");
    if (f_reader == NULL)
    {
        printf("File not found!\n");
        return 1;
    }

    // Determine file size
    fseek(f_reader, 0, SEEK_END);
    file_size = ftell(f_reader);
    rewind(f_reader);

    // Allocate memory for buffer
    char *data = (char*)malloc(file_size);

    // Read file data into buffer
    fread(data, file_size, 1, f_reader);

    // Close file
    fclose(f_reader);

    printf("File recovered! Enter filename to save recovered data: ");
    fgets(file_path, MAX_FILE_PATH_LENGTH, stdin);

    // Remove trailing newline character from file_path
    file_path[strcspn(file_path, "\n")] = 0;

    // Open file for writing
    f_writer = fopen(file_path, "wb");
    if (f_writer == NULL)
    {
        printf("Error creating file!\n");
        return 1;
    }

    // Write recovered data to file
    fwrite(data, file_size, 1, f_writer);

    // Close file
    fclose(f_writer);

    // Free memory allocated for buffer
    free(data);

    return 0;
}
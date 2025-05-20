//FormAI DATASET v1.0 Category: File handling ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 100

int main()
{
    // Open file for writing
    FILE *file = fopen("example.txt", "w");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    // Write some data to the file
    char *data = "This is some example data!\n";
    int data_length = strlen(data);
    int bytes_written = fwrite(data, sizeof(char), data_length, file);
    if (bytes_written != data_length)
    {
        printf("Error writing to file!\n");
        exit(1);
    }

    // Close file
    fclose(file);

    // Open file for reading
    file = fopen("example.txt", "r");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    // Read data from the file
    char read_data[MAX_LENGTH];
    int bytes_read = fread(read_data, sizeof(char), MAX_LENGTH, file);
    if (bytes_read < 0)
    {
        printf("Error reading from file!\n");
        exit(1);
    }

    // Null-terminate the string
    read_data[bytes_read] = '\0';

    // Print out the read data
    printf("%s", read_data);

    // Close file
    fclose(file);

    return 0;
}
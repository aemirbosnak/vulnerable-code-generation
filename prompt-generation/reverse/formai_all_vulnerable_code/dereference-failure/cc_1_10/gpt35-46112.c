//FormAI DATASET v1.0 Category: Error handling ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

// Function prototypes
void openFile(const char* filename);
void readData(FILE* fp, int* data);

int main(int argc, char* argv[])
{
    // Check if filename argument is provided
    if (argc != 2)
    {
        printf("Error: no filename provided\n");
        exit(EXIT_FAILURE);
    }
    
    // Call function to open the file and read data from it
    openFile(argv[1]);
    
    return 0;
}

void openFile(const char* filename)
{
    FILE* fp;
    int data;
    
    // Open file for reading
    fp = fopen(filename, "r");
    
    // Check if file opening was successful
    if (fp == NULL)
    {
        // Print error message and exit program with error code
        printf("Error %d: %s\n", errno, strerror(errno));
        exit(EXIT_FAILURE);
    }
    
    // Call function to read data from file
    readData(fp, &data);
    
    // Close file
    fclose(fp);
}

void readData(FILE* fp, int* data)
{
    // Read integer from file
    int result = fscanf(fp, "%d", data);
    
    // Check if reading was successful
    if (result != 1)
    {
        // Print error message and exit program with error code
        printf("Error %d: %s\n", errno, strerror(errno));
        exit(EXIT_FAILURE);
    }
    
    printf("Data read from file: %d\n", *data);
}
//GEMINI-pro DATASET v1.0 Category: File handling ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read a file and print its contents
void readFile(char *filename) {
    FILE *fp;
    char buffer[256];

    // Open the file for reading
    fp = fopen(filename, "r");

    // Check if the file was opened successfully
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }

    // Read the file line by line and print its contents
    while (fgets(buffer, sizeof(buffer), fp)) {
        printf("%s", buffer);
    }

    // Close the file
    fclose(fp);
}

// Function to write a file with some data
void writeFile(char *filename) {
    FILE *fp;
    char data[] = "This is some data that will be written to the file";

    // Open the file for writing
    fp = fopen(filename, "w");

    // Check if the file was opened successfully
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }

    // Write the data to the file
    fwrite(data, sizeof(data), 1, fp);

    // Close the file
    fclose(fp);
}

// Function to copy the contents of one file to another
void copyFile(char *sourceFile, char *destinationFile) {
    FILE *sourceFp, *destinationFp;
    char buffer[256];

    // Open the source file for reading
    sourceFp = fopen(sourceFile, "r");

    // Check if the source file was opened successfully
    if (sourceFp == NULL) {
        perror("Error opening source file");
        return;
    }

    // Open the destination file for writing
    destinationFp = fopen(destinationFile, "w");

    // Check if the destination file was opened successfully
    if (destinationFp == NULL) {
        perror("Error opening destination file");
        return;
    }

    // Read the source file line by line and write it to the destination file
    while (fgets(buffer, sizeof(buffer), sourceFp)) {
        fwrite(buffer, sizeof(buffer), 1, destinationFp);
    }

    // Close the files
    fclose(sourceFp);
    fclose(destinationFp);
}

// Function to append some data to a file
void appendFile(char *filename) {
    FILE *fp;
    char data[] = "This is some data that will be appended to the file";

    // Open the file for appending
    fp = fopen(filename, "a");

    // Check if the file was opened successfully
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }

    // Write the data to the file
    fwrite(data, sizeof(data), 1, fp);

    // Close the file
    fclose(fp);
}

// Main function to test the file handling functions
int main() {
    // Read a file
    readFile("file1.txt");

    // Write a file
    writeFile("file2.txt");

    // Copy the contents of one file to another
    copyFile("file1.txt", "file3.txt");

    // Append some data to a file
    appendFile("file2.txt");

    return 0;
}
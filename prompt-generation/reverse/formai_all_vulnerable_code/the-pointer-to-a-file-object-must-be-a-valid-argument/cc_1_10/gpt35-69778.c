//FormAI DATASET v1.0 Category: File handling ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

int main() {

    // Welcome message
    printf("Welcome to my program! This program is an example of C file handling.\n");

    // Ask user for filename
    printf("Please enter the filename you want to create: ");
    char filename[50];
    scanf("%s", filename);

    // Create file
    FILE *fp;
    fp = fopen(filename, "w");

    // Check if file was successfully created
    if (fp == NULL) {
        printf("Error creating file. Exiting program.\n");
        exit(1);
    }

    // Write data to file
    char data[100];
    printf("Please enter data to write to the file: ");
    scanf(" %[^\n]", data);
    fprintf(fp, "%s", data);

    // Close file
    fclose(fp);

    // Re-open file in read mode
    fp = fopen(filename, "r");

    // Read data from file
    char buffer[100];
    fgets(buffer, 100, fp);

    // Display data on the console
    printf("The data written to the file is: %s\n", buffer);

    // Close file
    fclose(fp);

    // Goodbye message
    printf("Thank you for using my program! Goodbye.\n");

    return 0;
}
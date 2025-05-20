//FormAI DATASET v1.0 Category: File Synchronizer ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_FILE_NAME 100

int main(){

    // Create variables to hold the file names
    char file_1[MAX_FILE_NAME], file_2[MAX_FILE_NAME];

    // Prompt user to enter file names
    printf("Enter the name of the first file: ");
    scanf("%s", file_1);

    printf("Enter the name of the second file: ");
    scanf("%s", file_2);

    // Open the first file in read mode
    FILE *file1 = fopen(file_1, "r");

    // If file1 is null, print error message and exit program
    if(file1 == NULL){
        printf("Error opening file1.");
        exit(1);
    }

    // Open the second file in read mode
    FILE *file2 = fopen(file_2, "r");

    // If file2 is null, print error message and exit program
    if(file2 == NULL){
        printf("Error opening file2.");
        exit(1);
    }

    // Get the size of the first file
    fseek(file1, 0, SEEK_END);
    int file1_size = ftell(file1);
    rewind(file1);

    // Get the size of the second file
    fseek(file2, 0, SEEK_END);
    int file2_size = ftell(file2);
    rewind(file2);

    // If the file sizes are not equal, print error message and exit program
    if(file1_size != file2_size){
        printf("The two files do not have the same size.");
        exit(1);
    }

    // Create buffer to hold file content
    char *buffer1 = (char*) malloc(file1_size * sizeof(char));
    char *buffer2 = (char*) malloc(file2_size * sizeof(char));

    // Read the content of the first file and store it in buffer1
    fread(buffer1, file1_size, 1, file1);

    // Read the content of the second file and store it in buffer2
    fread(buffer2, file2_size, 1, file2);

    // Compare the contents of the files
    int result = strcmp(buffer1, buffer2);

    // If the contents are equal, print success message
    if(result == 0){
        printf("The two files have synchronized contents.");
    }
    // If the contents are different, print error message
    else {
        printf("The two files do not have synchronized contents.");
    }

    // Free the memory allocated for the buffers
    free(buffer1);
    free(buffer2);

    // Close the files
    fclose(file1);
    fclose(file2);

    return 0;
}
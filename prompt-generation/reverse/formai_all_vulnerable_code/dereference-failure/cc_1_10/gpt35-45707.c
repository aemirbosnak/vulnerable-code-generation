//FormAI DATASET v1.0 Category: File Synchronizer ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LEN 256 // Maximum length of the file name
#define MAX_FILE_SIZE 1048576 // Maximum file size - 1 MB

// Function to compare two files
int compare_files(FILE *file1, FILE *file2) {
    char ch1, ch2;
    
    // Reset the file pointers to the start of the file
    fseek(file1, 0, SEEK_SET);
    fseek(file2, 0, SEEK_SET);
    
    // Compare each character in the files
    while(1) {
        ch1 = fgetc(file1);
        ch2 = fgetc(file2);
        
        // If end of files is reached, break out of the loop
        if(ch1 == EOF || ch2 == EOF) {
            break;
        }
        
        // If characters do not match, files are not the same
        if(ch1 != ch2) {
            return 0;
        }
    }
    
    // If end of file is not reached for both files, files are not the same
    if(ch1 != EOF || ch2 != EOF) {
        return 0;
    }
    
    // Files are the same
    return 1;
}

int main() {
    char filename1[MAX_FILENAME_LEN], filename2[MAX_FILENAME_LEN];
    FILE *file1, *file2;
    
    printf("Enter file 1 name: ");
    scanf("%s", filename1);
    
    printf("Enter file 2 name: ");
    scanf("%s", filename2);
    
    // Open the files
    file1 = fopen(filename1, "rb");
    file2 = fopen(filename2, "rb");
    
    // If files cannot be opened, exit
    if(file1 == NULL || file2 == NULL) {
        printf("Could not open file\n");
        exit(1);
    }
    
    // Get the file sizes
    fseek(file1, 0, SEEK_END);
    fseek(file2, 0, SEEK_END);
    int filesize1 = ftell(file1);
    int filesize2 = ftell(file2);
    
    // If file sizes do not match, files are not the same
    if(filesize1 != filesize2) {
        printf("Files are not the same size\n");
        exit(1);
    }
    
    // If file sizes are too large, do not compare files
    if(filesize1 > MAX_FILE_SIZE) {
        printf("Files are too large to compare\n");
        exit(1);
    }
    
    // Compare the files
    int result = compare_files(file1, file2);
    
    if(result == 1) {
        printf("Files are the same\n");
    } else {
        printf("Files are different\n");
    }
    
    // Close the files
    fclose(file1);
    fclose(file2);
    
    return 0;
}
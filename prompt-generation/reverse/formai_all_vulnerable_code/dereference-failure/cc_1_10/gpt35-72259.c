//FormAI DATASET v1.0 Category: File Synchronizer ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024 // Maximum file size in bytes

void sync_files(char *file1, char *file2);

int main(int argc, char **argv) {
    if(argc != 3) {
        printf("Usage: ./file-sync <file1> <file2>\n");
        exit(1);
    }
    
    sync_files(argv[1], argv[2]);
    
    return 0;
}

void sync_files(char *file1, char *file2) {
    FILE *fp1, *fp2;
    char *buffer1, *buffer2;
    int file_size1, file_size2;
    
    // Open file1 in read mode
    fp1 = fopen(file1, "rb");
    if(fp1 == NULL) {
        printf("%s does not exist.\n", file1);
        exit(1);
    }
    
    // Get file1 size
    fseek(fp1, 0L, SEEK_END);
    file_size1 = ftell(fp1);
    fseek(fp1, 0L, SEEK_SET);
    
    // Allocate memory for buffer1
    buffer1 = (char *) malloc(file_size1 * sizeof(char));
    if(buffer1 == NULL) {
        printf("Memory allocation error.\n");
        exit(1);
    }
    
    // Read file1 and store data in buffer1
    fread(buffer1, 1, file_size1, fp1);
    
    // Close file1
    fclose(fp1);
    
    // Open file2 in read mode
    fp2 = fopen(file2, "rb");
    if(fp2 == NULL) {
        printf("%s does not exist.\n", file2);
        exit(1);
    }
    
    // Get file2 size
    fseek(fp2, 0L, SEEK_END);
    file_size2 = ftell(fp2);
    fseek(fp2, 0L, SEEK_SET);
    
    // Allocate memory for buffer2
    buffer2 = (char *) malloc(file_size2 * sizeof(char));
    if(buffer2 == NULL) {
        printf("Memory allocation error.\n");
        exit(1);
    }
    
    // Read file2 and store data in buffer2
    fread(buffer2, 1, file_size2, fp2);
    
    // Close file2
    fclose(fp2);
    
    // Compare file1 and file2
    if(file_size1 == file_size2 && memcmp(buffer1, buffer2, file_size1) == 0) {
        printf("%s and %s are already in sync.\n", file1, file2);
        free(buffer1);
        free(buffer2);
        return;
    }
    
    // Open file2 in write mode
    fp2 = fopen(file2, "wb");
    if(fp2 == NULL) {
        printf("Error opening %s.\n", file2);
        free(buffer1);
        free(buffer2);
        exit(1);
    }
    
    // Write file1 data to file2
    fwrite(buffer1, 1, file_size1, fp2);
    
    // Close file2
    fclose(fp2);
    
    printf("%s and %s are now in sync.\n", file1, file2);
    
    // Free allocated memory
    free(buffer1);
    free(buffer2);
}
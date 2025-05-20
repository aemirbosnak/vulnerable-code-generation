//FormAI DATASET v1.0 Category: File Encyptor ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

    // Check if the file name is provided as argument
    if (argc < 2) {
        printf("Please provide a file name.\n");
        return 1;
    }
    
    // Open the file in read mode
    FILE *fp = fopen(argv[1], "r");
    
    // Check if the file is opened successfully
    if (fp == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }
    
    // Get the file size
    fseek(fp, 0L, SEEK_END);
    int file_size = ftell(fp);
    fseek(fp, 0L, SEEK_SET);
    
    // Allocate memory for the file content buffer
    char *file_content = (char*) malloc(file_size);
    
    // Read the file contents into the buffer
    fread(file_content, sizeof(char), file_size, fp);
    
    // Close the file
    fclose(fp);
    
    // Define the encryption key
    char key[] = "mysecretkey";
    int key_len = strlen(key);
    
    // Encrypt the file contents
    for (int i = 0; i < file_size; i++) {
        file_content[i] ^= key[i % key_len];
    }
    
    // Create a new file and write the encrypted contents to it
    char output_file_name[50];
    strcpy(output_file_name, "encrypted_");
    strcat(output_file_name, argv[1]);
    
    FILE *output_fp = fopen(output_file_name, "w");
    
    if (output_fp == NULL) {
        printf("Error creating the output file.\n");
        return 1;
    }
    
    fwrite(file_content, sizeof(char), file_size, output_fp);
    
    fclose(output_fp);
    
    printf("Encryption successful.\nNew file: %s\n", output_file_name);
    
    return 0;
}
//Falcon2-11B DATASET v1.0 Category: File Encyptor ; Style: ultraprecise
#include <stdio.h>
#include <string.h>

int main() {
    // Get the file name from the user
    char* file_name = "input.txt";
    printf("Enter the name of the file you want to encrypt: ");
    scanf("%s", file_name);
    
    // Open the file in read mode
    FILE* fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("Error: Unable to open the file.\n");
        return 1;
    }
    
    // Get the file size
    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    
    // Allocate memory for the encrypted file
    char* encrypted_file = (char*)malloc(file_size + 1);
    if (encrypted_file == NULL) {
        printf("Error: Unable to allocate memory for the encrypted file.\n");
        return 1;
    }
    
    // Read the contents of the file
    fread(encrypted_file, file_size, 1, fp);
    encrypted_file[file_size] = '\0';
    
    // Encrypt the file using a simple Caesar cipher technique
    for (int i = 0; i < file_size; i++) {
        encrypted_file[i] = (char)((encrypted_file[i] + 3) % 26 + 'a');
    }
    
    // Open the encrypted file in write mode
    fp = fopen("encrypted.txt", "w");
    if (fp == NULL) {
        printf("Error: Unable to open the encrypted file for writing.\n");
        return 1;
    }
    
    // Write the encrypted contents to the file
    fwrite(encrypted_file, file_size, 1, fp);
    
    // Close the files
    fclose(fp);
    free(encrypted_file);
    
    return 0;
}
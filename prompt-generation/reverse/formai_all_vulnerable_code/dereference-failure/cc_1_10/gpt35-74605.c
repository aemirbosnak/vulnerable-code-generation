//FormAI DATASET v1.0 Category: File Encyptor ; Style: Cryptic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Function to encrypt the file
void encrypt_file(FILE *f_source, FILE *f_destination, char *key) {
    int ch, key_index = 0;
    //Loop through each character in the source file
    while ((ch = fgetc(f_source)) != EOF) {
        //Encrypt each character using a bitwise XOR operation with the key
        fputc(ch ^ key[key_index], f_destination);
        //Increment the key index
        key_index++;
        //If the end of the key is reached, start over from the beginning
        if (key_index >= strlen(key)) {
            key_index = 0;
        }
    }
}

int main() {
    //Declare variables
    char file_name[50], new_file_name[50], key[50];
    FILE *f_source, *f_destination;
    //Prompt the user for the file to encrypt
    printf("Enter the name of the file to encrypt: ");
    scanf("%s", file_name);
    //Open the source file
    f_source = fopen(file_name, "rb");
    //If the file cannot be opened, print an error message and exit
    if (f_source == NULL) {
        printf("Error opening file %s!", file_name);
        exit(1);
    }
    //Prompt the user for the name of the encrypted file
    printf("Enter the name of the encrypted file: ");
    scanf("%s", new_file_name);
    //Open the destination file for writing
    f_destination = fopen(new_file_name, "wb");
    //If the file cannot be opened, print an error message and exit
    if (f_destination == NULL) {
        printf("Error opening file %s!", new_file_name);
        exit(1);
    }
    //Prompt the user for the encryption key
    printf("Enter the encryption key: ");
    scanf("%s", key);
    //Call the encrypt_file function with the source file, destination file, and key as arguments
    encrypt_file(f_source, f_destination, key);
    //Close both files
    fclose(f_source);
    fclose(f_destination);
    //Print a success message
    printf("File successfully encrypted!\n");
    return 0;
}
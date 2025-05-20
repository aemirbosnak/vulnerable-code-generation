//FormAI DATASET v1.0 Category: File Encyptor ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]){
    if(argc < 2){
        printf("Usage: %s <filename> <password>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *filename = argv[1];
    char *password = argv[2];

    FILE *input_file = fopen(filename, "rb");
    if(input_file == NULL){
        printf("Error opening file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    // Create output file with ".enc" extension
    char output_filename[strlen(filename) + 5];
    strcpy(output_filename, filename);
    strcat(output_filename, ".enc");
    FILE *output_file = fopen(output_filename, "wb");
    if(output_file == NULL){
        printf("Error creating output file: %s\n", output_filename);
        exit(EXIT_FAILURE);
    }

    // Write password length to output file
    int password_length = strlen(password);
    fwrite(&password_length, sizeof(int), 1, output_file);

    // Encrypt file content with password
    char buffer[BUFFER_SIZE];
    int read_bytes;
    int i = 0;
    int password_index = 0;

    while((read_bytes = fread(buffer, sizeof(char), BUFFER_SIZE, input_file)) > 0){
        for(i = 0; i < read_bytes; i++){
            buffer[i] ^= password[password_index];
            password_index++;
            if(password_index == password_length){
                password_index = 0;
            }
        }
        fwrite(buffer, sizeof(char), read_bytes, output_file);
    }

    fclose(input_file);
    fclose(output_file);

    printf("File %s encrypted with password %s\n", filename, password);

    return 0;
}
//FormAI DATASET v1.0 Category: File Encyptor ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000

void encrypt(char *filename, int key); // Function that encrypts the given file with the given key
void decrypt(char *filename, int key); // Function that decrypts the given file with the given key

int main(int argc, char *argv[]) {
    int key;

    if (argc < 4) { // Check if enough arguments are provided
        printf("Usage: %s <input_file> <output_file> <key>\n", argv[0]);
        return -1;
    }

    key = atoi(argv[3]); // Convert key from string to integer

    if (key <= 0) { // Check if key is valid
        printf("Invalid key. Key must be a positive integer.\n");
        return -1;
    }

    if (strcmp(argv[1], argv[2]) == 0) { // Check if input_file and output_file are the same
        printf("Input file and output file cannot be the same.\n");
        return -1;
    }

    encrypt(argv[1], key); // Encrypt input file with the given key
    decrypt(argv[2], key); // Decrypt output file with the given key

    return 0;
}

void encrypt(char *filename, int key) {
    FILE *input_file, *output_file;
    char input[MAX_LEN];
    int i = 0;

    input_file = fopen(filename, "r");

    if (input_file == NULL) { // Check if input file can be opened
        printf("Could not open file: %s\n", filename);
        exit(-1);
    }

    output_file = fopen("temp.bin", "wb"); // Create a binary file to write encrypted data in
    if (output_file == NULL) { // Check if output file can be created
        fclose(input_file);
        remove("temp.bin"); // Delete the binary file
        printf("Could not create file: temp.bin\n");
        exit(-1);
    }

    while (fgets(input, MAX_LEN, input_file) != NULL) { // Read line by line from the input file
        for (i = 0; i < strlen(input) - 1; i++) { // Encrypt each character of the line
            input[i] += key;
        }
        fwrite(input, sizeof(char), strlen(input), output_file); // Write encrypted data to binary file
    }

    fclose(input_file);
    fclose(output_file);
    remove(filename); // Delete original input file
    rename("temp.bin", filename); // Rename binary file to original file name
}

void decrypt(char *filename, int key) {
    FILE *input_file, *output_file;
    char input[MAX_LEN];
    int i = 0;

    input_file = fopen(filename, "rb");

    if (input_file == NULL) { // Check if input file can be opened
        printf("Could not open file: %s\n", filename);
        exit(-1);
    }

    output_file = fopen("temp.txt", "w"); // Create a text file to write decrypted data in
    if (output_file == NULL) { // Check if output file can be created
        fclose(input_file);
        remove("temp.txt"); // Delete the text file
        printf("Could not create file: temp.txt\n");
        exit(-1);
    }

    while (fread(input, sizeof(char), MAX_LEN, input_file) != 0) { // Read from binary file
        for (i = 0; i < strlen(input); i++) { // Decrypt each character of the line
            input[i] -= key;
        }
        fwrite(input, sizeof(char), strlen(input), output_file); // Write decrypted data to text file
    }

    fclose(input_file);
    fclose(output_file);
    remove(filename); // Delete original output file
    rename("temp.txt", filename); // Rename text file to original file name
}
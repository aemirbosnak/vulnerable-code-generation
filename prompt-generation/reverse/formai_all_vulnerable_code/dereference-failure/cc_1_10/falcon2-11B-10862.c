//Falcon2-11B DATASET v1.0 Category: Image Steganography ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

// Function to read image data from a file
int read_image(char* filename, unsigned char* data, int size) {
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: could not open %s\n", filename);
        exit(1);
    }
    
    fread(data, 1, size, fp);
    fclose(fp);
    return 0;
}

// Function to write image data to a file
int write_image(char* filename, unsigned char* data, int size) {
    FILE* fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error: could not open %s\n", filename);
        exit(1);
    }
    
    fwrite(data, 1, size, fp);
    fclose(fp);
    return 0;
}

// Function to perform steganography
int stego(unsigned char* secret, int secret_len, unsigned char* image, int image_len, char* output) {
    unsigned char* encoded_data = malloc(image_len);
    int encoded_len = 0;
    
    // Encode the secret message into the image
    for (int i = 0; i < secret_len; i++) {
        unsigned char value = secret[i];
        int index = (image_len - 1) - encoded_len;
        while (index >= 0) {
            if (image[index] == value) {
                encoded_data[encoded_len] = value;
                encoded_len++;
                index = encoded_len - 1;
                break;
            } else {
                index--;
            }
        }
    }
    
    // Write the encoded data back to the image
    write_image(output, encoded_data, encoded_len);
    free(encoded_data);
    
    return 0;
}

// Main function
int main() {
    char input_file[100];
    char output_file[100];
    unsigned char secret[100];
    int secret_len;
    
    printf("Enter input file name: ");
    scanf("%s", input_file);
    printf("Enter output file name: ");
    scanf("%s", output_file);
    
    printf("Enter secret message: ");
    scanf("%s", secret);
    secret_len = strlen(secret);
    
    printf("Reading image from %s...\n", input_file);
    read_image(input_file, secret, secret_len);
    printf("Steganography in progress...\n");
    stego(secret, secret_len, secret, secret_len, output_file);
    printf("Steganography completed. Encoded data saved to %s.\n", output_file);
    
    return 0;
}
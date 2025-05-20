//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: funny
#include <stdio.h>
#include <stdlib.h>

#define SECRET_KEY 0x42   // It's a bird, it's a plane, no, it's a key!
#define BUFFER_SIZE 1024   // Size of our superhero's cape... oops, buffer!

// Function prototypes
void encrypt_file(FILE *input_file, FILE *output_file);
void decrypt_file(FILE *input_file, FILE *output_file);
void hilarious_message(const char *message);

int main(int argc, char *argv[]) {
    if (argc != 4) {
        hilarious_message("Hey buddy! You need to provide: <command> <input_file> <output_file>");
        return EXIT_FAILURE;
    }

    FILE *input_file = fopen(argv[2], "rb");
    if (input_file == NULL) {
        hilarious_message("Oops! Can't find your input file. Did it run away?");
        return EXIT_FAILURE;
    }

    FILE *output_file = fopen(argv[3], "wb");
    if (output_file == NULL) {
        hilarious_message("Whoa! Can't create the output file. Where's my magic wand?");
        fclose(input_file);
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "encrypt") == 0) {
        encrypt_file(input_file, output_file);
        hilarious_message("Done! Your file is now encrypted. Don't lose the key!");
    } else if (strcmp(argv[1], "decrypt") == 0) {
        decrypt_file(input_file, output_file);
        hilarious_message("Voila! Your file has been decrypted. Welcome back!");
    } else {
        hilarious_message("Uh-oh! You entered a wrong command! It should be 'encrypt' or 'decrypt'.");
    }

    fclose(input_file);
    fclose(output_file);
    return EXIT_SUCCESS;
}

void encrypt_file(FILE *input_file, FILE *output_file) {
    unsigned char buffer[BUFFER_SIZE];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, input_file)) > 0) {        
        for (size_t i = 0; i < bytes_read; i++) {
            buffer[i] ^= SECRET_KEY; // Not just XOR, it’s magic XOR!
        }
        fwrite(buffer, 1, bytes_read, output_file);
    }
}

void decrypt_file(FILE *input_file, FILE *output_file) {
    unsigned char buffer[BUFFER_SIZE];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, input_file)) > 0) {
        for (size_t i = 0; i < bytes_read; i++) {
            buffer[i] ^= SECRET_KEY; // Even magicians have to follow the rules!
        }
        fwrite(buffer, 1, bytes_read, output_file);
    }
}

void hilarious_message(const char *message) {
    printf("\n*** HILARIOUS ENCRYPTION MESSAGE ***\n");
    printf("%s\n", message);
    printf("****************************************\n");
}
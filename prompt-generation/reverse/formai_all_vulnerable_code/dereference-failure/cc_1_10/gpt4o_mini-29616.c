//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define HEADER_SIZE 54

typedef struct {
    char *input_file;
    char *output_file;
    char *secret_message;
} ThreadArgs;

void encode_message_to_bmp(const char *input_file, const char *output_file, const char *message);
void decode_message_from_bmp(const char *input_file);
void *thread_func(void *arg);

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <input_bmp_file> <output_bmp_file> <secret_message>\n", argv[0]);
        return 1;
    }

    char *input_file = argv[1];
    char *output_file = argv[2];
    char *secret_message = argv[3];

    ThreadArgs args1 = {input_file, output_file, secret_message};
    ThreadArgs args2 = {output_file, NULL, NULL};

    pthread_t encoder_thread, decoder_thread;

    // Create threads for encoding and decoding
    pthread_create(&encoder_thread, NULL, thread_func, &args1);
    pthread_create(&decoder_thread, NULL, thread_func, &args2);

    // Wait for both threads to complete
    pthread_join(encoder_thread, NULL);
    pthread_join(decoder_thread, NULL);

    return 0;
}

void encode_message_to_bmp(const char *input_file, const char *output_file, const char *message) {
    FILE *infile = fopen(input_file, "rb");
    if (!infile) {
        perror("Error opening input file");
        return;
    }

    FILE *outfile = fopen(output_file, "wb");
    if (!outfile) {
        perror("Error opening output file");
        fclose(infile);
        return;
    }

    unsigned char header[HEADER_SIZE];
    fread(header, sizeof(unsigned char), HEADER_SIZE, infile);
    fwrite(header, sizeof(unsigned char), HEADER_SIZE, outfile);

    // Move to pixel data
    fseek(infile, HEADER_SIZE, SEEK_SET);
    fseek(outfile, HEADER_SIZE, SEEK_SET);

    // Encode the message into the BMP image
    int message_length = strlen(message);
    for (int i = 0; i < message_length; i++) {
        unsigned char pixel[3];
        fread(pixel, sizeof(unsigned char), 3, infile);
        
        // Embed the message into the least significant bit of the blue channel
        pixel[0] = (pixel[0] & 0xFE) | ((message[i] >> 7) & 0x01);
        pixel[1] = (pixel[1] & 0xFE) | ((message[i] >> 6) & 0x01);
        pixel[2] = (pixel[2] & 0xFE) | ((message[i] >> 5) & 0x01);
        
        fwrite(pixel, sizeof(unsigned char), 3, outfile);
    }

    // Copy the remaining pixel data
    unsigned char remaining_pixel[3];
    while (fread(remaining_pixel, sizeof(unsigned char), 3, infile)) {
        fwrite(remaining_pixel, sizeof(unsigned char), 3, outfile);
    }

    fclose(infile);
    fclose(outfile);
    printf("Message encoded successfully into %s\n", output_file);
}

void decode_message_from_bmp(const char *input_file) {
    FILE *infile = fopen(input_file, "rb");
    if (!infile) {
        perror("Error opening input file");
        return;
    }

    unsigned char header[HEADER_SIZE];
    fread(header, sizeof(unsigned char), HEADER_SIZE, infile);

    printf("Decoded Message: ");
    for (int i = 0; i < 100; i++) { // Read up to 100 characters.
        unsigned char pixel[3];
        if (fread(pixel, sizeof(unsigned char), 3, infile) != 3) break;

        char character = 0;
        character |= (pixel[0] & 0x01) << 7;
        character |= (pixel[1] & 0x01) << 6;
        character |= (pixel[2] & 0x01) << 5;

        if (character == '\0') break; // End of message
        putchar(character);
    }
    putchar('\n');

    fclose(infile);
}

void *thread_func(void *arg) {
    ThreadArgs *args = (ThreadArgs *)arg;

    if (args->secret_message) {
        encode_message_to_bmp(args->input_file, args->output_file, args->secret_message);
    } else {
        decode_message_from_bmp(args->input_file);
    }

    return NULL;
}
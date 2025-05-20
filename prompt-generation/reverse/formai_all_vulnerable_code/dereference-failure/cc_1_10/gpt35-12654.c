//FormAI DATASET v1.0 Category: Image Steganography ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// function to convert integer to binary
void decimal_to_binary(int n, int* binary) {
    // converting decimal to binary
    int i = 0;
    while(n > 0) {
        binary[i++] = n % 2;
        n /= 2;
    }
}

// function to convert binary to integer
int binary_to_decimal(int* binary, int size) {
    int decimal = 0;
    for(int i = 0; i < size; i++) {
        decimal += binary[i] * pow(2, i);
    }
    return decimal;
}

// function to embed message in the image
void embed_message(char* message, char* image_file_path) {
    // open image file in binary mode
    FILE* image_file = fopen(image_file_path, "rb+");
    if(image_file == NULL) {
        printf("ERROR: Failed to open file %s\n", image_file_path);
        return;
    }

    // get image file size
    fseek(image_file, 0, SEEK_END);
    int image_file_size = ftell(image_file);
    fseek(image_file, 0, SEEK_SET);

    // calculate maximum message size that can be embedded in the image
    int max_message_size = image_file_size / 8;

    // compute message size
    int message_size = strlen(message) + 1;
    int binary_message_size[32] = {0};
    decimal_to_binary(message_size, binary_message_size);

    // check if message can be embedded in the image
    if(message_size > max_message_size) {
        printf("ERROR: Message size is too large to be embedded in the image\n");
        fclose(image_file);
        return;
    }

    // read image data into buffer
    unsigned char image_buffer[image_file_size];
    fread(image_buffer, 1, image_file_size, image_file);

    // embed message size in the image
    int count = 0;
    int i, j, k;
    for(i = 0; i < 4; i++) {
        for(j = 0; j < 8; j++, count++) {
            int bit = (binary_message_size[i] >> j) & 1;
            if(bit == 0 && image_buffer[count] % 2 == 1) {
                image_buffer[count]--;
            }
            else if(bit == 1 && image_buffer[count] % 2 == 0) {
                image_buffer[count]++;
            }
        }
    }

    // embed message in the image
    count = 32;
    for(i = 0; i < message_size; i++) {
        char ascii_char = message[i];
        int binary_ascii_char[8] = {0};
        decimal_to_binary(ascii_char, binary_ascii_char);
        for(j = 0; j < 8; j++, count++) {
            int bit = binary_ascii_char[j];
            if(bit == 0 && image_buffer[count] % 2 == 1) {
                image_buffer[count]--;
            }
            else if(bit == 1 && image_buffer[count] % 2 == 0) {
                image_buffer[count]++;
            }
        }
    }

    // write updated image buffer to the image file
    fseek(image_file, 0, SEEK_SET);
    fwrite(image_buffer, 1, image_file_size, image_file);

    // close image file
    fclose(image_file);

    printf("Message successfully embedded in the image!\n");
}

// function to extract message from the image
void extract_message(char* image_file_path) {
    // open image in binary mode
    FILE* image_file = fopen(image_file_path, "rb");
    if(image_file == NULL) {
        printf("ERROR: Failed to open file %s\n", image_file_path);
        return;
    }

    // get image file size
    fseek(image_file, 0, SEEK_END);
    int image_file_size = ftell(image_file);
    fseek(image_file, 0, SEEK_SET);

    // read image data into buffer
    unsigned char image_buffer[image_file_size];
    fread(image_buffer, 1, image_file_size, image_file);

    // extract message size from the image
    int binary_message_size[32] = {0};
    int i, j, k;
    for(i = 0; i < 4; i++) {
        for(j = 0; j < 8; j++) {
            int byte = image_buffer[i*8+j];
            binary_message_size[i] += (byte % 2) * pow(2, j);
        }
    }
    int message_size = binary_to_decimal(binary_message_size, 32);

    // check if message size is valid
    if(message_size <= 0) {
        printf("ERROR: Invalid message size extracted from the image\n");
        fclose(image_file);
        return;
    }

    // extract message from the image
    char message[message_size];
    memset(message, 0, message_size);
    int count = 32;
    for(i = 0; i < message_size; i++) {
        int binary_ascii_char[8] = {0};
        for(j = 0; j < 8; j++, count++) {
            int byte = image_buffer[count];
            binary_ascii_char[j] = byte % 2;
        }
        message[i] = binary_to_decimal(binary_ascii_char, 8);
    }

    // print the extracted message
    printf("Extracted message from the image: %s\n", message);

    // close image file
    fclose(image_file);
}

// main function
int main(int argc, char* argv[]) {
    char* message;
    char* image_file_path;

    if(argc == 3) {
        message = argv[1];
        image_file_path = argv[2];

        // check if image file exists
        FILE* image_file = fopen(image_file_path, "rb");
        if(image_file == NULL) {
            printf("ERROR: Image file %s does not exist\n", image_file_path);
            return 1;
        }
        else {
            fclose(image_file);
        }

        // embed the message in the image
        embed_message(message, image_file_path);

        // extract the message from the image
        extract_message(image_file_path);
    }

    else {
        printf("ERROR: Invalid number of arguments\n");
        printf("USAGE: %s <message> <image file path>\n", argv[0]);
        return 1;
    }

    return 0;
}
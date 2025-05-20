//FormAI DATASET v1.0 Category: Image Steganography ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to encode message into image
void encode(char *img_file, char *message_file, char *new_img_file) {

    // open input file
    FILE *img_in = fopen(img_file, "rb");
    if (img_in == NULL) {
        printf("Error: could not open %s\n", img_file);
        exit(1);
    }

    // open message file
    FILE *msg_in = fopen(message_file, "r");
    if (msg_in == NULL) {
        printf("Error: could not open %s\n", message_file);
        exit(1);
    }

    // open output file
    FILE *img_out = fopen(new_img_file, "wb");
    if (img_out == NULL) {
        printf("Error: could not open %s\n", new_img_file);
        exit(1);
    }

    // get size of input image file
    fseek(img_in, 0, SEEK_END);
    long img_size = ftell(img_in);
    fseek(img_in, 0, SEEK_SET);

    // read image data into buffer
    unsigned char *img_buffer = (unsigned char *)malloc(img_size);
    fread(img_buffer, 1, img_size, img_in);
    fclose(img_in);

    // get size of message file
    fseek(msg_in, 0, SEEK_END);
    long msg_size = ftell(msg_in);
    fseek(msg_in, 0, SEEK_SET);

    // read message into buffer
    char *msg_buffer = (char *)malloc(msg_size);
    fread(msg_buffer, 1, msg_size, msg_in);
    fclose(msg_in);

    // check if message size is larger than size of image data
    if ((msg_size + 4) > (img_size * 3)) {
        printf("Error: message is too large to encode into image\n");
        exit(1);
    }

    // encode message into image data
    char *size_str = (char *)malloc(5);
    sprintf(size_str, "%04ld", msg_size);
    for (int i = 0; i < 4; i++) {
        img_buffer[i] = size_str[i];
    }
    int img_idx = 4; // skip past 4 bytes used to store message size
    int bit_idx = 0;
    for (int i = 0; i < msg_size; i++) {
        char msg_char = msg_buffer[i];
        for (int j = 7; j >= 0; j--) {
            unsigned int bit = (msg_char >> j) & 1;
            img_buffer[img_idx] &= 0xFE; // clear least significant bit
            img_buffer[img_idx] |= bit; // set least significant bit to message bit
            bit_idx++;
            img_idx += bit_idx / 8; // 1 byte can hold 8 bits, so increment buffer index every 8 bits
            bit_idx %= 8;
        }
    }

    // write encoded image data to output file
    fwrite(img_buffer, 1, img_size, img_out);
    fclose(img_out);

    // free dynamically allocated memory
    free(img_buffer);
    free(msg_buffer);
}

// function to decode message from image
void decode(char *img_file, char *message_file) {

    // open input file
    FILE *img_in = fopen(img_file, "rb");
    if (img_in == NULL) {
        printf("Error: could not open %s\n", img_file);
        exit(1);
    }

    // get size of input image file
    fseek(img_in, 0, SEEK_END);
    long img_size = ftell(img_in);
    fseek(img_in, 0, SEEK_SET);

    // read image data into buffer
    unsigned char *img_buffer = (unsigned char *)malloc(img_size);
    fread(img_buffer, 1, img_size, img_in);
    fclose(img_in);

    // read size of message from first 4 bytes of image data
    char *size_str = (char *)malloc(5);
    for (int i = 0; i < 4; i++) {
        size_str[i] = img_buffer[i];
    }
    size_str[4] = '\0';
    long msg_size = atol(size_str);

    // write message data to output file
    FILE *msg_out = fopen(message_file, "w");
    if (msg_out == NULL) {
        printf("Error: could not open %s\n", message_file);
        exit(1);
    }
    int img_idx = 4; // skip past 4 bytes used to store message size
    int bit_idx = 0;
    int byte = 0;
    for (int i = 0; i < msg_size; i++) {
        char msg_char = 0;
        for (int j = 0; j < 8; j++) {
            unsigned int bit = img_buffer[img_idx] & 1; // extract least significant bit
            msg_char |= (bit << (7 - j)); // set j-th bit of message character to extracted bit
            img_idx += bit_idx / 8; // 1 byte can hold 8 bits, so increment buffer index every 8 bits
            bit_idx++;
            bit_idx %= 8;
        }
        byte++;
        fprintf(msg_out, "%c", msg_char);
    }
    fclose(msg_out);

    // free dynamically allocated memory
    free(img_buffer);
    free(size_str);
}

// main function to test steganography
int main() {

    int choice = 0;
    char img_file[100];
    char message_file[100];
    char new_img_file[100];

    while (1) {
        printf("\n1. Encode message into image\n");
        printf("2. Decode message from image\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // encode message into image
                printf("\nEnter image file name (with extension): ");
                scanf("%s", img_file);
                printf("Enter message file name (with extension): ");
                scanf("%s", message_file);
                printf("Enter new image file name (with extension): ");
                scanf("%s", new_img_file);
                encode(img_file, message_file, new_img_file);
                printf("Message successfully encoded into image!\n");
                break;
            case 2: // decode message from image
                printf("\nEnter image file name (with extension): ");
                scanf("%s", img_file);
                printf("Enter message file name (with extension): ");
                scanf("%s", message_file);
                decode(img_file, message_file);
                printf("Message successfully decoded from image!\n");
                break;
            case 3: // exit program
                printf("Exiting...\n");
                exit(0);
            default: // invalid choice
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}
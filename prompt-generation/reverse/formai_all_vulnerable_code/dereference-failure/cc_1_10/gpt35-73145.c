//FormAI DATASET v1.0 Category: Image Steganography ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000 // maximum size of image file
#define MAX_MSG_SIZE 200 // maximum size of message that can be hidden in the image
#define BMP_HEADER_SIZE 54 // header size of bmp file

void hide_msg_in_bmp(const char *img_file_name, const char *msg_file_name, const char *output_file_name) {
    FILE *img_file = fopen(img_file_name, "rb");
    FILE *msg_file = fopen(msg_file_name, "r");
    FILE *output_file = fopen(output_file_name, "wb");

    if (!img_file) {
        printf("Error: Failed to open image file.\n");
        return;
    }

    if (!msg_file) {
        printf("Error: Failed to open message file.\n");
        return;
    }

    if (!output_file) {
        printf("Error: Failed to create output file.\n");
        return;
    }

    // read image header
    unsigned char header[BMP_HEADER_SIZE];
    fread(header, sizeof(unsigned char), BMP_HEADER_SIZE, img_file);

    // copy header to output file
    fwrite(header, sizeof(unsigned char), BMP_HEADER_SIZE, output_file);

    // read image data
    unsigned char data[MAX_SIZE];
    fread(data, sizeof(unsigned char), MAX_SIZE, img_file);

    // read message
    char msg[MAX_MSG_SIZE];
    fgets(msg, MAX_MSG_SIZE, msg_file);

    // calculate message length
    int msg_len = strlen(msg);

    // convert message to binary
    char binary_msg[MAX_MSG_SIZE * 8];
    int k = 0;
    for (int i = 0; i < msg_len; i++) {
        for (int j = 7; j >= 0; j--) {
            binary_msg[k++] = ((msg[i] >> j) & 1) + '0';
        }
    }
    binary_msg[k] = '\0';

    // hide message in image data
    int binary_msg_len = strlen(binary_msg);
    int data_index = 0;
    for (int i = 0; i < binary_msg_len; i++) {
        if (data[data_index] % 2 == 0) {
            // LSB of data byte is 0, need to set it to 1 if binary_msg bit is 1
            if (binary_msg[i] == '1') {
                data[data_index]++;
            }
        } else {
            // LSB of data byte is 1, need to set it to 0 if binary_msg bit is 0
            if (binary_msg[i] == '0') {
                data[data_index]--;
            }
        }
        data_index++;
    }

    // write modified image data to output file
    fwrite(data, sizeof(unsigned char), MAX_SIZE, output_file);

    // close files
    fclose(img_file);
    fclose(msg_file);
    fclose(output_file);

    printf("Message hidden successfully.\n");

}

void extract_msg_from_bmp(const char *img_file_name, const char *output_file_name) {
    FILE *img_file = fopen(img_file_name, "rb");
    FILE *output_file = fopen(output_file_name, "w");

    if (!img_file) {
        printf("Error: Failed to open image file.\n");
        return;
    }

    if (!output_file) {
        printf("Error: Failed to create output file.\n");
        return;
    }

    // read image header
    unsigned char header[BMP_HEADER_SIZE];
    fread(header, sizeof(unsigned char), BMP_HEADER_SIZE, img_file);

    // read image data
    unsigned char data[MAX_SIZE];
    fread(data, sizeof(unsigned char), MAX_SIZE, img_file);

    // extract message from image data
    int binary_msg_len = 0;
    char binary_msg[MAX_MSG_SIZE * 8];
    int data_index = 0;
    for (int i = 0; i < MAX_SIZE; i++) {
        // if LSB of data byte is 1, append 1 to binary message
        if (data[i] % 2 == 1) {
            binary_msg[binary_msg_len++] = '1';
        } else {
            binary_msg[binary_msg_len++] = '0';
        }

        // if binary message is complete, break loop
        if (binary_msg_len == MAX_MSG_SIZE * 8) {
            break;
        }
    }
    binary_msg[binary_msg_len] = '\0';

    // convert binary message to ASCII
    char msg[MAX_MSG_SIZE];
    for (int i = 0, j = 0; i < binary_msg_len; i += 8, j++) {
        char c = 0;
        for (int k = 0; k < 8; k++) {
            c += (binary_msg[i + k] - '0') << (7 - k);
        }
        msg[j] = c;
    }
    msg[binary_msg_len / 8] = '\0';

    // write extracted message to output file
    fprintf(output_file, "%s", msg);

    // close files
    fclose(img_file);
    fclose(output_file);

    printf("Message extracted successfully.\n");
}

int main() {
    const char *img_file_name = "image.bmp";
    const char *msg_file_name = "message.txt";
    const char *output_file_name = "output.bmp";

    // hide message in image file
    hide_msg_in_bmp(img_file_name, msg_file_name, output_file_name);

    // extract message from image file
    extract_msg_from_bmp(output_file_name, "output.txt");

    return 0;
}
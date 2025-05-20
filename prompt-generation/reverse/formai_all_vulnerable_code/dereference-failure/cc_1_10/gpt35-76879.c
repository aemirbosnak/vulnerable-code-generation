//FormAI DATASET v1.0 Category: Image Steganography ; Style: shocked
#include<stdio.h>
#include<stdlib.h>

// define function to encode the message in the image
void encode(char* image_name, char* message_file) {
    // open image file and message file in binary mode
    FILE* fp_image = fopen(image_name, "rb");
    FILE* fp_message = fopen(message_file, "rb");

    // check if files were opened successfully
    if(fp_image == NULL || fp_message == NULL) {
        printf("Error while opening file\n");
        exit(EXIT_FAILURE);
    }

    // read image data
    fseek(fp_image, 0, SEEK_END);
    int image_size = ftell(fp_image);
    unsigned char* image_data = (unsigned char*) malloc(image_size);
    fseek(fp_image, 0, SEEK_SET);
    fread(image_data, 1, image_size, fp_image);

    // read message data
    fseek(fp_message, 0, SEEK_END);
    int message_size = ftell(fp_message);
    unsigned char* message_data = (unsigned char*) malloc(message_size);
    fseek(fp_message, 0, SEEK_SET);
    fread(message_data, 1, message_size, fp_message);

    // hide message in the image data
    for(int i=0; i<message_size; i++) {
        image_data[i] = (image_data[i] & 0xFE) | ((message_data[i] & 0x80) >> 7);
        image_data[i+1] = (image_data[i+1] & 0xFE) | ((message_data[i] & 0x40) >> 6);
        image_data[i+2] = (image_data[i+2] & 0xFE) | ((message_data[i] & 0x20) >> 5);
        image_data[i+3] = (image_data[i+3] & 0xFE) | ((message_data[i] & 0x10) >> 4);
        image_data[i+4] = (image_data[i+4] & 0xFE) | ((message_data[i] & 0x08) >> 3);
        image_data[i+5] = (image_data[i+5] & 0xFE) | ((message_data[i] & 0x04) >> 2);
        image_data[i+6] = (image_data[i+6] & 0xFE) | ((message_data[i] & 0x02) >> 1);
        image_data[i+7] = (image_data[i+7] & 0xFE) | (message_data[i] & 0x01);
    }

    // write image data back to file
    fseek(fp_image, 0, SEEK_SET);
    fwrite(image_data, 1, image_size, fp_image);

    // close file pointers
    fclose(fp_image);
    fclose(fp_message);

    // free memory allocated for image and message data
    free(image_data);
    free(message_data);

    printf("Message successfully encoded in image\n");
}

// define function to decode the message from the image
void decode(char* image_name, char* message_file, int message_size) {
    // open image file and message file in binary mode
    FILE* fp_image = fopen(image_name, "rb");
    FILE* fp_message = fopen(message_file, "wb");

    // check if files were opened successfully
    if(fp_image == NULL || fp_message == NULL) {
        printf("Error while opening file\n");
        exit(EXIT_FAILURE);
    }

    // read image data
    fseek(fp_image, 0, SEEK_END);
    int image_size = ftell(fp_image);
    unsigned char* image_data = (unsigned char*) malloc(image_size);
    fseek(fp_image, 0, SEEK_SET);
    fread(image_data, 1, image_size, fp_image);

    // extract message from the image data
    unsigned char message_byte = 0;
    int message_index = 0;
    for(int i=0; i<image_size; i++) {
        message_byte |= ((image_data[i] & 0x01) << (7 - (message_index % 8)));
        message_index++;

        if(message_index % 8 == 0) {
            fwrite(&message_byte, 1, 1, fp_message);
            message_byte = 0;

            if((message_index / 8) == message_size) {
                break;
            }
        }
    }

    // close file pointers
    fclose(fp_image);
    fclose(fp_message);

    // free memory allocated for image data
    free(image_data);

    printf("Message successfully decoded from image\n");
}

int main() {
    printf("Welcome to the Image Steganography example program\n");

    // encode message in the image
    encode("image.bmp", "message.txt");

    // decode message from the image
    decode("image.bmp", "decoded_message.txt", 100);

    return 0;
}
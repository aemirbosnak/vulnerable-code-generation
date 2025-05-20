//FormAI DATASET v1.0 Category: Image Steganography ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char header[54];
    unsigned char *image_data;
} ImageData;

typedef struct {
    char data[100];
    int length;
} Message;

void hide_message_in_image(ImageData *image, Message *msg){
    int image_size = ((image->header[5] & 0xFF) << 24) |
                        ((image->header[4] & 0xFF) << 16) |
                        ((image->header[3] & 0xFF) << 8) |
                        (image->header[2] & 0xFF);
    int hidden_data_size = msg->length;
    int bytes_to_hide = hidden_data_size*8 + 32;
    if (bytes_to_hide > image_size){
        printf("Need a larger image to hide the message\n");
        exit(1);
    }
    unsigned char *image_data = image->image_data;
    int byte_index = 54;
    // hide message length in first 32 bits
    unsigned char *length_bytes = (unsigned char*)&(msg->length);
    for(int i=0; i<4; i++){
        unsigned char ch = length_bytes[i];
        for(int j=0; j<8; j++){
            int bit = (ch >> j) & 1;
            int index = byte_index + 8*i + j;
            image_data[index] = (image_data[index] & (~1)) | bit;
        }
    }
    // hide message data
    unsigned char *data_bytes = msg->data;
    for(int i=0; i<hidden_data_size; i++){
        unsigned char ch = data_bytes[i];
        for(int j=0; j<8; j++){
            int bit = (ch >> j) & 1;
            int index = byte_index + 8*4 + 8*i + j;
            image_data[index] = (image_data[index] & (~1)) | bit;
        }
    }
}

Message get_message_from_image(ImageData *image){
    Message msg;
    int image_size = ((image->header[5] & 0xFF) << 24) |
                        ((image->header[4] & 0xFF) << 16) |
                        ((image->header[3] & 0xFF) << 8) |
                        (image->header[2] & 0xFF);
    unsigned char *image_data = image->image_data;
    int byte_index = 54;
    // extract message length from first 32 bits
    unsigned char length_bytes[4];
    memset(length_bytes, 0, 4);
    for(int i=0; i<4; i++){
        for(int j=0; j<8; j++){
            int bit_index = byte_index + 8*i + j;
            int bit = image_data[bit_index] & 1;
            length_bytes[i] |= (bit<<j);
        }
    }
    msg.length = *((int*)length_bytes);
    // extract message data
    char *data_bytes = msg.data;
    int hidden_data_size = msg.length;
    for(int i=0; i<hidden_data_size; i++){
        unsigned char ch = 0;
        for(int j=0; j<8; j++){
            int bit_index = byte_index + 8*4 + 8*i + j;
            int bit = image_data[bit_index] & 1;
            ch |= (bit<<j);
        }
        data_bytes[i] = ch;
    }
    return msg;
}

int main(){
    ImageData image;
    FILE *file = fopen("sample.bmp", "rb");
    if (!file){
        printf("Error opening file\n");
        return 1;
    }
    fread(image.header, 1, 54, file);
    int image_size = ((image.header[5] & 0xFF) << 24) |
                        ((image.header[4] & 0xFF) << 16) |
                        ((image.header[3] & 0xFF) << 8) |
                        (image.header[2] & 0xFF);
    unsigned char *image_data = (unsigned char*)malloc(image_size);
    fread(image_data, 1, image_size, file);
    fclose(file);
    image.image_data = image_data;
    Message message;
    strncpy(message.data, "Hello World", 100);
    message.length = strlen(message.data);
    hide_message_in_image(&image, &message);
    file = fopen("stego.bmp", "wb");
    if (!file){
        printf("Error creating output file");
        return 1;
    }
    fwrite(image.header, 1, 54, file);
    fwrite(image_data, 1, image_size, file);
    fclose(file);
    printf("Message hidden in image\n");
    free(image_data);
    // extract message from image
    file = fopen("stego.bmp", "rb");
    if (!file){
        printf("Error opening file\n");
        return 1;
    }
    fread(image.header, 1, 54, file);
    image_size = ((image.header[5] & 0xFF) << 24) |
                        ((image.header[4] & 0xFF) << 16) |
                        ((image.header[3] & 0xFF) << 8) |
                        (image.header[2] & 0xFF);
    image_data = (unsigned char*)malloc(image_size);
    fread(image_data, 1, image_size, file);
    fclose(file);
    image.image_data = image_data;
    Message recovered_msg = get_message_from_image(&image);
    printf("Recovered message: %s\n", recovered_msg.data);
    free(image_data);
    return 0;
}
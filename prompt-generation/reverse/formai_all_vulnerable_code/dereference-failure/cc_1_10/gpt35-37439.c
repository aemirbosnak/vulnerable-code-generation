//FormAI DATASET v1.0 Category: Image Steganography ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

void write_file(FILE* fp, char* message){
    int c, i = 0;
    while ((c = message[i++]) != '\0')
        fputc(c, fp);
}

char* read_file(FILE* fp){
    char *buffer = NULL;
    int string_size, read_size;
    fseek(fp, 0, SEEK_END);
    string_size = ftell(fp);
    rewind(fp);
    buffer = (char*) malloc(sizeof(char) * (string_size + 1));
    read_size = fread(buffer, sizeof(char), string_size, fp);
    buffer[string_size] = '\0';
    return buffer;
}

void hide_message(char* image_path, char* message){
    FILE* fp_image;
    FILE* fp_new_image;
    unsigned char byte_pixel;
    unsigned char new_byte_pixel;
    long image_size;
    int bit_idx = 0;
    int c, i = 0;
    image_size = 0;
    fp_image = fopen(image_path, "rb");
    if(fp_image == NULL){
        printf("Image Path is Invalid!\n");
        exit(1);
    }
    fp_new_image = fopen("new.bmp", "wb");
    if(fp_new_image == NULL){
        printf("Couldn't create file");
        exit(1);
    }
    unsigned char buffer[54];
    fread(buffer, sizeof(unsigned char), 54, fp_image);
    fwrite(buffer, sizeof(unsigned char), 54, fp_new_image);
    while ((c = message[i++]) != '\0'){
        for(int bit=0; bit<8; bit++){
            fread(&byte_pixel, sizeof(byte_pixel), 1, fp_image);
            if (bit_idx < 8){
                new_byte_pixel = (byte_pixel & (~0x01)) | ((c >> bit) & 0x01);
                bit_idx++;
            } else {
                new_byte_pixel = byte_pixel;
            }
            fwrite(&new_byte_pixel, sizeof(new_byte_pixel), 1, fp_new_image);
        }
    }
    while((fread(&byte_pixel, sizeof(byte_pixel), 1, fp_image)) == 1){
        fwrite(&byte_pixel, sizeof(byte_pixel), 1, fp_new_image);
    }
    printf("Message is hidden in the image successfully!\n");
    fclose(fp_image);
    fclose(fp_new_image);
}

char* read_message(char* image_path){
    FILE* fp;
    char* message;
    unsigned char byte_pixel;
    unsigned char bit_pixel;
    long image_size;
    int bit_idx = 0;
    message = "";
    fp = fopen(image_path, "rb");
    if(fp == NULL){
        printf("Invalid Path!");
        exit(1);
    }
    fseek(fp, 54, SEEK_SET);
    while ((fread(&byte_pixel, sizeof(byte_pixel), 1, fp)) == 1){
        bit_pixel = byte_pixel & 0x01;
        message = (char *)realloc(message, sizeof(char) * (bit_idx + 1));
        message[bit_idx] = (bit_pixel << bit_idx % 8) | (message[bit_idx] >> (8 - bit_idx %8));
        bit_idx ++;
        if(bit_idx % 8 == 0){
            if(message[bit_idx-1] == '\r' && message[bit_idx-2] == '\n' && message[bit_idx-3] == '\r' && message[bit_idx-4] == '\n'){
                message[bit_idx + 1] = '\0';
                break;
            }
        }
    }
    fclose(fp);
    printf("The hidden message is: %s\n", message);
    return message;
}

int main() {
    char* message;
    char file_path[] = "image.bmp";
    hide_message(file_path, "Hiding this message!\n");
    message = read_message("new.bmp");
    return 0;
}
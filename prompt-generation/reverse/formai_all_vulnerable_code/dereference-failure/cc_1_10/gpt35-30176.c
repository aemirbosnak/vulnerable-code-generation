//FormAI DATASET v1.0 Category: Image Steganography ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#define BIT_SIZE 8

void hide_data(unsigned char* buffer, char* data, int data_len){
    for(int i=0; i<data_len; i++){
        for(int j=0; j<BIT_SIZE; j++){
            int mask = 1 << j;
            buffer[i] = (buffer[i] & ~mask) | ((data[i] & mask) >> j);
        }
    }
}

void retrieve_data(unsigned char* buffer, char* data, int data_len){
    for(int i=0; i<data_len; i++){
        data[i] = 0;
        for(int j=0; j<BIT_SIZE; j++){
            int mask = 1 << j;
            data[i] |= ((buffer[i] & mask) << j);
        }
    }
}

int main(){
    char* img_file = "example_image.jpg";
    char* secret_msg = "This is a secret message hidden in an image!";
    int secret_msg_len = strlen(secret_msg);

    FILE* fp = fopen(img_file, "rb");
    if(fp == NULL){
        printf("Failed to open file.\n");
        return 1;
    }

    // get file size
    struct stat file_stat;
    fstat(fileno(fp), &file_stat);
    int file_size = file_stat.st_size;

    // allocate buffer for image data
    unsigned char* img_buffer = (unsigned char*)malloc(file_size);
    if(img_buffer == NULL){
        printf("Failed to allocate memory.\n");
        return 1;
    }

    // read image data into buffer
    fread(img_buffer, 1, file_size, fp);
    fclose(fp);

    // hide secret message in image
    hide_data(img_buffer, secret_msg, secret_msg_len);

    // write modified buffer back to file
    fp = fopen(img_file, "wb");
    if(fp == NULL){
        printf("Failed to open file.\n");
        return 1;
    }

    fwrite(img_buffer, 1, file_size, fp);
    fclose(fp);

    // retrieve hidden secret message from image
    char* retrieved_msg = (char*)malloc(secret_msg_len);
    if(retrieved_msg == NULL){
        printf("Failed to allocate memory.\n");
        return 1;
    }

    fp = fopen(img_file, "rb");
    if(fp == NULL){
        printf("Failed to open file.\n");
        return 1;
    }

    fread(img_buffer, 1, file_size, fp);
    fclose(fp);

    retrieve_data(img_buffer, retrieved_msg, secret_msg_len);
    printf("Retrieved message: %s\n", retrieved_msg);

    free(img_buffer);
    free(retrieved_msg);

    return 0;
}
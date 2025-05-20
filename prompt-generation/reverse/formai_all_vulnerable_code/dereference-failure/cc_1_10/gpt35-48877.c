//FormAI DATASET v1.0 Category: Image Steganography ; Style: complete
#include<stdio.h>
#include<stdlib.h>

typedef unsigned char BYTE;

void writefile(char *filename, BYTE *data, int size) {
    FILE *fp = fopen(filename, "wb"); // open in write mode
    if(fp == NULL) {
        printf("Error in opening file");
        exit(1);
    }
    fwrite(data, sizeof(BYTE), size, fp); // write operation
    fclose(fp); // close file
}

BYTE *readfile(char *filename, int *size_ptr) {
    FILE *fp = fopen(filename, "rb"); // open in read mode
    if(fp == NULL) {
        printf("Error in opening file");
        exit(1);
    }
    fseek(fp, 0, SEEK_END); // seek to end of file
    int size = ftell(fp); // get size of file
    rewind(fp); // move file pointer to beginning
    BYTE *data = (BYTE*) malloc(sizeof(BYTE) * size); // allocate memory for data
    fread(data, sizeof(BYTE), size, fp); // read operation
    fclose(fp); // close file
    *size_ptr = size; // set size_ptr to size of file
    return data; // return data
}

void embed(BYTE *image_data, int image_size, BYTE *message_data, int message_size) {
    if(image_size < message_size + 54) { // check if image has enough space to embed message (54 = BMP header size)
        printf("Image size is not enough to embed message");
        exit(1);
    }
    for(int i=54, j=0; j<message_size; i+=3, j++) { // loop over image data and embed message in 3 bytes at a time
        image_data[i] = message_data[j]; // red pixel
        image_data[i+1] = message_data[j]; // green pixel
        image_data[i+2] = message_data[j]; // blue pixel
    }
}

BYTE *extract(BYTE *image_data, int image_size, int *message_size_ptr) {
    BYTE *message_data = (BYTE*) malloc(sizeof(BYTE) * image_size); // allocate maximum possible memory for extracted message
    int message_size = 0;
    for(int i=54, j=0; i<image_size; i+=3, j++) { // loop over image data and extract message from 3 bytes at a time
        message_data[j] = image_data[i];
        if(message_data[j] == 0) { // message end delimiter
            message_size = j;
            break;
        }
    }
    *message_size_ptr = message_size;
    return message_data;
}

int main() {
    // read image file
    int image_size = 0;
    BYTE *image_data = readfile("image.bmp", &image_size);
    
    // read message file
    int message_size = 0;
    BYTE *message_data = readfile("message.txt", &message_size);

    // embed message in image
    embed(image_data, image_size, message_data, message_size);

    // write output image with embedded message
    writefile("output.bmp", image_data, image_size);

    // extract message from output image
    int extracted_message_size = 0;
    BYTE *extracted_message_data = extract(image_data, image_size, &extracted_message_size);

    // write extracted message to output file
    writefile("extracted_message.txt", extracted_message_data, extracted_message_size);

    // free allocated memory
    free(image_data);
    free(message_data);
    free(extracted_message_data);

    return 0;
}
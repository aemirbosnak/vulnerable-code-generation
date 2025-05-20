//FormAI DATASET v1.0 Category: Image Steganography ; Style: high level of detail
#include<stdio.h>
#include<stdlib.h>

/*
 * This program demonstrates an example of image steganography
 * using Least Significant Bit (LSB) algorithm to hide a message
 * in a given image.
 */

// function to get the binary form of a character
char *get_binary(char ch){
    char *binary = (char*) malloc(sizeof(char)*8);
    int i, j;
    // converting decimal to binary
    for(i=7; i>=0; i--){
        j = ch >> i;
        if(j & 1){
            *(binary+7-i) = '1';
        } else {
            *(binary+7-i) = '0';
        }
    }
    return binary;
}

// function to set the least significant bit of a byte
char set_lsb(char byte, int bit){
    if(bit){
        return (byte | 0x01);
    } else {
        return (byte & 0xFE);
    }
}

// function to hide the message into LSB of the image
void hide_message(char *image_filename, char *message){
    FILE *fp;
    int i, j, k=0;
    char ch;
    char *binary;

    fp=fopen(image_filename, "rb+");
    if(!fp){
        printf("File \"%s\" not found!", image_filename);
        exit(0);
    }

    while(*message){
        ch = *message;
        binary = get_binary(ch);
        for(i=0; i<8; i++){
            fseek(fp, k, SEEK_SET);
            fread(&ch, sizeof(char), 1, fp);
            ch = set_lsb(ch, *(binary+i)-48);
            fwrite(&ch, sizeof(char), 1, fp);
            k++;
        }
        message++;
        free(binary);
    }

    // hiding end of message indicator
    binary = get_binary('\0');
    for(i=0; i<8; i++){
        fseek(fp, k, SEEK_SET);
        fread(&ch, sizeof(char), 1, fp);
        ch = set_lsb(ch, *(binary+i)-48);
        fwrite(&ch, sizeof(char), 1, fp);
        k++;
    }
    free(binary);

    fclose(fp);
}

// function to extract the hidden message from LSB of the image
void extract_message(char *image_filename, char *message){
    FILE *fp;
    int i, j, k=0;
    char ch, c;
    char *binary = (char*) malloc(sizeof(char)*8);

    fp=fopen(image_filename, "rb");
    if(!fp){
        printf("File \"%s\" not found!", image_filename);
        exit(0);
    }

    for(i=0; i<100; i++){ // skip header
        fread(&ch, sizeof(char), 1, fp);
    }

    while(1){
        for(i=0; i<8; i++){
            fread(&ch, sizeof(char), 1, fp);
            *(binary+i) = ((ch & 0x01) + 48);
        }
        c = strtol(binary, NULL, 2);
        if(c=='\0') break;
        *(message+k) = c;
        k++;
    }
    *(message+k) = '\0';

    fclose(fp);
    free(binary);
}

int main(){
    char *image_filename = "image.bmp";
    char *message = "Hello World!";
    char *extracted_message = (char*) malloc(sizeof(char)*100);

    // hiding message in the image
    hide_message(image_filename, message);
    printf("Message \"%s\" hidden successfully.\n", message);

    // extracting message from the image
    extract_message(image_filename, extracted_message);
    printf("Message extracted from image: \"%s\"\n", extracted_message);

    free(extracted_message);
    return 0;
}